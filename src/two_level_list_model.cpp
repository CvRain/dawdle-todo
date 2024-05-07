//
// Created by cvrain on 24-5-7.
//

#include "two_level_list_model.hpp"

namespace Model {

    TwoLevelListModel::TwoLevelListModel(QObject *parent) : QAbstractListModel(parent) {
        QMap<QString, QVariant> data1{{"level1", "Level 1 Heading 1"}, {"level2", QStringList{"Level 2 Heading 1.1", "Level 2 Heading 1.2", "Level 2 Heading 1.3"}}};
        model_data.append(QVariant(data1));

        QMap<QString, QVariant> data2{{"level1", "Level 1 Heading 2"}, {"level2", QStringList{"Level 2 Heading 2.1", "Level 2 Heading 2.2"}}};
        model_data.append(QVariant(data2));

        QMap<QString, QVariant> data3{{"level1", "Level 1 Heading 3"}, {"level2", QStringList{"Level 2 Heading 3.1", "Level 2 Heading 3.2", "Level 2 Heading 3.3", "Level 2 Heading 3.4"}}};
        model_data.append(QVariant(data3));

    }

    int TwoLevelListModel::rowCount(const QModelIndex &parent) const {
        return static_cast<int>(model_data.count());
    }

    QVariant TwoLevelListModel::data(const QModelIndex &index, int role) const {
        if (index.isValid() && role == Level1Role) {
            return model_data[index.row()].toMap().value(QStringLiteral("level1"));
        } else if (index.isValid() && role == Level2Role) {
            return model_data[index.row()].toMap().value(QStringLiteral("level2"));
        }
        return {};
    }

    QHash<int, QByteArray> TwoLevelListModel::roleNames() const {
        QHash<int, QByteArray> roles;
        roles[Level1Role] = "level1";
        roles[Level2Role] = "level2";
        return roles;
    }
}