#include "customitemdelegate.h"

CustomItemDelegate::CustomItemDelegate(QObject *parent) : QStyledItemDelegate(parent)
{

}

void CustomItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    QStyledItemDelegate::paint(painter, option, index);
    // Tüm öğelerin arka plan rengini ayarla
    painter->fillRect(option.rect, QColor("#789461")); // Arka plan rengini hex koduyla belirtmek

    // Metin rengini beyaz yap
    painter->setPen(Qt::black);

    // Öğe metnini çiz
    QString text = index.data(Qt::DisplayRole).toString();
    painter->drawText(option.rect, Qt::AlignLeft, text);
}
