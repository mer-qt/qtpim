TEMPLATE = subdirs

!contains(QT_CONFIG, no-widgets):
SUBDIRS += \
    calendardemo \
    todo
