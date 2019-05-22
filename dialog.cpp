#include "dialog.h"
#include "ui_dialog.h"
#include "QtDebug"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(this->ui->num_0,&QPushButton::clicked,this,[=](){inputNum(0);});
    connect(this->ui->num_1,&QPushButton::clicked,this,[=](){inputNum(1);});
    connect(this->ui->num_2,&QPushButton::clicked,this,[=](){inputNum(2);});
    connect(this->ui->num_3,&QPushButton::clicked,this,[=](){inputNum(3);});
    connect(this->ui->num_4,&QPushButton::clicked,this,[=](){inputNum(4);});
    connect(this->ui->num_5,&QPushButton::clicked,this,[=](){inputNum(5);});
    connect(this->ui->num_6,&QPushButton::clicked,this,[=](){inputNum(6);});
    connect(this->ui->num_7,&QPushButton::clicked,this,[=](){inputNum(7);});
    connect(this->ui->num_8,&QPushButton::clicked,this,[=](){inputNum(8);});
    connect(this->ui->num_9,&QPushButton::clicked,this,[=](){inputNum(9);});
    connect(this->ui->btn_add,&QPushButton::clicked,this,[=](){inputSymbols("+");});
    connect(this->ui->btn_sub,&QPushButton::clicked,this,[=](){inputSymbols("-");});
    connect(this->ui->btn_mul,&QPushButton::clicked,this,[=](){inputSymbols("*");});
    connect(this->ui->btn_div,&QPushButton::clicked,this,[=](){inputSymbols("/");});
    connect(this->ui->btn_equal,&QPushButton::clicked,this,[=](){inputSymbols("=");});
    connect(this->ui->btn_clear,&QPushButton::clicked,this,[=](){inputSymbols("c");});
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::inputNum(int i){
    QString num = QString();
    num.setNum(i);
    if(this->lastSymbol == "="){
        this->tmp = "0";
        this->setLastSymbols("");
    }
    if(this->tmp != "0"){
        this->tmp += num;
    }else{
        this->tmp = num;
    }

    this->ui->num2->setText(tmp);
    qDebug() << num <<endl;

}

void Dialog::setLastSymbols(QString symbol){
    this->lastSymbol = symbol;
}

void Dialog::inputSymbols(QString symbol){
    QString flag = symbol;
    this->lastSymbol = flag;
    if("+" == symbol || "-" == symbol || "*" == symbol || "/" == symbol ) {
        this->model.setNum1(this->tmp.toInt());
        this->model.setFlag(symbol);
        this->ui->num1->setText(this->tmp);
//        this->ui->num2->setText("0");
        this->tmp = "0";
    }else if ("=" == symbol) {
        qDebug() << "num2::"<<this->tmp<<endl;
        this->model.setNum2(this->tmp.toInt());
        QString result = this->model.doCacl();
        this->tmp = result;
        qDebug() << "result::"<<result<<endl;
        this->ui->num1->setText(result);
    }else if ("c" == symbol) {
        this->model.setNum1(0);
        this->model.setNum2(0);
        this->ui->num1->setText("0");
        this->ui->num2->setText("0");
        this->tmp = "0";
    }




//    qDebug() <<flag<<endl;

}
