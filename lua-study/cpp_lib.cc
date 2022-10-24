#include <iostream>
using namespace std;

extern "C" {
#include "lauxlib.h"
#include "lua.h"
#include "lualib.h"
}

int average(lua_State* L) {
  int num = lua_gettop(L);
  double sum;

  for (int i = 1; i <= num; i++) {
    sum += lua_tonumber(L, i);
  }

  double avg = sum / num;
  lua_pushnumber(L, avg);
  lua_pushnumber(L, sum);

  return 2;
}

int sub(lua_State* L) {
  int num = lua_gettop(L);
  if (num != 2) {
    cout << "Input param number is not correct" << endl;
    return 0;
  }

  int a = lua_tonumber(L, 1);
  int b = lua_tonumber(L, 2);

  lua_pushnumber(L, a - b);
  return 1;
}

int add(lua_State* L) {
  int num = lua_gettop(L);
  if (num != 2) {
    cout << "Input param number is not correct" << endl;
    return 0;
  }

  int a = lua_tonumber(L, 1);
  int b = lua_tonumber(L, 2);

  lua_pushnumber(L, a + b);
  return 1;
}

static luaL_Reg math_functions[] = {
    {"average", average},
    {"add", add},
    {"sub", sub},
    {"NULL", NULL}  // 数组中最后一对必须是这个， 表示结束
};

extern "C" {
//  luaopen_mathlib,  mathlib.so为库名称
// 注意， 定义 luaopen_xxx 的时候， 必须使用C语言的方式来定义，
// 不然会找不到symbol错误
int luaopen_mathlib(lua_State* L) {
  luaL_newlib(L,
              math_functions);  // lua5.2 用luaL_newlib 代替了 luaL_register
  return 1;
}
}