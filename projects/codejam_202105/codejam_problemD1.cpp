#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <cmath>

using namespace std;
#define _DEBUG_

#ifdef _DEBUG_
#include <chrono>
#endif

unsigned long long countDigit(unsigned long long int n)
{
    unsigned long long count = 0;
    while (n != 0)
    {
        n = n / 10;
        ++count;
    }
    return count;
}

int kthdigit(unsigned long long p, int k)
{
    int count = 0;
    while (p > 0 && count < k) {
        int rem = p % 10;
        count++;
        if (count == k)
            return rem;
        p = p / 10;
    } 
    return 0;
}
 
int main()
{
#ifdef _DEBUG_
    ifstream ifile ("testcase_D.txt", ifstream::in);
    #define cinstream   ifile
#else
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #define cinstream   cin
#endif
 
    int T;
    unsigned long long a, b;
    unsigned long long int c;
    unsigned long long int find_number;
    cinstream >> T;

#ifdef _DEBUG_
        auto start = chrono::steady_clock::now();
#endif

    for (int i = 0; i < T; i++)
    {   
        cinstream >> a >> b >> c;
#ifdef _DEBUG_
        printf("testcase: a = %d. b = %d. c = %d\n",a,b,c);
#endif
        unsigned long long int digits = 0, cur_digits = 0, cur_number = a;
        int id = 0;
        while(true){            
            cur_digits = countDigit(cur_number);
            digits += cur_digits;            
            if(digits >= c){
                unsigned long long int tmp =  (digits - c) +1;
#ifdef _DEBUG_
                printf("        >> cur_number = %llu. cur_digits = %10d. digits = %10d\n",cur_number,cur_digits,digits);
                printf("        >> tmp = %d. id = %d.\n",tmp, id);
#endif
                find_number = kthdigit(cur_number,tmp);
                break;
            }
            cur_number += b;
        }


        cout << find_number << '\n';
    }
    
#ifdef _DEBUG_
        cout << "Elapsed time in milliseconds: " << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() << " ms" << '\n';
#endif
    return 0;
}
