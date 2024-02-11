cmake_minimum_required(VERSION 3.16)

project(dawdle_todo VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 REQUIRED COMPONENTS Quick)


set(SRC src/main.cpp)

set(UI
    ui/Main.qml
    ui/Placeholder.qml
    ui/TaskBar.qml
    ui/RadioRectangle.qml
    ui/BottomPanel.qml
    ui/PanelTaskForm.qml
    ui/DeleteButton.qml)

set(RES res/res.qrc)

qt_add_executable(appdawdle_todo
    ${RES}
    ${SRC}
)

qt_add_qml_module(appdawdle_todo
    URI dawdle_todo
    VERSION 1.0
    RESOURCES ${RES}
    QML_FILES ${UI}
)

set_target_properties(appdawdle_todo PROPERTIES
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
