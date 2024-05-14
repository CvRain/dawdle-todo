#include "todo_title_model.hpp"
#include <spdlog/spdlog.h>

namespace Model {
    TodoTitleModel::TodoTitleModel(QObject *object) : QAbstractListModel(object) {
        spdlog::info("TodoTitleModel::TodoTitleModel");
        const auto data = todo_manager.get_all_todo_group();
        if(data.empty()){
            spdlog::info("group info without data");
        }
        for(const auto& it : data){
            spdlog::info("add group to list model: {}--{}", it.group_name, it.group_id);
            todo_items.push_back(it);
        }
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
