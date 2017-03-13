// Binary to String: Given a real number between 0 and 1 (e.g., 0.72) that is passed in as a double,
// print the binary representation. If the number cannot be represented accurately in binary with at
// most 32 characters, print "ERROR:'

#include <cstdint>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <limits>

std::string binaryToStringMul(double binary)
{
    std::stringstream str;
    if (binary < 0 || binary > 1)
        return "ERROR";
    if (binary == 1)
        return "1";
    if (binary == 0)
        return "0";

    str << "0.";

    while (binary != 0)
    {
        if (str.tellp() > 32)
            return "ERROR";

        binary *= 2;
        if (binary >= 1)
        {
            str << '1';
            binary -= 1;
        }
        else
            str << '0';
    }
    return str.str();
}

std::string binaryToStringDiv(double binary)
{
    std::stringstream str;
    if (binary < 0 || binary > 1)
        return "ERROR";
    if (binary == 1)
        return "1";
    if (binary == 0)
        return "0";

    double mantissaBit = 0.5;
    str << "0.";

    while (binary != 0)
    {
        if (str.tellp() > 32)
            return "ERROR";

        if (binary >= mantissaBit)
        {
            str << '1';
            binary -= mantissaBit;
        }
        else
            str << '0';
        mantissaBit /= 2;
    }
    return str.str();
}

int main()
{
    double value = 0;
    double frac = 1.0 / 2 + 1.0 / 8;

    std::cout << std::setprecision(std::numeric_limits<double>::digits10 + 1);

    for (int i = 0; i < 10; ++i)
    {
        std::cout << value << ": " << binaryToStringMul(value) << "(b), " << binaryToStringDiv(value) << "(b)\n";
        value += frac;
        frac /= 16;
    }
}
