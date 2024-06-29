//
// Created by cvrain on 24-6-8.
//

#include "catppuccin_provider.hpp"
#include <spdlog/spdlog.h>

namespace Theme {
    std::map<Model::CatppuccinColor::Color, QString (Theme::CatppuccinProvider::*)()>  CatppuccinProvider::theme_map = {};

    CatppuccinProvider::CatppuccinProvider(QObject *parent)
            : QObject(parent), instance(&CatppuccinFactory::get_instance()) {
        spdlog::debug("CatppuccinProvider::CatppuccinProvider");

        using CatppuccinColor = Model::CatppuccinColor::Color;
        theme_map.insert(std::make_pair(CatppuccinColor::Rosewater, &CatppuccinProvider::rosewater));
        theme_map.insert(std::make_pair(CatppuccinColor::Flamingo, &CatppuccinProvider::flamingo));
        theme_map.insert(std::make_pair(CatppuccinColor::Mauve, &CatppuccinProvider::mauve));
        theme_map.insert(std::make_pair(CatppuccinColor::Pink, &CatppuccinProvider::pink));
        theme_map.insert(std::make_pair(CatppuccinColor::Maroon, &CatppuccinProvider::maroon));
        theme_map.insert(std::make_pair(CatppuccinColor::Red, &CatppuccinProvider::red));
        theme_map.insert(std::make_pair(CatppuccinColor::Peach, &CatppuccinProvider::peach));
        theme_map.insert(std::make_pair(CatppuccinColor::Yellow, &CatppuccinProvider::yellow));
        theme_map.insert(std::make_pair(CatppuccinColor::Green, &CatppuccinProvider::green));
        theme_map.insert(std::make_pair(CatppuccinColor::Blue, &CatppuccinProvider::blue));
        theme_map.insert(std::make_pair(CatppuccinColor::Lavender, &CatppuccinProvider::lavender));
        theme_map.insert(std::make_pair(CatppuccinColor::Text, &CatppuccinProvider::text));
        theme_map.insert(std::make_pair(CatppuccinColor::Subtext0, &CatppuccinProvider::subtext0));
        theme_map.insert(std::make_pair(CatppuccinColor::Subtext1, &CatppuccinProvider::subtext1));
        theme_map.insert(std::make_pair(CatppuccinColor::Overlay0, &CatppuccinProvider::overlay0));
        theme_map.insert(std::make_pair(CatppuccinColor::Overlay1, &CatppuccinProvider::overlay1));
        theme_map.insert(std::make_pair(CatppuccinColor::Overlay2, &CatppuccinProvider::overlay2));
        theme_map.insert(std::make_pair(CatppuccinColor::Crust, &CatppuccinProvider::crust));
        theme_map.insert(std::make_pair(CatppuccinColor::Surface0, &CatppuccinProvider::surface0));
        theme_map.insert(std::make_pair(CatppuccinColor::Surface1, &CatppuccinProvider::surface1));
        theme_map.insert(std::make_pair(CatppuccinColor::Surface2, &CatppuccinProvider::surface2));
        theme_map.insert(std::make_pair(CatppuccinColor::Base, &CatppuccinProvider::base));
        theme_map.insert(std::make_pair(CatppuccinColor::Sapphire, &CatppuccinProvider::sapphire));
        theme_map.insert(std::make_pair(CatppuccinColor::Teal, &CatppuccinProvider::teal));
        theme_map.insert(std::make_pair(CatppuccinColor::Mantle, &CatppuccinProvider::mantle));
        theme_map.insert(std::make_pair(CatppuccinColor::Sky, &CatppuccinProvider::sky));
        theme_map.insert(std::make_pair(CatppuccinColor::Mantle, &CatppuccinProvider::mantle));
        theme_map.insert(std::make_pair(CatppuccinColor::Crust, &CatppuccinProvider::crust));

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
        spdlog::debug("CatppuccinProvider::switch_theme");
        instance->check_theme(paletteType);
        emit themeChanged();
    }

    QString CatppuccinProvider::get_color(Model::CatppuccinColor::Color catppuccinColor) {
        const auto color_func = theme_map.at(catppuccinColor);
        const auto get_color = (this->*color_func)();
        spdlog::debug("CatppuccinProvider::get_color::{}", get_color.toLocal8Bit().toStdString());
        return get_color;
    }
} // Theme
