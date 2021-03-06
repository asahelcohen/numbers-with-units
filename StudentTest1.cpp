#include "doctest.h"
#include "NumberWithUnits.hpp"
#include <sstream>
#include <fstream>
#include <cfloat>
using namespace ariel;
using namespace std;

void update_table(){
    ofstream myfile;
    myfile.open ("myTestFile.txt");
    myfile << "1 km = 1000 m" << endl;
    myfile << "1 m = 100 cm" << endl;
    myfile << "1 kg = 1000 g" << endl;
    myfile << "1 ton = 1000 kg" << endl;
    myfile << "1 hour = 60 min" << endl;
    myfile << "1 min = 60 sec" << endl;
    myfile << "1 day = 24 hour" << endl;
    myfile << "1 month = 30 day" << endl;
    myfile << "1 year = 12 month" << endl;   
    myfile.close(); 
    ifstream units_file{"myTestFile.txt"};
    NumberWithUnits::read_units(units_file);
}
void update_table(string s){
    ofstream myfile;
    myfile.open ("myTestFile.txt");
    myfile << s << endl;
    myfile.close(); 
    ifstream units_file{"myTestFile.txt"};
    NumberWithUnits::read_units(units_file);
}
TEST_CASE("read_units and Constractor") {
    CHECK_THROWS(NumberWithUnits(0,"year"));
    CHECK_THROWS(NumberWithUnits(1,"year"));
    CHECK_THROWS(NumberWithUnits(-1,"year"));
    CHECK_THROWS(NumberWithUnits(DBL_MAX,"year"));
    CHECK_THROWS(NumberWithUnits(DBL_MIN,"year"));
    CHECK_THROWS(NumberWithUnits(10,"year"));
    CHECK_THROWS(NumberWithUnits(-156,"year"));
    CHECK_THROWS(NumberWithUnits(112.45,"year"));
    CHECK_THROWS(NumberWithUnits(-999.63,"year"));
    update_table();
    CHECK_NOTHROW(NumberWithUnits(0,"year"));
    CHECK_NOTHROW(NumberWithUnits(1,"year"));
    CHECK_NOTHROW(NumberWithUnits(-1,"year"));
    CHECK_NOTHROW(NumberWithUnits(DBL_MAX,"year"));
    CHECK_NOTHROW(NumberWithUnits(DBL_MIN,"year"));
    CHECK_NOTHROW(NumberWithUnits(10,"year"));
    CHECK_NOTHROW(NumberWithUnits(-156,"year"));
    CHECK_NOTHROW(NumberWithUnits(112.45,"year"));
    CHECK_NOTHROW(NumberWithUnits(-999.63,"year"));
    CHECK_THROWS(NumberWithUnits a=NumberWithUnits(0.0,"USD"));
    CHECK_THROWS(NumberWithUnits a=NumberWithUnits(1.2,"USD"));
    CHECK_THROWS(NumberWithUnits a=NumberWithUnits(-2.4,"USD"));
    CHECK_THROWS(NumberWithUnits a=NumberWithUnits(DBL_MAX-4,"USD"));
    CHECK_THROWS(NumberWithUnits a=NumberWithUnits(DBL_MIN+3,"USD"));
    CHECK_THROWS(NumberWithUnits a=NumberWithUnits(555555,"USD"));
    CHECK_THROWS(NumberWithUnits a=NumberWithUnits(-6666666,"USD"));
    CHECK_THROWS(NumberWithUnits a=NumberWithUnits(9876.45,"USD"));
    CHECK_THROWS(NumberWithUnits a=NumberWithUnits(-84.63,"USD"));
    CHECK_THROWS(NumberWithUnits a=NumberWithUnits(021,"ILS"));
    CHECK_THROWS(NumberWithUnits a=NumberWithUnits(221,"ILS"));
    CHECK_THROWS(NumberWithUnits a=NumberWithUnits(-0,"ILS"));
    CHECK_THROWS(NumberWithUnits a=NumberWithUnits(0.000005,"ILS"));
    CHECK_THROWS(NumberWithUnits a=NumberWithUnits(-0.00000001,"ILS"));
    CHECK_THROWS(NumberWithUnits a=NumberWithUnits(3334,"ILS"));
    CHECK_THROWS(NumberWithUnits a=NumberWithUnits(-0.05,"ILS"));
    CHECK_THROWS(NumberWithUnits a=NumberWithUnits(0.3,"ILS"));
    CHECK_THROWS(NumberWithUnits a=NumberWithUnits(-4.444,"ILS"));
    update_table("1 USD = 3.33 ILS");
    CHECK_NOTHROW(NumberWithUnits a=NumberWithUnits(0.0,"USD"));
    CHECK_NOTHROW(NumberWithUnits a=NumberWithUnits(1.2,"USD"));
    CHECK_NOTHROW(NumberWithUnits a=NumberWithUnits(-2.4,"USD"));
    CHECK_NOTHROW(NumberWithUnits a=NumberWithUnits(DBL_MAX-4,"USD"));
    CHECK_NOTHROW(NumberWithUnits a=NumberWithUnits(DBL_MIN+3,"USD"));
    CHECK_NOTHROW(NumberWithUnits a=NumberWithUnits(555555,"USD"));
    CHECK_NOTHROW(NumberWithUnits a=NumberWithUnits(-6666666,"USD"));
    CHECK_NOTHROW(NumberWithUnits a=NumberWithUnits(9876.45,"USD"));
    CHECK_NOTHROW(NumberWithUnits a=NumberWithUnits(-84.63,"USD"));
    CHECK_NOTHROW(NumberWithUnits a=NumberWithUnits(021,"ILS"));
    CHECK_NOTHROW(NumberWithUnits a=NumberWithUnits(221,"ILS"));
    CHECK_NOTHROW(NumberWithUnits a=NumberWithUnits(-0,"ILS"));
    CHECK_NOTHROW(NumberWithUnits a=NumberWithUnits(0.000005,"ILS"));
    CHECK_NOTHROW(NumberWithUnits a=NumberWithUnits(-0.00000001,"ILS"));
    CHECK_NOTHROW(NumberWithUnits a=NumberWithUnits(3334,"ILS"));
    CHECK_NOTHROW(NumberWithUnits a=NumberWithUnits(-0.05,"ILS"));
    CHECK_NOTHROW(NumberWithUnits a=NumberWithUnits(0.3,"ILS"));
    CHECK_NOTHROW(NumberWithUnits a=NumberWithUnits(-4.444,"ILS"));
    CHECK_NOTHROW(NumberWithUnits(0,"year"));
    CHECK_NOTHROW(NumberWithUnits(1,"year"));
    CHECK_NOTHROW(NumberWithUnits(-1,"year"));
    CHECK_NOTHROW(NumberWithUnits(DBL_MAX,"year"));
    CHECK_NOTHROW(NumberWithUnits(DBL_MIN,"year"));
    CHECK_NOTHROW(NumberWithUnits(10,"year"));
    CHECK_NOTHROW(NumberWithUnits(-156,"year"));
    CHECK_NOTHROW(NumberWithUnits(112.45,"year"));
    CHECK_NOTHROW(NumberWithUnits(-999.63,"year"));
    CHECK_THROWS(NumberWithUnits a=NumberWithUnits(021,"ils"));
    CHECK_THROWS(NumberWithUnits a=NumberWithUnits(221,"ils"));
    CHECK_THROWS(NumberWithUnits a=NumberWithUnits(-0,"YEAR"));
    CHECK_THROWS(NumberWithUnits a=NumberWithUnits(0.000005,"Year"));
    CHECK_THROWS(NumberWithUnits a=NumberWithUnits(-0.00000001,"Y"));
    CHECK_THROWS(NumberWithUnits a=NumberWithUnits(3334,"usd"));
    CHECK_THROWS(NumberWithUnits a=NumberWithUnits(-0.05,"us"));
    CHECK_THROWS(NumberWithUnits a=NumberWithUnits(0.3,""));
    CHECK_THROWS(NumberWithUnits a=NumberWithUnits(-4.444,"USd"));
}
TEST_CASE("Operator + test"){
    NumberWithUnits min1=NumberWithUnits(1,"min");
    NumberWithUnits min2=NumberWithUnits(2,"min");
    NumberWithUnits min4=NumberWithUnits(4,"min");
    NumberWithUnits min0=NumberWithUnits(0,"min");
    NumberWithUnits min_9=NumberWithUnits(-9,"min");
    NumberWithUnits hour1=NumberWithUnits(1,"hour");
    NumberWithUnits hour0=NumberWithUnits(0,"hour");
    NumberWithUnits hour_888=NumberWithUnits(-888,"hour");
    NumberWithUnits hour3=NumberWithUnits(3,"hour");
    NumberWithUnits hourMAX=NumberWithUnits(DBL_MAX,"hour");
    NumberWithUnits day1=NumberWithUnits(1,"day");
    NumberWithUnits day0=NumberWithUnits(0,"day");
    NumberWithUnits day_3=NumberWithUnits(-3,"day");
    NumberWithUnits day12=NumberWithUnits(12,"day");
    NumberWithUnits sec100=NumberWithUnits(100,"sec");
    NumberWithUnits sec0=NumberWithUnits(0,"sec");
    NumberWithUnits ton10=NumberWithUnits(10,"ton");
    NumberWithUnits kg1=NumberWithUnits(1,"kg");
    CHECK((min2+min0)==NumberWithUnits(2,"min"));
    CHECK((min0+min2)==NumberWithUnits(2,"min"));
    CHECK((min4+min2)==NumberWithUnits(6,"min"));   
    CHECK((min2+min4)==NumberWithUnits(6,"min"));
    CHECK((min0+min_9)==NumberWithUnits(-9,"min"));
    CHECK((min_9+min0)==NumberWithUnits(-9,"min"));
    CHECK((min_9+min2)==NumberWithUnits(-7,"min"));
    CHECK((min2+min_9)==NumberWithUnits(-7,"min"));
    CHECK((min2+hour1)==NumberWithUnits(62,"min"));
    CHECK((hour1+min2)==NumberWithUnits(1.033333,"hour"));
    CHECK((min4+hour0)==NumberWithUnits(4,"min"));
    CHECK((hour0+min4)==NumberWithUnits(0.06666667,"hour"));
    CHECK((min_9+hour3)==NumberWithUnits(171,"min"));
    CHECK((hour3+min_9)==NumberWithUnits(2.85,"hour"));
    CHECK((hour_888+min_9)==NumberWithUnits(-888*60-9,"min"));
    CHECK((hourMAX+day1)==NumberWithUnits(DBL_MAX-24,"hour"));
    CHECK((hour0+day_3)==NumberWithUnits(-24*3,"hour"));
    CHECK((day_3+hour1)==NumberWithUnits(1.0/24-3,"day"));
    CHECK((min2+day12)==NumberWithUnits(24*60*12+2,"min"));
    CHECK((sec100+day12)==NumberWithUnits(24*60*60*12+100,"sec"));
    CHECK((sec0+min1)==NumberWithUnits(60,"sec"));
    CHECK((sec0+hour1)==NumberWithUnits(60*60,"sec"));
    CHECK((sec0+day1)==NumberWithUnits(60*60*24,"sec"));
    CHECK((kg1+ton10)==NumberWithUnits(1+10*1000,"kg"));
    CHECK((ton10+kg1)==NumberWithUnits(10+1.0/1000,"ton"));
    CHECK((min_9+min0+min4)==NumberWithUnits(-5,"min"));
    CHECK((sec100+min1+day1+hour3)==NumberWithUnits(100+60+60*60*24+60*60*3,"sec"));
    CHECK((hour3+sec100+min1+day1)==NumberWithUnits(3+100.0/(60*60)+1.0/60+24,"hour"));
    CHECK((min1+hour3+min2+sec100+sec0+day1+day_3)==
        NumberWithUnits(1+3*60+2+100.0/60+60*24-3*60*24,"min"));
    CHECK_THROWS(ton10+sec0);
    CHECK_THROWS(ton10+min4);
    CHECK_THROWS(ton10+day1);
    CHECK_THROWS(sec0+ton10);
    CHECK_THROWS(min4+ton10);
    CHECK_THROWS(day1+ton10);
    CHECK_THROWS(day1+kg1);
}
TEST_CASE("Operator - test"){
    NumberWithUnits min1=NumberWithUnits(1,"min");
    NumberWithUnits min2=NumberWithUnits(2,"min");
    NumberWithUnits min4=NumberWithUnits(4,"min");
    NumberWithUnits min0=NumberWithUnits(0,"min");
    NumberWithUnits min_9=NumberWithUnits(-9,"min");
    NumberWithUnits hour1=NumberWithUnits(1,"hour");
    NumberWithUnits hour0=NumberWithUnits(0,"hour");
    NumberWithUnits hour_888=NumberWithUnits(-888,"hour");
    NumberWithUnits hour3=NumberWithUnits(3,"hour");
    NumberWithUnits hourMAX=NumberWithUnits(DBL_MAX,"hour");
    NumberWithUnits day1=NumberWithUnits(1,"day");
    NumberWithUnits day0=NumberWithUnits(0,"day");
    NumberWithUnits day_3=NumberWithUnits(-3,"day");
    NumberWithUnits day12=NumberWithUnits(12,"day");
    NumberWithUnits sec100=NumberWithUnits(100,"sec");
    NumberWithUnits sec0=NumberWithUnits(0,"sec");
    NumberWithUnits ton10=NumberWithUnits(10,"ton");
    NumberWithUnits kg1=NumberWithUnits(1,"kg");
    CHECK((min2-min0)==NumberWithUnits(2,"min"));
    CHECK((min0-min2)==NumberWithUnits(-2,"min"));
    CHECK((min4-min2)==NumberWithUnits(2,"min"));   
    CHECK((min2-min4)==NumberWithUnits(-2,"min"));
    CHECK((min0-min_9)==NumberWithUnits(9,"min"));
    CHECK((min_9-min0)==NumberWithUnits(-9,"min"));
    CHECK((min_9-min2)==NumberWithUnits(-11,"min"));
    CHECK((min2-min_9)==NumberWithUnits(11,"min"));
    CHECK((min2-hour1)==NumberWithUnits(2-60,"min"));
    CHECK((hour1-min2)==NumberWithUnits(1-(2.0/60),"hour"));
    CHECK((min4-hour0)==NumberWithUnits(4,"min"));
    CHECK((hour0-min4)==NumberWithUnits(-4.0/60,"hour"));
    CHECK((min_9-hour3)==NumberWithUnits(-9-180,"min"));
    CHECK((hour3-min_9)==NumberWithUnits(3+9.0/60,"hour"));
    CHECK((hour_888-min_9)==NumberWithUnits(-888+9.0/60,"hour"));
    CHECK((hourMAX-day1)==NumberWithUnits(DBL_MAX-24,"hour"));
    CHECK((hour0-day_3)==NumberWithUnits(24*3,"hour"));
    CHECK((day_3-hour1)==NumberWithUnits(-1.0/24-3,"day"));
    CHECK((min2-day12)==NumberWithUnits(-24*60*12+2,"min"));
    CHECK((sec100-day12)==NumberWithUnits(-24*60*60*12+100,"sec"));
    CHECK((sec0-min1)==NumberWithUnits(-60,"sec"));
    CHECK((sec0-hour1)==NumberWithUnits(-60*60,"sec"));
    CHECK((sec0-day1)==NumberWithUnits(-60*60*24,"sec"));
    CHECK((min1-sec100)==NumberWithUnits(1-100.0/60,"min"));
    CHECK((hour1-sec100)==NumberWithUnits(1-100.0/(60*60),"hour"));
    CHECK((day1-sec100)==NumberWithUnits(1-100.0/(60*60*24),"day"));
    CHECK((kg1-ton10)==NumberWithUnits(1-10*1000,"kg"));
    CHECK((ton10-kg1)==NumberWithUnits(10-1.0/1000,"ton"));
    CHECK((min_9-min0-min4)==NumberWithUnits(-9-4,"min"));
    CHECK((sec100-min1-day1-hour3)==NumberWithUnits(100-60-60*60*24-60*60*3,"sec"));
    CHECK((hour3-sec100-min1-day1)==NumberWithUnits(3-100.0/(60*60)-1.0/60-24,"hour"));
    CHECK((min1-hour3-min2-sec100-sec0-day1-day_3)==
        NumberWithUnits(1-3*60-2-100.0/60-60*24+3*60*24,"min"));
    CHECK_THROWS(ton10-sec0);
    CHECK_THROWS(ton10-min4);
    CHECK_THROWS(ton10-day1);
    CHECK_THROWS(sec0-ton10);
    CHECK_THROWS(min4-ton10);
    CHECK_THROWS(day1-ton10);
    CHECK_THROWS(day1-kg1);
}
TEST_CASE("Operator += test"){
    NumberWithUnits min1=NumberWithUnits(1,"min");
    NumberWithUnits min4=NumberWithUnits(4,"min");
    NumberWithUnits min0=NumberWithUnits(0,"min");
    NumberWithUnits min_9=NumberWithUnits(-9,"min");
    NumberWithUnits hour1=NumberWithUnits(1,"hour");
    NumberWithUnits hour0=NumberWithUnits(0,"hour");
    NumberWithUnits hour3=NumberWithUnits(3,"hour");
    NumberWithUnits ton10=NumberWithUnits(10,"ton");
    NumberWithUnits kg1=NumberWithUnits(1,"kg");
    NumberWithUnits min_MIN=NumberWithUnits(DBL_MIN,"min");
    NumberWithUnits unit=NumberWithUnits(2,"min");
    double sum=2;
    unit+=min0;
    CHECK(unit==NumberWithUnits(sum,"min"));
    min0+=unit;
    CHECK(min0==NumberWithUnits(2,"min"));
    unit+=min_9;
    sum-=9;
    CHECK(unit==NumberWithUnits(sum,"min"));
    CHECK(min_9==NumberWithUnits(-9,"min"));
    sum+=4;
    unit+=min4;
    CHECK(unit==NumberWithUnits(sum,"min"));
    sum+=60;
    unit+=hour1;
    CHECK(unit==NumberWithUnits(sum,"min"));
    hour1+=unit;
    CHECK(hour1==NumberWithUnits(1+(sum+0.0)/60,"hour"));
    unit+=hour0;
    CHECK(unit==NumberWithUnits(sum,"min"));
    unit+=hour0+hour3;
    sum+=3*60;
    CHECK(unit==NumberWithUnits(sum,"min"));
    unit+=min_MIN;
    CHECK(unit==NumberWithUnits(sum,"min"));
    unit+=min4+min1;
    sum+=5;
    CHECK(unit==NumberWithUnits(sum,"min"));
    unit+=unit+min4+min1-hour3;
    sum+=sum+4+1-3*60;
    CHECK(unit==NumberWithUnits(sum,"min"));
    CHECK_THROWS(unit+=ton10);
    CHECK_THROWS(unit+=kg1);
    CHECK_THROWS(kg1+=min1);
    CHECK_THROWS(kg1+=hour0);
}
TEST_CASE("Operator -= test"){
    NumberWithUnits min1=NumberWithUnits(1,"min");
    NumberWithUnits min4=NumberWithUnits(4,"min");
    NumberWithUnits min0=NumberWithUnits(0,"min");
    NumberWithUnits min_9=NumberWithUnits(-9,"min");
    NumberWithUnits hour1=NumberWithUnits(1,"hour");
    NumberWithUnits hour0=NumberWithUnits(0,"hour");
    NumberWithUnits hour3=NumberWithUnits(3,"hour");
    NumberWithUnits ton10=NumberWithUnits(10,"ton");
    NumberWithUnits kg1=NumberWithUnits(1,"kg");
    NumberWithUnits min_MAX=NumberWithUnits(DBL_MAX,"min");
    NumberWithUnits unit=NumberWithUnits(2,"min");
    double sum=2;
    unit-=min0;
    CHECK(unit==NumberWithUnits(sum,"min"));
    min0-=unit;
    CHECK(min0==NumberWithUnits(-2,"min"));
    unit-=min_9;
    sum+=9;
    CHECK(unit==NumberWithUnits(sum,"min"));
    CHECK(min_9==NumberWithUnits(-9,"min"));
    sum-=4;
    unit-=min4;
    CHECK(unit==NumberWithUnits(sum,"min"));
    sum-=60;
    unit-=hour1;
    CHECK(unit==NumberWithUnits(sum,"min"));
    hour1-=unit;
    CHECK(hour1==NumberWithUnits(1-(sum+0.0)/60,"hour"));
    unit+=hour0;
    CHECK(unit==NumberWithUnits(sum,"min"));
    unit-=hour0+hour3;
    sum-=3*60;
    CHECK(unit==NumberWithUnits(sum,"min"));
    unit-=min_MAX;
    sum-=DBL_MAX;
    CHECK(unit==NumberWithUnits(sum,"min"));
    unit-=min4+min1;
    sum-=5;
    CHECK(unit==NumberWithUnits(sum,"min"));
    unit-=unit+min4+min1-hour3;
    sum-=sum+4+1-3*60;
    CHECK(unit==NumberWithUnits(sum,"min"));
    CHECK_THROWS(unit-=ton10);
    CHECK_THROWS(unit-=kg1);
    CHECK_THROWS(kg1-=min1);
    CHECK_THROWS(kg1-=hour0);
}
TEST_CASE("Operator + unary test"){
    NumberWithUnits min1=NumberWithUnits(1,"min");
    NumberWithUnits min_9=NumberWithUnits(-9,"min");
    NumberWithUnits hour1=NumberWithUnits(1,"hour");
    NumberWithUnits hour0=NumberWithUnits(0,"hour");
    NumberWithUnits sec_1=+NumberWithUnits(-1,"sec");
    NumberWithUnits sec4=+NumberWithUnits(4,"sec");
    CHECK(+min1==NumberWithUnits(1,"min"));
    CHECK(+hour1==NumberWithUnits(1,"hour"));
    CHECK(+hour0==NumberWithUnits(0,"hour"));
    CHECK(+min_9==NumberWithUnits(-9,"min"));
    CHECK(+sec_1==NumberWithUnits(-1,"sec"));
    CHECK(+sec4==NumberWithUnits(4,"sec"));
    CHECK(+NumberWithUnits(DBL_MAX,"kg")==NumberWithUnits(DBL_MAX,"kg"));
    CHECK(+NumberWithUnits(DBL_MIN,"ton")==NumberWithUnits(DBL_MIN,"ton"));
    NumberWithUnits unit=+(+(+(+(min1+hour1))));
    CHECK(unit==NumberWithUnits(1+60,"min"));
}
TEST_CASE("Operator - unary test"){
    NumberWithUnits min1=NumberWithUnits(1,"min");
    NumberWithUnits min_9=NumberWithUnits(-9,"min");
    NumberWithUnits hour1=NumberWithUnits(1,"hour");
    NumberWithUnits hour0=NumberWithUnits(0,"hour");
    NumberWithUnits sec_1=+NumberWithUnits(-1,"sec");
    NumberWithUnits sec4=+NumberWithUnits(4,"sec");
    CHECK(-min1==NumberWithUnits(-1,"min"));
    CHECK(-hour1==NumberWithUnits(-1,"hour"));
    CHECK(-hour0==NumberWithUnits(0,"hour"));
    CHECK(-min_9==NumberWithUnits(9,"min"));
    CHECK(-sec_1==NumberWithUnits(1,"sec"));
    CHECK(-sec4==NumberWithUnits(-4,"sec"));
    CHECK(-NumberWithUnits(DBL_MAX,"kg")==NumberWithUnits(-DBL_MAX,"kg"));
    CHECK(-NumberWithUnits(DBL_MIN,"ton")==NumberWithUnits(-DBL_MIN,"ton"));
    CHECK(-NumberWithUnits(-1350,"ton")==NumberWithUnits(1350,"ton"));
    NumberWithUnits unit=-(-(-(-(min1+hour1))));
    CHECK(unit==NumberWithUnits(-(-(-(-(1+60)))),"min"));
}
TEST_CASE("Operator > test"){
    CHECK(NumberWithUnits(1,"ton")>NumberWithUnits(0,"ton"));
    CHECK(NumberWithUnits(0,"ton")>NumberWithUnits(-6,"ton"));
    CHECK(NumberWithUnits(100,"ton")>NumberWithUnits(90,"ton"));
    CHECK(NumberWithUnits(5,"ton")>NumberWithUnits(-5,"ton"));
    CHECK(NumberWithUnits(DBL_MAX,"ton")>NumberWithUnits(DBL_MIN,"ton"));
    CHECK(NumberWithUnits(1,"day")>NumberWithUnits(23,"hour"));
    CHECK(NumberWithUnits(-1,"day")>NumberWithUnits(-25,"hour"));
    CHECK(NumberWithUnits(1,"hour")>NumberWithUnits(0,"day"));
    CHECK(NumberWithUnits(60*24+1,"min")>NumberWithUnits(1,"day"));
    CHECK(NumberWithUnits(1.1,"day")>NumberWithUnits(60*24,"min"));
    CHECK_FALSE(NumberWithUnits(-0,"sec")>NumberWithUnits(+0,"sec"));
    CHECK_FALSE(NumberWithUnits(-0,"sec")>NumberWithUnits(0,"sec"));
    CHECK_FALSE(NumberWithUnits(1,"day")>NumberWithUnits(60*24,"min"));
    CHECK_FALSE(NumberWithUnits(1,"day")>NumberWithUnits(61*24,"min"));
    CHECK_FALSE(NumberWithUnits(1,"day")>NumberWithUnits(1,"day"));
    CHECK_FALSE(NumberWithUnits(-10,"day")>NumberWithUnits(0.0001,"sec"));
    CHECK_FALSE(NumberWithUnits(-5,"kg")>NumberWithUnits(-4,"kg"));
    CHECK_FALSE(NumberWithUnits(240,"kg")>NumberWithUnits(240,"kg"));
}
TEST_CASE("Operator < test"){
    CHECK(NumberWithUnits(0,"ton")<NumberWithUnits(1,"ton"));
    CHECK(NumberWithUnits(-6,"ton")<NumberWithUnits(0,"ton"));
    CHECK(NumberWithUnits(90,"ton")<NumberWithUnits(100,"ton"));
    CHECK(NumberWithUnits(-5,"ton")<NumberWithUnits(5,"ton"));
    CHECK(NumberWithUnits(DBL_MIN,"ton")<NumberWithUnits(DBL_MAX,"ton"));
    CHECK(NumberWithUnits(23,"hour")<NumberWithUnits(1,"day"));
    CHECK(NumberWithUnits(-25,"hour")<NumberWithUnits(-1,"day"));
    CHECK(NumberWithUnits(0,"day")<NumberWithUnits(1,"hour"));
    CHECK(NumberWithUnits(1-0.1,"day")<NumberWithUnits(60*24,"min"));
    CHECK(NumberWithUnits(60*24,"min")<NumberWithUnits(1.1,"day"));
    CHECK_FALSE(NumberWithUnits(-0,"sec")<NumberWithUnits(+0,"sec"));
    CHECK_FALSE(NumberWithUnits(-0,"sec")<NumberWithUnits(0,"sec"));
    CHECK_FALSE(NumberWithUnits(60*24,"min")<NumberWithUnits(1,"day"));
    CHECK_FALSE(NumberWithUnits(61*24,"min")<NumberWithUnits(1,"day"));
    CHECK_FALSE(NumberWithUnits(1,"day")<NumberWithUnits(1,"day"));
    CHECK_FALSE(NumberWithUnits(0.0001,"sec")<NumberWithUnits(-10,"day"));
    CHECK_FALSE(NumberWithUnits(-4,"kg")<NumberWithUnits(-5,"kg"));
    CHECK_FALSE(NumberWithUnits(240,"kg")<NumberWithUnits(240,"kg"));
}
TEST_CASE("Operator <= test"){
    CHECK(NumberWithUnits(0,"ton")<=NumberWithUnits(1,"ton"));
    CHECK(NumberWithUnits(-6,"ton")<=NumberWithUnits(0,"ton"));
    CHECK(NumberWithUnits(90,"ton")<=NumberWithUnits(100,"ton"));
    CHECK(NumberWithUnits(-5,"ton")<=NumberWithUnits(5,"ton"));
    CHECK(NumberWithUnits(DBL_MIN,"ton")<=NumberWithUnits(DBL_MAX,"ton"));
    CHECK(NumberWithUnits(23,"hour")<=NumberWithUnits(1,"day"));
    CHECK(NumberWithUnits(-25,"hour")<=NumberWithUnits(-1,"day"));
    CHECK(NumberWithUnits(0,"day")<=NumberWithUnits(1,"hour"));
    CHECK(NumberWithUnits(1-0.1,"day")<=NumberWithUnits(60*24,"min"));
    CHECK(NumberWithUnits(60*24,"min")<=NumberWithUnits(1.1,"day"));
    CHECK(NumberWithUnits(60*24,"min")<=NumberWithUnits(1,"day"));
    CHECK(NumberWithUnits(1,"day")<=NumberWithUnits(1,"day"));
    CHECK(NumberWithUnits(240,"kg")<=NumberWithUnits(240,"kg"));
    CHECK(NumberWithUnits(-0,"sec")<=NumberWithUnits(+0,"sec"));
    CHECK(NumberWithUnits(-0,"sec")<=NumberWithUnits(0,"sec"));
    CHECK_FALSE(NumberWithUnits(60*24,"min")<=NumberWithUnits(0.9,"day"));
    CHECK_FALSE(NumberWithUnits(61*24,"min")<=NumberWithUnits(1,"day"));
    CHECK_FALSE(NumberWithUnits(0.0001,"sec")<=NumberWithUnits(-10,"day"));
    CHECK_FALSE(NumberWithUnits(-4,"kg")<=NumberWithUnits(-5,"kg"));
}
TEST_CASE("Operator >= test"){
    CHECK(NumberWithUnits(1,"ton")>=NumberWithUnits(0,"ton"));
    CHECK(NumberWithUnits(0,"ton")>=NumberWithUnits(-6,"ton"));
    CHECK(NumberWithUnits(100,"ton")>=NumberWithUnits(90,"ton"));
    CHECK(NumberWithUnits(5,"ton")>=NumberWithUnits(-5,"ton"));
    CHECK(NumberWithUnits(DBL_MAX,"ton")>=NumberWithUnits(DBL_MIN,"ton"));
    CHECK(NumberWithUnits(1,"day")>=NumberWithUnits(23,"hour"));
    CHECK(NumberWithUnits(-1,"day")>=NumberWithUnits(-25,"hour"));
    CHECK(NumberWithUnits(1,"hour")>=NumberWithUnits(0,"day"));
    CHECK(NumberWithUnits(60*24+1,"min")>=NumberWithUnits(1,"day"));
    CHECK(NumberWithUnits(1.1,"day")>=NumberWithUnits(60*24,"min"));
    CHECK(NumberWithUnits(240,"kg")>=NumberWithUnits(240,"kg"));
    CHECK(NumberWithUnits(1,"day")>=NumberWithUnits(60*24,"min"));
    CHECK(NumberWithUnits(1,"day")>=NumberWithUnits(1,"day"));
    CHECK(NumberWithUnits(-0,"sec")>=NumberWithUnits(+0,"sec"));
    CHECK(NumberWithUnits(-0,"sec")>=NumberWithUnits(0,"sec"));
    CHECK_FALSE(NumberWithUnits(1,"day")>=NumberWithUnits(61*24,"min"));
    CHECK_FALSE(NumberWithUnits(-10,"day")>=NumberWithUnits(0.0001,"sec"));
    CHECK_FALSE(NumberWithUnits(-5,"kg")>=NumberWithUnits(-4,"kg"));
    CHECK_FALSE(NumberWithUnits(0.9,"day")>=NumberWithUnits(60*24,"min"));
}
TEST_CASE("Operator != test"){
    CHECK(NumberWithUnits(1,"ton")!=NumberWithUnits(0,"ton"));
    CHECK(NumberWithUnits(0,"ton")!=NumberWithUnits(-6,"ton"));
    CHECK(NumberWithUnits(100,"ton")!=NumberWithUnits(90,"ton"));
    CHECK(NumberWithUnits(5,"ton")!=NumberWithUnits(-5,"ton"));
    CHECK(NumberWithUnits(DBL_MAX,"ton")!=NumberWithUnits(DBL_MIN,"ton"));
    CHECK(NumberWithUnits(1,"day")!=NumberWithUnits(23,"hour"));
    CHECK(NumberWithUnits(-1,"day")!=NumberWithUnits(-25,"hour"));
    CHECK(NumberWithUnits(1,"hour")!=NumberWithUnits(0,"day"));
    CHECK(NumberWithUnits(60*24+1,"min")!=NumberWithUnits(1,"day"));
    CHECK(NumberWithUnits(1.1,"day")!=NumberWithUnits(60*24,"min"));
    CHECK(NumberWithUnits(1,"day")!=NumberWithUnits(61*24,"min"));
    CHECK(NumberWithUnits(-10,"day")!=NumberWithUnits(0.0001,"sec"));
    CHECK(NumberWithUnits(-5,"kg")!=NumberWithUnits(-4,"kg"));
    CHECK(NumberWithUnits(0.9,"day")!=NumberWithUnits(60*24,"min"));
    CHECK_FALSE(NumberWithUnits(-0,"sec")!=NumberWithUnits(+0,"sec"));
    CHECK_FALSE(NumberWithUnits(-0,"sec")!=NumberWithUnits(0,"sec"));
    CHECK_FALSE(NumberWithUnits(240,"kg")!=NumberWithUnits(240,"kg"));
    CHECK_FALSE(NumberWithUnits(1,"day")!=NumberWithUnits(60*24,"min"));
    CHECK_FALSE(NumberWithUnits(1,"day")!=NumberWithUnits(1,"day")); 
}
TEST_CASE("Operator == test"){
    CHECK_FALSE(NumberWithUnits(1,"ton")==NumberWithUnits(0,"ton"));
    CHECK_FALSE(NumberWithUnits(0,"ton")==NumberWithUnits(-6,"ton"));
    CHECK_FALSE(NumberWithUnits(100,"ton")==NumberWithUnits(90,"ton"));
    CHECK_FALSE(NumberWithUnits(5,"ton")==NumberWithUnits(-5,"ton"));
    CHECK_FALSE(NumberWithUnits(DBL_MAX,"ton")==NumberWithUnits(DBL_MIN,"ton"));
    CHECK_FALSE(NumberWithUnits(1,"day")==NumberWithUnits(23,"hour"));
    CHECK_FALSE(NumberWithUnits(-1,"day")==NumberWithUnits(-25,"hour"));
    CHECK_FALSE(NumberWithUnits(1,"hour")==NumberWithUnits(0,"day"));
    CHECK_FALSE(NumberWithUnits(60*24+1,"min")==NumberWithUnits(1,"day"));
    CHECK_FALSE(NumberWithUnits(1.1,"day")==NumberWithUnits(60*24,"min"));
    CHECK_FALSE(NumberWithUnits(1,"day")==NumberWithUnits(61*24,"min"));
    CHECK_FALSE(NumberWithUnits(-10,"day")==NumberWithUnits(0.0001,"sec"));
    CHECK_FALSE(NumberWithUnits(-5,"kg")==NumberWithUnits(-4,"kg"));
    CHECK_FALSE(NumberWithUnits(0.9,"day")==NumberWithUnits(60*24,"min"));
    CHECK(NumberWithUnits(-0,"sec")==NumberWithUnits(+0,"sec"));
    CHECK(NumberWithUnits(-0,"sec")==NumberWithUnits(0,"sec"));
    CHECK(NumberWithUnits(240,"kg")==NumberWithUnits(240,"kg"));
    CHECK(NumberWithUnits(1,"day")==NumberWithUnits(60*24,"min"));
    CHECK(NumberWithUnits(1,"day")==NumberWithUnits(1,"day"));
}
TEST_CASE("Operators ++ test"){
    NumberWithUnits unit1=NumberWithUnits(1,"sec");
    NumberWithUnits unit2= unit1++;
    CHECK(unit2==NumberWithUnits(1,"sec"));
    CHECK(unit1==NumberWithUnits(2,"sec"));
    NumberWithUnits unit3=NumberWithUnits(1,"min");
    CHECK(unit3==NumberWithUnits(60,"sec"));
    unit3++;
    CHECK(unit3==NumberWithUnits(120,"sec"));
    unit3++;
    CHECK(unit3==NumberWithUnits(3,"min"));
    NumberWithUnits unit4=++unit3;
    CHECK(unit4==unit3);
    CHECK(unit4==NumberWithUnits(4,"min"));
    NumberWithUnits unit5=++++++unit3;
    CHECK(unit5==unit3);
    CHECK(unit5==NumberWithUnits(7,"min"));
    NumberWithUnits unitA=NumberWithUnits(1.42,"kg");
    NumberWithUnits unitB =unitA++;
    CHECK(unitA==NumberWithUnits(2.42,"kg"));
    CHECK(unitB==NumberWithUnits(1.42,"kg"));
    NumberWithUnits unitC =++unitA;
    CHECK(unitA==NumberWithUnits(3.42,"kg"));
    CHECK(unitC==NumberWithUnits(3.42,"kg"));
}
TEST_CASE("Operators -- test"){
    NumberWithUnits unit1=NumberWithUnits(1,"sec");
    NumberWithUnits unit2= unit1--;
    CHECK(unit2==NumberWithUnits(1,"sec"));
    CHECK(unit1==NumberWithUnits(0,"sec"));
    NumberWithUnits unit3=NumberWithUnits(1,"min");
    CHECK(unit3==NumberWithUnits(60,"sec"));
    unit3--;
    CHECK(unit3==NumberWithUnits(0,"sec"));
    unit3--;
    CHECK(unit3==NumberWithUnits(-1,"min"));
    NumberWithUnits unit4=--unit3;
    CHECK(unit4==unit3);
    CHECK(unit4==NumberWithUnits(-2,"min"));
    NumberWithUnits unit5=------unit3;
    CHECK(unit5==unit3);
    CHECK(unit5==NumberWithUnits(-5,"min"));
    NumberWithUnits unitA=NumberWithUnits(1.42,"kg");
    NumberWithUnits unitB =unitA--;
    CHECK(unitA==NumberWithUnits(0.42,"kg"));
    CHECK(unitB==NumberWithUnits(1.42,"kg"));
    NumberWithUnits unitC =--unitA;
    CHECK(unitA==NumberWithUnits(0.42-1,"kg"));
    CHECK(unitC==NumberWithUnits(0.42-1,"kg"));
}
TEST_CASE("Operators * test"){
    CHECK(NumberWithUnits(1,"ton")*4==4*NumberWithUnits(1,"ton"));
    CHECK(NumberWithUnits(1,"ton")*4==NumberWithUnits(4,"ton"));
    CHECK(NumberWithUnits(1,"ton")*-30==-30*NumberWithUnits(1,"ton"));
    CHECK(NumberWithUnits(1,"ton")*-30==NumberWithUnits(-30,"ton"));
    CHECK(NumberWithUnits(0,"kg")*200==200*NumberWithUnits(0,"kg"));
    CHECK(NumberWithUnits(0,"kg")*200==NumberWithUnits(0,"kg"));
    CHECK(NumberWithUnits(999999,"min")*0==NumberWithUnits(0,"min"));
    CHECK(NumberWithUnits(999999,"min")*0==0*NumberWithUnits(999765,"min"));
    CHECK(NumberWithUnits(-54,"min")*-0==NumberWithUnits(0,"min"));
    CHECK(NumberWithUnits(-59,"min")*+0==NumberWithUnits(0,"min"));
    CHECK(NumberWithUnits(-666,"min")*1==NumberWithUnits(-666,"min"));
    CHECK(NumberWithUnits(666,"min")==-1*NumberWithUnits(-666,"min"));
    CHECK(NumberWithUnits(1000,"kg")*0.1==NumberWithUnits(100,"kg"));
    CHECK(NumberWithUnits(1000,"kg")*0.1==0.1*NumberWithUnits(1000,"kg"));
    CHECK(NumberWithUnits(-1500,"kg")==1.5*-NumberWithUnits(1000,"kg"));
    CHECK(NumberWithUnits(500,"kg")==0.5*+NumberWithUnits(1000,"kg"));
}
void Initializes_unit_using_input(istringstream &input ,string str,NumberWithUnits& unit){
    input =istringstream{str};
    input >> unit;
}
TEST_CASE("output and input test"){
    stringstream out_30_kg;
    stringstream out_1_hour;
    stringstream out__6_min;
    stringstream out_999999_day;
    stringstream out_MIN;
    stringstream out_MAX;
    out_30_kg << NumberWithUnits(30,"kg");
    out_1_hour << NumberWithUnits(1,"hour");
    out__6_min << NumberWithUnits(-6,"min");
    out_999999_day << NumberWithUnits(999999,"day");
    out_MAX << NumberWithUnits(DBL_MAX,"day");
    out_MIN << NumberWithUnits(DBL_MIN,"day");
    CHECK(out_30_kg.str()=="30[kg]");
    CHECK(out_1_hour.str()=="1[hour]");  
    CHECK(out__6_min.str()=="-6[min]");
    CHECK(out_999999_day.str()=="999999[day]");
    CHECK(out_MAX.str()=="1.79769e+308[day]");
    CHECK(out_MIN.str()=="2.22507e-308[day]");
    istringstream input;
    NumberWithUnits unit=NumberWithUnits(0,"sec");
    Initializes_unit_using_input(input,"700[kg]",unit);
    CHECK(unit==NumberWithUnits(700,"kg"));
    Initializes_unit_using_input(input,"1[day]",unit);
    CHECK(unit==NumberWithUnits(1,"day"));
    Initializes_unit_using_input(input,"60[ sec ]",unit);
    CHECK(unit==NumberWithUnits(60,"sec"));
    Initializes_unit_using_input(input,"-15  [ hour ]",unit);
    CHECK(unit==NumberWithUnits(-15,"hour"));
    Initializes_unit_using_input(input,"-0  [ ton ]",unit);
    CHECK(unit==NumberWithUnits(0,"ton")); 
    Initializes_unit_using_input(input,"+0  [ sec ]",unit);
    CHECK(unit==NumberWithUnits(0,"sec"));
    Initializes_unit_using_input(input,"999999[day]   ",unit);
    CHECK(unit==NumberWithUnits(999999,"day")); 
    Initializes_unit_using_input(input,"-444444987[day]",unit);
    CHECK(unit==NumberWithUnits(-444444987,"day"));          
    CHECK_THROWS(Initializes_unit_using_input(input,"1[seC]",unit));
    CHECK_THROWS(Initializes_unit_using_input(input,"4[s]",unit));
    CHECK_THROWS(Initializes_unit_using_input(input,"7[HOUR]",unit));
    CHECK_THROWS(Initializes_unit_using_input(input,"-250[DAY]",unit));
    CHECK_THROWS(Initializes_unit_using_input(input,"1000[]",unit));
    CHECK_THROWS(Initializes_unit_using_input(input,"1[usd]",unit));
    CHECK_THROWS(Initializes_unit_using_input(input,"-00[seC]",unit));
    CHECK_THROWS(Initializes_unit_using_input(input,"1[123455]",unit));
    CHECK_THROWS(Initializes_unit_using_input(input,"1[  ]",unit));
}
