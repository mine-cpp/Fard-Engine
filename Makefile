fard_files         := $(wildcard src/*.cpp include/*/*.hpp)
# TODO create the foreground folder
foreground_files   := $(wildcard src/*.cpp include/*/*.hpp)

default: fard foreground
fard:         lib/libfard.a
foreground:   lib/libfard_fg.a

lib/libfard.a: lib/libfard.o
	ar rcs lib/libfard.a lib/libfard.o
lib/libfard.o: $(fard_files)
	g++ -c src/*.cpp -o lib/libfard.o -I include

lib/libfard_fg.a: lib/libfard_fg.o
	ar rcs lib/libfard_fg.a lib/libfard_fg.o
lib/libfard_fg.o: $(foreground_files)
	g++ -c src/*.cpp -o lib/libfard_fg.o -I include
