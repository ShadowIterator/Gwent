QT += core
QT -= gui

CONFIG += c++11

TARGET = Gwent_Battle
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    card.cpp \
    global.cpp \
    field.cpp \
    cardset.cpp \
    si_object.cpp \
    user.cpp \
    userinteraction.cpp \
    game.cpp \
    Card/dagon.cpp \
    Card/foglet.cpp \
    weather.cpp \
    Weather/w_torrential_rain.cpp \
    Card/torrential_rain.cpp \
    Weather/w_biting_frost.cpp \
    Weather/w_impenetrable_frog.cpp \
    Card/biting_frost.cpp \
    Card/impenetrable_frog.cpp \
    Card/lacerate.cpp \
    Card/thunderbolt_potion.cpp \
Card/commander_s_horn.cpp \
    Card/bekker_s_twisted_mirror.cpp \
    Card/geralt_igni.cpp \
    Card/roach.cpp \
    Card/ge_els.cpp \
    Card/harpy.cpp \
    Card/harpy_egg.cpp \
    Card/unseen_elder.cpp \
    Card/celaeno_harpy.cpp \
    Card/rabid_wolf.cpp \
    Card/woodland_spirit.cpp \
    Card/lesser_earth_elemental.cpp \
    Card/earth_elemental.cpp \
    Card/crone_brewess.cpp \
    Card/crone_weavess.cpp \
    Card/crone_whispess.cpp \
    Card/archgriffin.cpp \
    Card/wild_hunt_rider.cpp \
    Card/caranthir.cpp \
    Card/frightener.cpp \
    Card/arachas.cpp \
    Card/arachas_hatchling.cpp \
    Card/arachas_behemoth.cpp \
    Card/vran_warrior.cpp \
    Card/clear_skies.cpp \
    Card/rally.cpp \
    Card/first_light.cpp \
    Card/harpy_hatchling.cpp

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
    card.h \
    global.h \
    field.h \
    cardset.h \
    si_object.h \
    user.h \
    userinteraction.h \
    game.h \
    Card/dagon.h \
    Card/foglet.h \
    weather.h \
    Weather/w_torrential_rain.h \
    Card/torrential_rain.h \
    Weather/w_biting_frost.h \
Weather/w_impenetrable_frog.h \
    Card/biting_frost.h \
    Card/impenetrable_frog.h \
    Card/lacerate.h \
    Card/thunderbolt_potion.h \
Card/commander_s_horn.h \
    Card/bekker_s_twisted_mirror.h \
    Card/geralt_igni.h \
    Card/roach.h \
    Card/ge_els.h \
    Card/harpy.h \
    Card/harpy_egg.h \
    Card/unseen_elder.h \
    Card/celaeno_harpy.h \
    Card/rabid_wolf.h \
    Card/woodland_spirit.h \
    Card/lesser_earth_elemental.h \
    Card/earth_elemental.h \
    Card/crone_brewess.h \
    Card/crone_weavess.h \
    Card/crone_whispess.h \
    Card/archgriffin.h \
    Card/wild_hunt_rider.h \
    Card/caranthir.h \
    Card/frightener.h \
    Card/arachas.h \
    Card/arachas_hatchling.h \
    Card/arachas_behemoth.h \
    Card/vran_warrior.h \
    Card/clear_skies.h \
    Card/rally.h \
    Card/first_light.h \
    Card/harpy_hatchling.h
