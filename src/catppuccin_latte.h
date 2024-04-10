#ifndef CATPPUCCIN_LATTE_H
#define CATPPUCCIN_LATTE_H

#include <QObject>
#include <QString>

namespace Theme::Catppuccin {
    class Latte : public QObject {
        Q_OBJECT
    public:
        Q_PROPERTY(QString LeadWhite READ get_lead_white CONSTANT);
        Q_PROPERTY(QString Flamingo READ get_flamingo CONSTANT);
        Q_PROPERTY(QString Rosewater READ get_rosewater CONSTANT);
        Q_PROPERTY(QString Pink READ get_pink CONSTANT);
        Q_PROPERTY(QString DefaultText READ get_defaultText CONSTANT);
        Q_PROPERTY(QString Subtext1 READ get_subtext1 CONSTANT);
        Q_PROPERTY(QString Subtext0 READ get_subtext0 CONSTANT);
        Q_PROPERTY(QString Overlay2 READ get_overlay2 CONSTANT);
        Q_PROPERTY(QString Overlay1 READ get_overlay1 CONSTANT);
        Q_PROPERTY(QString Overlay0 READ get_overlay0 CONSTANT);
        Q_PROPERTY(QString Surface2 READ get_surface2 CONSTANT);
        Q_PROPERTY(QString Surface1 READ get_surface1 CONSTANT);
        Q_PROPERTY(QString Surface0 READ get_surface0 CONSTANT);
        Q_PROPERTY(QString Base READ get_base CONSTANT);
        Q_PROPERTY(QString Mantle READ get_mantle CONSTANT);
        Q_PROPERTY(QString Curst READ get_curst CONSTANT);


        [[nodiscard]] QString get_lead_white() const { return lead_white;};
        [[nodiscard]] QString get_flamingo() const {return flamingo;};
        [[nodiscard]] QString get_rosewater() const {return rosewater;};
        [[nodiscard]] QString get_pink() const {return pink;};
        [[nodiscard]] QString get_defaultText() const {return defaultText;};
        [[nodiscard]] QString get_subtext1() const {return subtext1;};
        [[nodiscard]] QString get_subtext0() const {return subtext0;};
        [[nodiscard]] QString get_overlay2() const {return overlay2;};
        [[nodiscard]] QString get_overlay1() const {return overlay1;};
        [[nodiscard]] QString get_overlay0() const {return overlay0;};
        [[nodiscard]] QString get_surface2() const {return surface2;};
        [[nodiscard]] QString get_surface1() const {return surface1;};
        [[nodiscard]] QString get_surface0() const {return surface0;};
        [[nodiscard]] QString get_base() const {return base;};
        [[nodiscard]] QString get_mantle() const {return mantle;};
        [[nodiscard]] QString get_curst() const {return curst;};

    private:
        const QString lead_white{"#f0f0f4"};
        const QString flamingo{"#dd7878"};
        const QString rosewater{ "#dc8a78"};
        const QString pink{ "#ea76cb"};
        const QString defaultText{ "#4c4f69"};
        const QString subtext1{ "#5c5f77"};
        const QString subtext0{ "#6c6f85"};
        const QString overlay2{ "#7c7f93"};
        const QString overlay1{ "#8c8fa1"};
        const QString overlay0{ "#9ca0b0"};
        const QString surface2{ "#acb0be"};
        const QString surface1{ "#bcc0cc"};
        const QString surface0{ "#ccd0da"};
        const QString base{"#eff1f5"};
        const QString mantle{ "#e6e9ef"};
        const QString curst{ "#dce0e8"};
    };
}

#endif // CATPPUCCIN_LATTE_H
