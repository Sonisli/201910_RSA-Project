#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "ReallyLongInt.hpp"
#include "numberTheory.hpp"


TEST_CASE("Testing numberTheory")
{
   SECTION("Testing extendedEuclid method")
   {
     ReallyLongInt zero1(0);
     ReallyLongInt zero2(0);
     ReallyLongInt* x = &zero1;
     ReallyLongInt* y = &zero2;
     ReallyLongInt RLI_1a(888);
     ReallyLongInt RLI_1b(54);
     ReallyLongInt RLI_2a = extendedEuclid(RLI_1a, RLI_1b, x, y);
     REQUIRE((RLI_2a.toString()) == "6");
     REQUIRE((x->toString()) == "-2");
     REQUIRE((y->toString()) == "33");
   }
}
