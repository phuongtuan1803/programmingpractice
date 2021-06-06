#include <iostream>
#include <vector>

#include <algorithm>

using namespace std;
#define MOD 1000000007
#define __FOR_DEBUG__
#define __FOR_DEBUG_INFO__

#ifdef __FOR_DEBUG__
#include <chrono>
#endif

void scan_integer(int &number)
{
    register int c;
    number = 0;
    c = getchar(); // extract current character from buffer
    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c > 47 && c < 58); c = getchar())
        number = number * 10 + c - 48;
}

void scan_integers_in_line(vector<int> &numbers)
{
    register int c;
    int number = 0;
    c = getchar();
    do
    {
        for (; (c > 47 && c < 58); c = getchar())
            number = number * 10 + c - 48;
        numbers.push_back(number);
        number = 0;
        if (c != '\n')
            c = getchar();
    } while (c != '\n');
}

// Function to return the count of required pairs
int countPairs(vector<int> a)
{
    int count = 0;
    for (int i = 0; i < a.size() - 1; i++)
    {
        for (int j = i + 1; j < a.size(); j++)
        {
            if (a[i] < a[j])
                count++;
        }
    }
    return count;
}
// PERMUTATION
int total = 0;
void permute(int i, vector<int> s, int a, int b)
{
    if (i == (s.size() - 1))
    {
        int score = countPairs(s);
#ifdef __FOR_DEBUG_INFO__
        cout << "Score: " << score << ". ";
        for (auto &it : s)
            cout << it << ' ';
#endif
        if (score >= a && score <= b)
        {
#ifdef __FOR_DEBUG_INFO__
            cout << " (OK)";
#endif
            total = (total + 1) % MOD;
        }
#ifdef __FOR_DEBUG_INFO__
        cout << '\n';
#endif
        return;
    }

    char prev = -1;
    for (int j = i; j < s.size(); j++)
    {
        vector<int> temp = s;
        if (j > i && temp[i] == temp[j])
            continue;
        if (prev != -1 && prev == s[j])
        {
            continue;
        }
        swap(temp[i], temp[j]);
        prev = s[j];
        permute(i + 1, temp, a, b);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    /* ------- CODING HERE */

    /* ------- INPUT HERE */
    int n, a, b;
    vector<vector<int>> testcases;
    int number_test_case;

#ifdef __FOR_DEBUG__
    number_test_case = 1;
    vector<int> tc{4, 1, 1};
    testcases.push_back(tc);
#else
    register int c;

    scan_integer(number_test_case);
    for (int i = 0; i < number_test_case; i++)
    {
        vector<int> tc;
        scan_integers_in_line(tc);
        testcases.push_back(tc);
    }
#endif

    /* ------- PROCESS HERE */
    // Create array from 1..n, n

    for (auto &it : testcases)
    {
        n = it[0];
        a = it[1];
        b = it[2];
#ifdef __FOR_DEBUG__
        auto start = chrono::steady_clock::now();
        printf("n = %d, a = %d, b = %d\n", n, a, b);
#endif
        vector<int> array(n + 1);
        total = 0;

        for (int i = 0; i < n; i++)
            array[i] = i + 1;
        array[n] = n;
        permute(0, array, a, b);
        cout << total << '\n';
#ifdef __FOR_DEBUG__
        cout << "Elapsed time in milliseconds: " << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() << " ms" << '\n';
#endif
    }

    /* ------- END */
    return 0;
}
