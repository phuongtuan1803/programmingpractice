#include <bits/stdc++.h>

// #undef _DEBUG

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
#define _DEEP string(deep*3,' ').c_str()
/* GLOBAL VAR */
bool check_max(long long& max_volumn, pair<int, long long>& max_1st, pair<int, long long>& max_2nd, pair<int, long long>& max_check ){
    if(max_2nd.first == -1){
        max_2nd = max_check;
        long long volum = max_1st.second + max_2nd.second ;
        max_volumn = max_volumn  <  volum ?  volum : max_volumn;
    }

    // compare max_1st, max_2nd and max_check
    if(max_check.second > max_1st.second){        
        max_2nd = max_1st;
        max_1st = max_check;
        long long volum = max_1st.second + max_2nd.second ;
        max_volumn = max_volumn  <  volum ?  volum : max_volumn;
        return true;
    } else if (max_check.second >= max_2nd.second){
        max_2nd = max_check;
        long long volum = max_1st.second + max_2nd.second ;
        max_volumn = max_volumn  <  volum ?  volum : max_volumn;
        return true;
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
        int n, x;
        cinstream >> n >> x;
        long long hs, ha, hb, hc;
        long long ws, wa, wb, wc;
        cinstream >> hs >> ha >> hb >> hc;
        cinstream >> ws >> wa >> wb >> wc;

        vector<long long> H(n), W(n);
        H[0] = hs % hc + 1;
        W[0] = ws % wc + 1;
        for (int i=1; i<=n-1; i++) {
            H[i] = H[i-1] + 1 + (H[i-1] * ha + hb) % hc;
            W[i] = (W[i-1] * wa + wb) % wc + 1;
        }

        // cout << n <<" " <<x <<'\n';
        // for(auto i : H){
        //     cout << setprecision(5) << fixed << i <<" ";
        // }
        // cout << '\n';

        // for(auto i : W){
        //     cout << setprecision(5) << fixed << i <<" ";
        // }
        // cout << '\n';
        
        // for(int i = 0 ; i < H.size();i++){
        //     cout << setprecision(5) << fixed << (H[i]*W[i]) <<" ";
        // }
        // cout << '\n';

        long long max_volumn = -1;
        int i,j = 0;
        pair<int,long long> max_1st = make_pair(-1,-1);
        pair<int,long long> max_2nd = make_pair(-1,-1);
        int count_num = 0;

        i = H.size() -1;
        while(i > 0){
            // TRACE("DEBUG:: i %d : j %d : max_volumn %d", i, j, max_volumn);
            max_1st = make_pair(i,  H[i] * W[i]);            
            count_num++;
            for(j = i-1 ; H[i] - H[j] <= x && j >=0 ; j--){
                count_num++;
                // TRACE("DEBUG2:: i %d : j %d : max_volumn %d", i, j, max_volumn);
                pair<int,long long> max_check = make_pair(j, H[j] * W[j]);
                bool check = check_max(max_volumn,max_1st, max_2nd, max_check); 
                if(check){
                    // TRACE("DEBUG3:: 1st %d : 2nd %d : max_volumn %d", max_1st.second, max_2nd.second, max_volumn);
                    i = (max_2nd.first < max_1st.first? max_2nd.first: max_1st.first) ;   
                    j = i;                  
                }                                           
            }
            i=j;
        }

        cout << max_volumn << "\n";
        cout << "fdsaf: " << count_num << "\n";
        // End of insertion
    }

    _STOP_TIMESTAMP_();
    return 0;
}
