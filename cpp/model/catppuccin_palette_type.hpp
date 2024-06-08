//
// Created by cvrain on 24-6-8.
//

#ifndef DAWDLE_TODO_CATPPUCCIN_PALETTE_TYPE_HPP
#define DAWDLE_TODO_CATPPUCCIN_PALETTE_TYPE_HPP

#include <QObject>
#include <QMetaType>
#include <QtQml>

namespace Model {
    Q_NAMESPACE

    class CatppuccinPaletteType : public QObject {
    Q_OBJECT

    public:
        explicit CatppuccinPaletteType(QObject *parent = nullptr) : QObject(parent) {}

        enum class PaletteType {
            Latte,
            Frappe,
            Macchiato,
            Mocha,
        };

        Q_ENUM(PaletteType);
    };
} // Model

#endif //DAWDLE_TODO_CATPPUCCIN_PALETTE_TYPE_HPP
