//
// Created by cvrain on 24-6-8.
//

#include "catppuccin_provider.hpp"

namespace Theme {
    CatppuccinProvider::CatppuccinProvider(QObject *parent)
    : QObject(parent), instance(&CatppuccinFactory::get_instance()) {

    }

    QString CatppuccinProvider::rosewater() {
        return instance->get_theme()->rosewater;
    }

    QString CatppuccinProvider::flamingo() {
        return instance->get_theme()->flamingo;
    }

    QString CatppuccinProvider::mauve() {
        return instance->get_theme()->mauve;
    }

    QString CatppuccinProvider::pink() {
        return instance->get_theme()->pink;
    }

    QString CatppuccinProvider::maroon() {
        return instance->get_theme()->maroon;
    }

    QString CatppuccinProvider::red() {
        return instance->get_theme()->red;
    }

    QString CatppuccinProvider::peach() {
        return instance->get_theme()->peach;
    }

    QString CatppuccinProvider::yellow() {
        return instance->get_theme()->yellow;
    }

    QString CatppuccinProvider::green() {
        return instance->get_theme()->green;
    }

    QString CatppuccinProvider::blue() {
        return instance->get_theme()->blue;
    }

    QString CatppuccinProvider::lavender() {
        return instance->get_theme()->lavender;
    }

    QString CatppuccinProvider::text() {
        return instance->get_theme()->text;
    }

    QString CatppuccinProvider::subtext0() {
        return instance->get_theme()->subtext0;
    }

    QString CatppuccinProvider::subtext1() {
        return instance->get_theme()->subtext1;
    }

    QString CatppuccinProvider::overlay0() {
        return instance->get_theme()->overlay0;
    }

    QString CatppuccinProvider::overlay1() {
        return instance->get_theme()->overlay1;
    }

    QString CatppuccinProvider::overlay2() {
        return instance->get_theme()->overlay2;
    }

    QString CatppuccinProvider::surface0() {
        return instance->get_theme()->surface0;
    }

    QString CatppuccinProvider::surface1() {
        return instance->get_theme()->surface1;
    }

    QString CatppuccinProvider::surface2() {
        return instance->get_theme()->surface2;
    }

    QString CatppuccinProvider::base() {
        return instance->get_theme()->base;
    }

    QString CatppuccinProvider::crust() {
        return instance->get_theme()->crust;
    }

    QString CatppuccinProvider::mantle() {
        return instance->get_theme()->mantle;
    }

    QString CatppuccinProvider::sapphire() {
        return instance->get_theme()->sapphire;
    }

    QString CatppuccinProvider::sky() {
        return instance->get_theme()->sky;
    }

    QString CatppuccinProvider::teal() {
        return instance->get_theme()->teal;
    }

    void CatppuccinProvider::switch_theme(PaletteType paletteType) {
        instance->check_theme(paletteType);
        emit themeChanged();
    }
} // Theme