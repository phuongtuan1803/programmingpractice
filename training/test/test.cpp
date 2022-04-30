#include <bits/stdc++.h>

#define LOG 1000000007
using namespace std;
int src[] = {1,3,4,5,6};
int num = 3;
int n = 5;
int x[100];
int choosen[100];
vector<int> subset;
void search(int k){
    if(k == n + 1 ){
        for(int i = 0 ; i< subset.size() ; i++){
            cout << subset[i] << ' ';
        }
        cout << '\n';
    } else{
        subset.push_back(src[k]);
        search(k+1);
        subset.pop_back();
        search(k+1);
    }
}
void search2(){
    if(subset.size() == num ){
        for(int i = 0 ; i< subset.size() ; i++){
            cout << subset[i] << ' ';
        }
        cout << '\n';
    } else{
        for(int i = 0 ; i < n ; i++ ){
            if(choosen[i]) continue;
            choosen[i] = true;
            subset.push_back(src[i]);
            search2();
            choosen[i] = false;
            subset.pop_back();
        }
    }
}
void search3(int k){
    if(subset.size() == num ){
        for(int i = 0 ; i< subset.size() ; i++){
            cout << subset[i] << ' ';
        }
        cout << '\n';
    } else{
        subset.push_back(src[k]);
        search3(k+1);
        subset.pop_back();
        // search3(k+1);
    }
}
int main(){int src[] = {1,3,4,5,6};
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    
    search2();
    return 0;
}

