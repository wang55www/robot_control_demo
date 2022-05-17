#ifndef DEVICE_ENUM_H
#define DEVICE_ENUM_H



namespace Device_ns {
    enum class Device_status;
    enum class Device_type;
}
// 设备状态枚举
enum class Device_ns::Device_status {
    IDLE/*空闲*/,
    BUSY/*工作中*/,
    SUSPEND/*暂停工作*/,
    DISABLE/*不可用*/
};

/**
 * @brief 设备类型
 */
enum class Device_ns::Device_type {
    //机械臂
    ARM,
    //AGV
    AGV,
    //摄像头
    CAMERA,
    //未知
    NA,
};

#endif // DEVICE_ENUM_H
