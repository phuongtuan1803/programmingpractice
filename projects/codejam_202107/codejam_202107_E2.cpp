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
#define _DEEP string(deep*3,' ').c_str()
/* GLOBAL VAR */
bool check_condition1(vector<int>& h,vector<int>& r, vector<int> order){
    if(order.size() == 1) return true;
    if(r[order[0]] == r[order[1]]) return false;

    int i = 1;
    for( ; i < order.size() - 1 ; i++){
        if(r[order[i-1]] > r[order[i]] && r[order[i]] < r[order[i+1]]){
            // do nothing
        } else if(r[order[i-1]] < r[order[i]] && r[order[i]] > r[order[i+1]]){
            // do nothing
        } else{
            return false;
        }
    }
    return true;
}

bool check_condition2(vector<int>& h,vector<int>& r, vector<int> order){
    bool h_increase = false;
    bool h_reverted = false;

    int i = 1;
    for( ; i < order.size() ; i++){
        if(!h_increase && h[order[i-1]] < h[order[i]]){
            h_increase = true;
        } else if(!h_increase && h[order[i-1]] >= h[order[i]]){
            return false;
        }
        
        if(h_reverted && h[order[i-1]] <= h[order[i]]){
            return false;
        } else if(h_increase && !h_reverted && h[order[i-1]] > h[order[i]]){
            h_reverted = true;
        }
    }
    if(h_reverted){
        return true;
    } else {
        return false;
    }
}
int coutfunction = 0;
bool search(vector<int>& h,vector<int>& r, int n, vector<int>& permutation, bool chosen[], int deep){
    // TRACE("DEBUG:: %s| go here", _DEEP);
    coutfunction++;
    if(permutation.size() == n){
        cout << "test: ";
        for(auto v : permutation){
            cout << (v + 1) << " ";
        }
        cout << '\n';
        if(check_condition2(h,r,permutation)){
            // TRACE("DEBUG:: %s| go here ss", _DEEP);
            return true;
        } else{
            return false;
        }
    } else{
        for(int i = 0 ; i < n ; i++){
            if(chosen[i]) continue;
            chosen[i] = true;
            permutation.push_back(i);
            
            if(check_condition1(h,r,permutation)){
                bool check = search(h,r,n,permutation,chosen,deep+1);
                if(check){
                    return true;
                }
            }            
            chosen[i] = false;
            permutation.pop_back();            
        }
        return false;
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
    while (T--) { 
        int n;
        cinstream >> n;
        vector<int> h(n);
        for (int i=0; i<n; i++) {
            cinstream >> h[i];
        }
        vector<int> r(n);
        for (int i=0; i<n; i++) {
            cinstream >> r[i];
        }
        coutfunction = 0;
        // Insert code here
        vector<int> permutation;
        bool chosen[n] = {false};
        bool check = search(h,r,n, permutation, chosen, 0);
    	
        if(check == false){
            cout << "-1" << '\n';
        }
        else{
            for(auto v : permutation){
                cout << (v+1) << " ";
            }
            cout << '\n';
        }

        cout << "countfunction: " << coutfunction << '\n';
        // End of insertion
    }

    _STOP_TIMESTAMP_();
    return 0;
}
