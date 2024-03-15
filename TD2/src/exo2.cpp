#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <math.h>

#include "utils.hpp"
#include "global.hpp"

using namespace std;

/* *********** TRI RAPIDE ************* */

size_t quick_sort_partition(vector<float> &vec, size_t const &min, size_t const &max)
{
    float pivot{vec[max]};
    size_t min_index{min - 1};

    for (size_t i{min}; i < max; i++)
    {
        if (vec[i] < pivot)
        {
            min_index++;
            swap(vec[min_index], vec[i]);
        }
    }

    swap(vec[min_index + 1], vec[max]);
    return min_index + 1;
}

void quick_sort(vector<float> &vec)
{
    quick_sort(vec, 0, vec.size() - 1);
}

void quick_sort(vector<float> &vec, size_t const &min, size_t const &max)
{
    if (min < max)
    {
        size_t indexPivot = quick_sort_partition(vec, min, max);

        // Left Part
        size_t newMax = indexPivot - 1;
        quick_sort(vec, min, newMax);

        // Right Part
        size_t newMin = indexPivot + 1;
        quick_sort(vec, newMin, max);
    }
}

/* *********** TRI FUSION ************* */

void merge_sort_merge(vector<float> &vec, size_t const left, size_t const right, size_t const middle)
{
    size_t const left_size{middle - left + 1};
    size_t const right_size{right - middle};
    vector<float> left_vec(vec.begin() + left, vec.begin() + middle + 1);
    vector<float> right_vec(vec.begin() + middle + 1, vec.begin() + right + 1);

    size_t left_index{0};
    size_t right_index{0};

    size_t index{left};

    while (left_index < left_size && right_index < right_size)
    {
        if (left_vec[left_index] < right_vec[right_index])
        {
            vec[index] = left_vec[left_index];
            left_index++;
        }
        else
        {
            vec[index] = right_vec[right_index];
            right_index++;
        }
        index++;
    }

    while (left_index < left_vec.size() - 1)
    {
        vec[index] = left_vec[left_index];
        left_index++;
        index++;
    }
    while (right_index < right_vec.size() - 1)
    {
        vec[index] = right_vec[right_index];
        right_index++;
        index++;
    }
}
void merge_sort(vector<float> &vec)
{
    merge_sort(vec, 0, vec.size() - 1);
}

void merge_sort(vector<float> &vec, size_t const left, size_t const right)
{
    if (left < right)
    {
        size_t middle = (right + left) / 2;
        merge_sort(vec, left, middle);
        merge_sort(vec, middle + 1, right);
        merge_sort_merge(vec, left, right, middle);
    }
}