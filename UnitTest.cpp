#include "ASI.hpp"
#include <iostream>


// add number randomizer for fair results
long long num = 100;
long long num2 = 100;
std::string str_num = "1234567890";

void incrementTest()
{
    //
}

void decrementTest()
{
    //
}

void additionTest()
{
    ASI big_num = num;
    ASI big_num2 = num2;
    ASI big_num3 = big_num + big_num2;
    long long sum = num + num2;

    if (big_num3.toInt() == sum)
        std::cout << "addition test   PASSED" << std::endl;
    else
        std::cout << "addition test   FAILED" << std::endl;
}

void subtractionTest()
{
    //
}

void multiplicationTest()
{
    ASI big_num = num;
    ASI big_num2 = num2;
    ASI big_num3 = big_num * big_num2;
    long long product = num * num2;

    if (big_num3.toInt() == product)
        std::cout << "multiplication test   PASSED" << std::endl;
    else
        std::cout << "multiplication test   FAILED" << std::endl;

    //std::cout << product << std::endl;
    //std::cout << big_num3.toInt() << std::endl;
}

void divisionTest()
{
    //
}

void stringConversionTest()
{
    ASI big_num = str_num;
    std::string str_num2 = big_num.toString();

    if (str_num == str_num2)
        std::cout << "string conversion test   PASSED" << std::endl;
    else
        std::cout << "string conversion test   FAILED" << std::endl;
}

void intConversionTest()
{
    ASI big_num = num;
    long long to_int = big_num.toInt();

    if (num == to_int)
        std::cout << "int conversion test   PASSED" << std::endl;
    else
        std::cout << "int conversion test   FAILED" << std::endl;
}

void copyTest()
{
    ASI big_num;
    ASI big_num2 = num;
    big_num = big_num2;

    if (big_num.toString() == str_num && big_num.toInt() == num)
        std::cout << "copy test   PASSED" << std::endl;
    else
        std::cout << "copy test   FAILED" << std::endl;
}

int main()
{
    stringConversionTest();
    intConversionTest();
    copyTest();
    additionTest();
    // subtractionTest();
    multiplicationTest();
    // divisionTest();
    // incrementTest();
    // decrementTest();
    return 0;
}