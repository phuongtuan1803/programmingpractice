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
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    vector<vector<int>> path;
    for (auto obstaclerow : obstacleGrid){
        vector<int> v(obstaclerow.size(),0);
        path.push_back(v);
    }
    path.at(0).at(0) = obstacleGrid.at(0).at(0) == 0 ? 1 : 0; 
    for(int i = 0; i < obstacleGrid.size() ; i ++){
        for(int j = 0 ; j < obstacleGrid.at(i).size(); j++){    
            if(obstacleGrid.at(i).at(j) == 1){
                path.at(i).at(j) = 0;
            } else if (!(i == 0 && j == 0)){
                int upval = i-1 >= 0 ? path.at(i-1).at(j) : 0;
                int leftval = j-1>=0 ? path.at(i).at(j-1) : 0;
                path.at(i).at(j) = upval + leftval;
            }
        }
    }
    return path.back().back();
}


int main()
{
    _INIT_();

    _START_TIMESTAMP_();
    
    // vector<int> vect1{ 0, 0, 0 };
    // vector<int> vect2{ 0, 1, 0 };
    // vector<int> vect3{ 0, 0, 0 };
    // vector<vector<int>> obstacleGrid{vect1,vect2,vect3};

    vector<int> vect1{ 1 , 0};
    vector<vector<int>> obstacleGrid{vect1};

    cout << uniquePathsWithObstacles(obstacleGrid);

    _STOP_TIMESTAMP_();
    return 0;
}
