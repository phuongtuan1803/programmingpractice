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
#define MAX_CLOCK 86400

/* GLOBAL VAR */
int convert_time(string s){
    int hour, min, sec;
    sec = (s.at(6)-'0') * 10 + (s.at(7)-'0');
    min = (s.at(3)-'0') * 10 + (s.at(4)-'0');
    hour = (s.at(0)-'0') * 10 + (s.at(1)-'0');

    return hour*3600+min*60+sec;
}
int tick_count = 0;
bool check_sync(bool clock_sync[MAX_CLOCK] ,const vector<int>& t_number,const vector<int>& d_number, int cur_time ,int cur_clock, int n){
    if(cur_clock == n - 1){
        return true;
    }
    if(t_number[cur_clock] != t_number[cur_clock+1] && d_number[cur_clock] == d_number[cur_clock+1]){
        return false;
    }
    int t_number_next1 = (t_number[cur_clock] + (long long int)d_number[cur_clock]*cur_time) % MAX_CLOCK;
    int t_number_next2 = (t_number[cur_clock+1] + (long long int)d_number[cur_clock+1]*cur_time) % MAX_CLOCK;
    t_number_next1 = t_number_next1 < 0 ? t_number_next1+MAX_CLOCK : t_number_next1;
    t_number_next2 = t_number_next2 < 0 ? t_number_next2+MAX_CLOCK : t_number_next2;
    
    clock_sync[cur_time] = t_number_next1 == t_number_next2;
    if(clock_sync[cur_time]){
        // TRACE("DEBUG:: EQUAL at cur_time = %d, clock: %d : (%d,%d)",cur_time,cur_clock,t_number_next1,t_number_next2);
        bool check = check_sync(clock_sync,t_number,d_number,cur_time, cur_clock+1 , n);
        if(!check){
            return false;
        }
    }
    return true;
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
        vector<string> t(n);
        for (int i=0; i<n; i++) {
            cinstream >> t[i];
        }
        vector<int> d(n);
        for (int i=0; i<n; i++) {
            cinstream >> d[i];
        }

        bool clock_sync[MAX_CLOCK] = {false};
        vector<int> t_number(n);
        vector<int> d_number(n);

        int output = 0;
        for(int i = 0 ;i< n; i++){
            t_number[i] = convert_time(t[i]);            
            d_number[i] = d[i]%MAX_CLOCK;
        }

        if(t_number.size() == 1){
            output = MAX_CLOCK;            
        } else {
            for(int i = 0 ;i < MAX_CLOCK ;i++){
                bool check = check_sync(clock_sync,t_number,d_number,i, 0 , t_number.size());
                if(!check){
                    output = 0;  
                    break;
                }
                output+= clock_sync[i];
            }
        }
        cout << output << '\n';
    }

    _STOP_TIMESTAMP_();
    return 0;
}
