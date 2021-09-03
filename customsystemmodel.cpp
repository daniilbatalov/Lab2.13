#include "customsystemmodel.h"

QString customSystemModel::print_attribs(const QModelIndex& index) const
{
  QString result;
    if (this->fileInfo(index).isReadable())
    result.append("R");
  if (this->fileInfo(index).isWritable())
    result.append("W");
  if (this->fileInfo(index).isHidden())
    result.append("H");
  if (this->fileInfo(index).isExecutable())
    result.append("E");
  return result;
}
QString customSystemModel::print_name(const QModelIndex& index) const
{
    if (this->fileInfo(index).fileName().contains(".txt", Qt::CaseInsensitive))
    {
        QString name = fileInfo(index).fileName();
        return name.replace(".txt", "#.txt");
    }
    else return fileInfo(index).fileName();
}
int customSystemModel::columnCount(const QModelIndex& parent = QModelIndex()) const
{
    return QFileSystemModel::columnCount() + 1;
}
QVariant customSystemModel::data(const QModelIndex& index,int role) const
{
   if(!index.isValid()){return QFileSystemModel::data(index,role);}
   if(index.column() == 0)
   {
       switch(role)
       {
          case(Qt::DisplayRole):
              {return print_name(index);}
          default:{}
       }
   }
   if(index.column() == columnCount()-1)
   {
       switch(role)
       {
          case(Qt::DisplayRole):
              {return print_attribs(index);}
          case(Qt::TextAlignmentRole):
              {return Qt::AlignLeft;}
          default:{}
       }
   }
   return QFileSystemModel::data(index,role);
}
QVariant customSystemModel::headerData(int section, Qt::Orientation orientation, int role) const
{

    if ((section == 4) && (role == Qt::DisplayRole)) {
        return "Attributes";
    } else {
        return QFileSystemModel::headerData(section,orientation,role);
    }
}
