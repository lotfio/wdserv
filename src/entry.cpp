#include <iostream>
#include <string>
#include <gtkmm.h>
#include "hdr/types.h"
#include "hdr/stylesheet.h"



int main(int argc, char** argv)
{
    app_t       app  = Gtk::Application::create(argc, argv);
    builder_t   bld  = Gtk::Builder::create_from_file("src/uis/mainwindow.ui");

    StyleSheet s;
    s.loadStyle();

    Gtk::Window* win = nullptr;
    bld->get_widget("mainwindow", win);


    return app->run(*win);
}