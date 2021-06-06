#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
#define MOD 1000000007
#define __FOR_DEBUG__

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

// PERMUTATION
int total = 0;
//vector<int> subset;
// void permute(int i, vector<int> &s, int x)
// {
//     if (i == s.size()) {
//         if(subset.size() != 2)
//             return;
//         if((subset[0]^subset[1]) == x){
//             total++;
//         }
//     } else if (subset.size() <= 2){
//         subset.push_back(s[i]);
//         permute(i+1,s,x);
//         subset.pop_back();
//         permute(i+1,s,x);
//     }
// }
void permute(int i, vector<int> &s, int x)
{
    for(int i = 0 ; i< s.size()-1; i ++){
        for(int j = i+1; j< s.size() ;j++){
            if((s[i]^s[j]) == x){
                //printf("%d%d\n", s[i], s[j]);
                total++;
            }
        }
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
    register int c;

    scan_integer(T);
    for (int i = 0; i < T; i++)
    {
        vector<int> arr;
        vector<int> n_x;
        scan_integers_in_line(n_x);
        scan_integers_in_line(arr);

        int n, x;
        n = n_x[0];
        x = n_x[1];

        total = 0;
#ifdef __FOR_DEBUG__        
        printf("n = %d, x = %d\n", n, x);
        // for (auto &tmp : arr) {
        //     printf("%d ", tmp);
        // }
        // printf("\n");
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
