#include "todo_title_model.hpp"

namespace Model {
    TodoTitleModel::TodoTitleModel(QObject *object) : QAbstractListModel(object) {
        todo_items.append(TodoTitleItem{"some assignment, group 1", "daily task"});
        todo_items.append(TodoTitleItem{"some assignment, group 2", "once assignment"});
        todo_items.append(TodoTitleItem{"some assignment, group 3", "do task one by one"});
        todo_items.append(TodoTitleItem{"some assignment, group 4", "do task one by one"});
        todo_items.append(TodoTitleItem{"some assignment, group 5", "do task one by one"});
        todo_items.append(TodoTitleItem{"some assignment, group 6", "do task one by one"});
    }

    int TodoTitleModel::rowCount(const QModelIndex &parent) const {
        Q_UNUSED(parent);
        return static_cast<int>(todo_items.count());
    }

    QVariant TodoTitleModel::data(const QModelIndex &index, int role) const {
        if (!index.isValid())
            return {};

        if (index.row() < 0 || index.row() >= todo_items.count())
            return {};

        const auto &item = todo_items.at(index.row());
        if (role == TodoThemeRole) {
            return QVariant{item.theme};
        } else if (role == TodoDescribeRole) {
            return QVariant{item.describe};
        }
        return {};
    }

    QHash<int, QByteArray> TodoTitleModel::roleNames() const {
        QHash<int, QByteArray> roles;
        roles[TodoThemeRole] = "theme";
        roles[TodoDescribeRole] = "describe";
        return roles;
    }

    void TodoTitleModel::remove(int index)
    {
        if(index <0 || todo_items.length() < index){
            return;
        }
        todo_items.removeAt(index);
    }

} // Model
