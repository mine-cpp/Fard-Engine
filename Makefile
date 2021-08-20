fard_files := $(wildcard src/*.cpp include/*/*.hpp)
# TODO create the foreground folder
foreground_files := $(wildcard src/*.cpp include/*/*.hpp)

default: fard foreground clean

fard: lib/libfard.a
foreground: lib/libfard_fg.a

lib/libfard.a: lib/fard.o
	ar rcs lib/libfard.a lib/fard.o
lib/fard.o: $(fard_files)
	g++ -c src/*.cpp -o lib/fard.o -I include

lib/libfard_fg.a: lib/fard_fg.o
	ar rcs lib/libfard_fg.a lib/libfard_fg.o
lib/fard_fg.o: $(foreground_files)
	g++ -c src/*.cpp -o lib/fard_fg.o -I include

clean:
	rm -f lib/*.o
