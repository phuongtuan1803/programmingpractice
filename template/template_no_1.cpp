#include <bits/stdc++.h>

//#undef _DEBUG

using namespace std;

/*  ====== PRE DEFINE ================================================================================================================ */
#ifdef _DEBUG
#define _INIT_()
#define _START_TIMESTAMP_()      auto start = chrono::steady_clock::now();
#define _STOP_TIMESTAMP_()       cout << "Elapsed time in milliseconds: " \
                                    << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() \
                                    << " ms" << '\n';

#define _TESTCASEFILE_          (string(__FILE__).substr(0, string(__FILE__).length() - 4 ) + ".txt")
ifstream ifile( _TESTCASEFILE_ , ifstream::in);
#define cinstream ifile

#else
#define _INIT_()                ios::sync_with_stdio(false);\
                                cin.tie(NULL);
#define _START_TIMESTAMP_()
#define _STOP_TIMESTAMP_()

#define cinstream cin
#endif
/*  ================================================================================================================================== */

/* GLOBAL VAR */
char c[150];

int main()
{
    _INIT_();

    /*  INPUT*/
    int T;
    cinstream >> T;

#ifdef _DEBUG
    printf("Loading Testcase from file %s\n Number of TestCase: %d.\n", T);
    printf("=================================\n");
#endif

    _START_TIMESTAMP_();
    
    for (int i = 0; i < T; i++)
    {   
        /* 
        FOR NUMBER 
            cinstream >> n >> x;

        FOR NUMBER ARRAY
            for(int j = 0; j < n ; ++j){
                cinstream >> tmp;
                s[j] = tmp;
            }

        FOR STRING
            string s;
            cinstream >> s;
            strcpy(c, s.c_str());
        */

#ifdef _DEBUG
        cout << "testcase: s = " << '\n';
#else
        cout << output << '\n';
#endif
    }

    _STOP_TIMESTAMP_();
    return 0;
}
