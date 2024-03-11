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

int right_part(vector<float> &vec, size_t &indexPivot)
{
    if (indexPivot == vec.size() - 1)
    {
        return int(vec.size() - 1);
    }
    return int(vec.size() - 1 - indexPivot);
}

int quick_sort_partition(vector<float> &vec, int const &min, int const &max)
{
    int pivot = vec[max];
    int min_index = min - 1;

    for (int i = min; i < max; i++)
    {
        if (vec[i] < pivot)
        {
            min_index++;
            swap_two_values(vec, min_index, i);
        }
    }

    swap_two_values(vec, min_index + 1, max);
    return min_index + 1;
}

void quick_sort(vector<float> &vec, int const &min, int const &max)
{
    if (min < max)
    {
        int indexPivot = quick_sort_partition(vec, min, max);

        // Left Part
        int newMax = indexPivot - 1;
        quick_sort(vec, min, newMax);

        // Right Part
        int newMin = indexPivot + 1;
        quick_sort(vec, newMin, max);
    }
}

/* *********** TRI FUSION ************* */

void merge_sort(vector<float> &vec, int const &start, int const &end)
{
    if (start < end)
    {
        int middle = (start + end) / 2;
        merge_sort(vec, start, middle);
        merge_sort(vec, middle + 1, end);
        merge_sort_merge(vec, start, end, middle);
    }
}

void merge_sort_merge(vector<float> &vec, int const &start, int const &end, int const &middle)
{
    vector<float> finalVec(vec.size());
    int leftIndex = start;
    int rightIndex = middle + 1;
    int indexToAdd = start;

    while (leftIndex <= middle && rightIndex <= end)
    {
        if (vec[leftIndex] <= vec[rightIndex])
        {
            finalVec[indexToAdd] = vec[leftIndex];
            leftIndex++;
        }
        else
        {
            finalVec[indexToAdd] = vec[rightIndex];
            rightIndex++;
        }
        indexToAdd++;
    }
    while (leftIndex < middle)
    {
        finalVec[indexToAdd] = vec[leftIndex];
        leftIndex++;
        indexToAdd++;
    }
    while (rightIndex <= end)
    {
        finalVec[indexToAdd] = vec[rightIndex];
        rightIndex++;
        indexToAdd++;
    }
    vec = finalVec;
}