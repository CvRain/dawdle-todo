cmake_minimum_required(VERSION 3.16)

project(dawdle_todo VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

if (LINUX)
    set(DUCK_DB_PATH ${CMAKE_SOURCE_DIR}/third_party/libduckdb-linux-amd64)
elseif (WIN32)
    set(DUCK_DB_PATH ${CMAKE_SOURCE_DIR}/third_party/libduckdb-windows-amd64)
endif ()
include_directories(${DUCK_DB_PATH})

find_package(Qt6 6.2 REQUIRED COMPONENTS Quick)


set(SRC ${MODULES}
        src/main.cpp
        src/catppuccin_latte.h
        src/main_window.cpp
        src/main_window.hpp
        src/todo_title_model.cpp
        src/todo_title_model.hpp
        src/todo_manager.cpp
        src/todo_manager.hpp
        src/todo_structure.hpp
        src/simple_id.cpp
        src/simple_id.hpp
        src/duck_service.hpp
        src/duck_service.cpp
        src/db_query_reader.cpp
        src/db_query_reader.hpp
        src/todo_structure.cpp
)

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
        component/HomePageMenu.qml
        component/HomeMenuItem.qml
)

set(RES res/res.qrc)

find_package(leveldb CONFIG REQUIRED)
find_package(jsoncpp CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

#add_executable(appdawdle_todo
#        ${RES}
#        ${SRC}
#)
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
        PRIVATE Qt6::Quick JsonCpp::JsonCpp leveldb::leveldb spdlog::spdlog_header_only
)

if (LINUX)
    target_link_libraries(appdawdle_todo PRIVATE ${DUCK_DB_PATH}/libduckdb.so)
elseif (WIN32)
    target_link_libraries(appdawdle_todo PRIVATE ${DUCK_DB_PATH}/libduckdb.lib)
endif ()

include(GNUInstallDirs)
install(TARGETS appdawdle_todo
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

target_compile_features(appdawdle_todo PRIVATE cxx_std_20)
