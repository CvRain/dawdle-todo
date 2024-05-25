#ifndef DAWDLE_TODO_TODO_TITLE_MODEL_HPP
#define DAWDLE_TODO_TODO_TITLE_MODEL_HPP

#include <QObject>
#include <QString>
#include <QAbstractListModel>
#include <QHash>
#include <QTimer>

#include "todo_structure.hpp"
#include "todo_manager.hpp"

#include <memory>

namespace Model {
    class TodoTitleModel : public QAbstractListModel {
    Q_OBJECT

    public:
        explicit TodoTitleModel(QObject *object = nullptr);

        ~TodoTitleModel() override;

        enum {
            TodoGroupName = Qt::UserRole + 1,
            TodoGroupId,
            TodoGroupCategory,
            TodoGroupFinishTime
        };

        [[nodiscard]] int rowCount(const QModelIndex &parent) const override;

        [[nodiscard]] QVariant data(const QModelIndex &index, int role) const override;

        [[nodiscard]] QHash<int, QByteArray> roleNames() const override;

        Q_INVOKABLE void remove(int index);

        void refreshItems();

        void connectToTodoManager(Controller::TodoManager* todoManager);

    public slots:
        void updateItem(int index, const TodoStructure::TodoGroupInfo &item);
        void handleNewGroup(const TodoStructure::TodoGroupInfo& groupInfo);
    private:
        QList<TodoStructure::TodoGroupInfo> todo_items;
        Controller::TodoManager* todo_manager;
        QTimer *update_time;
    };

} // Model

#endif //DAWDLE_TODO_TODO_TITLE_MODEL_HPP
