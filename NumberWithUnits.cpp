#include "NumberWithUnits.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

namespace ariel
{
    NumberWithUnits::NumberWithUnits(double d, string typo)
    {
        num = d;
        type = std::move(typo);
    }
    void NumberWithUnits::read_units(ifstream &units_file)
    {
        if (units_file){

        }
    }

    NumberWithUnits operator+(NumberWithUnits &a, NumberWithUnits &b)
    {
        return a;
    }
    NumberWithUnits operator-(NumberWithUnits &a, NumberWithUnits &b)
    {
        return a;
    }
    NumberWithUnits& NumberWithUnits::operator+=(const NumberWithUnits &a)
    {
        return *this;
    }
    NumberWithUnits& NumberWithUnits::operator-=(const NumberWithUnits &a)
    {
        return *this;
    }
    NumberWithUnits operator+(const NumberWithUnits &a)
    {
        return a;
    }
    NumberWithUnits operator-(const NumberWithUnits &a)
    {
        return a;
    }

    bool NumberWithUnits::operator==(const NumberWithUnits &a) const
    {
        return true;
    }
    bool NumberWithUnits::operator!=(const NumberWithUnits &a) const
    {
        return true;
    }
    bool NumberWithUnits::operator>=(const NumberWithUnits &a) const
    {
        return true;
    }
    bool NumberWithUnits::operator<=(const NumberWithUnits &a) const
    {
        return true;
    }
    bool NumberWithUnits::operator>(const NumberWithUnits &a) const
    {
        return true;
    }
    bool NumberWithUnits::operator<(const NumberWithUnits &a) const
    {
        return true;
    }

    NumberWithUnits &NumberWithUnits::operator++()
    {
        return *this;
    }
    NumberWithUnits NumberWithUnits::operator++(int)
    {
        return NumberWithUnits(1, "hi");
    }
    NumberWithUnits &NumberWithUnits::operator--()
    {
        return *this;
    }
    NumberWithUnits NumberWithUnits::operator--(int)
    {
        return NumberWithUnits(1, "hi");
    }

    NumberWithUnits operator*(const NumberWithUnits &a, const double d)
    {
        return NumberWithUnits(1, "hi");
    }
    NumberWithUnits operator*(const double d, const NumberWithUnits &a)
    {
        return NumberWithUnits(1, "hi");
    }

    ostream& operator <<  (ostream &os, const NumberWithUnits &f)
    {
        return os << f.num << "[" << f.type << "]";
    }

    istream& operator >>  (istream &is, NumberWithUnits &f)
    {
        return is;
    }

}