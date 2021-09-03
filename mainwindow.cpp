#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_getDirButton_clicked()
{
    QString dir_path = QFileDialog::getExistingDirectory(this, tr("Open Directory"), "/home", QFileDialog::ShowDirsOnly| QFileDialog::DontResolveSymlinks);
    customSystemModel *model = new customSystemModel;
    model->setRootPath(dir_path);
    ui->treeView->setModel(model);
    ui->treeView->setRootIndex(model->index(dir_path));
    for(int i = 0; i < 6; i++)
    {
        ui->treeView->header()->setSectionResizeMode(i, QHeaderView::ResizeToContents);
    }
}




























//QTextStream out(stdout);

//QString fileSize(qint64 nSize) {
//  qint64 i = 0;
//  for (; nSize > 1023; nSize /= 1024, ++i) { }
//  return QString().setNum(nSize) + "BKMGT"[i];
//}
//QString isTXT(QString file)
//{
//    if (file.contains(".txt", Qt::CaseInsensitive))
//    {
//        QString name = file;
//        return name.replace(".txt", "#.txt");
//    }
//    else return file;
//}
//    QDirIterator it(dir_path, QDir::NoFilter, QDirIterator::Subdirectories);
//    while (it.hasNext())
//    {
//        it.next();
//        if (it.fileName() == "." || it.fileName() == "..")
//          continue;
//        QFileInfo info = it.fileInfo();
//        QString name = isTXT(info.fileName());
//        out  << name << " | " << fileSize(info.size()) << " | "
//               << info.lastModified().toString() << " | ";
//        print_attribs(info, out);
//        out << "\n";
//      }
