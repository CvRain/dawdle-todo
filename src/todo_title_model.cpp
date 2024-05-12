#include "todo_title_model.hpp"

namespace Model {
    TodoTitleModel::TodoTitleModel(QObject *object) : QAbstractListModel(object) {
        //TODO
        //init load task group
        todo_items.push_back(TodoStructure::TodoGroupInfo{
            .group_name = "test",
            .group_id = "123",
            .category = TodoStructure::TodoCategoryToString(TodoStructure::TodoCategory::Cycle),
        });
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
        if (role == TodoGroupId) {
            return QVariant{item.group_id.data()};
        } else if (role == TodoGroupCategory) {
            return QVariant{item.category.data()};
        }else if(role == TodoGroupName){
            return QVariant{item.group_name.data()};
        }
        return {};
    }

    QHash<int, QByteArray> TodoTitleModel::roleNames() const {
        QHash<int, QByteArray> roles;
        roles[TodoGroupId] = "group_id";
        roles[TodoGroupCategory] = "group_category";
        roles[TodoGroupName] = "group_name";
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
