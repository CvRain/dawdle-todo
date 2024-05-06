#include "todo_title_model.hpp"

namespace Model {
    TodoTitleModel::TodoTitleModel(QObject *object) : QAbstractListModel(object) {
        //TODO
        //link core lib
        //init load task group
        todo_items.push_back(TodoTitleItem{"1","1"});
        todo_items.push_back(TodoTitleItem{"1","1"});
        todo_items.push_back(TodoTitleItem{"1","1"});
        todo_items.push_back(TodoTitleItem{"1","1"});
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
        if (index < 0 || index >= todo_items.size())
            return;

        beginRemoveRows(QModelIndex(), index, index); // 开始删除操作
        todo_items.removeAt(index);
        endRemoveRows(); // 结束删除操作
    }


} // Model
