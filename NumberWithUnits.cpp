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
        // string filename = "units.txt";
        // units_file.open(filename);

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
                    // for (auto itr : rates.at(bUnit))
                    // {
                    //     rates.at(sUnit).insert(make_pair(itr.first, (itr.second * rate1)));
                    //     rates.at(itr.first).insert(make_pair(sUnit, (1 / itr.second * rate)));
                    // }

                    // for (auto itr : rates.at(sUnit))
                    // {
                    //     rates.at(bUnit).insert(make_pair(itr.first, (itr.second * rate)));
                    //     rates.at(itr.first).insert(make_pair(bUnit, (1 / itr.second * rate1)));
                    // }
                    for (auto itr : rates.at(bUnit))
                    {
                        for (auto itr1 : rates.at(sUnit))
                        {
                            rates.at(itr.first).insert(make_pair(itr1.first, (1 / itr.second * itr1.second * rate)));
                            rates.at(itr1.first).insert(make_pair(itr.first, (itr.second * 1 / itr1.second * rate1)));
                        }
                        rates.at(sUnit).insert(make_pair(itr.first, itr.second * rate1));
                        rates.at(itr.first).insert(make_pair(sUnit, 1/itr.second * rate));
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

        for (auto temp1 : rates)
        {
            cout << " main:" << temp1.first << endl;
            for (auto t : rates.at(temp1.first))
            {
                cout << "  " << t.first << "   "
                     << "value: " << t.second << endl;
            }
            cout << endl
                 << endl;
        }
        cout << endl
             << endl
             << endl;
    }

    NumberWithUnits operator+(NumberWithUnits &a, NumberWithUnits &b)
    {
        return a;
    }
    NumberWithUnits operator-(NumberWithUnits &a, NumberWithUnits &b)
    {
        return a;
    }
    NumberWithUnits &NumberWithUnits::operator+=(const NumberWithUnits &a)
    {
        return *this;
    }
    NumberWithUnits &NumberWithUnits::operator-=(const NumberWithUnits &a)
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
