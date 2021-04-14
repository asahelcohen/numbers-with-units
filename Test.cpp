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
NumberWithUnits km1 = NumberWithUnits(6, "km");
NumberWithUnits km2 = NumberWithUnits(2, "km");
NumberWithUnits km3 = NumberWithUnits(8, "km");
NumberWithUnits km4 = NumberWithUnits(4, "km");

NumberWithUnits m1 = NumberWithUnits(508, "m");
NumberWithUnits m2 = NumberWithUnits(200, "m");
NumberWithUnits m3 = NumberWithUnits(708, "m");
NumberWithUnits m4 = NumberWithUnits(308, "m");

NumberWithUnits cm1 = NumberWithUnits(6014, "cm");
NumberWithUnits cm2 = NumberWithUnits(2081, "cm");
NumberWithUnits cm3 = NumberWithUnits(8095, "cm");
NumberWithUnits cm4 = NumberWithUnits(3933, "cm");

NumberWithUnits kg1 = NumberWithUnits(78, "kg");
NumberWithUnits kg2 = NumberWithUnits(3, "kg");
NumberWithUnits kg3 = NumberWithUnits(81, "kg");
NumberWithUnits kg4 = NumberWithUnits(75, "kg");

NumberWithUnits g1 = NumberWithUnits(1073, "g");
NumberWithUnits g2 = NumberWithUnits(406, "g");
NumberWithUnits g3 = NumberWithUnits(1479, "g");
NumberWithUnits g4 = NumberWithUnits(667, "g");

NumberWithUnits t1 = NumberWithUnits(75, "ton");
NumberWithUnits t2 = NumberWithUnits(6, "ton");
NumberWithUnits t3 = NumberWithUnits(81, "ton");
NumberWithUnits t4 = NumberWithUnits(69, "ton");

NumberWithUnits h1 = NumberWithUnits(24, "hour");
NumberWithUnits h2 = NumberWithUnits(11, "hour");
NumberWithUnits h3 = NumberWithUnits(35, "hour");
NumberWithUnits h4 = NumberWithUnits(13, "hour");

NumberWithUnits min1 = NumberWithUnits(132, "min");
NumberWithUnits min2 = NumberWithUnits(68, "min");
NumberWithUnits min3 = NumberWithUnits(200, "min");
NumberWithUnits min4 = NumberWithUnits(64, "min");

NumberWithUnits sec1 = NumberWithUnits(1094, "sec");
NumberWithUnits sec2 = NumberWithUnits(280, "sec");
NumberWithUnits sec3 = NumberWithUnits(1374, "sec");
NumberWithUnits sec4 = NumberWithUnits(814, "sec");

NumberWithUnits us1 = NumberWithUnits(81, "USD");
NumberWithUnits us2 = NumberWithUnits(18, "USD");
NumberWithUnits us3 = NumberWithUnits(89, "USD");
NumberWithUnits us4 = NumberWithUnits(63, "USD");

NumberWithUnits il1 = NumberWithUnits(821, "ILS");
NumberWithUnits il2 = NumberWithUnits(444, "ILS");
NumberWithUnits il3 = NumberWithUnits(1265, "ILS");
NumberWithUnits il4 = NumberWithUnits(377, "ILS");

NumberWithUnits km11 = NumberWithUnits(-6, "km");
NumberWithUnits km21 = NumberWithUnits(-2, "km");
NumberWithUnits km31 = NumberWithUnits(-8, "km");
NumberWithUnits km41 = NumberWithUnits(-4, "km");

NumberWithUnits m11 = NumberWithUnits(-508, "m");
NumberWithUnits m21 = NumberWithUnits(-200, "m");
NumberWithUnits m31 = NumberWithUnits(-708, "m");
NumberWithUnits m41 = NumberWithUnits(-308, "m");

NumberWithUnits cm11 = NumberWithUnits(-6014, "cm");
NumberWithUnits cm21 = NumberWithUnits(-2081, "cm");
NumberWithUnits cm31 = NumberWithUnits(-8095, "cm");
NumberWithUnits cm41 = NumberWithUnits(-3933, "cm");

NumberWithUnits kg11 = NumberWithUnits(-78, "kg");
NumberWithUnits kg21 = NumberWithUnits(-3, "kg");
NumberWithUnits kg31 = NumberWithUnits(-81, "kg");
NumberWithUnits kg41 = NumberWithUnits(-75, "kg");

NumberWithUnits g11 = NumberWithUnits(-1073, "g");
NumberWithUnits g21 = NumberWithUnits(-406, "g");
NumberWithUnits g31 = NumberWithUnits(-1479, "g");
NumberWithUnits g41 = NumberWithUnits(-667, "g");

