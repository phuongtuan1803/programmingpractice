#include <bits/stdc++.h>
using namespace std;

int N; // Number of executable code data
int M; // Number of virus data
int A[20000 + 10]; // Executable code data
int B[10 + 10]; // Virus data
int B_C[10 + 10]; // Virus data

int sol; // Correct answer

void InputData(void)
{
	int i;

	cin >> N >> M;

	for (i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (i = 0; i < M; i++) {
		cin >> B[i];
	}
}

void OutputData(void)
{
	cout << sol;
}

int Find(int start)
{
	int i;

	for (i = 0; i < M; i++) {
		if (B[i] != A[start + i]) return 0;
	}
	return 1;
}
int Find2(int start)
{
	int i;
	
	for (i = start; i < start + M; i++) {
		B_C[i-start] = A[i];
	}
	sort(B_C,B_C+M);
	// for(int i = 0 ; i < M ; i++){
	// 	cout << B_C[i] << " ";
	// }
	// cout << endl;
	int diff = B_C[0] - B[0];
	for (i = 1; i < M; i++) {
		if ((B_C[i] - B[i]) != diff) return 0;
	}
	return 1;
}
void Solve(void)
{
	int i;

	for (i = 0; i <= N - M; i++) {
		sol += Find2(i);
	}
}
void ProcessVirus(){
	sort(B,B+M);
	for(int i = 1 ; i < M ; i++){
		B[i] -= B[0];
	}
	B[0] = 0;
}

int main(void)
{
	InputData(); // Input
	ProcessVirus();
	Solve(); // Problem solving

	OutputData(); // Output

	return 0;
}
