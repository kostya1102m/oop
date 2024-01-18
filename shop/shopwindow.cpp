#include "shopwindow.h"
#include "ui_shopwindow.h"
#include <QDebug>
#include<QHBoxLayout>
#include<QPushButton>
#include <fstream>
#include <QFile>
shopwindow::shopwindow(QTableWidget *parent) //создаем окно как таблицу для удобной работы
    : QTableWidget(parent)
    , ui(new Ui::shopwindow)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowMinMaxButtonsHint);//блок свёртывания и сворачивания
    this->setWindowTitle("Магазин товаров");
}

shopwindow::~shopwindow()
{
    delete ui;
}
void shopwindow::readtxt()
{
    QFile file("C:/Users/meriglo/Desktop/vs/qt/shop/products.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList parts = line.split(" - ");
        if (parts.size() == 2)
        {
            QString productName = parts[0];
            QStringList priceAndAmount = parts[1].split(" $ ");
            if (priceAndAmount.size() == 2)
            {
                Product newproduct;
                QString priceStr = priceAndAmount[1];
                QString amountStr = priceAndAmount[0];

                newproduct.setName(productName);
                newproduct.setPrice(priceStr.toUInt());
                newproduct.setAmount(amountStr.toUInt());

                this->products.append(newproduct);
            }
        }
    }
    file.close();
}
void shopwindow::createshop(){

    this->readtxt();


    this->setRowCount(products.size());
    this->setColumnCount(5);

    this->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // чтоб таблица была полностью видна

    QStringList nameColumn = {"Название" , "Количество" , "Цена" , "В корзине","",""};
    this->setHorizontalHeaderLabels(nameColumn);


    QPushButton* button1 = new QPushButton("+");
    QPushButton* button2 = new QPushButton("-");
    QWidget* buttonWidget = new QWidget;
    QHBoxLayout* buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(button1);
    buttonLayout->addWidget(button2);
    buttonLayout->setAlignment(Qt::AlignCenter);  // Выравнивание кнопок по центру
    buttonWidget->setLayout(buttonLayout);

    this->setCellWidget(1, 4, buttonWidget);
    this->setEditTriggers(QAbstractItemView::NoEditTriggers); //блокировка ячеек

    for (int i = 0; i < products.size(); ++i) {
        QTableWidgetItem *itemName = new QTableWidgetItem(products[i].getName());
        QTableWidgetItem *itemAmount = new QTableWidgetItem(QString::number(products[i].getAmount()));
        QTableWidgetItem *itemPrice = new QTableWidgetItem(QString::number(products[i].getPrice()));
        QTableWidgetItem *itemPicked = new QTableWidgetItem(QString::number(0));

        this->setItem(i, 0, itemName);
        this->setItem(i, 1, itemAmount);
        this->setItem(i, 2, itemPrice);
        this->setItem(i, 3, itemPicked);
    }

}
void shopwindow::setusername(QString const &name){
    this->username = name;
}
