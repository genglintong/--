FORMS += \
    login.ui \
    users.ui \
    administrators.ui \
    zhuce.ui \
    luxian.ui \
    watch.ui \
    wrong.ui \
    add.ui \
    searcha.ui \
    chenggong.ui

HEADERS += \
    login.h \
    users.h \
    administrators.h \
    zhuce.h \
    luxian.h \
    watch.h \
    zhanghu.h \
    wrong.h \
    graph.h \
    init.h \
    plan.h \
    add.h \
    global.h \
    jmlog.h \
    searcha.h \
    chenggong.h

SOURCES += \
    login.cpp \
    users.cpp \
    administrators.cpp \
    main.cpp \
    zhuce.cpp \
    luxian.cpp \
    watch.cpp \
    zhanghu.cpp \
    wrong.cpp \
    init.cpp \
    add.cpp \
    plan.cpp \
    jmlog.cpp \
    searcha.cpp \
    chenggong.cpp
QT+=widgets
QT += multimedia

RESOURCES += \
    jm.qrc \
    jm.qrc \
    file.qrc \
    voice.qrc

DISTFILES +=
UI_DIR=./UI
RC_FILE +=myico.rc
