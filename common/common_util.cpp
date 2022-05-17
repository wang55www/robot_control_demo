#include <fstream>
#include <iostream>
#include <string>



#include "common_util.h"


Json::Value Common_util::getJsonFromFile(const char* path)
{
        Json::Reader reader;
        Json::Value root;
        std::ifstream in(path,std::ios::binary);

        if(!in.is_open())
        {
           std::cout << "Error opening file\n";
           return root;
        }

        reader.parse(in,root);
        in.close();
        return root;
}


Device_ns::Device_type Common_util::get_device_type(const char* device_type_str)
{
    if(strcmp(device_type_str,"ARM")==0)
        return Device_ns::Device_type::ARM;
    if(strcmp(device_type_str,"AGV")==0)
        return Device_ns::Device_type::AGV;
    if(strcmp(device_type_str,"CAMERA")==0)
        return Device_ns::Device_type::CAMERA;
    return Device_ns::Device_type::NA;
}
