QT += core gui widgets \
    multimedia

TARGET = sea++
TEMPLATE = app

SOURCES += \
    main.cpp \
	LanguageTerms.cpp \
    dialog.cpp  # Updated from mainwindow.cpp to dialog.cpp

HEADERS += \
    dialog.h \
	LanguageTerms.h

FORMS += \
    try.ui

RESOURCES += \
    res.qrc

