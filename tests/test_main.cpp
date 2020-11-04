
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2/catch.hpp"
#include "lcrypt.h"

TEST_CASE("main") {
    std::string k1 = "11111111";
    std::string k2 = "22222222";
    std::string content = "abcdefg";

    REQUIRE(lcrypt::tohex(lcrypt::hashkey(k1)) == "0dd711e621437285");

    REQUIRE(lcrypt::tohex(lcrypt::dhexchange(k1)) == "d58a469cfded705e");

    auto r = lcrypt::des_encode(k1, content);
    REQUIRE(lcrypt::base64_encode(r) == "v1uerWSRDzY=");
    REQUIRE(lcrypt::des_decode(k1, r) == content);

    REQUIRE(lcrypt::base64_encode(k1) == "MTExMTExMTE=");
    REQUIRE(lcrypt::base64_decode("MjIyMjIyMjI=") == k2);

    REQUIRE(lcrypt::tohex(k1) == "3131313131313131");
    REQUIRE(lcrypt::fromhex("3232323232323232") == k2);
}
