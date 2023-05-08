//
// Created by david on 4/27/2023.
//
#include <iostream>
#include <numeric>
//#include <sstream>
//#include <algorithm>
#include <cmath>
#include "Fraction.hpp"

using namespace std;
namespace ariel {
    Fraction::Fraction() {
        this->numerator = 0;
        this->denominator = 1;
    }

    Fraction::Fraction(int numerator, int denominator) {
        if (numerator < 0 && denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        } else if (numerator > 0 && denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }
        int gcdNum = gcd(numerator, denominator);
        if (denominator == 0) {
            throw invalid_argument("denominator can not be 0!\n");
        }
        if (numerator == 0) {
            this->denominator = 1;
            this->numerator = 0;
        } else {
            this->denominator = denominator / gcdNum;
            this->numerator = numerator / gcdNum;
        }

    }

    Fraction::Fraction(float floatNum) {
        int numeratorNew = (int) (floatNum * 1000);
        int denominatorNew = 1000;
        int gcdNum = gcd(numeratorNew, denominatorNew);
        setDenominator(denominatorNew / gcdNum);
        setNumerator(numeratorNew / gcdNum);
    }


    int Fraction::getNumerator() const {
        return this->numerator;
    }

    int Fraction::getDenominator() const {
        return this->denominator;
    }

    void Fraction::setNumerator(int numeratorNew) {
        if (numeratorNew == 0) {
            this->denominator = 1;
        }
        this->numerator = numeratorNew;
    }

    void Fraction::setDenominator(int denominator) {
        if (numerator < 0 && denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        } else if (numerator > 0 && denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }
        if (denominator == 0) {
            throw runtime_error("denominator can not be 0!\n");
        } else {
            this->denominator = denominator;
        }
    }

    Fraction Fraction::operator+(const Fraction &fraction) const {
        int max_int = std::numeric_limits<int>::max();
        int min_int = std::numeric_limits<int>::min();
        if (((max_int * 1.0 / this->numerator) / fraction.denominator < 1) &&
            ((max_int * 1.0 / this->numerator) / fraction.denominator > -1) ||
            ((max_int * 1.0 / this->denominator) / fraction.denominator < 1) &&
            ((max_int * 1.0 / this->denominator) / fraction.denominator > -1) ||
            ((max_int * 1.0 / fraction.numerator) / this->denominator < 1) &&
            ((max_int * 1.0 / fraction.numerator) / this->denominator > -1))
            throw overflow_error("adding this fractions will result in overflow");
        int newNum = this->numerator * fraction.denominator;
        int newDeno = this->denominator * fraction.denominator;
        int secondNum = fraction.numerator * this->denominator;
        if (newNum > 0 && max_int - newNum < secondNum || newNum < 0 && min_int - newNum > secondNum) {
            throw overflow_error("adding this fractions will result in overflow");
        }
        return Fraction(newNum + secondNum, newDeno);
    }


    Fraction operator+(const float float_num, const Fraction &fraction) {
        Fraction newFraction(float_num);
        return newFraction + fraction;
    }

    Fraction operator+(const Fraction &fraction, const float float_num) {
        Fraction newFraction(float_num);
        return fraction + newFraction;
    }


    Fraction Fraction::operator-(const Fraction &fraction) const {
        int max_int = std::numeric_limits<int>::max();
        int min_int = std::numeric_limits<int>::min();
        if (((max_int * 1.0 / this->numerator) / fraction.denominator < 1) &&
            ((max_int * 1.0 / this->numerator) / fraction.denominator > -1) ||
            ((max_int * 1.0 / this->denominator) / fraction.denominator < 1) &&
            ((max_int * 1.0 / this->denominator) / fraction.denominator > -1) ||
            ((max_int * 1.0 / fraction.numerator) / this->denominator < 1) &&
            ((max_int * 1.0 / fraction.numerator) / this->denominator > -1))
            throw overflow_error("subtracting these fractions will result in overflow");

        int newNum = this->numerator * fraction.denominator;
        int newDeno = this->denominator * fraction.denominator;
        int secondNum = fraction.numerator * this->denominator;
        if (newNum > 0 && max_int - newNum < -secondNum ||
            newNum < 0 && min_int - newNum > -secondNum)
            throw overflow_error("subtracting these fractions will result in overflow");
        return Fraction(newNum - secondNum, newDeno);
    }

    Fraction operator-(const float float_num, const Fraction &fraction) {
        Fraction newFraction(float_num);
        return newFraction - fraction;
    }

    Fraction operator-(const Fraction &fraction, const float float_num) {
        Fraction newFraction(float_num);


        return fraction - newFraction;
    }

    Fraction Fraction::operator*(const Fraction &fraction) const {
        int max_int = std::numeric_limits<int>::max();
        if (((max_int * 1.0 / this->numerator) / fraction.numerator < 1) &&
            ((max_int * 1.0 / this->numerator) / fraction.numerator > -1) ||
            ((max_int * 1.0 / this->denominator) / fraction.denominator < 1) &&
            ((max_int * 1.0 / this->denominator) / fraction.denominator > -1))
            throw overflow_error("multiplying this fractions will result in overflow");
        return Fraction(this->numerator * fraction.numerator, this->denominator * fraction.denominator);
    }

