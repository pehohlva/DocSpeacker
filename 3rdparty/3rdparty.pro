lessThan(QT_MAJOR_VERSION, 5): error("The QtSpeech library only supports Qt 5.")
CONFIG += warning_clean

TEMPLATE = subdirs
CONFIG += ordered

SUBDIRS = qtpdfium \
          qtspeech
