#include "NumberWithUnits.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

namespace ariel
{

    std::map<string type1, map<string type2, double x> rates;

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
        string filename = "units.txt";
        units_file.open(filename);

        if (!units_file.is_open()){
            exit(EXIT_FAILURE);
        }

        string line;
        vector<string> tempVector;
        while(units_file.good){
            getline(units_file, line);
            if(line.size > 0)
                tempVector.push_back(line);
        }
        
        int l = tempVector.size();
        for(int i = 0; i < l; i + 5){
            double rate = std::stod (rates[i+3]);
            double rate1 = 1/ rate;

            //2 new units
            if((rates.find(tempVector[i+1]) == end) && (rates.find(tempVector[i+4]) == end)){
                rates.insert(make_pair(tempVector[i+1], map<string, double>()));
                rates[i+1].insert(make_pair(tempVector[i+4], rate));

                rates.insert(make_pair(tempVector[i+4], map<string, double>()));
                rates[i+1].insert(make_pair(tempVector[i+1], rate1)));
            }

            //1 new units
            if(!(rates.find(tempVector[i+1]) == end) && (rates.find(tempVector[i+4]) == end)){
                rates[i+1].insert(make_pair(tempVector[i+4], rate));

                rates.insert(make_pair(tempVector[i+4], map<string, double>()));
                for (itr = rates[i+1].begin(); itr != rates[i+1].end(); itr++) {
                    rates[i+4].insert(make_pair(itr->first, (itr->second*rate1))));
                    rates[itr->first].insert(make_pair(rates[i+4], (itr->second*rate)));
                }
            }


            if((rates.find(tempVector[i+1]) == end) && !(rates.find(tempVector[i+4]) == end)){
                rates[i+1].insert(make_pair(tempVector[i+1], rate1));

                rates.insert(make_pair(tempVector[i+1], map<string, double>()));
                for (itr = rates[i+4].begin(); itr != rates[i+3].end(); itr++) {
                    rates[i+1].insert(make_pair(itr->first, (itr->second*rate))));
                    rates[itr->first].insert(make_pair(rates[i+1], (itr->second*rate1)));
                }
            }
            //0 new units
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
        return NumberWithUnits(a.num*d, a.type);
    }
    NumberWithUnits operator*(const double d, const NumberWithUnits &a)
    {
        return NumberWithUnits(a.num*d, a.type);
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
