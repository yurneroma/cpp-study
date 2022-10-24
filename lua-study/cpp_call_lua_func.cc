#include <stdio.h>

extern "C" {
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}




// doc
// cpp 调用lua提供的add 函数
// 1.dofile() 加载lua， 
// 2. 获取函数地址 push onto stack  lua_getglobal(L, "func_name") 
// 3. 传递参数 lua_pushnumber()
// 4. call function.  lua_call()
// 5. print result 


// the lua interpreter
lua_State* L;

// cpp call lua function
int luaadd(int x, int y) {
    int sum;

    // 把想调用的函数名压入stack
    lua_getglobal(L, "add");  

    // push paragram x, y
    lua_pushnumber(L, x);
    lua_pushnumber(L, y);

    // call function, with 2 params, and 1 return value   
    lua_call(L, 2, 1);

    // get the return value
    sum = (int)lua_tointeger(L, -1);

    lua_pop(L,1);

    return sum;
}

int main() {
    int sum;

    // init lua interpreter
    L = luaL_newstate(); 
    //luaL_openlibs(L);

    // load the script
    // 先把lua 文件加载进来， 然后才能使用Lua_getglobal(L, functionname) 去调用lua
    luaL_dofile(L, "add.lua");

    // call the add function
    sum = luaadd(10, 5);     
    printf("the sum is: %d\n", sum);

    // cleanup lua 
    lua_close(L);

    // pause 
    printf("Press enter to exit...");
    getchar();

    return 0;
}



