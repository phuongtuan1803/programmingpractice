//https://leetcode.com/problems/unique-paths/

#include <bits/stdc++.h>

//#undef _DEBUG

using namespace std;

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
int path[101][101];
int uniquePaths(int m, int n) {
    if(path[1][1] != 1){
        memset(path, -1, sizeof(path));
        path[1][1] = 1;
    }
    if(m ==0 || n == 0){
        return 0;
    }
    if(path[m][n] != -1){
        return path[m][n];
    }
    int result = uniquePaths(m,n-1) + uniquePaths(m-1,n);
    path[m][n] = result;
    return result;    
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
        int m, n;
        cinstream >> m >> n;
        TRACE("DEBUG:: Input: m = %d.  n = %d", m , n); 
        int output = uniquePaths(m,n);
        TRACE("DEBUG:: output: %d", output);
        cout << output << '\n';

    }

    _STOP_TIMESTAMP_();
    return 0;
}
