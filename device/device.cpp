#include "device.h"

Device_ns::Device::Device(int device_id)
{
    this->device_id=device_id;
}

int Device_ns::Device::get_device_id()
{
    return device_id;
}


Device_ns::Device::~Device()
{

}

