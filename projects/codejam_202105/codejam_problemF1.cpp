#include <cstdint>
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <cstring>
#include <string>
#include <climits>

using namespace std;
#define _DEBUG_

#ifdef _DEBUG_
#include <chrono>
#endif
#define MAX_N   50000

int32_t s[MAX_N];
int32_t arr[MAX_N];
int32_t opt_pos;
int64_t opt_price;
class MinHeap {
 
    int32_t size;
    int32_t* arr;
 
public:
    MinHeap(int32_t size, int32_t input[]);
 
    void heapify(int32_t i);
    void buildHeap();
};
 
MinHeap::MinHeap(int32_t size, int32_t input[])
{
    this->size = size;
    this->arr = input;
 
    buildHeap();
}
 
void swap_2(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}
 
void MinHeap::heapify(int32_t i)
{
    if (i >= size / 2)
        return;
    int32_t smallest;
 
    int32_t left = 2 * i + 1;
 
    int32_t right = 2 * i + 2;
 
    smallest = arr[left] < arr[i] ? left : i;

    if (right < size)
        smallest = arr[right] < arr[smallest]
                             ? right : smallest;
    if (smallest != i) {
        swap_2(arr[i], arr[smallest]);
        heapify(smallest);
    }
}
 
// Build Min Heap
void MinHeap::buildHeap()
{
    for (int32_t i = size / 2 - 1; i >= 0; i--) {
        heapify(i);
    }
}
 
int64_t discount_bundle( const int32_t arr_in[], int32_t begin, int32_t end){    
    int32_t size = end - begin;
    int32_t k =  size / 3;
    int64_t sum = 0;
    memcpy (arr,arr_in+begin,sizeof(arr[0])*size);
    MinHeap* m = new MinHeap(k, arr);
    for (int32_t i = k; i < size; i++) {
        if (arr[0] > arr[i])
            continue;
        else {
            arr[0] = arr[i];
            m->heapify(0);
        }
    }
    for (int32_t i = 0; i < k; i++) {
        sum+=arr[i];
    }
    return sum;
}

int64_t price_sum(const int32_t s[], int32_t n){
    int64_t sum = 0;
    for (int32_t i = 0; i < n; i++)
    {   
        sum += int64_t(s[i]);
    }
    return sum;
}


int32_t main()
{
#ifdef _DEBUG_
    ifstream ifile("testcase_F.txt", ifstream::in);
#define cinstream ifile
#else
    ios::sync_with_stdio(false);
    cin.tie(NULL);
#define cinstream cin
#endif

    int32_t T;
    int32_t n, tmp;
    cinstream >> T;

#ifdef _DEBUG_
    printf("Number of TestCase: %d.\n", T);
    printf("=================================\n");
    auto start = chrono::steady_clock::now();
#endif

    for (int32_t t = 0; t < T; t++)
    {
        opt_pos = 0;
        opt_price = 0;
        cinstream >> n;
        for(int32_t j = 0; j < n ; ++j){
            cinstream >> tmp;
            s[j] = tmp;
        }
        int64_t sum = price_sum(s,n);
        for (int32_t i = 0; i < n; i+=3)
        {   
            int select_pos = i;
            int64_t sum_bundle_left = 0, sum_bundle_right = 0;
            if(i != 0){
                sum_bundle_left = discount_bundle(s,0,i);
            }
            if(i!= n -1){
                sum_bundle_right = discount_bundle(s,i+1,n);
            }            
            int64_t price = sum - sum_bundle_left - sum_bundle_right;
            if(opt_price < price){
                opt_price = price;
                opt_pos = i;
            }
        }
        
#ifdef _DEBUG_
        cout << "testcase: n = " << n << ". Optimize pos: " << opt_pos << ". Optimize price: " << opt_price  << '\n';
#else
        cout << opt_pos << " " << opt_price  << '\n';
#endif
    }

#ifdef _DEBUG_
    cout << "Elapsed time in milliseconds: " << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() << " ms" << '\n';
#endif
    return 0;
}
