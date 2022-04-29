#include <bits/stdc++.h>

#define _DEBUG
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
char c[150];

vector<int> subset;
int alice_first_choice = 0;
int alice_second_choice = 0;

void search(int k, int n,bool chosen[], vector<int> &bob_v, vector<int> &alice_v)
{
 for (int v = 0 ; v < alice_v.size() ;v++)
        {
            x[k] = v;
            if (việc thử còn hy vọng để tìm ra cấu hình tốt hơn BEST_CONFIG)
            {
                if (k == n)
                { // Nếu i là phần tử cuối cùng trong cấu hình
                    cập nhật BEST_CONFIG;
                }
                else
                {
                    chosen[v] = true; // Ghi nhận việc x[i] nhận giá trị V nếu cần
                    search(k + 1,n,chosen,bob_v,alice_v);
                    chosen[v] = false; // Bỏ ghi nhận việc thử cho x[i] nếu cần
                }
            }
        }
}
void search(int k, int n, vector<int> &bob_v, vector<int> &alice_v)
{
        if (k == n)
        {
            // process subset
            for (int i = 0; i < subset.size(); i++)
            {
                alice_first_choice = alice_first_choice * 10 + subset.at(i);
            }
            cout << "    -----: " << alice_first_choice << '\n';
        }
        else
        {
            // include k in the subset
            subset.push_back(alice_v.at(k));
            cout << "    k    : " << k << '\n';
            cout << "    -----: " << bob_v.at(k) << '\n';
            cout << "    -----: " << alice_v.at(k) << '\n';

            if (bob_v.at(k) >= alice_v.at(k))
            {
                search(k, n, bob_v, alice_v);
            }
            subset.pop_back();
            // don’t include k in the subset
            if (bob_v.at(k) >= alice_v.at(k))
            {
                search(k, n, bob_v, alice_v);
            }
        }
}

int main()
{
        _INIT_();
        /*  INPUT*/
        int T;
        cinstream >> T;

#ifdef _DEBUG
        printf("Loading Testcase from file: %s (Number of TestCase: %d )\n", _TESTCASEFILE_.c_str(), T);
        printf("=================================\n");
#endif

        _START_TIMESTAMP_();

        for (int i = 0; i < T - 2; i++)
        {
            subset.clear();
            int n, bob_number, alice_number;
            int alice_choice;
            cinstream >> n >> bob_number >> alice_number;

            int tmp;
            // code here
            // Get vector of alice
            vector<int> alice_v;
            tmp = alice_number;
            while (tmp != 0)
            {
                alice_v.push_back(tmp % 10);
                tmp = tmp / 10;
            }

            // Get min choise of bob
            int bob_choice, bob_number_reverse = 0;
            tmp = bob_number;
            while (tmp != 0)
            {
                bob_number_reverse = bob_number_reverse * 10 + tmp % 10;
                tmp = tmp / 10;
            }
            bob_choice = bob_number < bob_number_reverse ? bob_number : bob_number_reverse;

            // Get vector of bob
            vector<int> bob_v;
            tmp = bob_choice;
            while (tmp != 0)
            {
                bob_v.push_back(tmp % 10);
                tmp = tmp / 10;
            }

        // Alice last choise
        std:
            sort(alice_v.begin(), alice_v.end(), std::greater<int>());
            alice_second_choice = 0;
            for (int i = 0; i < alice_v.size() - 1; i++)
            {
                alice_second_choice = alice_second_choice * 10 + alice_v.at(i);
            }

            // Alice first choise
            int alice_final_choice = 0;
            bool chosen[n + 1];
            alice_first_choice = -1;
            search(0, n, bob_v, alice_v);
            if (alice_first_choice == -1)
            {
                alice_final_choice = alice_second_choice;
            }
            else
            {
                alice_final_choice = alice_first_choice;
            }
#ifdef _DEBUG
            cout << "testcase: n = " << n << ", bob_number: " << bob_number << ", alice_number: " << alice_number << '\n';
            cout << "alice_final_choice: " << alice_final_choice << '\n';
            cout << "    alice_second_choice: " << alice_second_choice << '\n';
            cout << "    alice_first_choice: " << alice_first_choice << '\n';
            cout << "    bob_choice: " << bob_choice << '\n';
#else
            cout << alice_final_choice << '\n';
#endif
        }

        _STOP_TIMESTAMP_();
        return 0;
}