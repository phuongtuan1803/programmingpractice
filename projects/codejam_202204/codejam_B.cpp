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

long long largest_number_wei[50001]; 
int size_wei;
long long n, m;
long long A[50001];
long long A_count[50001];
int x_start[50001];
int y_stop[50001];
long long min_index;
long long x[200001];
long long y[200001];
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

    giaithuaarray[x] = (x % 1000000007* giaiThua(x - 1)% 1000000007)  % 1000000007;
    return giaithuaarray[x];
}

long long tohopdongcap()
{
    long long ret_val = 1;
    if (size_wei == 1)
    {
        return ret_val;
    }
    int count = 0;
    for (int i = 1; i < size_wei; i++)
    {
        if (largest_number_wei[i - 1] == largest_number_wei[i])
        {
            if (i == 1)
            {
                count = 2;
            }
            else
            {
                count++;
            }
            if (i == size_wei)
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
    tinhtruocgiaithua(50001);
    for (int tc = 0; tc < T; tc++)
    {
// #ifdef _DEBUG
//         printf("\n=================================\n");
// #endif
        max_value = -1;
        times = 0;
        long long tmp;

        cinstream >> n >> m;

        std::fill_n(A, n, 0);
        std::fill_n(A_count, n, 0);

        std::fill_n(largest_number_wei, n, 0);
        std::fill_n(x, m, 0);
        std::fill_n(y, m, 0);
        std::fill_n(x_start, n, false);
        std::fill_n(y_stop, n, false);

        for (int i = 0; i < n; i++)
        {
            cinstream >> A[i];
        }

        
        for (int i = 0; i < m; i++)
        {
            cinstream >> x[i];
            cinstream >> y[i];
            x_start[x[i] - 1] = x_start[x[i] - 1] + 1;
            y_stop[y[i] - 1] = y_stop[y[i] - 1] + 1;
            
        }

        // code here
        int incre = 0;
        for (int i = 0; i < n; i++)
        {

            if(x_start[i] !=0 ) incre+=x_start[i] ;
            A_count[i] = incre;
            if(y_stop[i] !=0  ) incre-=y_stop[i] ;
        }

        // for (int i = 0; i < m; i++)
        // {
        //     for (int j = x[i] - 1; j <= y[i] - 1; j++)
        //     {
        //         A_count[j]++;
        //     }
        // }

        size_wei = 0;
        for (int i = 0; i < n; i++)
        {
            // cout << "A_count[i] " << A_count[i]<< '\n';
            // cout << "x_start[i] " << x_start[i]<< '\n';
            // cout << "y_stop[i] " << y_stop[i]<< '\n';
            if(A_count[i] != 0)
                largest_number_wei[size_wei++] = A_count[i];
        }
        // for(int i = 0 ; i < size_wei ; i++){
        //     cout << "largest_number_wei[i] " << largest_number_wei[i] << '\n';
        // }
        std::sort(A, A+n, std::greater<long long>());
        std::sort(largest_number_wei, largest_number_wei+size_wei, std::greater<long long>());

        max_value = 0;
        for (int j = 0; j < size_wei; j++)
        {
            max_value += A[j] * largest_number_wei[j];
        }
    
        times = (tohopdongcap() * giaiThua(n - size_wei)) % 1000000007;

#ifdef _DEBUG
        // cout << "testcase: n = " << n << ", m: " << m   << '\n';
        cout << max_value << " " << times << '\n';
#else
        cout << max_value << " " << times << '\n';
#endif
    }

    _STOP_TIMESTAMP_();
    return 0;
}