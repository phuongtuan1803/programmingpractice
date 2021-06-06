#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
#pragma GCC target "arch=haswell" // For Processor: Intel Xeon E5-2666v3
#define MOD 1000000007
#define ESP 1e-9
#define CMP_F(a, b) (abs((a) - (b)) < ESP)

/* ------- UTILS FUNCTION */
void scan_integer(int &number)
{
    //variable to indicate sign of input number
    bool negative = false;
    register int c;

    number = 0;

    c = getchar(); // extract current character from buffer
    if (c == '-')
    {
        negative = true; // number is negative
        c = getchar();   // extract the next character from the buffer
    }

    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c > 47 && c < 58); c = getchar())
        number = number * 10 + c - 48;

    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        number *= -1;
}

void scan_integer(unsigned int &number)
{
    register int c;
    number = 0;
    c = getchar(); // extract current character from buffer
    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c > 47 && c < 58); c = getchar())
        number = number * 10 + c - 48;
}

void scan_integers_in_line(vector<int> &numbers)
{
    register int c;
    bool negative = false;
    unsigned int number = 0;

    c = getchar();
    do
    {
        if (c == '-')
        {
            negative = true; // number is negative
            c = getchar();   // extract the next character from the buffer
        }
        for (; (c > 47 && c < 58); c = getchar())
            number = number * 10 + c - 48;
        if (negative)
            number *= -1;
        numbers.push_back(number);

        number = 0;
        negative = false;

        if (c != '\n')
            c = getchar();
    } while (c != '\n');
}

void scan_integers_in_line(vector<unsigned int> &numbers)
{
    register int c;
    unsigned int number = 0;
    c = getchar();
    do
    {
        for (; (c > 47 && c < 58); c = getchar())
            number = number * 10 + c - 48;
        numbers.push_back(number);
        number = 0;
        if (c != '\n')
            c = getchar();
    } while (c != '\n');
}

/* ------- HELP CODE 
PARALLELISM


INPUT STRING
    string fullName;
    getline (cin, fullName);

PRINT FORMAT:
    printf("%d %d\n", a, b);
    printf("%.9f\n", x);

LOOP ALL SUBSET
    int x = (1<<1)|(1<<3)|(1<<4)|(1<<8);
    int b = 0;
    do{
        cout << b<<"\n";
    }while(b = (b-x)&x);

BIT MANIPULATION
    __builtin_clz(x): the number of zeros at the beginning of the bit representation
    __builtin_ctz(x): the number of zeros at the end of the bit representation 
    __builtin_popcount(x): the number of ones in the bit representation
    __builtin_parity(x): the parity (even or odd) of the number of ones in the bit representation.

SUBSET
    vector<int> subset;
    void search(int k)
    {
        if (k == n + 1)
        {
            // process subset
        }
        else
        {
            // include k in the subset
            subset.push_back(k);
            search(k + 1);
            subset.pop_back();
            // don’t include k in the subset
            search(k + 1);
        }
    }

PERMUTATION
    vector<int> permutation;
    bool chosen[n + 1];
    void search()
    {
        if (permutation.size() == n)
        {
            // process permutation
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                if (chosen[i])
                    continue;
                chosen[i] = true;
                permutation.push_back(i);
                search();
                chosen[i] = false;
                permutation.pop_back();
            }
        }
    }
*/

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    auto start = chrono::steady_clock::now();

    /* ------- CODING HERE */




    /* ------- END */
    cout << "\nElapsed time in milliseconds: " << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() << " ms" << '\n';
    return 0;
}
