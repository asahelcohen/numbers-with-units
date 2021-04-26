#include "NumberWithUnits.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <string>
using namespace std;

namespace ariel
{
    NumberWithUnits::NumberWithUnits(double d, string typo)
    {
        if (rates.count(typo) != 1)
        {
            throw invalid_argument("unit does not exist");
        }
        num = d;
        type = std::move(typo);    
    }
    // 1 km = 1000 m
    // 1 m = 100 cm
    // 1 kg = 1000 g
    // 1 ton = 1000 kg
    // 1 hour = 60 min
    // 1 min = 60 sec
    // 1 USD = 3.33 ILS
    void NumberWithUnits::read_units(ifstream &units_file)
    {
        if (!units_file.is_open())
        {
            exit(EXIT_FAILURE);
        }

        string line;
        vector<string> tempVector;
        if (units_file.is_open())
        {
            while (units_file >> line)
            {
                tempVector.push_back(line);
            }
        }

        int l = tempVector.size();
        const uint five = 5;
        for (uint i = 0; i < l; i += five)
        {
            double rate = std::stod(tempVector.at(i + 3));
            double rate1 = 1 / rate;
            string bUnit = tempVector.at(i + 1);
            string sUnit = tempVector.at(i + 4);

            //2 new units
            if ((rates.count(bUnit) == 0) && (rates.count(sUnit) == 0))
            {
                rates.insert(make_pair(bUnit, map<string, double>()));
                rates.at(bUnit).insert(make_pair(sUnit, rate));

                rates.insert(make_pair(sUnit, map<string, double>()));
                rates.at(sUnit).insert(make_pair(bUnit, rate1));
            }

            //1 new units
            if ((rates.count(bUnit) == 1) && (rates.count(sUnit) == 0))
            {
                rates.insert(make_pair(sUnit, map<string, double>()));
                rates.at(sUnit).insert(make_pair(bUnit, rate1));
                for (auto const &itr : rates.at(bUnit))
                {
                    rates.at(sUnit).insert(make_pair(itr.first, (itr.second * rate1)));
                    rates.at(itr.first).insert(make_pair(sUnit, (1 / itr.second * rate)));
                }

                rates.at(bUnit).insert(make_pair(sUnit, rate));
            }

            if ((rates.count(bUnit) == 0) && (rates.count(sUnit) == 1))
            {
                rates.insert(make_pair(bUnit, map<string, double>()));
                rates.at(bUnit).insert(make_pair(sUnit, rate));
                for (auto const &itr : rates.at(sUnit))
                {
                    rates.at(bUnit).insert(make_pair(itr.first, (itr.second * rate)));
                    rates.at(itr.first).insert(make_pair(bUnit, (1 / itr.second * rate1)));
                }

                rates.at(sUnit).insert(make_pair(bUnit, rate1));
            }

            //0 new units
            if ((rates.count(bUnit) == 1) && (rates.count(sUnit) == 1))
            {
                if (rates.at(bUnit).count(sUnit) == 0)
                {
                    for (auto const &itr : rates.at(bUnit))
                    {
                        for (auto const &itr1 : rates.at(sUnit))
                        {
                            rates.at(itr.first).insert(make_pair(itr1.first, (1 / itr.second * itr1.second * rate)));
                            rates.at(itr1.first).insert(make_pair(itr.first, (itr.second * 1 / itr1.second * rate1)));
                        }
                        rates.at(sUnit).insert(make_pair(itr.first, itr.second * rate1));
                        rates.at(itr.first).insert(make_pair(sUnit, 1 / itr.second * rate));
                    }
                    for (auto const &itr : rates.at(sUnit))
                    {
                        rates.at(itr.first).insert(make_pair(bUnit, (1 / itr.second * rate1)));
                        rates.at(bUnit).insert(make_pair(itr.first, (itr.second * rate)));
                    }
                    rates.at(sUnit).insert(make_pair(bUnit, rate1));
                    rates.at(bUnit).insert(make_pair(sUnit, rate));
                }
            }
        }

        //     for (auto temp1 : rates)
        //     {
        //         cout << " main:" << temp1.first << endl;
        //         for (auto t : rates.at(temp1.first))
        //         {
        //             cout << "  " << t.first << "   "
        //                  << "value: " << t.second << endl;
        //         }
        //         cout << endl
        //              << endl;
        //     }
        //     cout << endl
        //          << endl
        //          << endl;
    }

