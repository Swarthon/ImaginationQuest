HEADERS += include/*
SOURCES += src/*

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
