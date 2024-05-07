//
// Created by cvrain on 24-5-7.
//

#ifndef DAWDLE_TODO_TWO_LEVEL_LIST_MODEL_HPP
#define DAWDLE_TODO_TWO_LEVEL_LIST_MODEL_HPP

#include <QString>
#include <QStringList>
#include <QAbstractListModel>

namespace Model {
    class TwoLevelListModel : public QAbstractListModel {
    Q_OBJECT

    public:
        enum Roles {
            Level1Role = Qt::UserRole + 1,
            Level2Role
        };

        explicit TwoLevelListModel(QObject *parent = nullptr);

        [[nodiscard]] int rowCount([[maybe_unused]]const QModelIndex &parent) const override;

        [[nodiscard]] QVariant data(const QModelIndex &index, int role) const override;

        [[nodiscard]] QHash<int, QByteArray> roleNames() const override;

    private:
        QList<QVariant> model_data;
    };
}


#endif //DAWDLE_TODO_TWO_LEVEL_LIST_MODEL_HPP
