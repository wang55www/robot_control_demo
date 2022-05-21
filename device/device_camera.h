#ifndef DEVICE_CAMERA_H
#define DEVICE_CAMERA_H

#include "device.h"
#include "device_enum.h"

namespace Device_ns {
    class Device_camera;
}

class Device_ns::Device_camera : public Device_ns::Device {

public:

    Device_camera(int device_id):Device(device_id)
    {

    }

    //----摄像头设备的方法定义,需要子类根据具体摄像头型号来实现------ begin

    //字符数组，二进制数组base64之后的信息
    virtual char* get_result(char* sendMsg)=0;
    //----摄像头设备的方法定义------ end

    Device_ns::Device_type get_device_type()
    {
        return Device_type::CAMERA;
    }
};

#endif // DEVICE_CAMERA_H
