#include <iostream>
#include <vector>
#include <numeric>

#include "global.hpp"
#include "utils.hpp"

using namespace std;

auto const square = [](int sum, int nb)
{
    return sum + nb * nb;
};

auto const even = [](int sum, int nb)
{
    if (nb % 2 == 0)
        return sum * nb;
    return sum;
};

int sum_squared(vector<int> &vec)
{
    return accumulate(vec.begin(), vec.end(), 0, square);
}

int multiply_even(vector<int> &vec)
{
    return accumulate(vec.begin(), vec.end(), 1, even);
}