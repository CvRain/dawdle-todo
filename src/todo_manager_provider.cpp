//
// Created by cvrain on 24-5-25.
//

#include "todo_manager_provider.hpp"

TodoManagerProvider::TodoManagerProvider(QObject *parent)
: QObject(parent), m_todoManager(&Controller::TodoManager::get_instance()) {

}

Controller::TodoManager *TodoManagerProvider::todoManager() const {
    return m_todoManager;
}
