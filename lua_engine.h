#ifndef LUA_ENGINE_H
#define LUA_ENGINE_H

extern "C" {
      #include "lua5.1/lua.h"
      #include "lua5.1/lauxlib.h"
      #include "lua5.1/lualib.h"
}

#include "device/device_manager.h"
#include "LuaBridge/LuaBridge.h"

/**
 * @brief lua引擎
 */
class Lua_engine
{


public:
    lua_State* L;

    Device_ns::Device_manager dm;

    Lua_engine();

    ~Lua_engine();

    /**
     * @brief 初始化
     */
    void init();

    /**
     * @brief 执行Lua
     * @param script
     */
    void exe_lua_str(const char* script);


};

#endif // LUA_ENGINE_H
