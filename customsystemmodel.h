#ifndef CUSTOMSYSTEMMODEL_H
#define CUSTOMSYSTEMMODEL_H

#include <QFileSystemModel>



class customSystemModel : public QFileSystemModel
{
    Q_OBJECT
    QString print_attribs(const QModelIndex& ) const;
    QString print_name(const QModelIndex&) const;
    int columnCount(const QModelIndex&) const;
    QVariant data(const QModelIndex&,int) const;
    QVariant headerData(int, Qt::Orientation, int) const;
};

#endif // CUSTOMSYSTEMMODEL_H
