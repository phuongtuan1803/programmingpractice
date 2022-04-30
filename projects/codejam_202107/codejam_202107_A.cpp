#include <bits/stdc++.h>

//#undef _DEBUG

using namespace std;

#define MOD  1000000007
inline long long int addMOD(long long int a, long long int b){
   return (a % MOD + b % MOD) % MOD;
}
/*  ====== PRE DEFINE ================================================================================================================ */
#ifdef _DEBUG
#define TRACE( format, ... )    printf( "[%s](%d) " format"\n", __FUNCTION__,  __LINE__, __VA_ARGS__ )
#define _INIT_()
#define _START_TIMESTAMP_()      auto start = chrono::steady_clock::now();
#define _STOP_TIMESTAMP_()       TRACE("Elapsed time in milliseconds: %dms\n" , chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count())
#define _TESTCASEFILE_          string(string(__FILE__).substr(0, string(__FILE__).length() - 4 ) + ".txt").c_str()
ifstream ifile( _TESTCASEFILE_ , ifstream::in);
#define cinstream ifile
#else
#define TRACE( format, ... )
#define _INIT_()                ios::sync_with_stdio(false);cin.tie(NULL);
#define _START_TIMESTAMP_()
#define _STOP_TIMESTAMP_()
#define cinstream cin
#endif
/*  ================================================================================================================================== */

/* GLOBAL VAR */

bool get_sum(vector<string>& a ,int* sum, int* num_upper){
    for(int i = 0 ;i < a.size() ; i++){
        int sum_plate = 0;
        for(int j = 0 ;j < a[i].size() ; j++){
            sum_plate += (a[i].at(j) > 'Z' ? a[i].at(j) - 32 : a[i].at(j));
            num_upper[i] += (a[i].at(j) < 'Z' ? 1 : 0);
        }
        sum[i] = sum_plate;
    }

    return true;
}
int main()
{
    _INIT_();

    /*  INPUT*/
    int T;
    cinstream >> T;

    TRACE("DEBUG:: Loading Testcase from file %s", _TESTCASEFILE_);
    TRACE("DEBUG:: Number of TestCase: %d", T);
    TRACE("DEBUG:: %s", std::string(30, '=').c_str());
    _START_TIMESTAMP_();
    
    while (T--) { 
        int n, k;
        cinstream >> n >> k;
        vector<string> a(n);        

        for (int i=0; i<n; i++) {
            cinstream >> a[i];
        }
        
        int sum[100000] = {0};
        int num_upper[100000] = {0};
        int output = 0;
        get_sum(a, sum, num_upper);
        for(int i = 0 ; i < n-1 ; i++){
            for(int j = i + 1 ; j < n ; j++){
                if(sum[i] == sum[j] && num_upper[i] == num_upper[j] ){
                    output++;
                }
            }
        }
        cout << output << '\n';

    }

    _STOP_TIMESTAMP_();
    return 0;
}
