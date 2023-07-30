# Makefile for Lua BitOp -- a bit operations library for Lua 5.1/5.2.
## This version has been automake-ized
# To compile with MSVC please run: msvcbuild.bat
# To compile with MinGW please run: mingw32-make -f Makefile.mingw

ACLOCAL_AMFLAGS = -I m4 --install

# Include path where lua.h, luaconf.h and lauxlib.h reside:
AM_CPPFLAGS=-I/usr/local/include -I. -I$(top_srcdir)

DEFINES= @DEFS@

# Use this for the old ARM ABI with swapped FPA doubles.
# Do NOT use this for modern ARM EABI with VFP or soft-float!
ARM_DEFINES= -DSWAPPED_DOUBLE

# Lua executable name. Used to find the install path and for testing.
LUA=@LUA@

CC= @CC@
CCOPT= -O2 -fomit-frame-pointer
CCWARN= -Wall -Wimplicit -Wextra
SOCC= $(CC) -shared
SOCFLAGS= -fPIC $(CCOPT) $(CCWARN) $(DEFINES) $(AM_CPPFLAGS) $(INCLUDES) $(CFLAGS)
SOLDFLAGS= -fPIC $(LDFLAGS) $(LIBS)
RM= rm -f
INSTALL=@INSTALL@ 
INSTALLPATH= $(LUA) installpath.lua

MODNAME= bit
MODSO= $(MODNAME).so

## cannot use the MODNAME makefile variable here because that messes stuff
## up:
pkglib_LTLIBRARIES = bit.la

bit_la_SOURCES = bit.c bit.h

pkginclude_HEADERS = bit.h

noinst_HEADERS = config.h

bit_la_CFLAGS = -fPIC $(CCWARN)
bit_la_LDFLAGS = -module

EXTRA_DIST = doc

## Tests:
check_SCRIPTS = bittest.lua nsievebits.lua md5test.lua

EXTRA_DIST += bittest_orig.lua nsievebits_orig.lua md5test_orig.lua

DISTCLEANFILES = *~ .DS_Store $(check_SCRIPTS) autoscan.log

MAINTAINERCLEANFILES = configure.scan

## CMake junk:
DISTCLEANFILES += CPackConfig.cmake CPackSourceConfig.cmake \
		  CTestTestfile.cmake DartConfiguration.tcl \
		  cmake_install.cmake CMakeCache.txt

## CMake stuff that is actually necessary:
EXTRA_DIST += cmake CMakeLists.txt bit.def

## Stuff needed for Windows:
EXTRA_DIST += msvcbuild.bat msvctest.bat Makefile.mingw

## For LuaDist:
EXTRA_DIST += dist.info

all: $(MODSO)

# Alternative target for compiling on Mac OS X:
macosx:
	$(MAKE) all "SOCC=MACOSX_DEPLOYMENT_TARGET=10.4 $(CC) -dynamiclib -single_module -undefined dynamic_lookup"

$(MODNAME).o: $(MODNAME).c $(MODNAME).h $(top_srcdir)/config.h
	$(CC) $(SOCFLAGS) -c -o $@ $<

$(MODSO): $(MODNAME).o
	$(SOCC) $(SOLDFLAGS) -o $@ $<

luainstall: $(MODSO) installpath.lua
	$(INSTALL) $< `$(INSTALLPATH) $(MODNAME)`

install-exec-hook:
	$(LIBTOOL) --finish $(pkglibdir)

## Leaving installation of documentation out for now, as that would require
## an uninstall-hook to get rid of it, but for some reason adding an
## uninstall-hook makes the installation in the first place fail...

test: $(MODSO) $(check_SCRIPTS)
	@$(LUA) bittest.lua && echo "basic test OK"
	@$(LUA) nsievebits.lua && echo "nsievebits test OK"
	@$(LUA) md5test.lua && echo "MD5 test OK"

# have to copy these from backup copies, in case cmake overwrites the
# original copies:
bittest.lua: bittest_orig.lua
	cp -f $< $@

nsievebits.lua: nsievebits_orig.lua
	cp -f $< $@

md5test.lua: md5test_orig.lua
	cp -f $< $@

check-local: test

clean-local:
	$(RM) *.o *.so *.obj *.lib *.exp *.dll *.manifest

distclean-local:
	$(RM) -r autom4te.cache || rmdir autom4te.cache
	$(RM) -r CMakeFiles || rmdir CMakeFiles

configure.scan:
	autoscan || touch configure.scan

.PHONY: all macosx luainstall test check-local clean-local distclean-local

