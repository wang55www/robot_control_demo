#include <iostream>
#include "../device_agv.h"


class Oasis_agv:public Device_ns::Device_agv
{
public:

    Oasis_agv(int device_id):Device_ns::Device_agv(device_id){
    }

    /**
     * @brief 设备初始化
     */
    void init()
    {
       std::cout << "call Oasis_agv.init()" << std::endl;
       connect("127.0.0.1","8823",0);
    }

    /**
     * @brief 设备禁用
     */
    void disable()
    {
       std::cout << "call Oasis_agv.disable()" << std::endl;
    }

    int connect(std::string IP_Address, std::string Port_Num, int slave)
    {
        std::cout << "call Oasis_agv.connect()" << std::endl;
        std::cout << "IP_Address:"+IP_Address << " PortNum:"+Port_Num << "slave:"+std::to_string(slave) << std::endl;
        return 0;
    }

    int GetGlobalVariable(std::string paramName)
    {
        std::cout << "call Oasis_agv.GetGlobalVariable()" << std::endl;
        std::cout << "paramName:"+paramName << std::endl;
        return 0;
    }
    std::vector<int32_t>* GetAgvPose()
    {
        std::cout << "call Oasis_agv.GetAgvPose()" << std::endl;
        return nullptr;
    }

    int MoveToStation(int Station)
    {
        std::cout << "call Oasis_agv.MoveToStation()" << std::endl;
        std::printf("Station:%d",Station) ;
        return 0;
    }

    int MoveToPose(std::vector<int32_t>& PoseXY_Yaw)
    {
        std::cout << &PoseXY_Yaw << std::endl;
        std::cout << "call Oasis_agv.MoveToPose()" << std::endl;
        return 0;
    }

    int SetGlobalVariable(std::string paramName, int paramValue)
    {
        std::cout << "call Oasis_agv.SetGlobalVariable()" << std::endl;
        std::cout << "paramName:"+paramName<< " paramValue:"+std::to_string(paramValue) << std::endl;
        return 0;

    }

    int StartMission(int MissionID)
    {
        std::cout << std::to_string(MissionID) << std::endl;
        std::cout << "call Oasis_agv.StartMission()" << std::endl;
        return 0;
    }

};
