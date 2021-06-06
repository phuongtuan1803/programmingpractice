#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <iterator>

using namespace std;

int total = 0;
void permute(int i, vector<int> &s, int x)
{
    for(int i = 0 ; i< s.size()-1; i++){
        for(int j = i+1; j< s.size() ;j++){
            if(((s[i]^s[j])^x) == 0){
                total++;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> arr;
    int T, n, x;
    int tmp;
    cin >> T;

    for (int i = 0; i < T; i++)
    {   
        arr.clear();
        total = 0;  
        cin >> n >> x;
        for(int j = 0; j < n ;j++){
            cin >> tmp;
            arr.push_back(tmp);
        }

        permute(0, arr, x);
        cout << total << '\n';
    }
    return 0;
}
