//
// Created by cvrain on 24-6-6.
//

#ifndef DAWDLE_TODO_CATPPUCCIN_FACTORY_HPP
#define DAWDLE_TODO_CATPPUCCIN_FACTORY_HPP

#include <QObject>
#include <QString>

#include "catppuccin_latte.hpp"
#include "catppuccin_mocha.hpp"

namespace Theme {
    enum class CatppuccinPaletteType : int {
        Latte,
        Frappe,
        Macchiato,
        Mocha,
    };

    class CatppuccinFactory : public QObject {
    Q_OBJECT

    public:
        explicit CatppuccinFactory(QObject *parent);

        ~CatppuccinFactory();

        Q_INVOKABLE void check_theme(int paletteType);

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

    private:
        CatppuccinBasic *catppuccin_theme;
    };
}
#endif //DAWDLE_TODO_CATPPUCCIN_FACTORY_HPP
