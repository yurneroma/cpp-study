#include <stdio.h>

extern "C" {
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}

// lua interpreter
lua_State* L;

//doc
// lua 调用cpp 提供的函数
// 1. 函数原型  typedef int (*pointer)(lua_State* L)
// 2.定义这种函数， 然后通过 lua_State 传递参数 
//  在函数中计算逻辑， 然后把结果通过 lua_pushxxx() 压入stack 
// 3. lua_register(L, "func_name", func) 注册函数, 方便lua 调用
//  



// cpp read lua stack to sum
// lua 中想调用cpp的函数，  这个函数必须要通过lua_State 虚拟机来交互
// 所有的数据交互都必须塞入到 lua stack 中, 
static int average(lua_State *L) {
    int n = lua_gettop(L); 
    double sum = 0;
    int i;

    // 从lua中read 参数
    for (i = 1; i <= n; i++) {
        sum += lua_tonumber(L, i);
    }

    // cpp 中做计算， 结果塞回lua stack 
    lua_pushnumber(L, sum/n);
    lua_pushnumber(L, sum);

    return 2;
}


int main(){
    // init lua
    L = luaL_newstate();

    // load lua base libraries
    luaL_openlibs(L);

    //register our func
    lua_register(L, "average", average);

    // run the script 
    luaL_dofile(L, "avg.lua");
   
    // cleanup lua
    lua_close(L);

    //
    printf(" Press enter to exit...");
    getchar();

    return 0;
}
