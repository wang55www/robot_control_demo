#ifndef DEVICE_H
#define DEVICE_H


#include "device_enum.h"

namespace Device_ns {
    class Device;
}
/**
 * @brief 设备的通用抽象
 *
 */
class Device_ns::Device
{
    private:
        //设备ID
        int device_id;

    public:

        //设备的状态
        Device_status device_status;

        /**
         * @brief Device
         * @param device_id
         */
        Device(int device_id);

        /**
         * @brief 获取设备ID
         * @return
         */
        int get_device_id();

        /**
         * @brief 设备初始化
         */
        virtual void init()=0;

        /**
         * @brief 设备禁用
         */
        virtual void disable()=0;

        /**
         * @brief 获取设备类别
         * @return 设备类别枚举
         */
        virtual Device_type get_device_type()=0;

        ~Device();
};

#endif // DEVICE_H