    Fraction operator*(const Fraction &fraction, const float float_num) {
        Fraction newFraction(float_num);
        return fraction * newFraction;
    }

    Fraction operator*(const float float_num, const Fraction &fraction) {
        Fraction newFraction(float_num);
        return newFraction * fraction;
    }

    Fraction Fraction::operator/(const Fraction &fraction) const {
        if (fraction.numerator == 0) {
            throw runtime_error("denominator can not be eqaul to zero");
        }
        int max_int = std::numeric_limits<int>::max();
        if (((max_int * 1.0 / this->numerator) / fraction.denominator < 1) &&
            ((max_int * 1.0 / this->numerator) / fraction.denominator > -1) ||
            ((max_int * 1.0 / this->denominator) / fraction.numerator < 1) &&
            ((max_int * 1.0 / this->denominator) / fraction.numerator > -1))
            throw overflow_error("dividing these fractions will result in overflow");
        return Fraction(this->numerator * fraction.denominator, this->denominator * fraction.numerator);
    }

    Fraction operator/(const Fraction &fraction, float float_num) {
        Fraction newFraction(float_num);
        return fraction / newFraction;
    }

    Fraction operator/(float float_num, const Fraction &fraction) {
        Fraction newFraction(float_num);
        return newFraction / fraction;
    }

    bool Fraction::operator==(const Fraction &fraction) const {
        if ((this->numerator == fraction.numerator) && (this->denominator == fraction.denominator)) {
            return true;
        } else {
            return false;
        }
    }

    bool operator==(const Fraction &fraction, float float_num) {
        Fraction newFraction(float_num);
        return fraction == newFraction;
    }

    bool operator==(float float_num, const Fraction &fraction) {
        Fraction newFraction(float_num);
        return fraction == newFraction;
    }

    bool Fraction::operator!=(const Fraction &fraction) const {
        if ((this->numerator == fraction.numerator) && (this->denominator == fraction.denominator)) {
            return false;
        } else {
            return true;
        }
    }

    bool operator!=(const Fraction &fraction, float float_num) {
        Fraction newFraction(float_num);
        return fraction != newFraction;
    }

    bool operator!=(float float_num, const Fraction &fraction) {
        Fraction newFraction(float_num);
        return fraction != newFraction;
    }

    bool Fraction::operator>(const Fraction &fraction) const {
        if (((1.0 * this->numerator) / this->denominator) > ((1.0 * fraction.numerator) / fraction.denominator)) {
            return true;
        } else {
            return false;
        }
    }

    bool operator>(const Fraction &fraction, float float_num) {
        Fraction newFraction(float_num);
        return fraction > newFraction;
    }

    bool operator>(float float_num, const Fraction &fraction) {
        Fraction newFraction(float_num);
        return newFraction > fraction;
    }


    bool Fraction::operator<(const Fraction &fraction) const {
        if (((1.0 * this->numerator) / this->denominator) < ((1.0 * fraction.numerator) / fraction.denominator)) {
            return true;
        } else {
            return false;
        }
    }

    bool operator<(const Fraction &fraction, float float_num) {
        Fraction newFraction(float_num);
        return fraction < newFraction;
    }

    bool operator<(float float_num, const Fraction &fraction) {
        Fraction newFraction(float_num);
        return newFraction < fraction;
    }

    bool Fraction::operator>=(const Fraction &fraction) const {
        if (*this > fraction || *this == fraction) {
            return true;
        } else {
            return false;
        }
    }

    bool operator>=(float float_num, const Fraction &fraction) {
        Fraction newFraction(float_num);
        return newFraction >= fraction;
    }

    bool operator>=(const Fraction &fraction, float float_num) {
        Fraction newFraction(float_num);
        return fraction >= newFraction;
    }

    bool Fraction::operator<=(const Fraction &fraction) const {
        if (*this < fraction || *this == fraction) {
            return true;
        } else {
            return false;
        }
    }

    bool operator<=(float float_num, const Fraction &fraction) {
        Fraction newFraction(float_num);
        return newFraction <= fraction;
    }

    bool operator<=(const Fraction &fraction, float float_num) {
        Fraction newFraction(float_num);
        return fraction <= newFraction;
    }

    Fraction &Fraction::operator++() {
        this->numerator += this->denominator;
        return *this;
    }

    Fraction Fraction::operator++(int) {
        Fraction newFraction = *this;
        this->numerator += this->denominator;
        return newFraction;
    }

    Fraction &Fraction::operator--() {
        this->numerator -= this->denominator;
        return *this;
    }

    Fraction Fraction::operator--(int) {
        Fraction newFraction = *this;
        this->numerator -= this->denominator;
        return newFraction;
    }

    std::ostream &operator<<(std::ostream &output, const Fraction &fraction) {
        return (output << fraction.getNumerator() << '/' << fraction.getDenominator());
    }

    std::istream &operator>>(std::istream &input, Fraction &fraction) {
        int numerator, denominator;
        if (input >> numerator >> denominator) {
            if (denominator == 0) {
                throw runtime_error("denominator can not be 0!!");
            }
            fraction = Fraction(numerator, denominator);
        } else {
            throw runtime_error("ERROR in input");
        }
        return input;
    }


}
