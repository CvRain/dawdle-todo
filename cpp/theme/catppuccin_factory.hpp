//
// Created by cvrain on 24-6-6.
//

#ifndef DAWDLE_TODO_CATPPUCCIN_FACTORY_HPP
#define DAWDLE_TODO_CATPPUCCIN_FACTORY_HPP

#include <QObject>
#include <QString>


#include <map>

#include "model/catppuccin_palette_type.hpp"
#include "catppuccin_basic.hpp"

namespace Theme {
    class CatppuccinFactory : public QObject {
    Q_OBJECT

    public:
        using PaletteType = Model::CatppuccinPaletteType::PaletteType;

        static Theme::CatppuccinFactory &get_instance(QObject *parent = nullptr);

        Theme::CatppuccinBasic *get_theme();

        Q_INVOKABLE void check_theme(Model::CatppuccinPaletteType::PaletteType paletteType);

    private:
        explicit CatppuccinFactory(QObject *parent = nullptr);

        void instantiation_latte();

        void instantiation_mocha();

        void instantiation_frappe();

        void instantiation_macchiato();

    private:
        static CatppuccinFactory *instance;
        PaletteType current_palette_type;
        CatppuccinBasic *catppuccin_theme;
        std::map<PaletteType, void (CatppuccinFactory::*)()> instantiation_map;
    };
}
#endif //DAWDLE_TODO_CATPPUCCIN_FACTORY_HPP
