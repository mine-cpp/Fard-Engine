event_hpp = include/fard/event.hpp
event_eventtype_hpp = include/fard/event/event_type.hpp
event_keycode_hpp = include/fard/event/key_code.hpp
event_buttoncode_hpp = include/fard/event/button_code.hpp
image_hpp = include/fard/image.hpp
window_hpp = include/fard/window.hpp
utils_typedefs_hpp = include/fard/utils/typedefs.hpp

dir_event = $(event_eventtype_hpp) $(event_keycode_hpp) $(event_buttoncode_hpp)
dir_utils = $(utils_typedefs_hpp)

event = obj/fg/event.o
event_source = src/event.cpp
event_includes = $(event_hpp) $(dir_event) $(utils_typedefs_hpp)
window = obj/fg/window.o
window_source = src/window.cpp
window_includes = $(window_hpp) $(utils_typedefs_hpp) $(image_hpp)

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
