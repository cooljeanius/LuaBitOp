#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([LuaBitOp], [1.0.2], [web-08@luajit.org])
AC_CONFIG_SRCDIR([bit.c])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([foreign])
AM_MAINTAINER_MODE
AC_CANONICAL_HOST

# Checks for programs.
AM_PROG_AR
AC_PROG_CC
AM_PROG_CC_C_O
AC_PROG_GCC_TRADITIONAL
AC_PROG_INSTALL
AC_PATH_PROG([LUA], [lua])
AC_PROG_LIBTOOL

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stdio.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_INT32_T
AC_TYPE_SIZE_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T

# Checks for library functions.

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
