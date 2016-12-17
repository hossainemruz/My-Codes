#include <bits/stdc++.h>
static const unsigned long long small_primes[] ={2,3,5,7,11,13,17,19,23,29};
static const unsigned long long indices[] ={1,7,11,13,17,19,23,29};
bool is_prime(unsigned long long x)
{
    const size_t N = sizeof(small_primes) / sizeof(small_primes[0]);
    for (unsigned long long i = 3; i < N; ++i)
    {
        const unsigned long long p = small_primes[i];
        const unsigned long long q = x / p;
        if (q < p)
            return true;
        if (x == q * p)
            return false;
    }
    for (unsigned long long i = 31; true;)
    {
        unsigned long long q = x / i;
        if (q < i)
            return true;
        if (x == q * i)
            return false;
        i += 6;

        q = x / i;
        if (q < i)
            return true;
        if (x == q * i)
            return false;
        i += 4;

        q = x / i;
        if (q < i)
            return true;
        if (x == q * i)
            return false;
        i += 2;

        q = x / i;
        if (q < i)
            return true;
        if (x == q * i)
            return false;
        i += 4;

        q = x / i;
        if (q < i)
            return true;
        if (x == q * i)
            return false;
        i += 2;

        q = x / i;
        if (q < i)
            return true;
        if (x == q * i)
            return false;
        i += 4;

        q = x / i;
        if (q < i)
            return true;
        if (x == q * i)
            return false;
        i += 6;

        q = x / i;
        if (q < i)
            return true;
        if (x == q * i)
            return false;
        i += 2;
    }
    return true;
}

unsigned long long next_prime(unsigned long long n)
{
    const size_t L = 30;
    const size_t N = sizeof(small_primes) / sizeof(small_primes[0]);
    // If n is small enough, search in small_primes
    if (n <= small_primes[N-1])
        return *std::lower_bound(small_primes, small_primes + N, n);
    // Else n > largest small_primes
    // Start searching list of potential primes: L * k0 + indices[in]
    const size_t M = sizeof(indices) / sizeof(indices[0]);
    // Select first potential prime >= n
    //   Known a-priori n >= L
    size_t k0 = n / L;
    size_t in = std::lower_bound(indices, indices + M, n - k0 * L) - indices;
    n = L * k0 + indices[in];
    while (!is_prime(n))
    {
        if (++in == M)
        {
            ++k0;
            in = 0;
        }
        n = L * k0 + indices[in];
    }
    return n;
}
int main()
{
    unsigned long long n;
    scanf("%llu",&n);
    printf("%llu\n",next_prime(n));
    return 0;
}
