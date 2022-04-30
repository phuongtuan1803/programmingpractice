#include <bits/stdc++.h>

#define _DEBUG
// #undef _DEBUG

using namespace std;

/*  ====== PRE DEFINE ================================================================================================================ */
#ifdef _DEBUG
#define _INIT_()
#define _START_TIMESTAMP_() auto start = chrono::steady_clock::now();
#define _STOP_TIMESTAMP_() cout << "Elapsed time in milliseconds: "                                                         \
                                << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() \
                                << " ms" << '\n';

#define _TESTCASEFILE_ (string(__FILE__).substr(0, string(__FILE__).length() - 4) + ".txt")
ifstream ifile(_TESTCASEFILE_, ifstream::in);
#define cinstream ifile

#else
#define _INIT_()                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);
#define _START_TIMESTAMP_()
#define _STOP_TIMESTAMP_()

#define cinstream cin
#endif
/*  ================================================================================================================================== */

/* GLOBAL VAR */
vector<long long > permutation;
vector<bool> chosen;

long long  n,m;
vector<long long > A_p;
vector<long long > A;
vector<long long > x,y;

long long  max_value = 0;
long long  times = 0;

void search()
{
    // cout << "A_p.size(): " << A_p.size() << '\n';
    // return;
    if (permutation.size() == A.size())
    {
        // process permutation
        long long  sum = 0;       
        
        for(long long  i = 0; i < m ; i++){
            if(x[i] == y[i]){
                sum += permutation[x[i]-1];
            } else {
                sum += permutation[x[i]-1] + permutation[y[i]-1];
            }
        }
        if(max_value < sum){
            max_value = sum;
            times = 1;
            for(long long  i = 0 ; i <  n ;i++){
                cout << permutation[i] << " ";
            }
            cout  << "\n";
            cout << "max_value: " << max_value << ", times: " << times << ", sum " << sum << '\n';
            times = (times + 1 ) %1000000007;
        }
    }
    else
    {
        for (long long  i = 0; i < A.size(); i++)
        {
            if (chosen[i])
                continue;
            chosen[i] = true;
            permutation.push_back(A.at(i));
            search();
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}

int  main()
{
    _INIT_();
    /*  INPUT*/
    long long  T;
    cinstream >> T;

#ifdef _DEBUG
    printf("Loading Testcase from file: %s (Number of TestCase: %d )\n", _TESTCASEFILE_.c_str(), T);
    printf("=================================\n");
#endif

    _START_TIMESTAMP_();

    for (long long  i = 0; i < T ; i++)
    {
        // printf("=================================\n");
        permutation.clear();
        chosen.clear();

        max_value = -1;
        times = 0;
        A_p.clear();
        A.clear();
        x.clear();
        y.clear();
        chosen.clear();
        long long  tmp;
        
        cinstream >> n >> m;
        for(long long  i = 0 ; i < n ; i++){
            cinstream >> tmp ;
            A.push_back(tmp);
        }
        
        for(long long  i = 0 ; i < m ; i++){
            cinstream >> tmp ;
            x.push_back(tmp);
            cinstream >> tmp ;
            y.push_back(tmp);
        }

        // code here
        chosen.insert(chosen.end(), n, false);
        // set<long long > tt;
        // for(long long  i = 0 ; i < m ; i++){
        //     tt.insert(x[i]);
        //     tt.insert(y[i]);
        // }

        // // A_p.insert(A_p.end(), n, 0);
        // std::sort(A.begin(), A.end(), std::greater<long long >());
        // // vector<long long > checked(n,false);
        // set<long long >::iterator itr;
        // long long  count = 0;
        // for (itr = tt.begin(); itr != tt.end(); itr++) {
        //     // A_p[*itr-1] = A[count];
        //     A_p.push_back(A[count]);;
        //     for(long long  j = 0 ; j < m ; j++){
        //         if(x[j] == *itr) x[j] = A_p.size()-1;
        //         if(y[j] == *itr) y[j] = A_p.size()-1;
        //         cout << "A[count]: " << A[count] << ", count: " << count<<'\n';
        //     }
        //     cout << "A[count]: " << A[count] << ", count: " << count<<'\n';
        //     count++;
        //     // checked[*itr] = true;
        //     // cout << *itr << " ";
        // }
        // // cout << endl;

        search();

#ifdef _DEBUG
        cout << "testcase: n = " << n << ", m: " << m << ", A.size(): " << A.size()  << ", x.size(): " << x.size()<< ", y.size(): " << y.size()<< '\n';
        cout << max_value << " " << times << '\n';
#else
        cout << max_value << " " << times << '\n';
#endif
    }

    _STOP_TIMESTAMP_();
    return 0;
}