cmake_minimum_required(VERSION 3.16)

project(dawdle-todo VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)
find_package(SQLiteCpp CONFIG REQUIRED)

qt_standard_project_setup(REQUIRES 6.5)

set(CPP_FILES src/cpp/main.cpp
        src/cpp/application.cpp
        src/cpp/application.hpp)

qt_add_executable(appdawdle-todo
    ${CPP_FILES}
)

set(APP_QML_FILES src/app/Main.qml)

qt_add_qml_module(appdawdle-todo
    URI dawdle-todo
    VERSION 1.0
    QML_FILES ${APP_QML_FILES}
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appdawdle-todo PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appdawdle-todo
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appdawdle-todo
    PRIVATE Qt6::Quick
)

target_link_libraries(appdawdle-todo PRIVATE SQLiteCpp)

include(GNUInstallDirs)
install(TARGETS appdawdle-todo
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)