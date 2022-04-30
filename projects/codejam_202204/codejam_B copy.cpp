#include <bits/stdc++.h>

#define _DEBUG
// #undef _DEBUG

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
map<long long, long long> mapfomular;
vector<long long> largest_number_wei;
long long n, m;
// vector<long long> A;
long long A[50001];
long long A_count[50001];
vector<long long> x, y;
map<long long, long long>::iterator it;
long long max_value = 0;
long long times = 0;
long long giaithuaarray[50001];

void tinhtruocgiaithua(int max)
{
    for (int x = 0; x < max; x++)
    {
        if (giaithuaarray[x] != 0)
            continue;
        if (x == 0 || x == 1)
            giaithuaarray[x] = 1;
        else
            giaithuaarray[x] = (x * giaithuaarray[x - 1]) % 1000000007;
    }
}

long long giaiThua(int x)
{
    // cout << "            giaithuaarray[x] " << x  << '\n';
    if (giaithuaarray[x] != 0)
    {
        return giaithuaarray[x];
    }

    if (x == 0 || x == 1)
        return 1;

    giaithuaarray[x] = x * giaiThua(x - 1);
    return giaithuaarray[x];
}

long long tohopdongcap(vector<long long> largest_number_wei)
{
    long long ret_val = 1;
    if (largest_number_wei.size() == 1)
    {
        return ret_val;
    }
    int count = 0;
    for (int i = 1; i < largest_number_wei.size(); i++)
    {
        if (largest_number_wei.at(i - 1) == largest_number_wei.at(i))
        {
            if (i == 1)
            {
                count = 2;
            }
            else
            {
                count++;
            }
            if (i == largest_number_wei.size())
            {
            }
        }
        else
        {
            if (i == 1)
            {
                count = 1;
            }
            ret_val *= giaiThua(count);
            count = 1;
        }
    }
    if (count > 0)
    {
        ret_val *= giaiThua(count);
    }
    return ret_val;
}
int main()
{
    _INIT_();
    /*  INPUT*/
    long long T;
    cinstream >> T;

#ifdef _DEBUG
    printf("Loading Testcase from file: %s (Number of TestCase: %d )\n", _TESTCASEFILE_.c_str(), T);
    printf("=================================\n");
#endif

    _START_TIMESTAMP_();

    for (int tc = 0; tc < T; tc++)
    {
#ifdef _DEBUG
        printf("\n\n\n=================================\n");
#endif
        mapfomular.clear();
        largest_number_wei.clear();

        max_value = -1;
        times = 0;
        x.clear();
        y.clear();
        long long tmp;

        cinstream >> n >> m;
        for (int i = 0; i < n; i++)
        {
            cinstream >> A[i];
        }
        tinhtruocgiaithua(n);
        for (int i = 0; i < m; i++)
        {
            cinstream >> tmp;
            x.push_back(tmp);
            cinstream >> tmp;
            y.push_back(tmp);
        }

        // code here
        

        for (int i = 0; i < m; i++)
        {
            for (int j = x[i] - 1; j <= y[i] - 1; j++)
            {
                if (mapfomular.find(j) == mapfomular.end())
                {
                    mapfomular[j] = 1;
                }
                else
                {
                    mapfomular[j] = mapfomular[j] + 1;
                }
            }
        }
        

        for (it = mapfomular.begin(); it != mapfomular.end(); it++)
        {
            largest_number_wei.push_back(it->second);
        }

        std::sort(A.begin(), A.end(), std::greater<long long>());
        std::sort(largest_number_wei.begin(), largest_number_wei.end(), std::greater<long long>());

        max_value = 0;
        for (int j = 0; j < largest_number_wei.size(); j++)
        {
            max_value += A[j] * largest_number_wei[j];
        }

        times = (tohopdongcap(largest_number_wei) * giaiThua(A.size() - largest_number_wei.size())) % 1000000007;

#ifdef _DEBUG
        cout << "testcase: n = " << n << ", m: " << m << ", A.size(): " << A.size() << ", x.size(): " << x.size() << ", y.size(): " << y.size() << '\n';
        cout << max_value << " " << times << '\n';
#else
        cout << max_value << " " << times << '\n';
#endif
    }

    _STOP_TIMESTAMP_();
    return 0;
}