#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <iterator>
#include <fstream>

using namespace std;
#define _DEBUG_

#ifdef _DEBUG_
#include <chrono>
#endif

int total = 0;
void permute(int i, vector<int> &s, int x)
{
    for(int i = 0 ; i< s.size()-1; i++){
        for(int j = i+1; j< s.size() ;j++){
            if(((s[i]^s[j])^x) == 0){
                total++;
            }
        }
    }
}
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

    vector<tuple <int, int, vector<int>>>  testcases;   
    int T, n, x;
    vector<int> arr;
    int tmp;
    cinstream >> T;

#ifdef _DEBUG_
        auto start = chrono::steady_clock::now();
        printf("====================================\n");
#endif

    for (int i = 0; i < T; i++)
    {   
        arr.clear();
        total = 0;  
        cinstream >> n >> x;
        for(int j = 0; j < n ;j++){
            cinstream >> tmp;
            arr.push_back(tmp);
        }
#ifdef _DEBUG_
        printf("testcase: n = %d. x = %d. input_size = %d\n",n,x, arr.size());
#endif
        testcases.push_back(make_tuple(n,x,arr));
    }
    
    for (auto &it : testcases)
    {
        tie(n,x,arr) = it;        
        permute(0, arr, x);
        cout << total << '\n';
    }
#ifdef _DEBUG_
        cout << "Elapsed time in milliseconds: " << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() << " ms" << '\n';
#endif
    return 0;
}
