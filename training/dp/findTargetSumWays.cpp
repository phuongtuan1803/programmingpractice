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
int dp[2001];
int count[2001];
int findTargetSumWays(vector<int>& nums, int target) {
    memset(dp,0,2001*sizeof(int));

    for(auto v : nums){
        dp[v] = dp[v- ] + 1;
        count[v]++;
    }
    return dp[target];
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
        int target, num_max, tmp;
        cinstream >> target;

        vector<int> nums;
        cinstream >> num_max;

        for(int j = 0; j < num_max ; ++j){
            cinstream >> tmp;
            nums.push_back(tmp);
        }        
        TRACE("DEBUG:: num_max: %d", num_max);
        TRACE("DEBUG:: output: %d", findTargetSumWays(nums,target));

    }

    _STOP_TIMESTAMP_();
    return 0;
}
