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
#define coutstream cout

#else
#define _INIT_()                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);
#define _START_TIMESTAMP_()
#define _STOP_TIMESTAMP_()

#define cinstream cin
#define coutstream cout
#endif

/*  ================================================================================================================================== */

/* GLOBAL VAR */
#define MAX(x, y, z) ((x > y && x > z) ? x : (y > z) ? y \
                                                     : z)

string crossing(string s, int left, int mid, int right, int deep)
{
    cout << string(deep * 3, ' ') << "crossing: mid: " << mid << '\n';
    string retval = string(1, s.at(mid));
    string retval1 = "";
    string retval2 = "";

    for (int i = mid - 1, j = mid + 1; i >= left && j <= right; i--, j++)
    {
        if (s.at(i) == s.at(j))
        {
            retval = s.at(i) + retval + s.at(j);
        }
        else
        {
            break;
        }
    }

    for (int i = mid - 1, j = mid; i >= left && j <= right; i--, j++)
    {
        if (s.at(i) == s.at(j))
        {
            retval1 = s.at(i) + retval1 + s.at(j);
        }
        else
        {
            break;
        }
    }

    for (int i = mid, j = mid + 1; i >= left && j <= right; i--, j++)
    {
        if (s.at(i) == s.at(j))
        {
            retval2 = s.at(i) + retval2 + s.at(j);
        }
        else
        {
            break;
        }
    }

    int maxlen = max(max(retval.size(), retval1.size()), retval2.size());
    return retval.size() == maxlen ? retval : retval1.size() == maxlen ? retval1
                                                                       : retval2;
}

string divide(string s, int left, int right, int deep)
{
    cout << string(deep * 3, ' ') << "left: " << left << ". right: " << right << '\n';
    if (left > right)
        return "";

    if (left == right)
        return s.substr(left, 1);

    if (right - left == 2)
    {
        return crossing(s, left, left + 1, right, deep + 1);
    }
    if (right - left == 1)
    {
        if (s.at(left) == s.at(right))
        {
            return s.substr(left, 2);
        }
        else
        {
            return s.substr(left, 1);
        }
    }
    int mid = (left + right) / 2;

    string leftstr = divide(s, left, mid, deep + 1);
    string rightstr = divide(s, mid, right, deep + 1);
    string midstr = crossing(s, left, mid, right, deep + 1);
    cout << string((deep + 1) * 3, ' ') << "++ "
         << "leftstr: " << leftstr << ". rightstr: " << rightstr << ". midstr: " << midstr << '\n';
    int maxlen = max(max(leftstr.size(), rightstr.size()), midstr.size());
    return leftstr.size() == maxlen ? leftstr : midstr.size() == maxlen ? midstr
                                                                        : rightstr;
}

string longestPalindrome(string s)
{
    return divide(s, 0, s.size() - 1, 0);
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
