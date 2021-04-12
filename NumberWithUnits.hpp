#pragma once
#include <string>
#include <iostream>
#include <vector>

namespace ariel
{
    class NumberWithUnits
    {
    private:
        double num;
        string type;

    public:
        NumberWithUnits(){};

        void read_units(); //reads

        friend NumberWithUnits operator+(NumberWithUnits &a, NumberWithUnits &b);
        friend NumberWithUnits operator-(NumberWithUnits &a, NumberWithUnits &b);
        NumberWithUnits operator+=(const NumberWithUnits &a);
        NumberWithUnits operator-=(const NumberWithUnits &a);
        NumberWithUnits operator+(NumberWithUnits &a);
        NumberWithUnits operator-(NumberWithUnits &a);

        bool operator==(const NumberWithUnits &a) const;
        bool operator!=(const NumberWithUnits &a) const;
        bool operator<(const NumberWithUnits &a) const;
        bool operator>(const NumberWithUnits &a) const;
        bool operator>=(const NumberWithUnits &a) const;
        bool operator<=(const NumberWithUnits &a) const;

        NumberWithUnits& operator ++ ();      // prefix  - ++a
		const NumberWithUnits  operator ++ (int);   // postfix - a++
        NumberWithUnits& operator -- ();      // prefix  - ++a
		const NumberWithUnits  operator -- (int);   // postfix - a++

        friend NumberWithUnits operator*(const NumberWithUnits &a, const double d);
        friend NumberWithUnits operator*(const double d, const NumberWithUnits &a);

        friend std::ostream& operator <<	(std::ostream &os, const NumberWithUnits &f);
		friend std::istream& operator >>	(std::istream &is, NumberWithUnits &f);


        ~NumberWithUnits(){};
    };
}