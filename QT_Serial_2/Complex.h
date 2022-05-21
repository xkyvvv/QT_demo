#ifndef COMPLEX_H
#define COMPLEX_H

/*---------------------
作者：fengyhack
        来源：CSDN
        原文：https://blog.csdn.net/fengyhack/article/details/42780785

*/
#ifndef INC_06_C_CODE_COMPLEX_H
#define INC_06_C_CODE_COMPLEX_H
#endif



#ifndef BOOLEAN_VAL
#define BOOLEAN_VAL
typedef int BOOL;
#define TRUE 1
#define FALSE 0
#endif


class Complex {

public:
    Complex();
    Complex(float re, float im);

    Complex operator=(float v);
    Complex operator+(float v);
    Complex operator-(float v);
    Complex operator*(float v);
    Complex operator/(float v);
    Complex operator+=(float v);
    Complex operator-=(float v);
    Complex operator*=(float v);
    Complex operator/=(float v);

    Complex operator=(Complex c);
    Complex operator+(Complex c);
    Complex operator-(Complex c);
    Complex operator*(Complex c);
    Complex operator/(Complex c);
    Complex operator+=(Complex c);
    Complex operator-=(Complex c);
    Complex operator*=(Complex c);
    Complex operator/=(Complex c);

    BOOL operator==(Complex c);
    BOOL operator!=(Complex c);

    float real;
    float imag;

};



#endif // COMPLEX_H
