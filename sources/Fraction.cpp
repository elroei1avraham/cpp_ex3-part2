#include "Fraction.hpp"
#include <iostream>
#include <algorithm>

#include <cmath>
#include <numeric>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <climits>
using namespace ariel;
using namespace std;

// constractor
Fraction ::Fraction(int numerator, int denominator)
{
    if (denominator == 0)
    {
        throw invalid_argument("the denominator impossible 0");
    }
    if((numerator<0 && denominator<0) || (denominator<0)){
        this->numerator = numerator*(-1);
        this->denominator = denominator*(-1);        
    } 
    this->numerator = numerator;
    this->denominator = denominator;
    reduce();
};

Fraction ::Fraction(float number)
{
    long long numerator = number * 1000;
    long long denominator = 1000;
    // int gcd = std::gcd(numerator, denominator);
    // this->denominator = denominator/gcd;
    // this->numerator = numerator/gcd;
    reduce(numerator, denominator);
}

Fraction ::Fraction()
{
    this->numerator = 0;
    this->denominator = 1;
}

// Auxiliary functions
void Fraction::reduce(int numerator, int denominator)
{
    int gcd = std::gcd(numerator, denominator);
    this->denominator = denominator / gcd;
    this->numerator = numerator / gcd;
}

// Auxiliary functions
void Fraction::reduce()
{
    int gcd = std::gcd(this->numerator, this->denominator);
    this->denominator = this->denominator / gcd;
    this->numerator = this->numerator / gcd;
}

int Fraction ::getNumerator() const
{
    return this->numerator;
}

int Fraction ::getDenominator() const
{
    return this->denominator;
}

void Fraction ::setNumerator(int numerator)
{
    this->numerator = numerator;
}

void Fraction ::setDenominator(int denominator)
{
    this->denominator = denominator;
}

Fraction Fraction ::operator+(const Fraction &fraction) const
{
    long long tempNumerator = ((long long)(this->denominator * fraction.numerator) + (long long)(this->numerator * fraction.denominator));
    long long tempDenominator = (long long)(this->denominator * fraction.denominator);
    if (tempNumerator > INT_MAX ||
        tempNumerator < INT_MIN ||
        tempDenominator > INT_MAX ||
        tempDenominator < INT_MIN)
    {
        throw overflow_error("error, the franction is too big or too small");
    }
    Fraction newFraction(tempNumerator, tempDenominator);
    return newFraction;
};

Fraction Fraction ::operator-(const Fraction &fraction) const
{
    long long tempNumerator = ((long long)this->numerator * fraction.denominator - (long long)this->denominator * fraction.numerator);
    long long tempDenominator = ((long long)this->denominator * fraction.denominator);

    if (tempNumerator > INT_MAX ||
        tempNumerator < INT_MIN ||
        tempDenominator > INT_MAX ||
        tempDenominator < INT_MIN)
    {
        throw overflow_error("error, the franction is too big or too small");
    }
    Fraction newFraction(tempNumerator, tempDenominator);
    return newFraction;
};

Fraction Fraction ::operator/(const Fraction &fraction) const
{
    if(fraction.getNumerator() == 0)
    {
        throw runtime_error("the denominator impossible 0");
    }
    Fraction temp (fraction.getDenominator() , fraction.getNumerator());
    return *this*temp;
};

Fraction Fraction ::operator*(const Fraction &fraction) const
{
    long long tempNumerator = (long long)this->numerator * (long long)fraction.numerator;
    long long tempDenominator =(long long)this->denominator * (long long)fraction.denominator;

    if (tempNumerator > INT_MAX ||
        tempNumerator < INT_MIN ||
        tempDenominator > INT_MAX ||
        tempDenominator < INT_MIN)
    {
        throw overflow_error("error, the franction is too big or too small");
    }
    Fraction newFraction((int)tempNumerator, (int)tempDenominator);
    return newFraction;
};

Fraction Fraction ::operator+(float number) const
{
    Fraction a(number);
    Fraction temp = *this + a;
    temp.reduce();
    if (temp.getDenominator() > INT_MAX ||
        temp.getDenominator() < INT_MIN ||
        temp.getNumerator() > INT_MAX ||
        temp.getNumerator() < INT_MIN)
    {
        throw overflow_error("error, the franction is too big or too small");
    }
    return temp;
};

Fraction Fraction ::operator-(float number) const
{
    Fraction a(number);
    a.reduce();
    return *this-a;
};

Fraction Fraction ::operator/(float number) const
{
    if(number == 0)
    {
        throw runtime_error("the denominator impossible 0");
    }
    Fraction a(number);
    return *this/a;
};

Fraction Fraction ::operator*(float number) const
{
    Fraction a(number);
    Fraction temp = *this * a;
    temp.reduce();
    if (temp.getDenominator() > INT_MAX ||
        temp.getDenominator() < INT_MIN ||
        temp.getNumerator() > INT_MAX ||
        temp.getNumerator() < INT_MIN)
    {
        throw overflow_error("error, the franction is too big or too small");
    }
    return temp;
};

Fraction operator+(float number, const Fraction &fraction)
{
    Fraction a(number);
    Fraction temp = a + fraction;
    temp.reduce();
    if (temp.getDenominator() > INT_MAX ||
        temp.getDenominator() < INT_MIN ||
        temp.getNumerator() > INT_MAX ||
        temp.getNumerator() < INT_MIN)
    {
        throw overflow_error("error, the franction is too big or too small");
    }
    return temp;
};

Fraction operator-(float number, const Fraction &fraction)
{
    Fraction a(number);
    Fraction temp = a- fraction;
    temp.reduce();
    if (temp.getDenominator() > INT_MAX ||
        temp.getDenominator() < INT_MIN ||
        temp.getNumerator() > INT_MAX ||
        temp.getNumerator() < INT_MIN)
    {
        throw overflow_error("error, the franction is too big or too small");
    }
    return temp;
};

