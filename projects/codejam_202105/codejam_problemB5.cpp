#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <iterator>
#include <fstream>

using namespace std;
#define _DEBUG_
#define MAX_N   100000

#ifdef _DEBUG_
#include <chrono>
#endif

int s[MAX_N];
int total = 0;

int main()
{
#ifdef _DEBUG_
    ifstream ifile ("testcase_B.txt", ifstream::in);
    #define cinstream   ifile
#else
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #define cinstream   cin
#endif
 
    int T, n, x;
    int tmp;
    cinstream >> T;

#ifdef _DEBUG_
        auto start = chrono::steady_clock::now();
#endif

    for (int i = 0; i < T; i++)
    {   
        total = 0;  
        cinstream >> n >> x;
        for(int j = 0; j < n ; ++j){
            cinstream >> tmp;
            s[j] = tmp;
        }
#ifdef _DEBUG_
        printf("testcase: n = %d. x = %d\n",n,x);
#endif
        for(int k = 0 ; k < n-1; ++k){
            for(int j = k+1; j< n ;++j){
                if(((s[k]^s[j])^x) == 0){
                    total++;
                }
            }
        }
        cout << total << '\n';
    }
    
#ifdef _DEBUG_
        cout << "Elapsed time in milliseconds: " << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() << " ms" << '\n';
#endif
    return 0;
}
