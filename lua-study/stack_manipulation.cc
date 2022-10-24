#include <string.h>

extern "C" {
    #include "lua.h"
    #include "lauxlib.h"
    #include "lualib.h"
}

static void stackDump(lua_State *L) {
    int i;    
    int top = lua_gettop(L);
    for (i = 1; i <= top; i++) {
        int t = lua_type(L, i);
        switch (t)
        {
            case /* constant-expression */ LUA_TSTRING:{
                printf("'%s'", lua_tostring(L, i));
                /* code */
                break;
            }
            case LUA_TBOOLEAN: {
                printf(lua_toboolean(L, i) ? "true" : "false");
                break;
            }

            case LUA_TNUMBER: {
                printf("%g", lua_tonumber(L, i));
                break;
            }
            
            default: {
                printf("%s", lua_typename(L, t));
                break;
            }
        }

        printf(" ");
    }
    printf("\n");
}


int main() {
    lua_State *L = luaL_newstate();
    lua_pushboolean(L, 1);
    lua_pushnumber(L, 10);
    lua_pushnil(L);
    lua_pushstring(L, "hello");

    stackDump(L);

    // botoom--> --> top
    lua_pushvalue(L, -4);  // will print: true 10 nil 'hello' true
    stackDump(L);

    lua_replace(L, 3); // move the top element to the index, and then pop the top 
    stackDump(L);

    lua_settop(L, 6);  // stack size is 4, so settop 6 will push nil, nil  to top
    stackDump(L);

    lua_rotate(L, 3, 1); // 从第三个元素开始， 右移一位
    stackDump(L);

    lua_remove(L, -3);
    stackDump(L);

    lua_settop(L, -5); // now stack size is 5, set -5 will clear all elements except the bottom, keep only one 1
    stackDump(L);

    lua_close(L);
    return 0;

}