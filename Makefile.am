# Makefile for Lua BitOp -- a bit operations library for Lua 5.1/5.2.
# To compile with MSVC please run: msvcbuild.bat
# To compile with MinGW please run: mingw32-make -f Makefile.mingw

ACLOCAL_AMFLAGS = -I m4

# Include path where lua.h, luaconf.h and lauxlib.h reside:
AM_CPPFLAGS=-I/usr/local/include

DEFINES=

# Lua executable name. Used to find the install path and for testing.
LUA=@LUA@

CC= @CC@
CCOPT= -O2 -fomit-frame-pointer
CCWARN= -Wall
SOCC= $(CC) -shared
SOCFLAGS= -fPIC $(CCOPT) $(CCWARN) $(DEFINES) $(INCLUDES) $(CFLAGS)
SOLDFLAGS= -fPIC $(LDFLAGS)
RM= rm -f
INSTALL=@INSTALL@ 
INSTALLPATH= $(LUA) installpath.lua

MODNAME= bit
MODSO= $(MODNAME).so

all: $(MODSO)

# Alternative target for compiling on Mac OS X:
macosx:
	$(MAKE) all "SOCC=MACOSX_DEPLOYMENT_TARGET=10.4 $(CC) -dynamiclib -single_module -undefined dynamic_lookup"

$(MODNAME).o: $(MODNAME).c
	$(CC) $(SOCFLAGS) -c -o $@ $<

$(MODSO): $(MODNAME).o
	$(SOCC) $(SOLDFLAGS) -o $@ $<

install: $(MODSO)
	$(INSTALL) $< `$(INSTALLPATH) $(MODNAME)`

test: $(MODSO)
	@$(LUA) bittest.lua && echo "basic test OK"
	@$(LUA) nsievebits.lua && echo "nsievebits test OK"
	@$(LUA) md5test.lua && echo "MD5 test OK"

clean:
	$(RM) *.o *.so *.obj *.lib *.exp *.dll *.manifest

.PHONY: all macosx install test clean

