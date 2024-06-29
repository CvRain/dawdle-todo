//
// Created by cvrain on 24-6-8.
//

#include "catppuccin_palette_type.hpp"

namespace Model {

    CatppuccinPaletteType::CatppuccinPaletteType(QObject *parent) : QObject(parent) {
        color_name_to_string.insert(std::make_pair(Model::CatppuccinColor::Color::Rosewater, "rosewater"));
        color_name_to_string.insert(std::make_pair(Model::CatppuccinColor::Color::Flamingo, "flamingo"));
        color_name_to_string.insert(std::make_pair(Model::CatppuccinColor::Color::Pink, "pink"));
        color_name_to_string.insert(std::make_pair(Model::CatppuccinColor::Color::Mauve, "mauve"));
        color_name_to_string.insert(std::make_pair(Model::CatppuccinColor::Color::Red, "red"));
        color_name_to_string.insert(std::make_pair(Model::CatppuccinColor::Color::Maroon, "maroon"));
        color_name_to_string.insert(std::make_pair(Model::CatppuccinColor::Color::Peach, "peach"));
        color_name_to_string.insert(std::make_pair(Model::CatppuccinColor::Color::Yellow, "yellow"));
        color_name_to_string.insert(std::make_pair(Model::CatppuccinColor::Color::Green, "green"));
        color_name_to_string.insert(std::make_pair(Model::CatppuccinColor::Color::Teal, "teal"));
        color_name_to_string.insert(std::make_pair(Model::CatppuccinColor::Color::Blue, "blue"));
        color_name_to_string.insert(std::make_pair(Model::CatppuccinColor::Color::Sapphire, "sapphire"));
        color_name_to_string.insert(std::make_pair(Model::CatppuccinColor::Color::Sky, "sky"));
        color_name_to_string.insert(std::make_pair(Model::CatppuccinColor::Color::Lavender, "lavender"));
        color_name_to_string.insert(std::make_pair(Model::CatppuccinColor::Color::Text, "text"));
        color_name_to_string.insert(std::make_pair(Model::CatppuccinColor::Color::Subtext0, "subtext0"));
        color_name_to_string.insert(std::make_pair(Model::CatppuccinColor::Color::Overlay0, "overlay0"));
        color_name_to_string.insert(std::make_pair(Model::CatppuccinColor::Color::Subtext1, "subtext1"));
        color_name_to_string.insert(std::make_pair(Model::CatppuccinColor::Color::Overlay1, "overlay1"));
        color_name_to_string.insert(std::make_pair(Model::CatppuccinColor::Color::Overlay2, "overlay2"));
        color_name_to_string.insert(std::make_pair(Model::CatppuccinColor::Color::Base, "base"));
        color_name_to_string.insert(std::make_pair(Model::CatppuccinColor::Color::Surface0, "surface0"));
        color_name_to_string.insert(std::make_pair(Model::CatppuccinColor::Color::Surface1, "surface1"));
        color_name_to_string.insert(std::make_pair(Model::CatppuccinColor::Color::Surface2, "surface2"));
        color_name_to_string.insert(std::make_pair(Model::CatppuccinColor::Color::Mantle, "mantle"));
        color_name_to_string.insert(std::make_pair(Model::CatppuccinColor::Color::Crust, "crust"));
    }

    QString CatppuccinPaletteType::color_name(Model::CatppuccinColor::Color color) {
        if (color_name_to_string.find(color) == color_name_to_string.end()) {
            return "";
        }
        return color_name_to_string.at(color);
    }

    CatppuccinColor::CatppuccinColor(QObject *parent) : QObject(parent) {

    }
}
