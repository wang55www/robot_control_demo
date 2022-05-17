#ifndef DEVICE_MANAGER_H
#define DEVICE_MANAGER_H

#include <iostream>
#include <map>
#include <vector>


#include "../common/common_util.h"
#include "device.h"


namespace Device_ns
{
    class Device_manager;
}

/**
 * @brief 设备管理器
 */
class Device_ns::Device_manager
{
public:

    std::map<int,Device_ns::Device*> deviceMap;

    /**
     * @brief 初始化设备管理器
     */
    void build();

    /**
     * @brief 查询设备
     * @param device_id
     * @return
     */
    Device* get_device(int device_id);

    /**
     * @brief 获取所有设备列表
     * @return
     */
    std::vector<Device*> get_devices();


    /**
     * @brief build_device
     * @param device_type
     * @param device_id
     * @return
     */
    Device_ns::Device* build_device(Device_ns::Device_type device_type,int device_id);

};

#endif // DEVICE_MANAGER_H
