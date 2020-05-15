#include <gtkmm.h>
#include "hdr/types.h"
#include "hdr/server.h"

Server::Server(builder_t bld, Gtk::Button* btn) : _bld(bld), _btn(btn)
{
}

void Server::start()
{
    Gtk::TextView* textView = nullptr;
    this->_bld->get_widget("textview1", textView);

    textView->get_buffer()->set_text("starting server .....");
}

void Server::stop()
{
    
}

Server::~Server()
{
    delete this->_btn;
}