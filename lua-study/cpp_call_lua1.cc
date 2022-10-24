#include <iostream>
#include <string.h>

extern "C" {
    #include "lua.h"
    #include "lauxlib.h"
    #include "lualib.h"
}
using namespace std;

int main() {
    // create a state
    lua_State *L = luaL_newstate();    

    // push stack    
    lua_pushstring(L, "I am so cool~");
    lua_pushnumber(L, 20);

    // 取值
    if (lua_isstring(L, 1)) {
        cout << lua_tostring(L, 1) << endl; 
    }

    if (lua_isnumber(L,2)) {
        cout << lua_tonumber(L,2) << endl; 
    }

    // getglobal will get a global value of lua,
    // and push it onto stack
    lua_getglobal(L, "z");
    int z = (int)lua_tointeger(L, -1);
    cout << "z is " << z << endl;

    // setglobal will sets the value of global variable,
    // with param which will be pushed by pushnumber function
    lua_pushnumber(L, 10);
    lua_setglobal(L, "z");

    cout << "top1 is " <<  lua_tonumber(L, -1) << endl;
    cout << "top2 is " <<  lua_tonumber(L, -2) << endl;

    lua_getglobal(L, "z");
    z = (int)lua_tointeger(L, -1);
    cout << "new z is " << z << endl;

    //  close state
    lua_close(L);
    return 0;
}