#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowMinMaxButtonsHint);//блок свёртывания и сворачивания
    shop = new shopwindow();
    QWidget::setFixedSize(window()->width() , window()->height());
    this->setWindowTitle("Регистрация");
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_clicked()
{
    if(ui->lineEdit->text().isEmpty()){
        QMessageBox::information(this,"Ошибка", "Имя пользователя не введено");
        return;
    }
    QString userName = ui->lineEdit->text();
    shop->setusername(userName);
    shop->show();
    shop->createshop();
    this->close();
}