    NumberWithUnits operator+(const NumberWithUnits &a, const NumberWithUnits &b)
    {
        if (a.type == b.type)
        {
            return NumberWithUnits(a.num + b.num, a.type);
        }
        if (rates.count(a.type) == 1)
        {
            if (rates.at(a.type).count(b.type) == 1)
            {
                double temp = (b.num / rates.at(a.type).at(b.type));
                return NumberWithUnits(a.num + temp, a.type);
            }
        }
        throw invalid_argument("Units do not match - " + b.type + " cannot be converted to " + a.type + "");
    }
    NumberWithUnits operator-(const NumberWithUnits &a, const NumberWithUnits &b)
    {
        if (a.type == b.type)
        {
            return NumberWithUnits(a.num - b.num, a.type);
        }
        if (rates.count(a.type) == 1)
        {
            if (rates.at(a.type).count(b.type) == 1)
            {
                double temp = (b.num / rates.at(a.type).at(b.type));
                return NumberWithUnits(a.num - temp, a.type);
            }
        }
        throw invalid_argument("Units do not match - " + b.type + " cannot be converted to " + a.type + "");
    }
    NumberWithUnits &NumberWithUnits::operator+=(const NumberWithUnits &a)
    {
        if (a.type == type)
        {
            num += a.num;
            return *this;
        }
        if (rates.count(a.type) == 1)
        {
            if (rates.at(a.type).count(type) == 1)
            {
                num += (a.num * rates.at(a.type).at(type));
                return *this;
            }
        }
        throw invalid_argument("Units do not match - " + a.type + " cannot be converted to " + type + "");
    }
    NumberWithUnits &NumberWithUnits::operator-=(const NumberWithUnits &a)
    {
        if (a.type == type)
        {
            num -= a.num;
            return *this;
        }
        if (rates.count(a.type) == 1)
        {
            if (rates.at(a.type).count(type) == 1)
            {
                num -= (a.num * rates.at(a.type).at(type));
                return *this;
            }
        }
        throw invalid_argument("Units do not match - " + a.type + " cannot be converted to " + type + "");
    }
    NumberWithUnits operator+(const NumberWithUnits &a)
    {
        return a;
    }
    NumberWithUnits operator-(const NumberWithUnits &a)
    {
        NumberWithUnits temp = NumberWithUnits(-a.num, a.type);
        return temp;
    }

    bool NumberWithUnits::operator==(const NumberWithUnits &a) const
    {
        const double eps = 0.0001;
        if (a.type == type)
        {
            return (abs(a.num - num) <= eps);
        }
        if (rates.count(a.type) == 1)
        {
            if (rates.at(a.type).count(type) == 1)
            {
                return (abs(num - (a.num * rates.at(a.type).at(type))) <= eps);
            }
        }
        throw invalid_argument("Units do not match - " + a.type + " cannot be converted to " + type + "");
    }
    bool NumberWithUnits::operator!=(const NumberWithUnits &a) const
    {
        return !(*this == a);
    }
    bool NumberWithUnits::operator>=(const NumberWithUnits &a) const
    {
        return !(*this < a);
    }
    bool NumberWithUnits::operator<=(const NumberWithUnits &a) const
    {
        return !(*this > a);
    }
    bool NumberWithUnits::operator>(const NumberWithUnits &a) const
    {
        if (a.type == type)
        {
            return (num > a.num);
        }
        if (rates.count(a.type) == 1)
        {
            if (rates.at(a.type).count(type) == 1)
            {
                if(*this == a){
                    return false;
                }
                return (num > (a.num * rates.at(a.type).at(type)));
            }
        }
        throw invalid_argument("Units do not match - " + a.type + " cannot be converted to " + type + "");
    }
    bool NumberWithUnits::operator<(const NumberWithUnits &a) const
    {
        if (a.type == type)
        {
            return (num < a.num);
        }
        if (rates.count(a.type) == 1)
        {
            if (rates.at(a.type).count(type) == 1)
            {
                if(*this == a){
                    return false;
                }
                return (num < (a.num * rates.at(a.type).at(type)));
            }
        }
        throw invalid_argument("Units do not match - " + a.type + " cannot be converted to " + type + "");
    }

    NumberWithUnits &NumberWithUnits::operator++()
    {
        num += 1;
        return *this;
    }
    NumberWithUnits NumberWithUnits::operator++(int)
    {
        double numTemp = num;
        num += 1;
        return NumberWithUnits(numTemp, type);
    }
    NumberWithUnits &NumberWithUnits::operator--()
    {
        num -= 1;
        return *this;
    }
    NumberWithUnits NumberWithUnits::operator--(int)
    {
        double numTemp = num;
        num -= 1;
        return NumberWithUnits(numTemp, type);
    }

    NumberWithUnits operator*(const NumberWithUnits &a, const double d)
    {
        return NumberWithUnits(a.num * d, a.type);
    }
    NumberWithUnits operator*(const double d, const NumberWithUnits &a)
    {
        return NumberWithUnits(a.num * d, a.type);
    }

    ostream &operator<<(ostream &os, const NumberWithUnits &unit)
    {
        return os << unit.num << "[" << unit.type << "]";
    }

    istream &operator>>(istream &is, NumberWithUnits &unit)
    {
        string type = "/0";
        double value = 1;
        char braket1 = 0;
        char braket2 = 0;

        is >> skipws >> value >> braket1 >> type;
        unit.num = value;
        if (type.at(type.length() - 1) == ']')
        {
            type = type.substr(0, type.length() - 1);
        }
        else
        {
            is >> skipws >> braket2;
        }
        
        unit.type = type;

        if (rates.count(type) == 0){ throw invalid_argument("unit does not exist");}


        return is;
    }
}
