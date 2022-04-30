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
bool canPartition(vector<int>& nums) {

    int sum = 0;
    for(auto e : nums){
        sum+=e;
    }
    
    if(sum%2 == 1 || sum/2 < nums[0]){
        return false;
    }
    TRACE("DEBUG::  sum: %d",sum);      
    int dp[nums.size()+1][sum/2+1]; 
    memset(dp,0,sizeof(dp));
    for (int i = 1; i <= nums.size(); i++)
    {
        dp[i][0] = 1;
    }
    dp[0][0] = 1;
    for(int i = 1 ; i <= nums.size() ; i++){
        for(int j = 1 ; j <= sum/2 ; j++){
            if(j - nums[i-1] >= 0){
                dp[i][j] = addMOD(dp[i][j],dp[i-1][j-nums[i-1]]);
                TRACE("DEBUG::  dp[%d][%d]: %d",i ,j,  dp[i][j]);      
            }    
              
        }
    }

    for (int i = 1; i <= nums.size(); i++)
    {
       if(dp[i][sum/2] == 1){
           return true;
       }
    }    
    return false;
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
        int num_max, tmp;
        vector<int> nums;
        cinstream >> num_max;

        for(int j = 0; j < num_max ; ++j){
            cinstream >> tmp;
            nums.push_back(tmp);
        }        
        TRACE("DEBUG:: num_max: %d", num_max);
        TRACE("DEBUG:: output: %d", canPartition(nums));

    }

    _STOP_TIMESTAMP_();
    return 0;
}
