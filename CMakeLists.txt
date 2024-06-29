cmake_minimum_required(VERSION 3.16)

project(dawdle_todo VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

find_package(Qt6 6.7 REQUIRED COMPONENTS Quick)
find_package(jsoncpp CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(SqliteOrm CONFIG REQUIRED)

qt_standard_project_setup(REQUIRES 6.5)

set(QML_COMPONENTS
        qml/components/TitleButton.qml
        qml/components/WindowTitle.qml
        qml/components/RoundedRectangle.qml
        qml/components/MoveableWindow.qml
)

set(QML_MODELS

)

set(QML_UTILS
)

set(QML_VIEWS
        qml/views/Main.qml
        qml/views/TimeDisplayPanel.qml
        qml/views/WeatherPanel.qml
)

set(UI ${QML_COMPONENTS}
        ${QML_MODELS}
        ${QML_UTILS}
        ${QML_VIEWS}
)

include_directories(cpp)

set(CPP_UTIL
    cpp/utils/simple_id.cpp
    cpp/utils/simple_id.hpp
        cpp/utils/panel_manager.cpp
        cpp/utils/panel_manager.hpp
)

set(CPP_SERVICE
        cpp/services/database_service.cpp
        cpp/services/database_service.hpp
        cpp/services/todo_group_table.cpp
        cpp/services/todo_group_table.hpp
)

set(CPP_MODEL
        cpp/model/catppuccin_palette_type.hpp
        cpp/model/catppuccin_palette_type.cpp
        cpp/model/todo_group.hpp
)

set(CPP_THEME
        cpp/theme/catppuccin_basic.hpp
        cpp/theme/catppuccin_factory.hpp
        cpp/theme/catppuccin_factory.cpp
        cpp/theme/catppuccin_latte.cpp
        cpp/theme/catppuccin_latte.hpp
        cpp/theme/catppuccin_mocha.cpp
        cpp/theme/catppuccin_mocha.hpp
        cpp/theme/catppuccin_provider.cpp
        cpp/theme/catppuccin_provider.hpp
)

set(CPP_SOURCE ${CPP_MODEL} ${CPP_THEME} ${CPP_SERVICE} ${CPP_UTIL})

set(RESOURCE_FILES resource.qrc qml.qrc)

qt_add_executable(appdawdle_todo
        cpp/main.cpp
        ${CPP_SOURCE}
        ${RESOURCE_FILES}
)

qt_add_qml_module(appdawdle_todo
        URI dawdle_todo
        VERSION 1.0
        QML_FILES ${UI}
        RESOURCES ${RESOURCE_FILES}
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appdawdle_todo PROPERTIES
        #    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appdawdle_todo
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
)

target_link_libraries(appdawdle_todo
        PRIVATE Qt6::Quick
        sqlite_orm::sqlite_orm
        spdlog::spdlog_header_only
        JsonCpp::JsonCpp
)

include(GNUInstallDirs)
install(TARGETS appdawdle_todo
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

target_compile_features(appdawdle_todo PRIVATE cxx_std_20)
