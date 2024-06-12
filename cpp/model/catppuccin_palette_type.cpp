//
// Created by cvrain on 24-6-8.
//

#include "catppuccin_palette_type.hpp"

Model::CatppuccinPaletteType::CatppuccinPaletteType(QObject *parent) : QObject(parent) {
    color_name_to_string.insert(std::make_pair(CatppuccinColor::Rosewater, "rosewater"));
    color_name_to_string.insert(std::make_pair(CatppuccinColor::Flamingo, "flamingo"));
    color_name_to_string.insert(std::make_pair(CatppuccinColor::Pink, "pink"));
    color_name_to_string.insert(std::make_pair(CatppuccinColor::Mauve, "mauve"));
    color_name_to_string.insert(std::make_pair(CatppuccinColor::Red, "red"));
    color_name_to_string.insert(std::make_pair(CatppuccinColor::Maroon, "maroon"));
    color_name_to_string.insert(std::make_pair(CatppuccinColor::Peach, "peach"));
    color_name_to_string.insert(std::make_pair(CatppuccinColor::Yellow, "yellow"));
    color_name_to_string.insert(std::make_pair(CatppuccinColor::Green, "green"));
    color_name_to_string.insert(std::make_pair(CatppuccinColor::Teal, "teal"));
    color_name_to_string.insert(std::make_pair(CatppuccinColor::Blue, "blue"));
    color_name_to_string.insert(std::make_pair(CatppuccinColor::Sapphire, "sapphire"));
    color_name_to_string.insert(std::make_pair(CatppuccinColor::Sky, "sky"));
    color_name_to_string.insert(std::make_pair(CatppuccinColor::Lavender, "lavender"));
    color_name_to_string.insert(std::make_pair(CatppuccinColor::Text, "text"));
    color_name_to_string.insert(std::make_pair(CatppuccinColor::Subtext0, "subtext0"));
    color_name_to_string.insert(std::make_pair(CatppuccinColor::Overlay0, "overlay0"));
    color_name_to_string.insert(std::make_pair(CatppuccinColor::Subtext1, "subtext1"));
    color_name_to_string.insert(std::make_pair(CatppuccinColor::Overlay1, "overlay1"));
    color_name_to_string.insert(std::make_pair(CatppuccinColor::Overlay2, "overlay2"));
    color_name_to_string.insert(std::make_pair(CatppuccinColor::Base, "base"));
    color_name_to_string.insert(std::make_pair(CatppuccinColor::Surface0, "surface0"));
    color_name_to_string.insert(std::make_pair(CatppuccinColor::Surface1, "surface1"));
    color_name_to_string.insert(std::make_pair(CatppuccinColor::Surface2, "surface2"));
    color_name_to_string.insert(std::make_pair(CatppuccinColor::Mantle, "mantle"));
    color_name_to_string.insert(std::make_pair(CatppuccinColor::Crust, "crust"));
}

QString Model::CatppuccinPaletteType::color_name(Model::CatppuccinPaletteType::CatppuccinColor color) {
    if(color_name_to_string.find(color) == color_name_to_string.end()){
        return "";
    }
    return color_name_to_string.at(color);
}
