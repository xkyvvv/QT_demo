/*---------------------
作者：fengyhack
        来源：CSDN
        原文：https://blog.csdn.net/fengyhack/article/details/42780785

*/

#include "Complex.h"
Complex::Complex()
{
    real = 0;
    imag = 0;
}

Complex::Complex(float re, float im)
{
    real = re;
    imag = im;
}

Complex Complex::operator+(float v)
{
    return Complex(real + v, imag);
}

Complex Complex::operator-(float v)
{
    return Complex(real - v, imag);
}

Complex Complex::operator*(float v)
{
    return Complex(real*v, imag*v);
}

Complex Complex::operator/(float v)
{
    return Complex(real / v, imag / v);
}

Complex Complex::operator=(float v)
{
    real = v;
    imag = 0;
    return *this;
}

Complex Complex::operator+=(float v)
{
    real += v;
    return *this;
}

Complex Complex::operator-=(float v)
{
    real -= v;
    return *this;
}

Complex Complex::operator*=(float v)
{
    real *= v;
    imag *= v;
    return *this;
}

Complex Complex::operator/=(float v)
{
    real /= 2;
    imag /= 2;
    return *this;
}

Complex Complex::operator+(Complex c)
{
    return Complex(real + c.real, imag + c.imag);
}

Complex Complex::operator-(Complex c)
{
    return Complex(real - c.real, imag - c.imag);
}

Complex Complex::operator*(Complex c)
{
    float re = real*c.real - imag*c.imag;
    float im = real*c.imag + imag*c.real;
    return Complex(re, im);
}

Complex Complex::operator/(Complex c)
{
    float x = c.real;
    float y = c.imag;
    float f = x*x + y*y;
    float re = (real*x + imag*y) / f;
    float im = (imag*x - real*y) / f;
    return Complex(re, im);
}

Complex Complex::operator=(Complex c)
{
    real = c.real;
    imag = c.imag;
    return *this;
}

Complex Complex::operator+=(Complex c)
{
    real += c.real;
    imag += c.imag;
    return *this;
}

Complex Complex::operator-=(Complex c)
{
    real -= c.real;
    imag -= c.imag;
    return *this;
}

Complex Complex::operator*=(Complex c)
{
    float re = real*c.real - imag*c.imag;
    float im = real*c.imag + imag*c.real;
    real = re;
    imag = im;
    return *this;
}

Complex Complex::operator/=(Complex c)
{
    float x = c.real;
    float y = c.imag;
    float f = x*x + y*y;
    float re = (real*x + imag*y) / f;
    float im = (imag*x - real*y) / f;
    real = re;
    imag = im;
    return *this;
}

BOOL Complex::operator==(Complex c)
{
    return ((real == c.real) && (imag == c.imag));
}

BOOL Complex::operator!=(Complex c)
{
    return ((real != c.real) || (imag != c.imag));
}
