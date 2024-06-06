//
// Created by cvrain on 24-6-5.
//

#ifndef DAWDLE_TODO_CATPPUCCIN_BASIC_HPP
#define DAWDLE_TODO_CATPPUCCIN_BASIC_HPP

#include <QString>

namespace Theme {
    using ColorGroup = struct {
        QString rosewater;
        QString flamingo;
        QString pink;
        QString mauve;
        QString red;
        QString maroon;
        QString peach;
        QString yellow;
        QString green;
        QString teal;
        QString sky;
        QString sapphire;
        QString blue;
        QString lavender;
        QString text;
        QString subtext1;
        QString subtext0;
        QString overlay2;
        QString overlay1;
        QString overlay0;
        QString surface2;
        QString surface1;
        QString surface0;
        QString base;
        QString mantle;
        QString crust;
    };

    class CatppuccinBasic {
    public:
        virtual ColorGroup get_color_group(){
            return colorGroup;
        };

    protected:
        ColorGroup colorGroup;
    };
}
#endif //DAWDLE_TODO_CATPPUCCIN_BASIC_HPP
