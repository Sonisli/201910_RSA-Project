#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "ReallyLongInt.hpp"


TEST_CASE("Testing ReallyLongInt class")
{
   SECTION("Testing ReallyLongInt()")
   {
     ReallyLongInt RLI1;
     REQUIRE((RLI1.toString()) == "0");
   }
   
   SECTION("Testing ReallyLongInt(long long num)")
   {
     ReallyLongInt RLI2_0(0);
     REQUIRE((RLI2_0.toString()) == "0");
     REQUIRE((RLI2_0.toStringBinary()) == "0");
     ReallyLongInt RLI2_1(12);
     REQUIRE((RLI2_1.toString()) == "12");
     REQUIRE((RLI2_1.toStringBinary()) == "1100");
     ReallyLongInt RLI2_2(-12);
     REQUIRE((RLI2_2.toString()) == "-12");
     REQUIRE((RLI2_2.toStringBinary()) == "-1100");
   }

   SECTION("Testing ReallyLongInt(const string& numStr)")
   {
     ReallyLongInt RLI3_0("0");
     REQUIRE((RLI3_0.toString()) == "0");
     ReallyLongInt RLI3_1("23");
     REQUIRE((RLI3_1.toString()) == "23");
     ReallyLongInt RLI3_2("-23");
     REQUIRE((RLI3_2.toString()) == "-23");
   }

   SECTION("Testing ReallyLongInt(const ReallyLongInt& other)")
   {
     ReallyLongInt RLI4_1a(-12);
     ReallyLongInt RLI4_2a("23");
     ReallyLongInt RLI4_1b(RLI4_1a);
     ReallyLongInt RLI4_2b(RLI4_2a);
     REQUIRE((RLI4_1b.toString()) == "-12");
     REQUIRE((RLI4_2b.toString()) == "23");
   }

   SECTION("Testing equal, absGreater and greater")
   {
     ReallyLongInt RLI5_1a(12);
     ReallyLongInt RLI5_1b(12);
     ReallyLongInt RLI5_1c(-12);
     ReallyLongInt RLI5_1d(-13);
     REQUIRE(RLI5_1a.equal(RLI5_1b) == true);
     REQUIRE(RLI5_1a.equal(RLI5_1c) == false);
     REQUIRE(RLI5_1d.greater(RLI5_1c) == false);	     
   }

   SECTION("Testing operator= and swap function")
   {
     ReallyLongInt RLI0_1a(12);
     ReallyLongInt RLI0_1b(-38);
     RLI0_1a = RLI0_1b;
     REQUIRE((RLI0_1a.toString()) == "-38");
   }

   SECTION("Testing addition, substraction and flipSign")
   {
     ReallyLongInt RLI6_1a(12);
     ReallyLongInt RLI6_1b(-38);
     ReallyLongInt RLI6_2a = RLI6_1a.absAdd(RLI6_1b);
     ReallyLongInt RLI6_2b = RLI6_1a.absSub(RLI6_1b);
     REQUIRE((RLI6_2a.toString()) == "50");
     REQUIRE((RLI6_2b.toString()) == "-26");
     ReallyLongInt RLI6_2c = -RLI6_2b;
     REQUIRE((RLI6_2c.toString()) == "26");
     
     ReallyLongInt RLI6_3a(56);
     ReallyLongInt RLI6_3b(-27);
     ReallyLongInt RLI6_3c(36);
     ReallyLongInt RLI6_3d(-22);
     ReallyLongInt RLI6_4a = RLI6_3a.add(RLI6_3b);
     ReallyLongInt RLI6_4b = RLI6_3a.add(RLI6_3c);
     ReallyLongInt RLI6_4c = RLI6_3b.add(RLI6_3c);
     ReallyLongInt RLI6_4d = RLI6_3b.add(RLI6_3d);
     REQUIRE((RLI6_4a.toString()) == "29");
     REQUIRE((RLI6_4b.toString()) == "92");
     REQUIRE((RLI6_4c.toString()) == "9");
     REQUIRE((RLI6_4d.toString()) == "-49");
     ReallyLongInt RLI6_5a = RLI6_3a.sub(RLI6_3b);
     ReallyLongInt RLI6_5b = RLI6_3a.sub(RLI6_3c);
     ReallyLongInt RLI6_5c = RLI6_3b.sub(RLI6_3c);
     ReallyLongInt RLI6_5d = RLI6_3b.sub(RLI6_3d);
     REQUIRE((RLI6_5a.toString()) == "83");
     REQUIRE((RLI6_5b.toString()) == "20");
     REQUIRE((RLI6_5c.toString()) == "-63");
     REQUIRE((RLI6_5d.toString()) == "-5");
     ReallyLongInt RLI6_6a = RLI6_3a + RLI6_3b;
     ReallyLongInt RLI6_6b = RLI6_3a - RLI6_3b;
     REQUIRE((RLI6_6a.toString()) == "29");
     REQUIRE((RLI6_6b.toString()) == "83");
   }

   SECTION("Testing multiplication")
   {
     ReallyLongInt RLI7_1a(12);
     ReallyLongInt RLI7_1b(-3);
     ReallyLongInt RLI7_1c(7);
     ReallyLongInt RLI7_1d(-16);
     ReallyLongInt RLI7_2a = RLI7_1a.absMult(RLI7_1a);
     ReallyLongInt RLI7_2b = RLI7_1a.absMult(RLI7_1b);
     ReallyLongInt RLI7_2c = RLI7_1a.absMult(RLI7_1c);
     ReallyLongInt RLI7_2d = RLI7_1a.absMult(RLI7_1d);
     REQUIRE((RLI7_2a.toString()) == "144");
     REQUIRE((RLI7_2b.toString()) == "36");
     REQUIRE((RLI7_2c.toString()) == "84");
     REQUIRE((RLI7_2d.toString()) == "192");
     ReallyLongInt RLI7_3a = RLI7_1a.mult(RLI7_1a);
     ReallyLongInt RLI7_3b = RLI7_1a.mult(RLI7_1b);
     ReallyLongInt RLI7_4a = RLI7_1a * RLI7_1a;
     ReallyLongInt RLI7_4b = RLI7_1a * RLI7_1b;
     REQUIRE((RLI7_3a.toString()) == "144");
     REQUIRE((RLI7_3b.toString()) == "-36");
     REQUIRE((RLI7_4a.toString()) == "144");
     REQUIRE((RLI7_4b.toString()) == "-36");
   }

   SECTION("Testing division")
   {
     ReallyLongInt RLI8_1a(1);
     ReallyLongInt RLI8_1b(27);
     ReallyLongInt RLI8_1c(-5);
     ReallyLongInt RLI8_1_r;
     ReallyLongInt RLI8_1_q;
     ReallyLongInt RLI8_2_r;
     ReallyLongInt RLI8_2_q;
     ReallyLongInt RLI8_3_r;
     ReallyLongInt RLI8_3_q;
     RLI8_1b.absDiv(RLI8_1a, RLI8_1_q, RLI8_1_r); // 27/1
     RLI8_1a.absDiv(RLI8_1c, RLI8_2_q, RLI8_2_r); // 1/(-5)
     RLI8_1b.absDiv(RLI8_1c, RLI8_3_q, RLI8_3_r); // 27/(-5)
     REQUIRE((RLI8_1_r.toString()) == "0");
     REQUIRE((RLI8_1_q.toString()) == "27");
     REQUIRE((RLI8_2_r.toString()) == "1");
     REQUIRE((RLI8_2_q.toString()) == "0");
     REQUIRE((RLI8_3_r.toString()) == "2");
     REQUIRE((RLI8_3_q.toString()) == "5");

     ReallyLongInt RLI8_1d(-22);
     ReallyLongInt RLI8_4_r;
     ReallyLongInt RLI8_4_q;
     ReallyLongInt RLI8_5_r;
     ReallyLongInt RLI8_5_q;
     ReallyLongInt RLI8_6_r;
     ReallyLongInt RLI8_6_q;
     ReallyLongInt RLI8_7_r;
     ReallyLongInt RLI8_7_q;
     RLI8_1a.div(RLI8_1b, RLI8_4_q, RLI8_4_r); //1/27
     RLI8_1b.div(RLI8_1c, RLI8_5_q, RLI8_5_r); //27/-5
     RLI8_1c.div(RLI8_1d, RLI8_6_q, RLI8_6_r); //-5/-22
     RLI8_1d.div(RLI8_1a, RLI8_7_q, RLI8_7_r); //-22/1
     REQUIRE((RLI8_4_r.toString()) == "1");
     REQUIRE((RLI8_4_q.toString()) == "0");
     REQUIRE((RLI8_5_r.toString()) == "2");
     REQUIRE((RLI8_5_q.toString()) == "-5");
     REQUIRE((RLI8_6_r.toString()) == "-5");
     REQUIRE((RLI8_6_q.toString()) == "0");
     REQUIRE((RLI8_7_r.toString()) == "0");
     REQUIRE((RLI8_7_q.toString()) == "-22");
   }

   SECTION("Testing Exponents and isPrime")
   {
     ReallyLongInt zero(0);
     ReallyLongInt one(1);
     ReallyLongInt two(2);
     ReallyLongInt RLI9_1a(5);
     ReallyLongInt RLI9_1b(3);
     ReallyLongInt RLI9_2a = RLI9_1a.exp(RLI9_1b);
     ReallyLongInt RLI9_2b = RLI9_1a.exp(zero);
     ReallyLongInt RLI9_2c = RLI9_1a.exp(one);
     REQUIRE((RLI9_2a.toString()) == "125");
     REQUIRE((RLI9_2b.toString()) == "1");
     REQUIRE((RLI9_2c.toString()) == "5");
     REQUIRE((zero.isPrime()) == false);
     REQUIRE((one.isPrime()) == false);
     REQUIRE((two.isPrime()) == true);
     REQUIRE((RLI9_1a.isPrime()) == true);
     REQUIRE((RLI9_2a.isPrime()) == false);
   }
}
