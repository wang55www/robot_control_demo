#include <iostream>
#include "../device_camera.h"

class XX_camera:public Device_ns::Device_camera
{
public:

    XX_camera(int device_id):Device_camera(device_id)
    {

    }

    /**
     * @brief 设备初始化
     */
    void init()
    {
       std::cout << "call XX_camera.init()" << std::endl;
    }

    /**
     * @brief 设备禁用
     */
    void disable()
    {
       std::cout << "call XX_camera.disable()" << std::endl;
    }



    char* get_result(char* sendMsg)
    {
        std::printf("sendMsg:%s",sendMsg);
        std::printf("call xx_camera.get_result()");
        char* rst;
        std::strcpy(rst,"hello");
        return rst;
    }

};
