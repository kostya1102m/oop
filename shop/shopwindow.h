#ifndef SHOPWINDOW_H
#define SHOPWINDOW_H

#include <QWidget>
#include <QString>
#include <QHash>
#include <QList>
#include <QTableWidget>
#include <QStandardItemModel>
#include <QStringListModel>
#include <QModelIndex>
#include "product.h"
namespace Ui {
class shopwindow;
}

class shopwindow : public QTableWidget
{
    Q_OBJECT

public:
    shopwindow(QTableWidget *parent = nullptr);
    ~shopwindow();

    void readtxt();
    void createshop();
    void setusername(QString const &name);


private:
    Ui::shopwindow *ui;
    QString username;
    QList<Product> products;
};

#endif // SHOPWINDOW_H
