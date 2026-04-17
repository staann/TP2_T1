#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "romanos.hpp"


TEST_CASE("Numeros romanos - algarismo I", "[romanos]") {
    REQUIRE(romanos_para_decimal("I") == 1);
}

TEST_CASE("Numeros romanos - algarismo V", "[romanos]") {
    REQUIRE(romanos_para_decimal("V") == 5);
}

TEST_CASE("Numeros romanos - algarismo X", "[romanos]") {
    REQUIRE(romanos_para_decimal("X") == 10);
}

TEST_CASE("Numeros romanos - algarismo L", "[romanos]") {
    REQUIRE(romanos_para_decimal("L") == 50);
}

TEST_CASE("Numeros romanos - algarismo C", "[romanos]") {
    REQUIRE(romanos_para_decimal("C") == 100);
}

TEST_CASE("Numeros romanos - algarismo D", "[romanos]") {
    REQUIRE(romanos_para_decimal("D") == 500);
}

TEST_CASE("Numeros romanos - algarismo M", "[romanos]") {
    REQUIRE(romanos_para_decimal("M") == 1000);
}

TEST_CASE("Numeros romanos - repetição válida", "[romanos]") {
    REQUIRE(romanos_para_decimal("II") == 2);
    REQUIRE(romanos_para_decimal("III") == 3);
    REQUIRE(romanos_para_decimal("XX") == 20);
    REQUIRE(romanos_para_decimal("XXX") == 30);
}

TEST_CASE("Numeros romanos - adição simples", "[romanos]") {
    REQUIRE(romanos_para_decimal("VI") == 6);
    REQUIRE(romanos_para_decimal("VII") == 7);
    REQUIRE(romanos_para_decimal("VIII") == 8);
    REQUIRE(romanos_para_decimal("XV") == 15);
    REQUIRE(romanos_para_decimal("XII") == 12);
}

TEST_CASE("Numeros romanos - subtração", "[romanos]") {
    REQUIRE(romanos_para_decimal("IV") == 4);
    REQUIRE(romanos_para_decimal("IX") == 9);
    REQUIRE(romanos_para_decimal("XL") == 40);
    REQUIRE(romanos_para_decimal("XC") == 90);
}

TEST_CASE("Numeros romanos - números complexos", "[romanos]") {
    REQUIRE(romanos_para_decimal("XIV") == 14);
    REQUIRE(romanos_para_decimal("XLIX") == 49);
    REQUIRE(romanos_para_decimal("MCMXCIV") == 1994);
}

TEST_CASE("Numeros romanos - algarismos inválidos", "[romanos]") {
    REQUIRE(romanos_para_decimal("G") == -1);
    REQUIRE(romanos_para_decimal("i") == -1);
}

TEST_CASE("Numeros romanos - repetição inválida", "[romanos]") {
    REQUIRE(romanos_para_decimal("VV") == -1);
    REQUIRE(romanos_para_decimal("LL") == -1);
    REQUIRE(romanos_para_decimal("DD") == -1);
    REQUIRE(romanos_para_decimal("IIII") == -1);
}

TEST_CASE("Numeros romanos - subtração inválida", "[romanos]") {
    REQUIRE(romanos_para_decimal("VX") == -1);
    REQUIRE(romanos_para_decimal("LC") == -1);
    REQUIRE(romanos_para_decimal("DM") == -1);
}

TEST_CASE("Numeros romanos - string vazia", "[romanos]") {
    REQUIRE(romanos_para_decimal("") == -1);
}
