#include <stdio.h>
#include <string.h>

extern "C" {

#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

int main() {
    char buff[256];
    int error;
    lua_State *L = luaL_newstate(); // open lua
    luaL_openlibs(L); // open the standard lib

    while(fgets(buff, sizeof(buff), stdin) != NULL ) {
        error = luaL_loadstring(L, buff) || lua_pcall(L, 0, 0, 0);
        if (error) {
            fprintf(stderr, "%s\n", lua_tostring(L, -1)); // 
            lua_pop(L, 1);
        }
    }

    lua_close(L);
    return 0;
}