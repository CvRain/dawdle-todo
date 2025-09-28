pragma Singleton

import QtQuick

Item {
    property alias fontComicShannsMonoBold: comicShannsMonoBold
    property alias fontComicShannsMonoRegular: comicShannsMonoRegular
    property alias fontSharasaFixedBold: sharasaFixedBold
    property alias fontSharasaFixedRegular: sharasaFixedRegular

    FontLoader {
        id: comicShannsMonoBold
        source: "qrc:/qt/qml/DawdleTodo/public/fonts/ComicShannsMono/ComicShannsMonoNerdFontMono-Bold.otf"
    }
    FontLoader {
        id: comicShannsMonoRegular
        source: "qrc:/qt/qml/DawdleTodo/public/fonts/ComicShannsMono/ComicShannsMonoNerdFontMono-Regular.otf"
    }
    FontLoader {
        id: sharasaFixedBold
        source: "qrc:/qt/qml/DawdleTodo/public/fonts/SarasaFixedSC/SarasaFixedSC-Bold.ttf"
    }
    FontLoader {
        id: sharasaFixedRegular
        source: "qrc:/qt/qml/DawdleTodo/public/fonts/SarasaFixedSC/SarasaFixedSC-Regular.ttf"
    }
}
