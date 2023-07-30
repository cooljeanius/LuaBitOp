dnl#                                               -*- Autoconf -*-
dnl# Process this file with autoconf to produce a configure script.

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
AC_PROG_MKDIR_P
AC_PROG_INSTALL
AM_PROG_INSTALL_STRIP
AC_DEFUN([AC_REQUIRE_RANLIB],[
  AC_REQUIRE([AC_PROG_RANLIB])dnl
])dnl
  ## https://savannah.gnu.org/support/?108503
if test "x${RANLIB}" = "x"; then
  test -z "${RANLIB}"
  AC_REQUIRE_RANLIB
else
  test ! -z "${RANLIB}" && export RANLIB
  AC_SUBST([RANLIB])
fi
AC_PATH_PROGS([LUA],[lua lua5.1 lua5.2 lua5.3 lua5.4 luajit])
LT_INIT([win32-dll dlopen])
CMAKE_FIND_BINARY

# Checks for libraries.
PKG_CHECK_MODULES([LUA],
                  [lua >= 5.1],
                  [HAVE_LUA=yes
                   CFLAGS="${CFLAGS} ${LUA_CFLAGS}"
                   CPPFLAGS="${CPPFLAGS} ${LUA_CFLAGS}"
                   LIBS="${LIBS} ${LUA_LIBS}"
                   AC_SUBST([LUA_CFLAGS])dnl
                   AC_SUBST([LUA_LIBS])],[
  # If the previous check failed, see if the pkg name includes the version:
  PKG_CHECK_MODULES([LUA51],
                    [lua5.1 >= 5.1],
                    [HAVE_LUA=yes
                     CFLAGS="${CFLAGS} ${LUA51_CFLAGS}"
                     CPPFLAGS="${CPPFLAGS} ${LUA51_CFLAGS}"
                     LIBS="${LIBS} ${LUA51_LIBS}"
                     AC_SUBST([LUA51_CFLAGS])dnl
                     AC_SUBST([LUA51_LIBS])dnl
  ])dnl
])dnl
  ## Check like this too:
AC_CHECK_LIB([lua],[luaL_error],[],[
  AC_SEARCH_LIBS([luaL_error],[lua lua5.1 lua5.2 lua5.3 lua5.4 luajit])dnl
])dnl

# Checks for header files.
AC_CHECK_HEADERS([lua.h luaconf.h lauxlib.h])
if test "x${ac_cv_header_lua_h}" = "xno"; then
  test ! -z "${ac_cv_header_lua_h}"
  AC_MSG_ERROR([lua.h is required, but it was not found])
fi
if test "x${ac_cv_header_stdio_h}" = "x"; then
  test -z "${ac_cv_header_stdio_h}"
  AC_CHECK_HEADERS([stdio.h])
fi
if test "x${ac_cv_header_stdint_h}" = "x"; then
  test -z "${ac_cv_header_stdint_h}"
  AC_CHECK_HEADERS([stdint.h])
fi

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_INT32_T
AC_TYPE_SIZE_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T
AC_CHECK_TYPE([lua_State])dnl

# Checks for library functions.
AC_CHECK_FUNCS([luaL_error lua_pushlstring lua_pushnumber \
                luaL_checknumber lua_gettop luaL_setfuncs lua_createtable \
                lua_type])dnl

# Output.
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
