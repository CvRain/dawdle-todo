#ifndef DAWDLE_TODO_TODO_TITLE_MODEL_HPP
#define DAWDLE_TODO_TODO_TITLE_MODEL_HPP

#include <QObject>
#include <QString>
#include <QAbstractListModel>
#include <QHash>

namespace Model {
    class TodoTitleModel : public QAbstractListModel {
        Q_OBJECT

    public:
        explicit TodoTitleModel(QObject *object = nullptr);

        enum {
            TodoThemeRole = Qt::UserRole + 1,
            TodoDescribeRole
        };

        [[nodiscard]] int rowCount(const QModelIndex &parent = QModelIndex()) const override;

        [[nodiscard]] QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

        [[nodiscard]] QHash<int, QByteArray>  roleNames() const override;

        void remove(int index);

    private:
        struct TodoTitleItem {
            QString theme;
            QString describe;
        };
        QList <TodoTitleItem> todo_items;
    };

} // Model

#endif //DAWDLE_TODO_TODO_TITLE_MODEL_HPP
