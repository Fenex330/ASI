/*

Arbitrary Size Integer (ASI) - is a C++ header-only, dependency free library
supporting basic ariphmetic operations on signed integers of any size such as:

addition, subtraction, multiplication, division, modulus, absolute, power

floats are not supported at the moment

///////////////////////////////////////////////////////////////////////////////////////////



BSD 3-Clause "New" or "Revised" License

Copyright (c) 2020 Ilya Ballet

All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are
permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of
conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of
conditions and the following disclaimer in the documentation and/or other materials
provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used
to endorse or promote products derived from this software without specific prior written
permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/



#include <vector>
#include <string>
#include <algorithm>


class ASI
{
    typedef long long big; // remove when templates arrive
    typedef unsigned short digit;

    private:
        std::vector <digit> value;
        bool isPositive;

    public:
        ASI() = default;
        ASI (big x);
        ASI (std::string x);
        // add overloaded constructor for floats and trancate decimals

        big toInt();
        void fromInt (big x);
        std::string toString();
        void fromString (std::string x);

        ASI &operator= (const ASI &x);
        ASI operator+ (const ASI &x) const;
        ASI operator- (const ASI &x) const;
        ASI operator* (const ASI &x) const;
        ASI operator/ (const ASI &x) const;
};



ASI::ASI (big x)
{
    fromInt (x);
}

ASI::ASI (std::string x)
{
    fromString (x);
}

long long ASI::toInt()
{
    big x = 0;

    for (size_t i = 0; i < value.size(); ++i)
    {
        x = (x + value.at (i)) * 10;
    }

    x /= 10;

    return x;
}

void ASI::fromInt (big x)
{
    while (x > 9)
    {
        digit y = x % 10;
        value.push_back (y);
        x = (x - y) / 10;
    }

    value.push_back (x);
    std::reverse (value.begin(), value.end());
}

std::string ASI::toString()
{
    std::string x = {};

    for (size_t i = 0; i < value.size(); ++i)
    {
        x.push_back (value.at (i));
    }

    return x;
}

void ASI::fromString(std::string x)
{
    for (size_t i = 0; i < x.size(); ++i)
    {
        value.push_back (x.at (i));
    }
}

ASI &ASI::operator= (const ASI &x) // does not work with toString - returns "", fix later
{
    if (this == &x) return *this;

    value = x.value;

    return *this;
}

ASI ASI::operator+ (const ASI &x) const
{
    ASI buffer;
    ASI self = *this;
    ASI operand = x;

    size_t count;
    big i;
    digit deriv = 0;
    digit v;

    if (self.value.size() > operand.value.size())
    {
        count = self.value.size();
        i = count - 1;
        while (operand.value.size() < count) operand.value.insert(operand.value.begin(), 0);
    }
    else
    {
        count = operand.value.size();
        i = count - 1;
        while (self.value.size() < count) self.value.insert(self.value.begin(), 0);
    }

    while (i >= 0)
    {
        v = self.value.at (i) + operand.value.at (i);

        if (deriv > 0) v++;

        if (v > 9)
        {
            v = v % 10;
            deriv = 1;
        }
        else
        {
            deriv = 0;
        }

        buffer.value.push_back (v);

        if (deriv == 1 && i == 0)
        {
            buffer.value.push_back (1);
        }

        --i;
    }

    std::reverse (buffer.value.begin(), buffer.value.end());

    return buffer;
}

ASI ASI::operator* (const ASI &x) const
{
    ASI buffer;
    ASI self = *this;
    ASI operand = x;

    return buffer;
}