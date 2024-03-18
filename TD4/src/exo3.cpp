#include <iostream>

#include "global.hpp"
#include "utils.hpp"

using namespace std;

bool is_palindrome(string const &str)
{
    return equal(str.begin(), str.end(), str.rbegin());
}