#ifndef SERVER_H
#define SERVER_H

#include <gtkmm.h>
#include "types.h"

class Server
{
    private:
        builder_t     _bld;
        Gtk::Button*  _btn;

    public:
                 Server(builder_t bld, Gtk::Button* btn);
        virtual ~Server();

        void start();

        void stop();

        std::string execute(const char* cmd);
};

#endif