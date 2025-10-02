cmake_minimum_required(VERSION 3.16)

project(DawdleTodo VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(QT_QML_GENERATE_QMLLS_INI ON)

find_package(Qt6 REQUIRED COMPONENTS Quick Core Qml Quick3D)
find_package(SQLiteCpp CONFIG REQUIRED)
find_package(unofficial-sqlite3 CONFIG REQUIRED)

qt_standard_project_setup(REQUIRES 6.5)

if (QT_KNOWN_POLICY_QTP0004)
    qt_policy(SET QTP0004 NEW)
endif ()

if (QT_KNOWN_POLICY_QTP0005)
    qt_policy(SET QTP0005 NEW)
endif ()

set(CPP_FILES src/cpp/main.cpp
        src/cpp/application.cpp
        src/cpp/application.hpp
        src/cpp/saveService.cpp
        src/cpp/saveService.hpp
        src/cpp/models/group.cpp
        src/cpp/models/group.hpp
        src/cpp/models/recurrenceDetail.cpp
        src/cpp/models/recurrenceDetail.hpp
        src/cpp/models/todo.cpp
        src/cpp/models/todo.hpp)

qt_add_executable(appDawdleTodo
        ${CPP_FILES}
)

target_include_directories(appDawdleTodo PRIVATE
        src/cpp
        src/cpp/models)

set(QML_COMPONENTS src/app/Components/TitleBar.qml
        src/app/Components/CustomFont.qml
        src/app/Components/TitleButton.qml
        src/app/Components/Cake.qml
)

set(QML_ICONS
        src/app/Icons/IconClose.qml
        src/app/Icons/IconMaximize.qml
        src/app/Icons/IconMinimize.qml)

set(APP_QML_FILES
        src/app/Main.qml
        ${QML_COMPONENTS}
        ${QML_ICONS}
)

set(SOURCE_FONTS
        public/fonts/ComicShannsMono/ComicShannsMonoNerdFontMono-Bold.otf
        public/fonts/ComicShannsMono/ComicShannsMonoNerdFontMono-Regular.otf
        public/fonts/SarasaFixedSC/SarasaFixedSC-Bold.ttf
        public/fonts/SarasaFixedSC/SarasaFixedSC-Regular.ttf
)

set(SQL_SOURCES
        src/sql/create_groups.sql
        src/sql/create_todos.sql
        src/sql/create_recurrence_details.sql
)

set_source_files_properties(src/app/Components/CustomFont.qml
        PROPERTIES QT_QML_SINGLETON_TYPE TRUE)

qt_add_qml_module(appDawdleTodo
        URI DawdleTodo
        VERSION 1.0
        QML_FILES ${APP_QML_FILES}
        RESOURCES ${SOURCE_FONTS} ${SQL_SOURCES}
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appDawdleTodo PROPERTIES
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
)

target_link_libraries(appDawdleTodo
        PRIVATE Qt6::Quick Qt6::Core Qt6::Qml Qt6::Quick3D
)

target_link_libraries(appDawdleTodo PRIVATE SQLiteCpp unofficial::sqlite3::sqlite3)

include(GNUInstallDirs)
install(TARGETS appDawdleTodo
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
