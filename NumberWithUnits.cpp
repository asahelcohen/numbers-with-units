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
                tempVector.push_back(line);
        }

        int l = tempVector.size();

        for (uint i = 0; i < l; i += 5)
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
                for (auto itr : rates.at(bUnit))
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
                for (auto itr : rates.at(sUnit))
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
                    for (auto itr : rates.at(bUnit))
                    {
                        for (auto itr1 : rates.at(sUnit))
                        {
                            rates.at(itr.first).insert(make_pair(itr1.first, (1 / itr.second * itr1.second * rate)));
                            rates.at(itr1.first).insert(make_pair(itr.first, (itr.second * 1 / itr1.second * rate1)));
                        }
                        rates.at(sUnit).insert(make_pair(itr.first, itr.second * rate1));
                        rates.at(itr.first).insert(make_pair(sUnit, 1 / itr.second * rate));
                    }
                    for (auto itr : rates.at(sUnit))
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

    NumberWithUnits operator+(NumberWithUnits &a, NumberWithUnits &b)
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

        return a;
    }
    NumberWithUnits operator-(NumberWithUnits &a, NumberWithUnits &b)
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

        return a;
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
                num += (a.num / rates.at(a.type).at(type));
                return *this;
            }
        }

        return *this;
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
                num -= (a.num / rates.at(a.type).at(type));
                return *this;
            }
        }

        return *this;
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
        if (a.type == type)
        {
            if (a.num == num)
            {
                return true;
            }
            return false;
        }
        if (rates.count(a.type) == 1)
        {
            if (rates.at(a.type).count(type) == 1)
            {
                if (num == (a.num / rates.at(a.type).at(type)))
                {
                    return true;
                }
                return false;
            }
        }

        return false;
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
            if (num > a.num)
            {
                return true;
            }
            return false;
        }
        if (rates.count(a.type) == 1)
        {
            if (rates.at(a.type).count(type) == 1)
            {
                if (num > (a.num / rates.at(a.type).at(type)))
                {
                    return true;
                }
                return false;
            }
        }
        return false;
    }
    bool NumberWithUnits::operator<(const NumberWithUnits &a) const
    {
        if (a.type == type)
        {
            if (num < a.num)
            {
                return true;
            }
            return false;
        }
        if (rates.count(a.type) == 1)
        {
            if (rates.at(a.type).count(type) == 1)
            {
                if (num < (a.num / rates.at(a.type).at(type)))
                {
                    return true;
                }
                return false;
            }
        }
        return false;
    }

    NumberWithUnits &NumberWithUnits::operator++()
    {
        num += 1;
        return *this;
    }
    NumberWithUnits NumberWithUnits::operator++(int)
    {
        double numTemp = num + 1;
        string typeTemp = type;
        num += 1;
        return NumberWithUnits(numTemp, typeTemp);
    }
    NumberWithUnits &NumberWithUnits::operator--()
    {
        num -= 1;
        return *this;
    }
    NumberWithUnits NumberWithUnits::operator--(int)
    {
        double numTemp = num - 1;
        string typeTemp = type;
        num -= 1;
        return NumberWithUnits(numTemp, typeTemp);
    }

    NumberWithUnits operator*(const NumberWithUnits &a, const double d)
    {
        return NumberWithUnits(a.num * d, a.type);
    }
    NumberWithUnits operator*(const double d, const NumberWithUnits &a)
    {
        return NumberWithUnits(a.num * d, a.type);
    }

    ostream &operator<<(ostream &os, const NumberWithUnits &f)
    {
        return os << f.num << "[" << f.type << "]";
    }

    istream &operator>>(istream &is, NumberWithUnits &f)
    {
        return is;
    }

}
