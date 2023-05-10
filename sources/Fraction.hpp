#pragma once
#include <string>
#include <iostream>

using namespace std;
namespace ariel
{
}
    class Fraction
    {
    private:
        int numerator;
        int denominator;

    public:
        Fraction(int numerator, int denominator);
        Fraction(float num);
        Fraction();
        void reduce(int numerator, int denominator);
        void reduce();
        int getNumerator() const;
        int getDenominator() const;
        void setNumerator(int numerator);
        void setDenominator(int denominator);
        Fraction operator+(const Fraction &fraction) const;
        Fraction operator-(const Fraction &fraction) const;
        Fraction operator/(const Fraction &fraction) const;
        Fraction operator*(const Fraction &fraction) const;
        Fraction operator+(float number) const;
        Fraction operator-(float number) const;
        Fraction operator/(float number) const;
        Fraction operator*(float number) const;
        friend Fraction operator+(float number, const Fraction &fraction);
        friend Fraction operator-(float number, const Fraction &fraction);
        friend Fraction operator/(float number, const Fraction &fraction);
        friend Fraction operator*(float, const Fraction &fraction);
        Fraction &operator++();
        Fraction operator++(int dummy);
        Fraction &operator--();
        Fraction operator--(int dummy);

        bool operator>=(float number)const;
        bool operator>(float number)const;
        bool operator<(float number) const;
        bool operator<=(float number) const;
        bool operator==(float number) const;
        bool operator<(const Fraction &fraction) const;
        bool operator<=(const Fraction &fraction) const;
        bool operator>(const Fraction &fraction) const;
        bool operator>=(const Fraction &fraction) const;
        bool operator==(const Fraction &fraction) const;
        friend bool operator<(float number, const Fraction &fraction);
        friend bool operator<=(float number, const Fraction &fraction);
        friend bool operator>(float number, const Fraction &fraction);
        friend bool operator>=(float number, const Fraction &fraction);
        friend bool operator==(float number, const Fraction &fraction);

        friend ostream &operator<<(ostream &output, const Fraction &fraction);
        friend istream &operator>>(istream &input, Fraction &fraction);
    };
