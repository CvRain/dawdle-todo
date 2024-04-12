#ifndef CATPPUCCIN_LATTE_H
#define CATPPUCCIN_LATTE_H

#include <QObject>
#include <QString>

namespace Theme::Catppuccin {
    class Latte : public QObject {
    Q_OBJECT

    public:
        Q_PROPERTY(QString LeadWhite MEMBER lead_white CONSTANT);
        Q_PROPERTY(QString Flamingo MEMBER flamingo CONSTANT);
        Q_PROPERTY(QString Rosewater MEMBER rosewater CONSTANT);
        Q_PROPERTY(QString Pink MEMBER pink CONSTANT);
        Q_PROPERTY(QString Mauve MEMBER mauve CONSTANT);
        Q_PROPERTY(QString Red MEMBER red CONSTANT);
        Q_PROPERTY(QString Maroon MEMBER maroon CONSTANT);
        Q_PROPERTY(QString Peach MEMBER peach CONSTANT);
        Q_PROPERTY(QString Yellow MEMBER yellow CONSTANT);
        Q_PROPERTY(QString Green MEMBER green CONSTANT);
        Q_PROPERTY(QString Teal MEMBER teal CONSTANT);
        Q_PROPERTY(QString Sky MEMBER sky CONSTANT);
        Q_PROPERTY(QString Sapphire MEMBER sapphire CONSTANT);
        Q_PROPERTY(QString Blue MEMBER blue CONSTANT);
        Q_PROPERTY(QString Lavender MEMBER lavender CONSTANT);
        Q_PROPERTY(QString DefaultText MEMBER defaultText CONSTANT);
        Q_PROPERTY(QString Subtext1 MEMBER subtext1 CONSTANT);
        Q_PROPERTY(QString Subtext0 MEMBER subtext0 CONSTANT);
        Q_PROPERTY(QString Overlay2 MEMBER overlay2 CONSTANT);
        Q_PROPERTY(QString Overlay1 MEMBER overlay1 CONSTANT);
        Q_PROPERTY(QString Overlay0 MEMBER overlay0 CONSTANT);
        Q_PROPERTY(QString Surface2 MEMBER surface2 CONSTANT);
        Q_PROPERTY(QString Surface1 MEMBER surface1 CONSTANT);
        Q_PROPERTY(QString Surface0 MEMBER surface0 CONSTANT);
        Q_PROPERTY(QString Base MEMBER base CONSTANT);
        Q_PROPERTY(QString Mantle MEMBER mantle CONSTANT);
        Q_PROPERTY(QString Crust MEMBER crust CONSTANT);

    private:
        const QString lead_white{"#f0f0f4"};
        const QString flamingo{"#dd7878"};
        const QString rosewater{"#dc8a78"};
        const QString pink{"#ea76cb"};
        const QString mauve{"#8839ef"};
        const QString red{"#d20f39"};
        const QString maroon{"#e64553"};
        const QString peach{"#fe640b"};
        const QString yellow{"#df8e1d"};
        const QString green{"#40a02b"};
        const QString teal{"#179299"};
        const QString sky{"#04a5e5"};
        const QString sapphire{"#209fb5"};
        const QString blue{"#1e66f5"};
        const QString lavender{"#7287fd"};
        const QString defaultText{"#4c4f69"};
        const QString subtext1{"#5c5f77"};
        const QString subtext0{"#6c6f85"};
        const QString overlay2{"#7c7f93"};
        const QString overlay1{"#8c8fa1"};
        const QString overlay0{"#9ca0b0"};
        const QString surface2{"#acb0be"};
        const QString surface1{"#bcc0cc"};
        const QString surface0{"#ccd0da"};
        const QString base{"#eff1f5"};
        const QString mantle{"#e6e9ef"};
        const QString crust{"#dce0e8"};
    };
}

#endif // CATPPUCCIN_LATTE_H
