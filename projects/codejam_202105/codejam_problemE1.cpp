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

char c[150];

vector<int> v_albert;
vector<int> v_alice;
// int score_albert;
// int score_alice;
int smallest_score_diff;
bool draw_chance;

inline bool check_albert(char c) { return c == 'A' || c == 'L' || c == 'B' || c == 'E' || c == 'R' || c == 'T'; }
inline bool check_alice(char c) { return c == 'A' || c == 'L' || c == 'I' || c == 'C' || c == 'E'; }

void search(int left, int right, int score_albert, int score_alice)
{
    if (smallest_score_diff == 1)
    {
        return;
    }

    if (left > right)
    {
        int diff = score_albert - score_alice;
        if (diff > 0)
        {
            smallest_score_diff = smallest_score_diff > diff ? diff : smallest_score_diff;
            //cout << "Albert: " << score_albert << ". Alice: " << score_alice << ". Diff: " << diff << '\n';
        }
        else if (diff == 0)
        {
            draw_chance = true;
            //cout << "Albert: " << score_albert << ". Alice: " << score_alice << ". DRAW !!!!" << '\n';
        }
    } else if (left == right){
        if (check_albert(c[left])){            
            score_albert += 2;
        }
        search(++left, right, score_albert, score_alice);
    }  else
    {
        bool is_plus_albert = false;
        bool is_plus_alice = false;

        if (check_albert(c[left]) && check_albert(c[right]))
        {
            left++;
            score_albert += 2;
            is_plus_albert = true;
        }
        else if (check_albert(c[left]))
        {
            left++;
            score_albert += 2;
            is_plus_albert = true;
        }
        else if (check_albert(c[right]))
        {
            right--;
            score_albert += 2;
            is_plus_albert = true;
        }
        else
        {
            right--;
        }

        // Alice Turn
        if (check_alice(c[left]))
        {
            score_alice += 1;
            is_plus_alice = true;
        }
        search(++left, right, score_albert, score_alice);

        left--;
        if (is_plus_alice == true)
        {
            score_alice -= 1;
        }

        if (check_alice(c[right]))
        {
            score_alice += 1;
            is_plus_alice = true;
        }
        search(left, --right, score_albert, score_alice);
    }
}

int main()
{
#ifdef _DEBUG_
    ifstream ifile("testcase_E.txt", ifstream::in);
#define cinstream ifile
#else
    ios::sync_with_stdio(false);
    cin.tie(NULL);
#define cinstream cin
#endif

    int T;

    cinstream >> T;

#ifdef _DEBUG_
    printf("Number of TestCase: %d.\n", T);
    printf("=================================\n");
    auto start = chrono::steady_clock::now();
#endif

    for (int i = 0; i < T; i++)
    {
        string s;
        cinstream >> s;
        strcpy(c, s.c_str());

        smallest_score_diff = INT_MAX;
        draw_chance = false;

        search(0, s.size() - 1, 0, 0);

        if (smallest_score_diff == INT_MAX)
        {
            smallest_score_diff = -1;
        }
        else if (draw_chance)
        {
            smallest_score_diff = -1;
        }
#ifdef _DEBUG_
        cout << "testcase: s = " << s << "\n    Diff: " << smallest_score_diff << '\n';
#else
        cout << smallest_score_diff << '\n';
#endif
    }

#ifdef _DEBUG_
    cout << "Elapsed time in milliseconds: " << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() << " ms" << '\n';
#endif
    return 0;
}
