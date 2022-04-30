#include <bits/stdc++.h>

//#undef _DEBUG

using namespace std;

#define MODULO  1000000007
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
int step[10000001];
int climbStairs(int n) {
    step[0] = 1;
    step[1] = 1;
    step[2] = 2;
    for(int i = 3; i <= n ;i++){
        step[i] = 0;
        for(int j = 1 ; j <= 2 ;j++ ){
            if(n - j >= 0){
                step[i] = step[i]%MODULO + step[i-j]%MODULO;
            }
        }
    }
    return step[n];
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
    
    for (int i = 0; i < T; i++)
    {   
        int n;
        cinstream >> n;

        int output = climbStairs(n);
        TRACE("DEBUG:: output: %d", output);


    }

    _STOP_TIMESTAMP_();
    return 0;
}
