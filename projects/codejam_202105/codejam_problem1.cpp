#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
#define MOD 1000000007
//#define __FOR_DEBUG__

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

void scan_integers_in_line(vector<long long> &numbers)
{
    register long long c;
    long long number = 0;
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


// PERMUTATION
int total = 0;
vector<long long> subset;
void permute(int i, vector<long long> s, long long x)
{
    if (i == s.size()) {
        if(subset.size() != 2)
            return;
        if((subset[0]^subset[1]) == x){
            // for(auto &tmp : subset){
            //     printf("%d", tmp);
            // }
            // printf("   %d\n",subset[0]^subset[1]);
            total++;
        }
    } else {
        // include k in the subset
        subset.push_back(s[i]);
        permute(i+1,s,x);
        subset.pop_back();
        // don’t include k in the subset
        permute(i+1,s,x);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    /* ------- CODING HERE */

    /* ------- INPUT HERE */
    /*
        T: Number TestCase
        n x
        array
    */
    int T;
    vector<tuple <int, int, vector<long long>>>  testcases;    

#ifdef __FOR_DEBUG__
    T = 1;
    vector<long long> tc1{2, 2, 3, 3};
    vector<long long> tc2{2, 3, 3, 2};
    vector<long long> tc3{3, 7, 5, 6};

    testcases.push_back(make_tuple(4,0,tc1));
    testcases.push_back(make_tuple(4,1,tc2));
    testcases.push_back(make_tuple(4,4,tc3));
#else
    register int c;

    scan_integer(T);
    for (int i = 0; i < T; i++)
    {
        vector<long long> testcase;
        vector<long long> n_x;
        scan_integers_in_line(n_x);
        scan_integers_in_line(testcase);

        testcases.push_back(make_tuple(n_x[0],n_x[1],testcase));
    }
#endif

    /* ------- PROCESS HERE */
    // Create array from 1..n, n
    for (auto &it : testcases) 
    {
        int n, x;
        vector<long long> arr;
        tie(n,x,arr) = it;
        total = 0;
#ifdef __FOR_DEBUG__        
        printf("n = %d, x = %d\n", n, x);
        for (auto &tmp : arr) {
            printf("%d ", tmp);
        }
        printf("\n");
        auto start = chrono::steady_clock::now();
#endif
        permute(0, arr,x);
        cout << total << '\n';

#ifdef __FOR_DEBUG__
        cout << "Elapsed time in milliseconds: " << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() << " ms" << '\n';
#endif
    }

    /* ------- END */
    return 0;
}