NumberWithUnits t11 = NumberWithUnits(-75, "ton");
NumberWithUnits t21 = NumberWithUnits(-6, "ton");
NumberWithUnits t31 = NumberWithUnits(-81, "ton");
NumberWithUnits t41 = NumberWithUnits(-69, "ton");

NumberWithUnits h11 = NumberWithUnits(-24, "hour");
NumberWithUnits h21 = NumberWithUnits(-11, "hour");
NumberWithUnits h31 = NumberWithUnits(-35, "hour");
NumberWithUnits h41 = NumberWithUnits(-13, "hour");

NumberWithUnits min11 = NumberWithUnits(-132, "min");
NumberWithUnits min21 = NumberWithUnits(-68, "min");
NumberWithUnits min31 = NumberWithUnits(-200, "min");
NumberWithUnits min41 = NumberWithUnits(-64, "min");

NumberWithUnits sec11 = NumberWithUnits(-1094, "sec");
NumberWithUnits sec21 = NumberWithUnits(-280, "sec");
NumberWithUnits sec31 = NumberWithUnits(-1374, "sec");
NumberWithUnits sec41 = NumberWithUnits(-814, "sec");

NumberWithUnits us11 = NumberWithUnits(-81, "USD");
NumberWithUnits us21 = NumberWithUnits(-18, "USD");
NumberWithUnits us31 = NumberWithUnits(-89, "USD");
NumberWithUnits us41 = NumberWithUnits(-63, "USD");

NumberWithUnits il11 = NumberWithUnits(-821, "ILS");
NumberWithUnits il21 = NumberWithUnits(-444, "ILS");
NumberWithUnits il31 = NumberWithUnits(-1265, "ILS");
NumberWithUnits il41 = NumberWithUnits(-377, "ILS");

TEST_CASE("operator+ basic")
{
    CHECK(km1 + km2 == km3);
    CHECK(m1 + m2 == m3);
    CHECK(cm1 + cm2 == cm3);
    CHECK(kg1 + kg2 == kg3);
    CHECK(g1 + g2 == g3);
    CHECK(t1 + t2 == t3);
    CHECK(h1 + h2 == h3);
    CHECK(min1 + min2 == min3);
    CHECK(sec1 + sec2 == sec3);
    CHECK(us1 + us2 == us3);
    CHECK(il1 + il2 == il3);
}

TEST_CASE("operator- basic")
{
    CHECK(km1 - km2 == km4);
    CHECK(m1 - m2 == m4);
    CHECK(cm1 - cm2 == cm4);
    CHECK(kg1 - kg2 == kg4);
    CHECK(g1 - g2 == g4);
    CHECK(t1 - t2 == t4);
    CHECK(h1 - h2 == h4);
    CHECK(min1 - min2 == min4);
    CHECK(sec1 - sec2 == sec4);
    CHECK(us1 - us2 == us4);
    CHECK(il1 - il2 == il4);
}

TEST_CASE("operator+= basic")
{
    km1 += km2;
    CHECK(km1 == km3);
    m1 += m2;
    CHECK(m1 == m3);
    cm1 += cm2;
    CHECK(cm1 == cm3);
    kg1 += kg2;
    CHECK(kg1 == kg3);
    g1 += g2;
    CHECK(g1 == g3);
    t1 += t2;
    CHECK(t1 == t3);
    h1 += h2;
    CHECK(h1 == h3);
    min1 += min2;
    CHECK(min1 + min2 == min3);
    sec1 += sec2;
    CHECK(sec1 == sec3);
    us1 += us2;
    CHECK(us1 == us3);
    il1 += il2;
    CHECK(il1 == il3);

    km1 = km3 - km2;
    m1 = m3 - m2;
    cm1 = cm3 - cm2;
    kg1 = kg3 - kg2;
    g1 = g3 - g2;
    t1 = t3 - t2;
    h1 = h3 - h2;
    min1 = min3 - min2;
    sec1 = sec3 - sec2;
    us1 = us3 - us2;
    il1 = il3 - il2;
}

TEST_CASE("operator-= basic")
{
    km3 -= km2;
    CHECK(km1 == km3);
    m3 -= m2;
    CHECK(m1 == m3);
    cm3 -= cm2;
    CHECK(cm1 == cm3);
    kg3 -= kg2;
    CHECK(kg1 == kg3);
    g3 -= g2;
    CHECK(g1 == g3);
    t3 -= t2;
    CHECK(t1 == t3);
    h3 -= h2;
    CHECK(h1 == h3);
    min3 -= min2;
    CHECK(min1 + min2 == min3);
    sec3 -= sec2;
    CHECK(sec1 == sec3);
    us3 -= us2;
    CHECK(us1 == us3);
    il3 -= il2;
    CHECK(il1 == il3);

    km3 = km3 + km2;
    m3 = m3 + m2;
    cm3 = cm3 + cm2;
    kg3 = kg3 + kg2;
    g3 = g3 + g2;
    t3 = t3 + t2;
    h3 = h3 + h2;
    min3 = min3 + min2;
    sec3 = sec3 + sec2;
    us3 = us3 + us2;
    il3 = il3 + il2;
}

