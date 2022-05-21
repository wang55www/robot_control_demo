#include "lua_engine.h"

#include "device/device_manager.h"
#include "device/device_agv.h"
#include "device/device_arm.h"
#include "device/device_camera.h"

Lua_engine::Lua_engine()
{
   this->L=luaL_newstate();
   this->dm.build();
}

Lua_engine::~Lua_engine()
{

}

extern Lua_engine inst;

int agv_GetGlobalVariable(int device_id,std::string paramName)
{

   Device_ns::Device* device=inst.dm.get_device(device_id);
   if(Device_ns::Device_type::AGV!=device->get_device_type()){
       //必须是AGV
       return -1;
   }
   Device_ns::Device_agv* d_ptr=dynamic_cast<Device_ns::Device_agv*>(device);
   return d_ptr->GetGlobalVariable(paramName);

}


void Lua_engine::init()
{
    luaL_openlibs(this->L);
    luabridge::Namespace luans=luabridge::getGlobalNamespace(L);
    std::vector<Device_ns::Device*> devices=dm.get_devices();
    for(unsigned int i=0;i<devices.size();i++)
    {
        Device_ns::Device* device=devices[i];
//        std::printf("device_type:%d\n",device->get_device_type());
        if(Device_ns::Device_type::AGV==device->get_device_type()){
            luans.addFunction("agv_GetGlobalVariable",agv_GetGlobalVariable);
//            std::printf("Device_agv.device_type:%d\n",d_ptr->get_device_type());
//            luabridge::setGlobal(L,d_ptr,"b");
//            void (Device_ns::Device_agv::* fp)() = &Device_ns::Device_agv::test;
//            luans.addFunction("test",fp);
//            luans.addFunction("test",test);
//            luabridge::setGlobal(L,d_ptr,"device_agv");
        }else if(Device_ns::Device_type::ARM==device->get_device_type()){
//            luabridge::setGlobal(L,dynamic_cast<Device_ns::Device_arm*>(device),("device_arm"+std::to_string(i)).c_str());
        }else if(Device_ns::Device_type::CAMERA==device->get_device_type()){
//            luabridge::setGlobal(L,dynamic_cast<Device_ns::Device_camera*>(device),("Device_camera"+std::to_string(i)).c_str());
        }
    }

}


void Lua_engine::exe_lua_str(const char *script)
{
  std::cout << luaL_dostring(L,script) <<std::endl;
}
