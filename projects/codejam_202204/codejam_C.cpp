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

int n, m;
int v[50001];
int v_clone[50001];
int lookup[500001];
long long z;

vector<int> permutation;
vector<int> chosen;
int remain_select;
bool check_fail_select(int current, int previos){
    if(current == previos ){
        return true;
    }
    if(remain_select == 0 || remain_select == 1){
        return false;
    }
    // for(int i = 0 ; i < n ;i ++){                
    //     if(v_clone[i] == remain_select){
    //         return true;
    //     }
    // }
    return false;
}
void print_vclone(string mes){
    cout << "v_clone: " << mes << ": ";
    for(int i = 0 ; i < n ;i ++){                
        cout << v_clone[i] << " ";
    }
    cout << " remain_select: " << remain_select <<"\n";
}
void print_v(string mes){
    cout << "v: " << mes << ": ";
    for(int i = 0 ; i < m ;i ++){                
        cout << v[i] << " ";
    }
    cout << "\n";
}
void print_lookup(string mes){
    cout << "lookup: " << mes << ": ";
    for(int i = 0 ; i < m ;i ++){                
        cout << lookup[i] << " ";
    }
    cout << "\n";
}
void print_permutation(string mes){
    cout << "permutation: " << mes << ": ";
    for(int i = 0 ; i < m ;i ++){                
        cout << permutation[i] << " ";
    }
    cout << "\n";
}
int get_number(int number){
    // print_vclone("OUT");
    v_clone[lookup[number]]--;
    remain_select--;
    if(remain_select != 0 && v_clone[lookup[number]] == remain_select){
        // print_vclone("   PRE");
        return -1;
    }
    return lookup[number];
}
int recover_number(int number){
    v_clone[lookup[number]]++;
    remain_select++;
    return lookup[number];
}
bool get_z(){
    long long ret_val = 0;
    for(int i = 0 ; i < m ;i ++){                
        ret_val += ((permutation[i]%987654323 + 1) * (i+1)) %987654323;
    }
    z = ret_val;
    return true;
}
void search() {
    if (permutation.size() == m) {
        // print_permutation("ORI");
        get_z();
        return;
    } else {
        bool selected[100];
        std::fill_n(selected, 100, false);
        for (int i = 0; i < m; i++) {
            
            if (chosen[i]) continue;
            chosen[i] = true;
            if(z != -1) return;
            int number = get_number(i);
            // if(number == -1) continue;;
            permutation.push_back(number);
            // cout << "remain_select: " << remain_select << ", i: " << i << " get_number(i): " << permutation.back() << " : ";
            // print_vclone("Pre");
            // print_permutation("");

            if(!(permutation.size() >= 2 && check_fail_select(permutation.at(permutation.size() - 1),permutation.at(permutation.size() - 2)))
                && selected[permutation.back()] == false
                && number != -1
                ){
                search();
                selected[permutation.back()] = true;
            }
            chosen[i] = false;
            recover_number(i);
            // cout << "i: " << i << ": ";
            // print_vclone("Post");
            permutation.pop_back();
        }
    }
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
        printf("\n=================================\n");
#endif

        long long tmp;
        z = -1;
        cinstream >> n;

        permutation.clear();
        chosen.clear();
        
        std::fill_n(v, n, 0);
        std::fill_n(v_clone, n, 0);

        std::fill_n(lookup, n, 0);

        m = 0;
        int m_pre = 0;
        for (int i = 0; i < n; i++)
        {
            cinstream >> v[i];
            m += v[i];
            for(int j = m_pre; j < m; j++){
                lookup[j] = i;                
            }
            m_pre = m;
        }
        
        memcpy(v_clone,v,sizeof(v));

        // code here
        // count remain select

        remain_select = m;
        chosen.resize(m, false);
        
        search();
#ifdef _DEBUG
        cout << "testcase: n = " << n   << ", m = " << m<< '\n';
        if(z != -1)
            cout << z << '\n';
        else
            cout << "IMPOSSIBLE\n";
#else
        if(z != -1)
            cout << z << '\n';
        else
            cout << "IMPOSSIBLE\n";
#endif
    }

    _STOP_TIMESTAMP_();
    return 0;
}