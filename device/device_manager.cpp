#include "device_manager.h"

#include "../common/common_util.h"
#include "device_agv.h"
#include "impl/oasis_agv.h"
#include "impl/diana_arm.h"
#include "impl/xx_camera.h"
#include <typeinfo>

#define DEVICE_SET_FILE "/Users/xiangnan.wxn/cppws/robot_control_demo/config/devices.json"

/**
 * @brief 初始化设备管理器
 */
void Device_ns::Device_manager::build()
{
    Json::Value root=Common_util::getJsonFromFile(DEVICE_SET_FILE);
    Json::Value devices=root["devices"];
    for(unsigned int i=0;i<devices.size();i++)
    {
        Json::Value device_info=devices[i];
        Json::Int device_id=device_info["device_id"].asInt();
        Json::String device_t = device_info["device_type"].asString();
        Device_ns::Device_type device_type=Common_util::get_device_type(device_t.c_str());
        Device_ns::Device* device=build_device(device_type,device_id);
        this->deviceMap.insert(std::pair<int,Device*>(device_id,device));
    }
}

Device_ns::Device* Device_ns::Device_manager::get_device(int device_id)
{
    return deviceMap.at(device_id);
}

std::vector<Device_ns::Device*> Device_ns::Device_manager::get_devices()
{
    std::vector<Device_ns::Device*> devices;
    std::map<int,Device_ns::Device*>::iterator iter;
    for(iter=deviceMap.begin();iter!=deviceMap.end();iter++)
    {
        devices.insert(devices.begin(),iter->second);
    }
    return devices;
}

Device_ns::Device* Device_ns::Device_manager::build_device(Device_ns::Device_type device_type,int device_id)
{
    Device_ns::Device* device_p=nullptr;
    if(device_type==Device_ns::Device_type::AGV)
    {
        Oasis_agv agv(device_id);
        device_p=&agv;
    }
    else if(device_type == Device_ns::Device_type::ARM)
    {
        Diana_arm arm(device_id);
        device_p=&arm;
    }
    else if(device_type == Device_ns::Device_type::CAMERA)
    {
        XX_camera camera(device_id);
        device_p=&camera;
    }
    return device_p;
}
