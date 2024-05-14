#ifndef DAWDLE_TODO_TODO_TITLE_MODEL_HPP
#define DAWDLE_TODO_TODO_TITLE_MODEL_HPP

#include <QObject>
#include <QString>
#include <QAbstractListModel>
#include <QHash>

#include "todo_structure.h"
#include "todo_manager.hpp"
#include "todo_manager.hpp"

namespace Model {
    class TodoTitleModel : public QAbstractListModel {
        Q_OBJECT

    public:
        explicit TodoTitleModel(QObject *object = nullptr);

        enum {
            TodoGroupName = Qt::UserRole + 1,
            TodoGroupId,
            TodoGroupCategory
        };

        [[nodiscard]] int rowCount(const QModelIndex &parent) const override;

        [[nodiscard]] QVariant data(const QModelIndex &index, int role) const override;

        [[nodiscard]] QHash<int, QByteArray>  roleNames() const override;

        Q_INVOKABLE void remove(int index);

    private:
        QList <TodoStructure::TodoGroupInfo> todo_items;
        Controller::TodoManager todo_manager{};
    };

} // Model

#endif //DAWDLE_TODO_TODO_TITLE_MODEL_HPP
