#include "model.h"
#include "QString"

Model::Model()
{

}

void Model::setNum1(int num1){
    this->num1 = num1;
}

void Model::setNum2(int num2){
    this->num2 = num2;
}

void Model::setFlag(QString flag){
    this->flag = flag;
}

QString Model::doCacl(){
    QString flag = this->flag;
    int result = 0;
    if(flag == "+"){
        result = this->num1 + this->num2;
    }else if (flag == "-") {
        result = this->num1 - this->num2;
    }else if (flag == "*") {
        result = this->num1 * this->num2;
    }else if (flag == "/") {
        result = this->num1 / this->num2;
    }else {
        result = this->num1;
    }
    QString num ;
    num.setNum(result);
    return num;
}
