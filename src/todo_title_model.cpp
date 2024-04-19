#include "todo_title_model.hpp"

namespace Model {
    TodoTitleModel::TodoTitleModel(QObject *object) : QAbstractListModel(object) {
        todo_items.append(TodoTitleItem{"daily", "daily task"});
        todo_items.append(TodoTitleItem{"assignment", "once assignment"});
        todo_items.append(TodoTitleItem{"cycle", "do task one by one"});
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

} // Model
