TEMPLATE	= app
LANGUAGE	= C++

CONFIG	+= qt warn_on release

LIBS	+= -lpcap

HEADERS	+= sniffer.h \
	sniffThread.h

SOURCES	+= main.cpp \
	sniffer.cpp \
	sniffThread.cpp

FORMS	= uiFilter.ui

unix {
  UI_DIR = .ui
  MOC_DIR = .moc
  OBJECTS_DIR = .obj
}


