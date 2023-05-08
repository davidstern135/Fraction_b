//
// Created by david on 4/27/2023.
//
#pragma once
#include <iostream>

using namespace std;
namespace ariel{

    class Fraction{
    private:
        int numerator;
        int denominator;

    public:
        Fraction();
        Fraction(int numerator,int denominator);
//        Fraction(double doubleNum);
        Fraction(float floatNum);

        int getNumerator() const;
        int getDenominator() const;
        void setNumerator(int numeratorNew);
        void setDenominator(int denominatorNew);

        Fraction operator+(const Fraction& fraction) const;
        friend Fraction operator+(const Fraction& fraction,float float_num);
        friend Fraction operator+(float float_num, const Fraction& fraction);

//        friend Fraction operator+(const double double_num, const Fraction &fraction);
//        friend Fraction operator+(const Fraction &fraction, const double double_num);

        Fraction operator-(const Fraction& fraction) const;
        friend Fraction operator-(const Fraction& fraction,float float_num);
        friend Fraction operator-(float float_num,const Fraction& fraction);

        Fraction operator*(const Fraction& fraction) const;
        friend Fraction operator*(const Fraction& fraction,float float_num);
        friend Fraction operator*(float float_num,const Fraction& fraction);

        Fraction operator/(const Fraction& fraction) const;
        friend Fraction operator/(const Fraction& fraction,float float_num);
        friend Fraction operator/(float float_num,const Fraction& fraction);

        bool operator==(const Fraction& fraction) const;
        friend bool operator==(const Fraction& fraction,float float_num);
        friend bool operator==(float float_num,const Fraction& fraction);

        bool operator!=(const Fraction& fraction) const;
        friend bool operator!=(const Fraction& fraction,float float_num);
        friend bool operator!=(float float_num,const Fraction& fraction);

        bool operator>(const Fraction& fraction) const;
        friend bool operator>(const Fraction& fraction,float float_num);
        friend bool operator>(float float_num,const Fraction& fraction);

        bool operator<(const Fraction& fraction) const;
        friend bool operator<(const Fraction& fraction,float float_num);
        friend bool operator<(float float_num,const Fraction& fraction);

        bool operator>=(const Fraction& fraction) const;
        friend bool operator>=(const Fraction& fraction,float float_num);
        friend bool operator>=(float float_num,const Fraction& fraction);

        bool operator<=(const Fraction& fraction) const;
        friend bool operator<=(const Fraction& fraction,float float_num);
        friend bool operator<=(float float_num,const Fraction& fraction);

        Fraction& operator++();
        Fraction operator++(int);
        Fraction& operator--();
        Fraction operator--(int);

        friend std::ostream& operator<<(std::ostream& output, const Fraction& fraction);
        friend std::istream& operator>>(std::istream& input, Fraction& fraction);
    };
}

