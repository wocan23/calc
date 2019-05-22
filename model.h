#ifndef MODEL_H
#define MODEL_H

#include "QString"

class Model
{
public:
    Model();
    void setNum1(int num1);
    void setNum2(int num2);
    void setFlag(QString);
    QString doCacl();
private:
    int num1;
    int num2;
    QString flag;

};

#endif // MODEL_H
