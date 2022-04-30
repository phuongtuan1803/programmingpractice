#include <bits/stdc++.h>
// https://leetcode.com/problems/dice-roll-simulation/
//#undef _DEBUG

using namespace std;

#define MOD 1000000007
inline long long int addMOD(long long int a, long long int b)
{
    return (a % MOD + b % MOD) % MOD;
}
inline long long int mulMOD(long long int a, long long int b)
{
    return (a % MOD * b % MOD) % MOD;
}
/*  ====== PRE DEFINE ================================================================================================================ */
#ifdef _DEBUG
#define TRACE(format, ...) printf("[%s](%d) " format "\n", __FUNCTION__, __LINE__, __VA_ARGS__)
#define _INIT_()
#define _START_TIMESTAMP_() auto start = chrono::steady_clock::now();
#define _STOP_TIMESTAMP_() TRACE("Elapsed time in milliseconds: %dms\n", chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count())
#define _TESTCASEFILE_ string(string(__FILE__).substr(0, string(__FILE__).length() - 4) + ".txt").c_str()
ifstream ifile(_TESTCASEFILE_, ifstream::in);
#define cinstream ifile
#else
#define TRACE(format, ...)
#define _INIT_()                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);
#define _START_TIMESTAMP_()
#define _STOP_TIMESTAMP_()
#define cinstream cin
#endif
/*  ================================================================================================================================== */

/* GLOBAL VAR */


int dieSimulator(int n, vector<int> &rollMax)
{
    int dp[5001][6][16] = { 0 };
    int ret_val;
    for (int dicenum = 0; dicenum < 6; dicenum++)
    {
        dp[1][dicenum][0] = 1;
        dp[1][dicenum][1] =2;
    }

    for (int rolltime = 2; rolltime <= n; rolltime++)
    {
        for (int dicenum = 0; dicenum < 6; dicenum++)
        {
            int rollmaxnum = min(rollMax[dicenum], n);
            // dp[rolltime][dicenum][rollmaxnum] = 1;
            dp[rolltime][dicenum][0] += rollmaxnum + 1;
            TRACE("[%d][%d][%d] = %d", rolltime, dicenum, 0, dp[rolltime][dicenum][0]);
            for (int time = 1; time <= rollmaxnum; time++)
            {
                dp[rolltime][dicenum][time] += dp[rolltime - 1][dicenum][time - 1];
                TRACE("[%d][%d][%d] = %d", rolltime, dicenum, time, dp[rolltime][dicenum][time]);
            }
        }
    }

    for (int dicenum = 0; dicenum < 6; dicenum++)
    {
        int rollmaxnum = min(rollMax[dicenum], n);
        for (int time = 0; time <= rollmaxnum; time++)
        {
            ret_val += dp[n][dicenum][time];
        }        
    }

    return ret_val;
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
        int n, tmp;
        vector<int> rollMax;
        cinstream >> n;
        for (int j = 0; j < 6; ++j)
        {
            cinstream >> tmp;
            rollMax.push_back(tmp);
        }
        int output = dieSimulator(n, rollMax);
        TRACE("DEBUG:: output: %d", output);
    }

    _STOP_TIMESTAMP_();
    return 0;
}
