//
// Created by cvrain on 24-6-8.
//

#ifndef DAWDLE_TODO_CATPPUCCIN_PROVIDER_HPP
#define DAWDLE_TODO_CATPPUCCIN_PROVIDER_HPP

#include <QObject>
#include <QColor>
#include <map>

#include "catppuccin_factory.hpp"
#include "model/catppuccin_palette_type.hpp"

namespace Theme {
    class CatppuccinProvider : public QObject {
    Q_OBJECT

    public:
        using PaletteType = Model::CatppuccinPaletteType::PaletteType;

        explicit CatppuccinProvider(QObject *parent = nullptr);

        Q_INVOKABLE void switch_theme(Model::CatppuccinPaletteType::PaletteType paletteType);

        Q_INVOKABLE QString get_color(Model::CatppuccinColor::Color catppuccinColor);

        Q_INVOKABLE static QColor alpha(QString color, double alpha);

        Q_INVOKABLE QString rosewater();

        Q_INVOKABLE QString flamingo();

        Q_INVOKABLE QString pink();

        Q_INVOKABLE QString mauve();

        Q_INVOKABLE QString red();

        Q_INVOKABLE QString maroon();

        Q_INVOKABLE QString peach();

        Q_INVOKABLE QString yellow();

        Q_INVOKABLE QString green();

        Q_INVOKABLE QString teal();

        Q_INVOKABLE QString sky();

        Q_INVOKABLE QString sapphire();

        Q_INVOKABLE QString blue();

        Q_INVOKABLE QString lavender();

        Q_INVOKABLE QString text();

        Q_INVOKABLE QString subtext1();

        Q_INVOKABLE QString subtext0();

        Q_INVOKABLE QString overlay2();

        Q_INVOKABLE QString overlay1();

        Q_INVOKABLE QString overlay0();

        Q_INVOKABLE QString surface2();

        Q_INVOKABLE QString surface1();

        Q_INVOKABLE QString surface0();

        Q_INVOKABLE QString base();

        Q_INVOKABLE QString mantle();

        Q_INVOKABLE QString crust();

    signals:

        virtual void themeChanged();

    private:
        CatppuccinFactory *instance;
        static std::map<Model::CatppuccinColor::Color, QString (Theme::CatppuccinProvider::*)()> theme_map;
    };

} // Theme

#endif //DAWDLE_TODO_CATPPUCCIN_PROVIDER_HPP
