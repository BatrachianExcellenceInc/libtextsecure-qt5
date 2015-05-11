TEMPLATE = lib

TARGET = textsecureqt5
VERSION = 0.0.1

QT       += core network
QT       -= gui

CONFIG   += console debug
CONFIG   += dll
CONFIG   -= app_bundle

HEADERS += src/ts_exception.h \
           src/file_pre_key_store.h \
           src/file_client_conf.h \
           src/ts_keyhelper.h \
           src/api_client.h

SOURCES += src/ts_exception.cpp \
           src/file_pre_key_store.cpp \
           src/file_client_conf.cpp \
           src/ts_keyhelper.cpp \
           src/api_client.cpp

INCLUDEPATH += ../libaxolotl-qt5/

LIBS += -L../libaxolotl-qt5/ -L../libcurve25519/ -laxolotl -lcurve25519

QMAKE_CXXFLAGS += -Wall -Wextra -Werror -pedantic -std=c++11 -O2 -g -ggdb3 -fno-inline

