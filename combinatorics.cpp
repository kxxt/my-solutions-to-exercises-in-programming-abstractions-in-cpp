#include "combinatorics.h"

template <typename T>
T fact(T n)
{
    T prod = 1;
    for (T i = n; i > 1; i--)
    {
        prod *= i;
    }
    return prod;
}

template <typename T>
T permutations(T n, T k)
{
    T prod = 1;
    for (T i = n; i > n - k; i--)
    {
        prod *= i;
    }
    return prod;
}

template <typename T>
T combinations(T n, T k)
{
    return permutations(n, k) / fact(k);
}

template int permutations(int n, int k);