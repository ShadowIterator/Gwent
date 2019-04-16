QT += core
QT -= gui

CONFIG += c++11

TARGET = Gwent_Console
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Card/arachas.cpp \
    Card/arachas_behemoth.cpp \
    Card/arachas_hatchling.cpp \
    Card/archgriffin.cpp \
    Card/bekker_s_twisted_mirror.cpp \
    Card/biting_frost.cpp \
    Card/caranthir.cpp \
    Card/celaeno_harpy.cpp \
    Card/clear_skies.cpp \
    Card/commander_s_horn.cpp \
    Card/crone_brewess.cpp \
    Card/crone_weavess.cpp \
    Card/crone_whispess.cpp \
    Card/dagon.cpp \
    Card/earth_elemental.cpp \
    Card/first_light.cpp \
    Card/foglet.cpp \
    Card/frightener.cpp \
    Card/ge_els.cpp \
    Card/geralt_igni.cpp \
    Card/harpy.cpp \
    Card/harpy_egg.cpp \
    Card/harpy_hatchling.cpp \
    Card/impenetrable_frog.cpp \
    Card/lacerate.cpp \
    Card/lesser_earth_elemental.cpp \
    Card/rabid_wolf.cpp \
    Card/rally.cpp \
    Card/roach.cpp \
    Card/thunderbolt_potion.cpp \
    Card/torrential_rain.cpp \
    Card/unseen_elder.cpp \
    Card/vran_warrior.cpp \
    Card/wild_hunt_rider.cpp \
    Card/woodland_spirit.cpp \
    Weather/w_biting_frost.cpp \
    Weather/w_impenetrable_frog.cpp \
    Weather/w_torrential_rain.cpp \
    card.cpp \
    cardset.cpp \
    game.cpp \
    global.cpp \
    si_object.cpp \
    user.cpp \
    userinteraction.cpp \
    weather.cpp \
    field.cpp

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    Card/arachas.h \
    Card/arachas_behemoth.h \
    Card/arachas_hatchling.h \
    Card/archgriffin.h \
    Card/bekker_s_twisted_mirror.h \
    Card/biting_frost.h \
    Card/caranthir.h \
    Card/celaeno_harpy.h \
    Card/clear_skies.h \
    Card/commander_s_horn.h \
    Card/crone_brewess.h \
    Card/crone_weavess.h \
    Card/crone_whispess.h \
    Card/dagon.h \
    Card/earth_elemental.h \
    Card/first_light.h \
    Card/foglet.h \
    Card/frightener.h \
    Card/ge_els.h \
    Card/geralt_igni.h \
    Card/harpy.h \
    Card/harpy_egg.h \
    Card/harpy_hatchling.h \
    Card/impenetrable_frog.h \
    Card/lacerate.h \
    Card/lesser_earth_elemental.h \
    Card/rabid_wolf.h \
    Card/rally.h \
    Card/roach.h \
    Card/thunderbolt_potion.h \
    Card/torrential_rain.h \
    Card/unseen_elder.h \
    Card/vran_warrior.h \
    Card/wild_hunt_rider.h \
    Card/woodland_spirit.h \
    Weather/w_biting_frost.h \
    Weather/w_impenetrable_frog.h \
    Weather/w_torrential_rain.h \
    card.h \
    cardset.h \
    game.h \
    global.h \
    si_object.h \
    user.h \
    userinteraction.h \
    weather.h \
    field.h

RESOURCES += \
    rc.qrc
