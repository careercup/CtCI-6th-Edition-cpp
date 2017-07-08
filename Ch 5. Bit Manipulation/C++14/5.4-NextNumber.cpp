// Next Number: Given a positive integer, print the next smallest and the previous largest number that
// have the same number of 1 bits in their binary representation.

#include <tuple>
#include <iostream>
#include "bitutils.hpp"

template <typename T>
std::tuple<T, T> nextBiggerSmaller(T v)
{
    static_assert(std::is_unsigned<T>::value, "T must be unsigned integral type");

    auto result = std::make_tuple(0U, 0U);
    T rightZeros = 0; // tail zero count
    T rightOnes = 0;  // count of tightmost ones between zeros
    T zeroPos = 0;    // first/rightmost zero of 01 bits
    T tmp = v;

    while (tmp != 0 && !(tmp & 1))
    {
        ++rightZeros;
        tmp >>= 1;
    }
    while (tmp != 0 && (tmp & 1))
    {
        ++rightOnes;
        tmp >>= 1;
    }
    zeroPos = rightZeros + rightOnes;
    if (0 < zeroPos && zeroPos < std::numeric_limits<decltype(v)>::digits)
    {
        tmp = v | (1 << zeroPos);     // rightmost non-trailing zero to 1
        // at this point we have one more bit 1
        tmp &= ~((1 << zeroPos) - 1); // reset all bits right from previously set
        tmp |= (1 << (rightOnes - 1)) - 1; // set rightOnes - 1 rightmost bits to 1
        std::get<1>(result) = tmp;
    }

    rightOnes = rightZeros = 0;
    tmp = v;

    while (tmp != 0 && (tmp & 1))
    {
        ++rightOnes;
        tmp >>= 1;
    }
    while (tmp != 0 && !(tmp & 1))
    {
        ++rightZeros;
        tmp >>= 1;
    }
    T onePos = rightZeros + rightOnes; // first/rightmost one of 10 bits
    if (0 < onePos && onePos < std::numeric_limits<decltype(v)>::digits)
    {
        tmp = v & ~(1 << onePos);  // rightmost non-trailing 1 to zero
        // at this point we have one bit 1 less
        tmp |= (1 << onePos) - 1;  // set all bits right from previously reset to 0
        tmp &= ~((1 << (rightZeros - 1)) - 1); // reset rightZeros - 1 rightmost bits to 0
        std::get<0>(result) = tmp;
    }

    return result;
}

int main()
{
    for (uint16_t v : {
              0b11011101111U
            , 0U
            , 0b1111111111111111U
            , 0b0111111111111111U
            , 0b1111111111111110U})
    {
        auto minMax = nextBiggerSmaller(v);
        auto nextMin = std::get<1>(minMax);
        auto prevMax = std::get<0>(minMax);
        std::cout << v << " (" << bits(v) << "b " << countBits(v) << " bits)\nNext min: ";
        if (nextMin > 0)
            std::cout << nextMin << " (" << bits(nextMin) << "b " << countBits(static_cast<unsigned>(nextMin)) << " bits)";
        else
            std::cout << "Not existing";
        std::cout << "\nPrev max: ";
        if (prevMax > 0)
            std::cout << prevMax << " (" << bits(prevMax) << "b " << countBits(static_cast<unsigned>(prevMax)) << " bits)";
        else
            std::cout << "Not existing";
        std::cout << std::endl << std::endl;
    }

    uint8_t v = 1; // rightmost
    do
    {
        std::cout << bits(v) << '\n';
        v = std::get<1>(nextBiggerSmaller(v));
    }
    while (v != 0);
    std::cout << std::endl;
    v = 1 << (std::numeric_limits<decltype(v)>::digits - 1);
    do
    {
        std::cout << bits(v) <<  '\n';
        v = std::get<0>(nextBiggerSmaller(v));
    }
    while (v != 0);
}
