cmake_minimum_required(VERSION 3.14)
project(veikk_driver_config C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_VERBOSE_MAKEFILE ON)

# add gtk
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

add_definitions(${GTK3_CFLAGS_OTHER})

# bundle in g resources
# not sure about needing .., but it works
add_custom_command(OUTPUT vdcresources.c
                  COMMAND glib-compile-resources ../vdcapp.gresource.xml
                          --target=vdcresources.c --sourcedir=../assets
                          --generate-source
                  DEPENDS vdcapp.gresource.xml assets/vdcui.glade)

add_executable(veikk_driver_config vdcapp.c vdcresources.c vdchandlers.c
        vdcapp.h select_area.c)
target_link_libraries(veikk_driver_config ${GTK3_LIBRARIES})

# necessary for signals to work from template
target_link_options(veikk_driver_config PUBLIC -rdynamic)
