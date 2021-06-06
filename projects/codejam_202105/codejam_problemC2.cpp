#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <cmath>
#include <climits>

using namespace std;
#define _DEBUG_

#ifdef _DEBUG_
#include <chrono>
#endif

int primers[6000];
int s[201];
int cur_primers = -1;

void gen_next_prime()
{
    if (cur_primers == -1)
    {
        primers[++cur_primers] = 2;
        primers[++cur_primers] = 3;
        primers[++cur_primers] = 5;
        primers[++cur_primers] = 7;
        primers[++cur_primers] = 11;
        return;
    }
    int tmp = primers[cur_primers];
    bool is_primer;
    while (true)
    {
        tmp++;
        is_primer = true;
        for (int i = 0; i <= cur_primers; i++)
        {
            if ((tmp % primers[i]) == 0)
            {
                is_primer = false;
                break;
            }
        }
        if (is_primer)
        {
            primers[++cur_primers] = tmp;
            return;
        }
    }
}
void gen_2n_prime(int max_value)
{
    while (primers[cur_primers] <= max_value)
    {
        gen_next_prime();
    }
}
int penalty_cal(int prime_index, int n)
{
    int penalty = 0;
    for (int i = 0; i < n; i++)
    {
        penalty += abs(s[i] - primers[i + prime_index]);
    }
    return penalty;
}
int main()
{
#ifdef _DEBUG_
    ifstream ifile("testcase_C.txt", ifstream::in);
#define cinstream ifile
#else
    ios::sync_with_stdio(false);
    cin.tie(NULL);
#define cinstream cin
#endif

    int T;
    int n, tmp;
    int min_penalty;

    cinstream >> T;
    gen_next_prime();
#ifdef _DEBUG_
    printf("Number of TestCase: %d.\n", T);
    printf("=================================\n");    
    auto start = chrono::steady_clock::now();
#endif

    for (int i = 0; i < T; i++)
    {
        cinstream >> n;
        for (int j = 0; j < n; ++j)
        {
            cinstream >> tmp;
            s[j] = tmp;
        }

        sort(s, s + n);
        gen_2n_prime(s[n - 1]);

        min_penalty = INT_MAX;
        for (int k = 0; s[n - 1] >= primers[k]; k++)
        {
            int penalty = penalty_cal(k, n);
            min_penalty = min_penalty > penalty ? penalty : min_penalty;
        }

#ifdef _DEBUG_
        printf("testcase: n = %d.\n", n);
        printf("min_penalty: %d.\n\n", min_penalty);
#else
        cout << min_penalty << '\n';
#endif
    }

#ifdef _DEBUG_
    cout << "Elapsed time in milliseconds: " << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() << " ms" << '\n';
    printf("cur_primers: %d\n", cur_primers);
    // for (int i = 0; i <= cur_primers; i++)
    // {
    //     printf("%d ", primers[i]);
    // }
    printf("\n");
#endif
    return 0;
}
