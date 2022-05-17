#ifndef DEVICE_AGV_H
#define DEVICE_AGV_H


#include "device.h"
#include "device_enum.h"
#include <iostream>

namespace Device_ns {
    class Device_agv;
}

class Device_ns::Device_agv : public Device_ns::Device {

public:

    Device_agv(int device_id):Device(device_id)
    {

    }

    //----agv设备的方法定义,需要子类根据具体agv型号来实现------ begin

    virtual int connect(std::string IP_Address, std::string Port_Num, int slave) = 0;
    virtual int GetGlobalVariable(std::string paramName)               = 0;
    virtual std::vector<int32_t>* GetAgvPose()                        = 0;
    virtual int MoveToStation(int Station)                                          = 0;
    virtual int MoveToPose(std::vector<int32_t>& PoseXY_Yaw)                        = 0;
    virtual int SetGlobalVariable(std::string paramName, int paramValue)            = 0;
    virtual int StartMission(int MissionID)                                         = 0;

    //----agv设备的方法定义------ end

    Device_type get_device_type()
    {
        return Device_type::AGV;
    }
};

#endif // DEVICE_AGV_H
