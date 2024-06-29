//
// Created by cvrain on 24-6-8.
//

#ifndef DAWDLE_TODO_CATPPUCCIN_PALETTE_TYPE_HPP
#define DAWDLE_TODO_CATPPUCCIN_PALETTE_TYPE_HPP

#include <QObject>
#include <QMetaType>
#include <QtQml>

#include <map>

namespace Model {
    Q_NAMESPACE

    class CatppuccinColor : public QObject {
    Q_OBJECT

    public:
        explicit CatppuccinColor(QObject *parent = nullptr);

        enum class Color : int {
            Rosewater,
            Flamingo,
            Pink,
            Mauve,
            Red,
            Maroon,
            Peach,
            Yellow,
            Green,
            Teal,
            Sky,
            Sapphire,
            Blue,
            Lavender,
            Text,
            Subtext1,
            Subtext0,
            Overlay2,
            Overlay1,
            Overlay0,
            Surface2,
            Surface1,
            Surface0,
            Base,
            Mantle,
            Crust,
        };
        Q_ENUM(Color)
    };

    class CatppuccinPaletteType : public QObject {
    Q_OBJECT

    public:
        explicit CatppuccinPaletteType(QObject *parent = nullptr);

        enum class PaletteType : int {
            Latte,
            Frappe,
            Macchiato,
            Mocha,
        };


        Q_ENUM(PaletteType)

        Q_INVOKABLE QString color_name(Model::CatppuccinColor::Color color);

    private:
        std::map<Model::CatppuccinColor::Color, QString> color_name_to_string;
    };

} // Model

#endif //DAWDLE_TODO_CATPPUCCIN_PALETTE_TYPE_HPP
