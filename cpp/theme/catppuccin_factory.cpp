//
// Created by cvrain on 24-6-6.
//

#include "catppuccin_factory.hpp"

#include "catppuccin_latte.hpp"
#include "catppuccin_mocha.hpp"

namespace Theme {
    Theme::CatppuccinFactory* CatppuccinFactory::instance = nullptr;

    CatppuccinFactory::CatppuccinFactory(QObject *parent)
    : QObject(parent),
    catppuccin_theme(new CatppuccinLatte),
    current_palette_type{PaletteType::Latte}{
        instantiation_map.insert(std::make_pair(PaletteType::Latte, &CatppuccinFactory::instantiation_latte));
        instantiation_map.insert(std::make_pair(PaletteType::Mocha, &CatppuccinFactory::instantiation_mocha));
        instantiation_map.insert(std::make_pair(PaletteType::Macchiato, &CatppuccinFactory::instantiation_macchiato));
        instantiation_map.insert(std::make_pair(PaletteType::Frappe, &CatppuccinFactory::instantiation_frappe));
    }

    void CatppuccinFactory::check_theme(PaletteType palette_type)
    {
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
        qDebug() << "change theme: latte";
        delete catppuccin_theme;
        catppuccin_theme = new CatppuccinLatte;
    }

    void CatppuccinFactory::instantiation_mocha() {
        qDebug() << "change theme: mocha";
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

    Theme::CatppuccinFactory &CatppuccinFactory::get_instance(QObject *parent) {
        if(instance == nullptr){
            instance = new CatppuccinFactory(parent);
        }
        return *instance;
    }

    Theme::CatppuccinBasic *CatppuccinFactory::get_theme() {
        return catppuccin_theme;
    }
}
