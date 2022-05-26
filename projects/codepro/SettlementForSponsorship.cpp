#include <iostream>
using namespace std;

int N;//Number of sponsored goods
int D[100000 + 10];//Preference
int sol = -30001;//Maximum preference of the first method

void InputData(){
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> D[i];
	}
}

void Solve()
{
	int i, sum = 0;
	for (i = 0; i < N - 2; i++) {
		sum = D[i] + D[i + 1] + D[i + 2];
		if (sum > sol) sol = sum;
	}
}

void Solve2()
{
	int i, sum = 0;
	for (i = 0; i < N; i++) {
		sum = 0;
		if(D[i] < 0 ) {
			if (D[i] > sol) sol = D[i];
			continue;
		}
		for(int j = i ; j < N - i + 1 ; j++)
		{
			sum += D[j];
			if(sum<0) continue;
			if (sum > sol) sol = sum;
		}
	}
}

int main(){
	InputData();//Input function
	Solve2();
	cout << sol << endl;//Output
	return 0;
}