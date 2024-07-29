QT += widgets

TARGET = waves
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
