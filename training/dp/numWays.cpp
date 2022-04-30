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

int dp[501][501];

int numWays(int steps, int arrLen) {

    int max_distance = min(steps/2+1, arrLen);
    dp[0][0] = 0;
    dp[1][0] = 1;
    
    for(int i = 1 ; i < max_distance; i++){
        dp[i][i] = 1;
    }
    for(int i = 2 ; i <= steps; i++){
        for(int j = 0; j < max_distance; j++){
            if(i < j){
                // bypass max distance lager steps
            } else if(dp[i][j] == 0){
                dp[i][j] = addMOD(dp[i][j],dp[i-1][j]);

                if(j-1>=0)
                    dp[i][j] = addMOD(dp[i][j],dp[i-1][j-1]);
                dp[i][j] = addMOD(dp[i][j],dp[i-1][j+1]);
            } 
            TRACE(" dp[%d][%d] = %d", i, j, dp[i][j]);
            if(i == steps){
                break;
            }
        }
    }
    return dp[steps][0];
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
        int steps, arrLen;
        cinstream >> steps >> arrLen;

        int output = numWays(steps, arrLen);
        TRACE("DEBUG:: output: %d", output);


    }

    _STOP_TIMESTAMP_();
    return 0;
}
