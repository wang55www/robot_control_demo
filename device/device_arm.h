#ifndef DEVICE_ARM_H
#define DEVICE_ARM_H


#include "device.h"
#include "device_enum.h"
#include <iostream>
#include <Eigen/Dense>


namespace Device_ns {
    class Device_arm;
}

/**
 * @brief 机械臂设备基类
 */
class Device_ns::Device_arm : public Device_ns::Device {

public:

    Device_arm(int device_id):Device(device_id)
    {

    }

    //----机械臂设备的方法定义,需要子类根据具体机械臂型号来实现------ begin

    virtual bool connectRobot(const char* strIpAddress = nullptr)            = 0;
    virtual bool holdRobotBraker()                                           = 0;
    virtual char* getRobotVariant(const char* strVariantName) = 0;
    virtual bool setRobotVariant(const char* strVariantName, const char* dblVal)  = 0;
    virtual bool runProgramEx()                                              = 0;
    virtual bool stopProgramEx()                                             = 0;
    virtual bool pauseProgramEx()                                            = 0;
    virtual bool resumeProgramEx()                                           = 0;

    using Vector6d = Eigen::Matrix<double, 6, 1>;
    virtual Vector6d* getTcpPose()           = 0;
    virtual Eigen::VectorXd* getJointPosition() = 0;

    //----机械臂设备的方法定义------ end

    Device_type get_device_type()
    {
        return Device_type::ARM;
    }
};

#endif // DEVICE_ARM_H
