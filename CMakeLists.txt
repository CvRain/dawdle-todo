cmake_minimum_required(VERSION 3.16)

project(dawdle_todo VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)

set(CPP_MODEL

)

set(CPP_THEME
        cpp/theme/catppuccin_basic.hpp
        cpp/theme/catppuccin_factory.hpp
        cpp/theme/catppuccin_factory.cpp
        cpp/theme/catppuccin_latte.cpp
        cpp/theme/catppuccin_latte.hpp
        cpp/theme/catppuccin_mocha.cpp
        cpp/theme/catppuccin_mocha.hpp
)

qt_add_executable(appdawdle_todo
        main.cpp
        ${CPP_MODEL}
        ${CPP_THEME}
)

qt_add_qml_module(appdawdle_todo
        URI dawdle_todo
        VERSION 1.0
        QML_FILES
        Main.qml
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
)

include(GNUInstallDirs)
install(TARGETS appdawdle_todo
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
