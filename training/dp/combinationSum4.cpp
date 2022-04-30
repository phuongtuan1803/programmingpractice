#include <bits/stdc++.h>
// https://leetcode.com/problems/combination-sum-iv/
//#undef _DEBUG

using namespace std;

#define MOD  INT_MAX
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
int combinationSum4(vector<int>& nums, int target) {
    int count[target+1];
    memset(count,0,sizeof(count));

    count[0] = 1; 
    for(int i = 1 ;i <= target;i++){
        for(int j = 0 ;j < nums.size();j++){
            if(i-nums[j]>=0){
                count[i] = addMOD(count[i],count[i-nums[j]]);
                TRACE("DEBUG:: count[%d]: %d", i, count[i]);
            }
        }
    }
    
    return count[target];
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
        int target , max_num, tmp;
        vector<int> nums;
        cinstream >> target >> max_num;
        for (int j = 0; j < max_num; ++j)
        {
            cinstream >> tmp;
            nums.push_back(tmp);
        }
        TRACE("DEBUG:: target: %d", target);
        TRACE("DEBUG:: output: %d", combinationSum4(nums,target));

    }

    _STOP_TIMESTAMP_();
    return 0;
}
