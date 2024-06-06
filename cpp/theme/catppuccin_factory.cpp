//
// Created by cvrain on 24-6-6.
//

#include "catppuccin_factory.hpp"

namespace Theme {
    CatppuccinFactory::CatppuccinFactory(QObject *parent)
    : QObject(parent), current_palette_type{CatppuccinPaletteType::Latte}, catppuccin_theme{new CatppuccinLatte} {
        instantiation_map.insert(std::make_pair(CatppuccinPaletteType::Latte, &CatppuccinFactory::instantiation_latte));
        instantiation_map.insert(std::make_pair(CatppuccinPaletteType::Mocha, &CatppuccinFactory::instantiation_mocha));
        instantiation_map.insert(std::make_pair(CatppuccinPaletteType::Macchiato, &CatppuccinFactory::instantiation_macchiato));
        instantiation_map.insert(std::make_pair(CatppuccinPaletteType::Frappe, &CatppuccinFactory::instantiation_frappe));
    }

    CatppuccinFactory::~CatppuccinFactory() {
        delete catppuccin_theme;
        catppuccin_theme = nullptr;
    }

    void CatppuccinFactory::check_theme(CatppuccinPaletteType palette_type) {
        if(current_palette_type == palette_type){
            return;
        }
        if(instantiation_map.find(palette_type) != instantiation_map.end()){
            current_palette_type = palette_type;
            const auto function = instantiation_map.at(palette_type);
            (this->*function)();
        }
    }

    void CatppuccinFactory::instantiation_latte() {
        delete catppuccin_theme;
        catppuccin_theme = new CatppuccinLatte;
    }

    void CatppuccinFactory::instantiation_mocha() {
        delete catppuccin_theme;
        catppuccin_theme = new CatppuccinMocha;
    }

    void CatppuccinFactory::instantiation_macchiato() {
        //todo
//        delete catppuccin_theme;
//        catppuccin_theme = new CatppuccinMacchiato;
    }

    void CatppuccinFactory::instantiation_frappe() {
        //todo
//        delete catppuccin_theme;
//        catppuccin_theme = new CatppuccinFrappe;
    }

    QString CatppuccinFactory::rosewater() {
        return catppuccin_theme->get_color_group().rosewater;
    }

    QString CatppuccinFactory::flamingo() {
        return catppuccin_theme->get_color_group().flamingo;
    }

    QString CatppuccinFactory::mauve() {
        return catppuccin_theme->get_color_group().mauve;
    }

    QString CatppuccinFactory::pink() {
        return catppuccin_theme->get_color_group().pink;
    }

    QString CatppuccinFactory::maroon() {
        return catppuccin_theme->get_color_group().maroon;
    }

    QString CatppuccinFactory::red() {
        return catppuccin_theme->get_color_group().red;
    }

    QString CatppuccinFactory::peach() {
        return catppuccin_theme->get_color_group().peach;
    }

    QString CatppuccinFactory::yellow() {
        return catppuccin_theme->get_color_group().yellow;
    }

    QString CatppuccinFactory::green() {
        return catppuccin_theme->get_color_group().green;
    }

    QString CatppuccinFactory::blue() {
        return catppuccin_theme->get_color_group().blue;
    }

    QString CatppuccinFactory::lavender() {
        return catppuccin_theme->get_color_group().lavender;
    }

    QString CatppuccinFactory::text() {
        return catppuccin_theme->get_color_group().text;
    }

    QString CatppuccinFactory::subtext0() {
        return catppuccin_theme->get_color_group().subtext0;
    }

    QString CatppuccinFactory::subtext1() {
        return catppuccin_theme->get_color_group().subtext1;
    }

    QString CatppuccinFactory::overlay0() {
        return catppuccin_theme->get_color_group().overlay0;
    }

    QString CatppuccinFactory::overlay1() {
        return catppuccin_theme->get_color_group().overlay1;
    }

    QString CatppuccinFactory::overlay2() {
        return catppuccin_theme->get_color_group().overlay2;
    }

    QString CatppuccinFactory::surface0() {
        return catppuccin_theme->get_color_group().surface0;
    }

    QString CatppuccinFactory::surface1() {
        return catppuccin_theme->get_color_group().surface1;
    }

    QString CatppuccinFactory::surface2() {
        return catppuccin_theme->get_color_group().surface2;
    }

    QString CatppuccinFactory::base() {
        return catppuccin_theme->get_color_group().base;
    }

    QString CatppuccinFactory::crust() {
        return catppuccin_theme->get_color_group().crust;
    }

    QString CatppuccinFactory::mantle() {
        return catppuccin_theme->get_color_group().mantle;
    }

    QString CatppuccinFactory::sapphire() {
        return catppuccin_theme->get_color_group().sapphire;
    }

    QString CatppuccinFactory::sky() {
        return catppuccin_theme->get_color_group().sky;
    }

    QString CatppuccinFactory::teal() {
        return catppuccin_theme->get_color_group().teal;
    }
}