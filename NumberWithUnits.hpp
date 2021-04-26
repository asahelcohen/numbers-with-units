#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
using namespace std;

namespace ariel
{
    static std::map<string, map<string, double>> rates;

    class NumberWithUnits
    {
    private:
        double num;
        std::string type;

    public:
        NumberWithUnits(double d, std::string typo);

        static void read_units(std::ifstream&);

        friend NumberWithUnits operator+(const NumberWithUnits &a, const NumberWithUnits &b);
        friend NumberWithUnits operator-(const NumberWithUnits &a, const NumberWithUnits &b);
        NumberWithUnits& operator+=(const NumberWithUnits &a);
        NumberWithUnits& operator-=(const NumberWithUnits &a);
        friend NumberWithUnits operator+(const NumberWithUnits &a);
        friend NumberWithUnits operator-(const NumberWithUnits &a);

        bool operator==(const NumberWithUnits &a) const;
        bool operator!=(const NumberWithUnits &a) const;
        bool operator<(const NumberWithUnits &a) const;
        bool operator>(const NumberWithUnits &a) const;
        bool operator>=(const NumberWithUnits &a) const;
        bool operator<=(const NumberWithUnits &a) const;

        NumberWithUnits& operator ++ ();      // prefix  - ++a
		NumberWithUnits  operator ++ (int);   // postfix - a++
        NumberWithUnits& operator -- ();      // prefix  - ++a
		NumberWithUnits  operator -- (int);   // postfix - a++

        friend NumberWithUnits operator*(const NumberWithUnits &a, const double d);
        friend NumberWithUnits operator*(const double d, const NumberWithUnits &a);

        friend std::ostream& operator <<	(std::ostream &os, const NumberWithUnits &unit);
		friend std::istream& operator >>	(std::istream &is, NumberWithUnits &unit);


        ~NumberWithUnits(){};
    };
}