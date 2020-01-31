#-------------------------------------------------
#
# Project created by QtCreator 2019-05-09T13:00:36
#
#-------------------------------------------------
TEMPLATE = app
TARGET = polypimpl
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt


# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++14

SOURCES += \
        main.cpp \
        Base.cpp \
        Derived.cpp \
        Composition.cpp

HEADERS += \
        Base.h \
        Base_p.h \
        Derived.h \
        Derived_p.h \
        Composition.h \
        poly_pimpl.h \
        cath.hpp

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
