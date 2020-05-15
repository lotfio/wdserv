#include <iostream>
#include <string>
#include <gtkmm.h>
#include "hdr/types.h"
#include "hdr/style.h"
#include "hdr/server.h"

int main(int argc, char** argv)
{
    app_t       app  = Gtk::Application::create(argc, argv);
    builder_t   bld  = Gtk::Builder::create_from_file("src/uis/mainwindow.ui");

    Style s;
    s.loadStyle();

    Gtk::Window* win = nullptr;
    bld->get_widget("mainwindow", win);

    Gtk::Button* startBtn;
    Gtk::Button* browsBtn;
    Gtk::Button* editIniBtn;
    bld->get_widget("button1", startBtn);
    bld->get_widget("button2", browsBtn);
    bld->get_widget("button3", editIniBtn);

    Server srv(bld, startBtn);
    startBtn->signal_clicked().connect(sigc::mem_fun(srv, &Server::start));

    return app->run(*win);
}