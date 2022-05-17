#ifndef COMMON_UTIL_H
#define COMMON_UTIL_H

#include <json/json.h>

#include "../device/device_enum.h"

class Common_util
{
public:

    /**
     * @brief 从文件中解析json
     * @param path 文件路径
     * @return
     */
    static Json::Value getJsonFromFile(const char* path);

    //获取设备类型
    static Device_ns::Device_type get_device_type(const char* device_type_str);
};

#endif // COMMON_UTIL_H
