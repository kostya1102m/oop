#include "shopwindow.h"
#include "ui_shopwindow.h"
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
    this->setColumnCount(6);

    this->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // чтоб таблица была полностью видна

    QStringList nameColumn = {"Название" , "Количество" , "Цена" , "В корзине",""};
    this->setHorizontalHeaderLabels(nameColumn);



    this->setEditTriggers(QAbstractItemView::NoEditTriggers); //блокировка ячеек

    for (int i = 0; i < products.size(); ++i) {
        QTableWidgetItem *itemName = new QTableWidgetItem(products[i].getName());
        QTableWidgetItem *itemAmount = new QTableWidgetItem(QString::number(products[i].getAmount()));
        QTableWidgetItem *itemPrice = new QTableWidgetItem(QString::number(products[i].getPrice()));
        QTableWidgetItem *itemPicked = new QTableWidgetItem(QString::number(0));

        QPushButton* buttonPlus = new QPushButton("+");
        QPushButton* buttonMinus = new QPushButton("-");

        // Создаем новый объект, который будет хранить данные строки, чтобы быть переданным в слоты
        QSignalMapper* signalMapperPlus = new QSignalMapper(this);
        QSignalMapper* signalMapperMinus = new QSignalMapper(this);

        // Устанавливаем маппинг для каждой кнопки
        signalMapperPlus->setMapping(buttonPlus, i);
        signalMapperMinus->setMapping(buttonMinus, i);

        // Соединяем сигналы нажатия кнопок с мапперами
        connect(buttonPlus, SIGNAL(clicked()), signalMapperPlus, SLOT(map()));
        connect(buttonMinus, SIGNAL(clicked()), signalMapperMinus, SLOT(map()));

        // Соединяем мапперы со слотами
        connect(signalMapperPlus, SIGNAL(mapped(int)), this, SLOT(on_buttonPlus_clicked(int)));
        connect(signalMapperMinus, SIGNAL(mapped(int)), this, SLOT(on_buttonMinus_clicked(int)));


        this->setItem(i, 0, itemName);
        this->setItem(i, 1, itemAmount);
        this->setItem(i, 2, itemPrice);
        this->setItem(i, 3, itemPicked);
        this->setCellWidget(i, 4, buttonPlus);
        this->setCellWidget(i, 5, buttonMinus);
    }

}
void shopwindow::setusername(QString const &name){
    this->username = name;
}
void shopwindow::on_buttonPlus_clicked(int row) {
    uint currentPicked = this->item(row, 3)->text().toInt();
    uint availableAmount = this->item(row, 1)->text().toInt(); // Получаем доступное количество товара
    if (currentPicked < availableAmount || (currentPicked+availableAmount == products[row].getAmount() && availableAmount > 0)) {
        this->item(row, 3)->setText(QString::number(currentPicked + 1)); // Увеличиваем количество выбранных товаров
        this->item(row, 1)->setText(QString::number(availableAmount - 1));
    }
}

void shopwindow::on_buttonMinus_clicked(int row) {
    uint currentPicked = this->item(row, 3)->text().toInt();
    uint availableAmount = this->item(row, 1)->text().toInt();
    if (currentPicked > 0) {
        this->item(row, 3)->setText(QString::number(currentPicked - 1)); // Уменьшаем количество выбранных товаров
        this->item(row, 1)->setText(QString::number(availableAmount + 1));
    }
}
void shopwindow::resetTable() {
    uint totalItems = this->rowCount();
    for (uint i = 0; i < totalItems; ++i) {
        this->item(i, 1)->setText(QString::number(this->products[i].getAmount())); // Восстанавливаем количество товаров на складе
        this->item(i, 3)->setText(QString::number(0)); // Сбрасываем количество выбранных товаров в корзине
    }
}
void shopwindow::on_buttonconfirm_clicked() {
    QFile file("C:/Users/meriglo/Desktop/vs/qt/shop/check.txt");
    QTextStream stream(&file);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        stream << "Имя покупателя: " + username + "\n";
        uint totalItems = this->rowCount(); // Получаем общее количество товаров
        uint total = 0;
        for (uint i = 0; i < totalItems; ++i) {
            uint pickedAmount = this->item(i, 3)->text().toInt(); // Получаем количество выбранных товаров
            if (pickedAmount > 0) {
                QString itemName = this->products[i].getName(); // Получаем название товара
                uint itemPrice = this->products[i].getPrice(); // Получаем цену товара
                uint totalPrice = pickedAmount * itemPrice; // Вычисляем общую стоимость товара
                total +=totalPrice;
                // Выполняем действия для подтверждения покупки, например, выводим информацию о товаре и его стоимости
                stream << "\nТовар: " + itemName + ", Количество: " + QString::number(pickedAmount) + " $ Общая стоимость за позицию : " + QString::number(totalPrice);
            }
        }
        if(total == 0){
            QMessageBox::information(this,"Ошибка", "Корзина пуста - выберите товар");
            return;
        }
        else{
            QMessageBox::information(this,"Успешная покупка", "Покупка совершена - подробная информация в чеке");
            stream <<"\n Cумма чека: " + QString::number(total);
        }
    }



    resetTable();
}

