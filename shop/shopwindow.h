#ifndef SHOPWINDOW_H
#define SHOPWINDOW_H

#include<QWidget>
#include<QString>
#include<QTableWidget>
#include<QDebug>
#include<QHBoxLayout>
#include<QPushButton>
#include<QSignalMapper>
#include<fstream>
#include<QFile>
#include<QMessageBox>
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

    void resetTable();
private slots:
    void on_buttonPlus_clicked(int row);
    void on_buttonMinus_clicked(int row);

    void on_buttonconfirm_clicked();

private:
    Ui::shopwindow *ui;
    QString username;
    QList<Product> products;
};

#endif // SHOPWINDOW_H
