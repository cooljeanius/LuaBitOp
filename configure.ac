#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([LuaBitOp],[1.0.2],[web-08@luajit.org])
AC_CONFIG_SRCDIR([bit.c])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_AUX_DIR([build-aux])
AC_CANONICAL_TARGET dnl# also calls the "_HOST" version of the macro

# Automake
AM_INIT_AUTOMAKE([foreign])
AM_MAINTAINER_MODE

# Checks for programs.
AM_PROG_AR
AM_PROG_CC_C_O
AC_PROG_CC_C99
AC_PROG_CPP
AC_PROG_CXX
AC_PROG_GCC_TRADITIONAL
AC_PROG_LN_S
AC_PROG_INSTALL
AC_DEFUN([AC_REQUIRE_RANLIB],[
  AC_REQUIRE([AC_PROG_RANLIB])
])
if test "x${RANLIB}" = "x"; then
  test -z "${RANLIB}"
  AC_REQUIRE_RANLIB
else
  test ! -z "${RANLIB}" && export RANLIB
  AC_SUBST([RANLIB])
fi
AC_PATH_PROGS([LUA],[lua lua5.1 luajit])
LT_INIT([win32-dll dlopen])
CMAKE_FIND_BINARY

# Checks for libraries.
PKG_CHECK_MODULES([LUA],
                  [lua >= 5.1],
                  [HAVE_LUA=yes
                   CFLAGS="${CFLAGS} ${LUA_CFLAGS}"
                   CPPFLAGS="${CPPFLAGS} ${LUA_CFLAGS}"
                   LIBS="${LIBS} ${LUA_LIBS}"],
                  [HAVE_LUA=no])
AC_SUBST([LUA_CFLAGS])
AC_SUBST([LUA_LIBS])
AC_CHECK_LIB([lua],[luaL_error])

# Checks for header files.
AC_CHECK_HEADERS([lua.h luaconf.h lauxlib.h stdio.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_INT32_T
AC_TYPE_SIZE_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T
AC_CHECK_TYPE([lua_State])

# Checks for library functions.
AC_CHECK_FUNCS([luaL_error lua_pushlstring lua_pushnumber \
                luaL_checknumber lua_gettop luaL_setfuncs lua_createtable \
                lua_type])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
