#include <iostream>
#include "../device_arm.h"

class Diana_arm:public Device_ns::Device_arm
{
public:

    Diana_arm(int device_id):Device_arm(device_id)
    {

    }

    /**
     * @brief 设备初始化
     */
    void init()
    {
       std::cout << "call Diana_arm.init()" << std::endl;
       connectRobot("127.0.0.1");
    }

    /**
     * @brief 设备禁用
     */
    void disable()
    {
       std::cout << "call Diana_arm.disable()" << std::endl;
    }

    bool connectRobot(const char* strIpAddress = nullptr)
    {
        std::printf("strIpAddress:%s",strIpAddress);
        std::cout << "call Diana_arm.connectRobot()" << std::endl;
        return true;
    }

    bool holdRobotBraker()
    {
        std::cout << "call Diana_arm.holdRobotBraker()" << std::endl;
        return true;
    }

    char*  getRobotVariant(const char* strVariantName)
    {
        std::printf("strVariantName:%s",strVariantName);
        std::cout << "call Diana_arm.getRobotVariant()" << std::endl;
        char* rst;
        return std::strcpy(rst,"resultVal");
    }

    bool setRobotVariant(const char* strVariantName, const char* dblVal)
    {
        std::printf("strVariantName:%s, dblVal:%s",strVariantName,dblVal);
        std::cout << "call Diana_arm.setRobotVariant()" << std::endl;
        return true;
    }

    bool runProgramEx()
    {
        std::cout << "call Diana_arm.runProgramEx()" << std::endl;
        return true;
    }

    bool stopProgramEx()
    {
        std::cout << "call Diana_arm.stopProgramEx()" << std::endl;
        return true;
    }
    bool pauseProgramEx()
    {
        std::cout << "call Diana_arm.pauseProgramEx()" << std::endl;
        return true;
    }
    bool resumeProgramEx()
    {
        std::cout << "call Diana_arm.resumeProgramEx()" << std::endl;
        return true;
    }

    Vector6d* getTcpPose()
    {
        std::cout << "call Diana_arm.getTcpPose()" << std::endl;
        return nullptr;
    }

    Eigen::VectorXd* getJointPosition()
    {
        std::cout << "call Diana_arm.getJointPosition()" << std::endl;
       return nullptr;
    }


};
