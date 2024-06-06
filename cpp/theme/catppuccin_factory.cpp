//
// Created by cvrain on 24-6-6.
//

#include "catppuccin_factory.hpp"

namespace Theme {
    CatppuccinFactory::CatppuccinFactory(QObject *parent) : QObject(parent) {
        catppuccin_theme = new CatppuccinLatte();
    }

    CatppuccinFactory::~CatppuccinFactory() {
        delete catppuccin_theme;
        catppuccin_theme = nullptr;
    }


    QString CatppuccinFactory::rosewater() {
        return catppuccin_theme->get_color_group().rosewater;
    }

    void CatppuccinFactory::check_theme(int palette_type) {
        const auto result = palette_type + static_cast<int>(CatppuccinPaletteType::Latte);

    }


}