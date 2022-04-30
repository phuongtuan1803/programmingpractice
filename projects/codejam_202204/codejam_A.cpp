#include <bits/stdc++.h>

// #define _DEBUG
#undef _DEBUG

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

int alice_first_choice = 0;
int alice_second_choice = 0;
int bob_choice = 0;
vector<int> permutation;
vector<int> alice_first_choice_v;
void search(int n, vector<bool>& chosen , vector<int>& alice_v,vector<int>& bob_v)
{
    if (permutation.size() == n)
    {
        // cout << "    n: " << permutation.at(0) << '\n';
        // process permutation
        int tmp = 0;
        for (int i = 0; i < permutation.size() ; i++)
        {
            tmp = tmp * 10 + permutation.at(i);
        }
        if(tmp > alice_first_choice && tmp < bob_choice){
            alice_first_choice = tmp;
            // cout << "    tmp2: " << tmp << '\n';
            return;
            // alice_first_choice_v.assign(permutation.begin(), permutation.end());
        }
        // cout << "    tmp: " << tmp << '\n';
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            // cout << "    i: " << i << "    alice_v.at(i): " << alice_v.at(i) << '\n';
            // cout << "    bob_v.at(i): " << bob_v.at(i) << "    alice_v.at(i): " << alice_v.at(i) << '\n';
            // if(alice_v.at(i) > bob_v.at(i) ){
            //     continue;
            // }
            // if(alice_first_choice_v.size() == n ){
            //     cout << "    alice_first_choice_v.at(i): " << alice_first_choice_v.at(i) << "    alice_v.at(i): " << alice_v.at(i) << '\n';
            //     if( alice_v.at(i) < alice_first_choice_v.at(i)){
                    
            //         continue;
            //     }                
            // }
            if (chosen[i])
                continue;
            
            chosen[i] = true;
            permutation.push_back(alice_v.at(i));
            // if(alice_v.at(i) <= bob_v.at(i) ){
                search(n,chosen,alice_v,bob_v);
            // }
            
            chosen[i] = false;
            permutation.pop_back();
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

    for (int i = 0; i < T; i++)
    {
        // printf("=================================\n");
        permutation.clear();
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
        int bob_number_reverse = 0;
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
    
        std::sort(alice_v.begin(), alice_v.end(), std::greater<int>());
        alice_second_choice = 0;
        for (int i = 0; i < alice_v.size() - 1; i++)
        {
            alice_second_choice = alice_second_choice * 10 + alice_v.at(i);
        }

        // Alice first choise
        int alice_final_choice = 0;
        vector<bool> chosen (n,false);
        alice_first_choice = -1;
        // std::sort(alice_v.begin(), alice_v.end());
        search(n,chosen,alice_v,bob_v);
        
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