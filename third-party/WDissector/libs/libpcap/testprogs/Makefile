#  Copyright (c) 1993, 1994, 1995, 1996
#	The Regents of the University of California.  All rights reserved.
#
#  Redistribution and use in source and binary forms, with or without
#  modification, are permitted provided that: (1) source code distributions
#  retain the above copyright notice and this paragraph in its entirety, (2)
#  distributions including binary code include the above copyright notice and
#  this paragraph in its entirety in the documentation or other materials
#  provided with the distribution, and (3) all advertising materials mentioning
#  features or use of this software display the following acknowledgement:
#  ``This product includes software developed by the University of California,
#  Lawrence Berkeley Laboratory and its contributors.'' Neither the name of
#  the University nor the names of its contributors may be used to endorse
#  or promote products derived from this software without specific prior
#  written permission.
#  THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED
#  WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF
#  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.

#
# Various configurable paths (remember to edit Makefile.in, not Makefile)
#

# Top level hierarchy
prefix = /usr/local
exec_prefix = ${prefix}
datarootdir = ${prefix}/share
# Pathname of directory to install the configure program
bindir = ${exec_prefix}/bin
# Pathname of directory to install the rpcapd daemon
sbindir = ${exec_prefix}/sbin
# Pathname of directory to install the include files
includedir = ${prefix}/include
# Pathname of directory to install the library
libdir =  ${exec_prefix}/lib
# Pathname of directory to install the man pages
mandir = ${datarootdir}/man

# VPATH
srcdir = .
top_srcdir = ..


#
# You shouldn't need to edit anything below.
#

LD = /usr/bin/ld
CC = gcc
AR = ar
LN_S = ln -s
MKDEP = 
CCOPT =  -fvisibility=hidden
INCLS = -I. -I.. -I. -I./..  -I/usr/include/dbus-1.0 -I/usr/lib/x86_64-linux-gnu/dbus-1.0/include
DEFS = -DHAVE_CONFIG_H 
ADDLOBJS = 
ADDLARCHIVEOBJS = 
LIBS = -libverbs  -ldbus-1 
PTHREAD_LIBS = 
CROSSFLAGS=
CFLAGS = -I/usr/include/libnl3 -g -O2   ${CROSSFLAGS}
LDFLAGS =  ${CROSSFLAGS}
DYEXT = so
V_RPATH_OPT = @V_RPATH_OPT@
DEPENDENCY_CFLAG = 

# Standard CFLAGS for building test programs
FULL_CFLAGS = $(CCOPT) $(INCLS) $(DEFS) $(CFLAGS)

INSTALL = /usr/bin/install -c
INSTALL_PROGRAM = ${INSTALL}
INSTALL_DATA = ${INSTALL} -m 644

# Explicitly define compilation rule since SunOS 4's make doesn't like gcc.
# Also, gcc does not remove the .o before forking 'as', which can be a
# problem if you don't own the file but can write to the directory.
.c.o:
	@rm -f $@
	$(CC) $(FULL_CFLAGS) -c $(srcdir)/$*.c

SRC = valgrindtest.c \
	activatetest.c \
	can_set_rfmon_test.c \
	capturetest.c \
	filtertest.c \
	findalldevstest-perf.c \
	findalldevstest.c \
	opentest.c \
	nonblocktest.c \
	reactivatetest.c \
	selpolltest.c \
	threadsignaltest.c \
	writecaptest.c

TESTS = $(SRC:.c=)

TAGFILES = \
	$(SRC) $(HDR)

CLEANFILES = $(OBJ) $(TESTS)

all: $(TESTS)

# illumos make is the only known supported make that would expand "$<" below
# into "../libpcap.a" instead of "$(srcdir)/xxxxxxxx.c ../libpcap.a".

activatetest: $(srcdir)/activatetest.c ../libpcap.a
	$(CC) $(FULL_CFLAGS) -I. -L. -o $@ $(srcdir)/activatetest.c \
	    ../libpcap.a $(LIBS)

capturetest: $(srcdir)/capturetest.c ../libpcap.a
	$(CC) $(FULL_CFLAGS) -I. -L. -o $@ $(srcdir)/capturetest.c \
	    ../libpcap.a $(LIBS)

can_set_rfmon_test: $(srcdir)/can_set_rfmon_test.c ../libpcap.a
	$(CC) $(FULL_CFLAGS) -I. -L. -o $@ \
	    $(srcdir)/can_set_rfmon_test.c \
	    ../libpcap.a $(LIBS)

filtertest: $(srcdir)/filtertest.c ../libpcap.a
	$(CC) $(FULL_CFLAGS) -I. -L. -o $@ $(srcdir)/filtertest.c \
	    ../libpcap.a $(LIBS)

findalldevstest: $(srcdir)/findalldevstest.c ../libpcap.a
	$(CC) $(FULL_CFLAGS) -I. -L. -o $@ \
	    $(srcdir)/findalldevstest.c \
	    ../libpcap.a $(LIBS)

findalldevstest-perf: $(srcdir)/findalldevstest-perf.c ../libpcap.a
	$(CC) $(FULL_CFLAGS) -I. -L. -o $@ \
	    $(srcdir)/findalldevstest-perf.c \
	    ../libpcap.a $(LIBS)

opentest: $(srcdir)/opentest.c ../libpcap.a
	$(CC) $(FULL_CFLAGS) -I. -L. -o $@ $(srcdir)/opentest.c \
	    ../libpcap.a $(LIBS)

nonblocktest: $(srcdir)/nonblocktest.c ../libpcap.a
	$(CC) $(FULL_CFLAGS) -I. -L. -o $@ $(srcdir)/nonblocktest.c \
	    ../libpcap.a $(LIBS)

reactivatetest: $(srcdir)/reactivatetest.c ../libpcap.a
	$(CC) $(FULL_CFLAGS) -I. -L. -o $@ \
	    $(srcdir)/reactivatetest.c ../libpcap.a $(LIBS)

selpolltest: $(srcdir)/selpolltest.c ../libpcap.a
	$(CC) $(FULL_CFLAGS) -I. -L. -o $@ $(srcdir)/selpolltest.c \
	    ../libpcap.a $(LIBS)

threadsignaltest: $(srcdir)/threadsignaltest.c ../libpcap.a
	$(CC) $(FULL_CFLAGS) -I. -L. -o $@ \
	    $(srcdir)/threadsignaltest.c \
	    ../libpcap.a $(LIBS) $(PTHREAD_LIBS)

valgrindtest: $(srcdir)/valgrindtest.c ../libpcap.a
	$(CC) $(FULL_CFLAGS) -I. -L. -o $@ $(srcdir)/valgrindtest.c \
	    ../libpcap.a $(LIBS)

writecaptest: $(srcdir)/writecaptest.c ../libpcap.a
	$(CC) $(FULL_CFLAGS) -I. -L. -o $@ $(srcdir)/writecaptest.c \
	    ../libpcap.a $(LIBS)

clean:
	rm -f $(CLEANFILES)
	rm -rf *.dSYM

distclean: clean
	rm -f Makefile config.cache config.log config.status \
	    config.h stamp-h stamp-h.in
	rm -rf autom4te.cache

install:

uninstall:

tags: $(TAGFILES)
	ctags -wtd $(TAGFILES)

depend:
	$(MKDEP) -c "$(CC)" -m "$(DEPENDENCY_CFLAG)" -s "$(srcdir)" $(CFLAGS) $(DEFS) $(INCLS) $(SRC)
