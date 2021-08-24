image_hpp = include/fard/image.hpp
window_hpp = include/fard/window.hpp
utils_types_hpp = include/fard/utils/types.hpp

window = obj/fg/window.o
window_source = src/window.cpp
window_includes = $(window_hpp) $(utils_types_hpp) $(image_hpp)

fard = lib/libfard.a
foreground = lib/libfard_fg.a



default: $(fard)
$(fard): $(foreground)
	ar rcs lib/libfard.a obj/*/*.o
$(foreground): $(window)
	ar rcs lib/libfard_fg.a obj/fg/*.o

$(window): $(window_source)
	g++ -c src/window.cpp -o obj/fg/window.o -I include -Wall
$(window_source): $(window_includes)
$(window_includes):
