#############################################################################
# Makefile for building: test1
# Generated by qmake (1.07a) (Qt 3.3.8b) on: Mon Mar 30 21:37:41 2009
# Project:  test1.pro
# Template: app
# Command: $(QMAKE) -o Makefile test1.pro
#############################################################################

####### Compiler, tools and options

CC       = gcc
CXX      = g++
LEX      = flex
YACC     = yacc
CFLAGS   = -pipe -g -Wall -W -O2 -D_REENTRANT  -DQT_NO_DEBUG -DQT_THREAD_SUPPORT -DQT_SHARED -DQT_TABLET_SUPPORT
CXXFLAGS = -pipe -g -Wall -W -O2 -D_REENTRANT  -DQT_NO_DEBUG -DQT_THREAD_SUPPORT -DQT_SHARED -DQT_TABLET_SUPPORT
LEXFLAGS = 
YACCFLAGS= -d
INCPATH  = -I/usr/share/qt3/mkspecs/default -I. -I/usr/include/qt3 -I.ui/ -I. -I.moc/
LINK     = g++
LFLAGS   = 
LIBS     = $(SUBLIBS) -L/usr/share/qt3/lib -L/usr/X11R6/lib -lpcap -lqt-mt -lXext -lX11 -lm -lpthread
AR       = ar cqs
RANLIB   = 
MOC      = /usr/share/qt3/bin/moc
UIC      = /usr/share/qt3/bin/uic
QMAKE    = qmake
TAR      = tar -cf
GZIP     = gzip -9f
COPY     = cp -f
COPY_FILE= $(COPY)
COPY_DIR = $(COPY) -r
INSTALL_FILE= $(COPY_FILE)
INSTALL_DIR = $(COPY_DIR)
DEL_FILE = rm -f
SYMLINK  = ln -sf
DEL_DIR  = rmdir
MOVE     = mv -f
CHK_DIR_EXISTS= test -d
MKDIR    = mkdir -p

####### Output directory

OBJECTS_DIR = .obj/

####### Files

HEADERS = sniffer.h \
		sniffThread.h
SOURCES = main.cpp \
		sniffer.cpp \
		sniffThread.cpp
OBJECTS = .obj/main.o \
		.obj/sniffer.o \
		.obj/sniffThread.o \
		.obj/uiFilter.o
FORMS = uiFilter.ui
UICDECLS = .ui/uiFilter.h
UICIMPLS = .ui/uiFilter.cpp
SRCMOC   = .moc/moc_uiFilter.cpp
OBJMOC = .obj/moc_uiFilter.o
DIST	   = test1.pro
QMAKE_TARGET = test1
DESTDIR  = 
TARGET   = test1

first: all
####### Implicit rules

.SUFFIXES: .c .o .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o $@ $<

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(UICDECLS) $(OBJECTS) $(OBJMOC)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJMOC) $(OBJCOMP) $(LIBS)

mocables: $(SRCMOC)
uicables: $(UICDECLS) $(UICIMPLS)

$(MOC): 
	( cd $(QTDIR)/src/moc && $(MAKE) )

Makefile: test1.pro  /usr/share/qt3/mkspecs/default/qmake.conf /usr/share/qt3/lib/libqt-mt.prl
	$(QMAKE) -o Makefile test1.pro
qmake: 
	@$(QMAKE) -o Makefile test1.pro

dist: 
	@mkdir -p .obj/test1 && $(COPY_FILE) --parents $(SOURCES) $(HEADERS) $(FORMS) $(DIST) .obj/test1/ && $(COPY_FILE) --parents uiFilter.ui.h .obj/test1/ && ( cd `dirname .obj/test1` && $(TAR) test1.tar test1 && $(GZIP) test1.tar ) && $(MOVE) `dirname .obj/test1`/test1.tar.gz . && $(DEL_FILE) -r .obj/test1

mocclean:
	-$(DEL_FILE) $(OBJMOC)
	-$(DEL_FILE) $(SRCMOC)

uiclean:
	-$(DEL_FILE) $(UICIMPLS) $(UICDECLS)

yaccclean:
lexclean:
clean: mocclean uiclean
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) $(TARGET)


FORCE:

####### Compile

.obj/main.o: main.cpp .ui/uiFilter.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/main.o main.cpp

.obj/sniffer.o: sniffer.cpp sniffer.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/sniffer.o sniffer.cpp

.obj/sniffThread.o: sniffThread.cpp sniffThread.h \
		sniffer.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/sniffThread.o sniffThread.cpp

.ui/uiFilter.h: uiFilter.ui 
	$(UIC) uiFilter.ui -o .ui/uiFilter.h

.ui/uiFilter.cpp: .ui/uiFilter.h uiFilter.ui uiFilter.ui.h 
	$(UIC) uiFilter.ui -i uiFilter.h -o .ui/uiFilter.cpp

.obj/uiFilter.o: .ui/uiFilter.cpp uiFilter.ui.h \
		.ui/uiFilter.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/uiFilter.o .ui/uiFilter.cpp

.obj/moc_uiFilter.o: .moc/moc_uiFilter.cpp  .ui/uiFilter.h 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/moc_uiFilter.o .moc/moc_uiFilter.cpp

.moc/moc_uiFilter.cpp: $(MOC) .ui/uiFilter.h
	$(MOC) .ui/uiFilter.h -o .moc/moc_uiFilter.cpp

####### Install

install:  

uninstall:  