TEST_CASE("operator+ basic")
{
    CHECK(+km1 == km1);
    CHECK(+m1 == m1);
    CHECK(+cm1 == cm1);
    CHECK(+kg1 == kg1);
    CHECK(+g1 == g1);
    CHECK(+t1 == t1);
    CHECK(+h1 == h1);
    CHECK(+min1 == min1);
    CHECK(+sec1 == sec1);
    CHECK(+us1 == us1);
    CHECK(+il1 == il1);

    CHECK(+km11 == km11);
    CHECK(+m11 == m11);
    CHECK(+cm11 == cm11);
    CHECK(+kg11 == kg11);
    CHECK(+g11 == g11);
    CHECK(+t11 == t11);
    CHECK(+h11 == h11);
    CHECK(+min11 == min11);
    CHECK(+sec11 == sec11);
    CHECK(+us11 == us11);
    CHECK(+il11 == il11);
}

TEST_CASE("operator- basic")
{
    CHECK(-km1 == km11);
    CHECK(-m1 == m11);
    CHECK(-cm1 == cm11);
    CHECK(-kg1 == kg11);
    CHECK(-g1 == g11);
    CHECK(-t1 == t11);
    CHECK(-h1 == h11);
    CHECK(-min1 == min11);
    CHECK(-sec1 == sec11);
    CHECK(-us1 == us11);
    CHECK(-il1 == il11);

    CHECK(-km11 == km1);
    CHECK(-m11 == m1);
    CHECK(-cm11 == cm1);
    CHECK(-kg11 == kg1);
    CHECK(-g11 == g1);
    CHECK(-t11 == t1);
    CHECK(-h11 == h1);
    CHECK(-min11 == min1);
    CHECK(-sec11 == sec1);
    CHECK(-us11 == us1);
    CHECK(-il11 == il1);
}

TEST_CASE("operator=/!=/</> basic")
{
    CHECK(km1 != km11);
    CHECK(m1 != m11);
    CHECK(sec1 != sec2);
    CHECK(-cm1 <= cm1);
    CHECK(kg2 <= kg1);
    CHECK(g2 <= g3);
    CHECK(t1 >= t11);
    CHECK(h1 >= h11);
    CHECK(min2 >= -min1);
    CHECK(sec1 > sec11);
    CHECK(us1 > us2);
    CHECK(il3 > il1);
    CHECK(km1 < km3);
    CHECK(m2 < m1);
    CHECK(cm11 < cm2);
    CHECK(-km1 == km11);
    CHECK(m1 == -m11);
    CHECK(cm1 == -cm11);
}

TEST_CASE("operator++/--")
{
    // prefix  - --a
    CHECK(--km1 != km1--);
    NumberWithUnits temp = NumberWithUnits(507, "m");
    CHECK(--m1 == temp);
    temp = NumberWithUnits(1093, "sec");
    CHECK(--sec1 == temp);
    temp = NumberWithUnits(6013, "cm");
    CHECK(--cm1 == temp);
    // postfix - a--
    temp = NumberWithUnits(78, "kg");
    CHECK(kg1-- == kg1);
    CHECK(kg1 != kg1);
    temp = NumberWithUnits(1073, "g");
    CHECK(g1-- == g1);
    CHECK(kg1 != kg1);
    temp = NumberWithUnits(74, "ton");
    CHECK(t1-- != t1);
    temp = NumberWithUnits(23, "hour");
    CHECK(h1-- != h1);
    // prefix  - ++a
    CHECK(++km1 != km1++);
    temp = NumberWithUnits(508, "m");
    CHECK(++m1 == temp);
    temp = NumberWithUnits(1094, "sec");
    CHECK(++sec1 == temp);
    temp = NumberWithUnits(6014, "cm");
    CHECK(++cm1 == temp);
    // postfix - a++
    temp = NumberWithUnits(77, "kg");
    CHECK(kg1++ == kg1);
    CHECK(kg1 != kg1);
    temp = NumberWithUnits(1072, "g");
    CHECK(g1++ == g1);
    CHECK(kg1 != kg1);
    temp = NumberWithUnits(73, "ton");
    CHECK(t1++ != t1);
    temp = NumberWithUnits(22, "hour");
    CHECK(h1++ != h1);
}
