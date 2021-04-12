#include "NumberWithUnits.hpp"
#include "doctest.h"
#include <string>
#include <iostream>
using namespace ariel;

// 1 km = 1000 m
// 1 m = 100 cm
// 1 kg = 1000 g
// 1 ton = 1000 kg
// 1 hour = 60 min
// 1 min = 60 sec
// 1 USD = 3.33 ILS
NumberWithUnits a = NumberWithUnits(2, "km");
NumberWithUnits b = NumberWithUnits(6, "km");
NumberWithUnits c = NumberWithUnits(8, "km");
NumberWithUnits d = NumberWithUnits(200, "m");
NumberWithUnits e = NumberWithUnits(508, "m");
NumberWithUnits f = NumberWithUnits(708, "m");
NumberWithUnits g = NumberWithUnits(2081, "cm");
NumberWithUnits h = NumberWithUnits(6014, "cm");
NumberWithUnits i = NumberWithUnits(8095, "cm");
NumberWithUnits j = NumberWithUnits(3, "kg");
NumberWithUnits k = NumberWithUnits(78, "kg");
NumberWithUnits l = NumberWithUnits(81, "kg");
NumberWithUnits m = NumberWithUnits(1073, "g");
NumberWithUnits n = NumberWithUnits(406, "g");
NumberWithUnits o = NumberWithUnits(1479, "g");
NumberWithUnits p = NumberWithUnits(6, "ton");
NumberWithUnits q = NumberWithUnits(75, "ton");
NumberWithUnits r = NumberWithUnits(81, "ton");
NumberWithUnits s = NumberWithUnits(24, "hour");
NumberWithUnits t = NumberWithUnits(11, "hour");
NumberWithUnits u = NumberWithUnits(35, "hour");
NumberWithUnits v = NumberWithUnits(68, "min");
NumberWithUnits w = NumberWithUnits(132, "min");
NumberWithUnits x = NumberWithUnits(200, "min");
NumberWithUnits y = NumberWithUnits(280, "sec");
NumberWithUnits z = NumberWithUnits(1094, "sec");
NumberWithUnits a1 = NumberWithUnits(1374, "sec");
NumberWithUnits b1 = NumberWithUnits(81, "USD");
NumberWithUnits c1 = NumberWithUnits(18, "USD");
NumberWithUnits d1 = NumberWithUnits(89, "USD");
NumberWithUnits e1 = NumberWithUnits(444, "ILS");
NumberWithUnits f1 = NumberWithUnits(821, "ILS");
NumberWithUnits g1 = NumberWithUnits(1265, "ILS");


TEST_CASE("operator+ basic")
{
    CHECK(a + b == c);
    CHECK(d + e == f);
    CHECK(g + h == i);
    CHECK(j + k == l);
    CHECK(m + n == o);
    CHECK(p + q == r);
    CHECK(s + t == u);
    CHECK(v + w == x);
    CHECK(y + z == a1);
    CHECK(b1 + c1 == d1);
    CHECK(e1 + f1 == g1);
}