Fraction operator/(float number, const Fraction &fraction)
{
    Fraction a(number);
    Fraction temp = a / fraction;
    temp.reduce();
    if (temp.getDenominator() > INT_MAX ||
        temp.getDenominator() < INT_MIN ||
        temp.getNumerator() > INT_MAX ||
        temp.getNumerator() < INT_MIN)
    {
        throw overflow_error("error, the franction is too big or too small");
    }
    return temp;
};

Fraction operator*(float number, const Fraction &fraction)
{
    Fraction a(number);
    Fraction temp = a * fraction;
    temp.reduce();
    if (temp.getDenominator() > INT_MAX ||
        temp.getDenominator() < INT_MIN ||
        temp.getNumerator() > INT_MAX ||
        temp.getNumerator() < INT_MIN)
    {
        throw overflow_error("error, the franction is too big or too small");
    }
    return temp;
};

Fraction &Fraction ::operator++()
{
    this->setNumerator(this->getNumerator() + this->getDenominator());
    if (this->getNumerator() > INT_MAX ||
        this->getNumerator() < INT_MIN)
    {
        throw overflow_error("error, the franction is too big or too small");
    }
    return *this;
};

Fraction &Fraction ::operator--()
{
    this->setNumerator(this->getNumerator() - this->getDenominator());
    if (this->getNumerator() > INT_MAX ||
        this->getNumerator() < INT_MIN)
    {
        throw overflow_error("error, the franction is too big or too small");
    }
    return *this;
};

Fraction Fraction ::operator++(int number)
{
    Fraction temp = *this;
    this->setNumerator(this->getNumerator() + this->getDenominator());
    if (this->getNumerator() > INT_MAX ||
        this->getNumerator() < INT_MIN)
    {
        throw overflow_error("error, the franction is too big or too small");
    }
    return temp;
};

Fraction Fraction ::operator--(int number)
{
    Fraction temp = *this;
    this->setNumerator(this->getNumerator() - this->getDenominator());
    if (this->getNumerator() > INT_MAX ||
        this->getNumerator() < INT_MIN)
    {
        throw overflow_error("error, the franction is too big or too small");
    }
    return temp;
};

bool Fraction ::operator>=(float number) const
{
    Fraction temp(number);
    return (*this>=temp);
};

bool Fraction ::operator>(float number) const
{
    Fraction temp(number);
    return (*this>temp);
};

bool Fraction ::operator<=(float number) const
{
    Fraction temp(number);
    return (*this<=temp);
};

bool Fraction ::operator<(float number) const
{
    Fraction temp(number);
    return (*this<temp);
};

bool Fraction ::operator==(float number) const
{
    Fraction temp(number);
    return ((*this>=temp) && (*this<=temp));
};

bool Fraction ::operator>=(const Fraction &fraction) const
{
    return !(*this < fraction);
};

bool Fraction ::operator>(const Fraction &fraction) const
{
    float number1 = (float)this->getNumerator() / this->getDenominator();
    number1 = (int)(number1 * 1000);
    number1 = (float)number1 / 1000;

    float number2 = (float)fraction.getNumerator() / fraction.getDenominator();
    number2 = (int)(number2 * 1000);
    number2 = (float)number2 / 1000;

    return number1 > number2;
};

bool Fraction ::operator<=(const Fraction &fraction) const
{
    return !(*this > fraction);
};

bool Fraction ::operator<(const Fraction &fraction) const
{
    float number1 = (float)this->getNumerator() / this->getDenominator();
    number1 = (int)(number1 * 1000);
    number1 = (float)number1 / 1000;

    float number2 = (float)fraction.getNumerator() / fraction.getDenominator();
    number2 = (int)(number2 * 1000);
    number2 = (float)number2 / 1000;

    return number1 < number2;
};

bool Fraction ::operator==(const Fraction &fraction) const
{
    return ((*this>=fraction) && (*this<=fraction));;
};

bool operator>=(float number, const Fraction &fraction)
{
    Fraction temp(number);
    return temp>=fraction;
};

bool operator>(float number, const Fraction &fraction)
{
    Fraction temp(number);
    return temp>fraction;
};

bool operator<=(float number, const Fraction &fraction)
{
    Fraction temp(number);
    return temp<=fraction;
};

bool operator<(float number, const Fraction &fraction)
{
    Fraction temp(number);
    return temp<fraction;
};

bool operator==(float number, const Fraction &fraction)
{
    Fraction temp(number);
    return temp==fraction;
};

ostream &operator<<(ostream &output, const Fraction &fraction)
{
    if(fraction.getDenominator()<0){
        return (output << fraction.getNumerator()*(-1) << '/' << fraction.getDenominator()*(-1));    
    }
    return (output << fraction.getNumerator() << '/' << fraction.getDenominator());
}

istream &operator>>(istream &input, Fraction &fraction)
{
    if (input.peek() == EOF)
    {
        throw std::runtime_error("no input detected");
    }
    int newNumerator;
    input >> newNumerator;
    
    if (input.peek() == EOF)
    {
        throw std::invalid_argument("invalid input");
    }
    int newDenominator;
    input >> newDenominator;

    if (newDenominator == 0)
        throw std::runtime_error("division by zero");
    
    if (newDenominator < 0 && newNumerator < 0)
    {
        newNumerator
 *= (-1);
        newDenominator *= (-1);
    }
    if (newDenominator < 0)
    {
        newDenominator *= (-1);
        newNumerator *= (-1);
    }
    
    fraction.setNumerator(newNumerator);
    fraction.setDenominator(newDenominator);
    return input;
}