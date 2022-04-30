// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

#include <bits/stdc++.h>

//#undef _DEBUG

using namespace std;

/*  ====== PRE DEFINE ================================================================================================================ */
#ifdef _DEBUG
#define _INIT_()
#define _START_TIMESTAMP_()      auto start = chrono::steady_clock::now();
#define _STOP_TIMESTAMP_()       cout << "Elapsed time in milliseconds: " \
                                    << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() \
                                    << " ms" << '\n';

#define _TESTCASEFILE_          (string(__FILE__).substr(0, string(__FILE__).length() - 4 ) + ".txt")
ifstream ifile( _TESTCASEFILE_ , ifstream::in);
#define cinstream ifile

#else
#define _INIT_()                ios::sync_with_stdio(false);\
                                cin.tie(NULL);
#define _START_TIMESTAMP_()
#define _STOP_TIMESTAMP_()

#define cinstream cin
#endif
/*  ================================================================================================================================== */

/* GLOBAL VAR */
vector<int> nums;

bool search(vector<int>& nums, int left, int right, int target, int deep){
    //cout << string(deep*3,' ') << "left : " << left<< ". right: " << right<<'\n';
    if(left > right){
        return false;
    }        

    if(right - left <= 1){
        return nums[left] == target || nums[right] == target;
    } else if (right - left == 2){
        return nums[left] == target || nums[left+1] == target || nums[right] == target;
    }

    int mid = (left + right) /2;
    return search(nums,left, mid,target,deep+1) || search(nums, mid+1, right,target,deep+1);
}

bool search(vector<int>& nums, int target) {
    return search(nums,0,nums.size()-1,target, 0);
}

int main()
{
    _INIT_();

    /*  INPUT*/
    int T;
    cinstream >> T;

#ifdef _DEBUG
    cout << "DEBUG:: Loading Testcase from file " << _TESTCASEFILE_<< "\n"; 
    cout << "DEBUG:: Number of TestCase: " << T << '\n' << std::string(30, '=') << '\n';
#endif

    _START_TIMESTAMP_();
    
    for (int i = 0; i < T; i++)
    {   
        bool output;
        int target, n, tmp;
        cinstream >> target >> n;
        for(int j = 0; j < n ; ++j){
            cinstream >> tmp;
            nums.push_back(tmp);
        }

       output = search(nums, target);
#ifdef _DEBUG
        cout << "output: " << output << '\n';
#else
        cout << output << '\n';
#endif
    }

    _STOP_TIMESTAMP_();
    return 0;
}
