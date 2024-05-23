#include "todo_title_model.hpp"
#include <spdlog/spdlog.h>
#include "duck_service.hpp"

namespace Model {
    TodoTitleModel::TodoTitleModel(QObject *object)
    : QAbstractListModel(object),update_time(new QTimer(this)) {
        spdlog::info("TodoTitleModel::TodoTitleModel");
        refreshItems();
        //初始化update_time， 30s刷新一次列表
        connect(update_time, &QTimer::timeout, this, &TodoTitleModel::refreshItems);
        update_time->start(30000);
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
        }else if(role == TodoGroupFinishTime){
            return QVariant{item.finish_time.data()};
        }
        return {};
    }

    QHash<int, QByteArray> TodoTitleModel::roleNames() const {
        QHash<int, QByteArray> roles;
        roles[TodoGroupId] = "group_id";
        roles[TodoGroupCategory] = "group_category";
        roles[TodoGroupName] = "group_name";
        roles[TodoGroupFinishTime] = "group_finish_time";
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

//    void TodoTitleModel::addItem(const TodoStructure::TodoGroupInfo &item) {
//        beginInsertRows(QModelIndex(), rowCount(), rowCount());
//        todo_items.append(item);
//        endInsertRows();
//    }

    void TodoTitleModel::updateItem(int index, const TodoStructure::TodoGroupInfo &item) {
        if (index < 0 || index >= todo_items.size())
            return;

        todo_items[index] = item;
        emit dataChanged(this->index(index), this->index(index));
    }

    void TodoTitleModel::refreshItems() {
        spdlog::info("TodoTitleModel::refreshItems");
        const auto data = Service::DuckDatabase::get_instance().get_group_info();
        if(data.empty()){
            spdlog::info("group info without data");
        }
        for(const auto& it : data){
            spdlog::info("add group to list model: {}--{}", it.group_name, it.group_id);
            todo_items.push_back(it);
        }
    }

    TodoTitleModel::~TodoTitleModel() {
        delete update_time;
        update_time = nullptr;
    }

} // Model
