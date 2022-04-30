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
#define _DEEP string(level*3,' ').c_str()
// #define _DEEP string(string(level*3,'') + "| ").c_str()
/* GLOBAL VAR */
unsigned long long int get_hex_value(string s){
    if(s == ""){
        return 0;
    }
    unsigned long long int ret = 0;
    for(int i = s.size() - 1; i >=0 ; i--){
        ret += (s.at(i) >= 'A' ? s.at(i)-'A' + 10 :  s.at(i)-'0') * (unsigned long long int)pow(16,s.size() - 1 - i);
    }
    return ret;
}

int count_string(string prev_value , string s, int level){
    int count = 0;
    TRACE("DEBUG:: %s| full: '%s' - '%s'", _DEEP,prev_value.c_str(), s.c_str());
    if(get_hex_value(prev_value) > get_hex_value(s)){
        TRACE("DEBUG:: %s| X", _DEEP);
        return -1;
    }
    count++;
    TRACE("DEBUG:: %s| incre", _DEEP);
    for(int i = 0; i < s.size()-1 ;i++){
        TRACE("DEBUG:: %s| sub: '%s' - '%s' - '%s'", _DEEP, s.c_str(), s.substr(0,i+1).c_str(), s.substr(i+1,s.size()-i).c_str());
        if(get_hex_value(prev_value) > get_hex_value(s.substr(0,i+1))){
            continue;
        } 
        int tmp = count_string(s.substr(0,i+1), s.substr(i+1,s.size()-i),level+1);
        if(tmp == -1){
            break;
        }
        count += tmp;
        TRACE("DEBUG:: %s| count: %d",_DEEP,count);
    }
    return count;
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
        int n, k;
        string s;
        cinstream >> s;
        
        int output = 0;
        output = count_string("",s,0);        
        cout << output << '\n';
        cout << get_hex_value(s) << '\n';
        
    }
    
    _STOP_TIMESTAMP_();
    return 0;
}
