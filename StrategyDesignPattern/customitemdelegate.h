#ifndef CUSTOMITEMDELEGATE_H
#define CUSTOMITEMDELEGATE_H

#include <QObject>
#include <QStyledItemDelegate>
#include <QPainter>

class CustomItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit CustomItemDelegate(QObject *parent = nullptr);
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
signals:

};

#endif // CUSTOMITEMDELEGATE_H
