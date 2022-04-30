// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

#include <bits/stdc++.h>

//#undef _DEBUG

using namespace std;

/*  ====== PRE DEFINE ================================================================================================================ */
#ifdef _DEBUG
#define _INIT_()
#define _START_TIMESTAMP_() auto start = chrono::steady_clock::now();
#define _STOP_TIMESTAMP_() cout << "Elapsed time in milliseconds: "                                                         \
                                << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() \
                                << " ms" << '\n';

#define _TESTCASEFILE_ (string(__FILE__).substr(0, string(__FILE__).length() - 4) + ".txt")
ifstream ifile(_TESTCASEFILE_, ifstream::in);
#define cinstream ifile

#else
#define _INIT_()                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);
#define _START_TIMESTAMP_()
#define _STOP_TIMESTAMP_()

#define cinstream cin
#endif

/*  ================================================================================================================================== */

/* GLOBAL VAR */

string checkPalindrome(string s, int i, string longeststr){
    // Precheck
    string leftstr = s.substr(i - longeststr.size()/2+1, longeststr.size()/2 );
    string rightstr1 = s.substr(i,  longeststr.size()/2);
    string rightstr2 = s.substr(i+1 , longeststr.size()/2);

    cout << "   s.at(i): " <<s.at(i)<<'\n';
    cout << "   leftstr: " <<leftstr<<'\n';
    cout << "   rightstr1: " <<rightstr1<<'\n';
    cout << "   rightstr2: " <<rightstr2<<'\n';

    for(int i=0;i<leftstr.size();i++){
        if(leftstr.at(i) == rightstr1.at(leftstr.size()-1-i) || leftstr.at(i) == rightstr2.at(leftstr.size()-1-i)){

        } else{
            return "";
        }
    }
    
    string ret1 = string(1,s.at(i)), ret2 = "";
    int index = 1;
    while(i - index >= 0 && i+ index < s.size() && s.at(i-index) ==s.at(i+index) ){
        ret1 = s.at(i-index) + ret1 + s.at(i+index);
        index++;
    }
    cout << "   ret1: " << ret1 << '\n';
    index = 0;

    while((i - index) >= 0 && (i+1+ index) < s.size() && s.at(i-index) ==s.at(i+1+index) ){
        ret2 = s.at(i-index) + ret2 + s.at(i+1+index);
        index++;
    }    

    return ret1.size() > ret2.size() ? ret1 : ret2;
}

string longestPalindrome(string s)
{
    if(s.size() == 0){
        return "";
    }
    string longeststr = string(1,s.at(0));
    for(int i = 0; i < s.size();i++){
        cout << "     s.size() - i: " << s.size() - i << '\n';
        cout << "     longeststr.size(): " <<longeststr.size() << '\n';
        if(s.size() - i > longeststr.size()/2){
            string strcheck = checkPalindrome(s,i, longeststr);
            cout << "strcheck: " << strcheck << '\n';
            longeststr = strcheck.size() > longeststr.size() ? strcheck : longeststr;
        }
    }
    return longeststr;
}

int main()
{
    _INIT_();

    /*  INPUT*/
    int T;
    cinstream >> T;

#ifdef _DEBUG
    cout << "DEBUG:: Loading Testcase from file " << _TESTCASEFILE_ << "\n";
    cout << "DEBUG:: Number of TestCase: " << T << '\n'
         << std::string(30, '=') << '\n';
#endif

    _START_TIMESTAMP_();

    for (int i = 0; i < T; i++)
    {
        string output;
        string s;
        cinstream >> s;
        cout << "input: " << s << '\n';
        output = longestPalindrome(s);

#ifdef _DEBUG
        cout << ">> output: " << output << '\n'
             << '\n';
#else
        cout << output << '\n';
#endif
    }

    _STOP_TIMESTAMP_();
    return 0;
}
