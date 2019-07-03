cmake_minimum_required(VERSION 3.14)
project(veikk_driver_config C)

set(CMAKE_C_STANDARD 99)

# add gtk
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

add_definitions(${GTK3_CFLAGS_OTHER})

# bundle in g resources
# not sure about needing .., but it works
add_custom_command(OUTPUT resources.c
                  COMMAND glib-compile-resources ../vdcapp.gresource.xml
                          --target=resources.c --sourcedir=.. --generate-source
                  DEPENDS vdcapp.gresource.xml window.ui)

add_executable(veikk_driver_config main.c vdcapp.c vdcapp.h vdcappwin.c vdcappwin.h resources.c)

target_link_libraries(veikk_driver_config ${GTK3_LIBRARIES})
