HEADERS +=	include/GUI/MainWindow.h \
		include/GUI/HelpWindow.h \
		include/GUI/InventoryWindow.h \
		include/GUI/Content.h \
		include/GUI/Gui.h \
		include/Game/Game.h \
		include/Game/Place.h \
		include/Game/Parser.h \
		include/Game/Command.h \
		include/Game/Story/SpawnPlain.h \
		include/Core/Core.h \
		include/Core/Event.h \
		include/Core/ImplementedEvents.h \
		include/Core/Observer.h \
		include/Core/Director.h

SOURCES +=	src/main.cpp \
		src/GUI/MainWindow.cpp \
		src/GUI/HelpWindow.cpp \
		src/GUI/InventoryWindow.cpp \
		src/GUI/Content.cpp \
		src/GUI/Gui.cpp \
		src/Game/Game.cpp \
		src/Game/Place.cpp \
		src/Game/Parser.cpp \
		src/Game/Story/SpawnPlain.cpp \
		src/Core/Core.cpp \
		src/Core/ImplementedEvents.cpp \

INCLUDEPATH += include

CONFIG += qt debug_and_release
TARGET = ImaginationQuest

debug:OBJECTS_DIR	= target/debug/obj
debug:MOC_DIR		= target/debug/moc

release:OBJECTS_DIR	= target/release/obj
release:MOC_DIR		= target/release/moc

CONFIG(debug, debug|release) {
	DESTDIR = target/debug/bin
}
CONFIG(release, debug|release) {
	DESTDIR = target/release/bin
}

QMAKE_CXXFLAGS += -std=c++11
