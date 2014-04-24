/* bit.h: header file for bit.c */

#ifndef __LUA_BITOP_BIT_H__
#define __LUA_BITOP_BIT_H__ 1

/* same includes that the ".c" version uses; not sure why they are quotes
 * instead of angle brackets... */
#include "lua.h"
#include "lauxlib.h"

LUALIB_API int luaopen_bit(lua_State *L);

#endif /* __LUA_BITOP_BIT_H__ */

/* EOF */
