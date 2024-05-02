cmake_minimum_required(VERSION 3.16)

project(dawdle_todo VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# if(WIN32)
#     set(CMAKE_PREFIX_PATH D:/DevKit/Qt/6.5.3/mingw_64)
# endif()

find_package(Qt6 6.2 REQUIRED COMPONENTS Quick)


set(SRC src/main.cpp
    src/catppuccin_latte.h
        src/random_value.hpp
        src/random_value.cpp
        src/main_window.cpp
        src/main_window.hpp
        src/todo_title_model.cpp
        src/todo_title_model.hpp)

set(UI
    component/Main.qml
    component/TaskOverviewBar.qml
    component/TodoSideBar.qml
    component/TodoDetailBar.qml
    component/CheckButton.qml
    component/WindowTitle.qml
    component/TitleButton.qml
    component/TaskOverviewGroup.qml
    component/TaskDetailBase.qml
    component/TaskCreationPopup.qml

)

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

target_compile_features(appdawdle_todo PRIVATE cxx_std_20)
