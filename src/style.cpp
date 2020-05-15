#include <gtkmm.h>
#include <iostream>
#include "hdr/style.h"
#include "hdr/types.h"

void Style::loadStyle()
{
    try
    {
        css_t css = Gtk::CssProvider::create();
        css->load_from_path("src/uis/css/style.css");

        Gtk::StyleContext::add_provider_for_screen(
            Gdk::Screen::get_default(), css,
            GTK_STYLE_PROVIDER_PRIORITY_APPLICATION
        );
    }
    catch(const Gtk::CssProviderError error)
    {
        std::cerr << "Failed to load style:" << error.code() << std::endl;
    }
}