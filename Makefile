event_hpp = include/fard/event.hpp
image_hpp = include/fard/image.hpp
window_hpp = include/fard/window.hpp
utils_types_hpp = include/fard/utils/types.hpp

event = obj/fg/event.o
event_source = src/event.cpp
event_includes = $(event_hpp) $(utils_types_hpp)
window = obj/fg/window.o
window_source = src/window.cpp
window_includes = $(window_hpp) $(utils_types_hpp) $(image_hpp)

fard = lib/libfard.a
foreground = lib/libfard_fg.a



default: $(fard)
$(fard): $(foreground)
	ar rcs lib/libfard.a obj/*/*.o
$(foreground): $(event) $(window)
	ar rcs lib/libfard_fg.a obj/fg/*.o

$(window): $(window_source) $(window_includes)
	g++ -c src/window.cpp -o obj/fg/window.o -I include -Wall
$(window_source):
$(window_includes):

$(event): $(event_source) $(event_includes)
	g++ -c src/event.cpp -o obj/fg/event.o -I include -Wall
$(event_source):
$(event_includes):
