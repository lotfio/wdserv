#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>

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


    textView->get_buffer()->set_text(Server::execute("libs\\php\\php.exe -S 127.0.0.1:8080 -t libs\\www"));
}

void Server::stop()
{
    
}

std::string Server::execute(const char* command)
{
    char tmpname [L_tmpnam];
    std::tmpnam ( tmpname );
    std::string scommand = command;
    std::string cmd = scommand + " >> " + tmpname;
    std::system(cmd.c_str());
    std::ifstream file(tmpname, std::ios::in | std::ios::binary );
    std::string result;
    if (file) {
        while (!file.eof()) result.push_back(file.get())
            ;
        file.close();
    }
    remove(tmpname);
    return result;
}

Server::~Server()
{
    delete this->_btn;
}