//
// Created by cvrain on 24-5-25.
//

#ifndef DAWDLE_TODO_TODO_MANAGER_PROVIDER_HPP
#define DAWDLE_TODO_TODO_MANAGER_PROVIDER_HPP

#include <QObject>
#include "todo_manager.hpp"

class TodoManagerProvider : public QObject{
    Q_OBJECT
public:
    explicit TodoManagerProvider(QObject* parent = nullptr);
    [[nodiscard]] Q_INVOKABLE Controller::TodoManager* todoManager() const;
private:
    Controller::TodoManager* m_todoManager;
};


#endif //DAWDLE_TODO_TODO_MANAGER_PROVIDER_HPP
