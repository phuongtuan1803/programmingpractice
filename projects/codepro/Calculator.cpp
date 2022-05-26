#include <iostream>
using namespace std;

int N;//the number of test cases
int B;//number system
char S[110];//first integer
char D[110];//second integer

long long cal_num(char S[100]){
	// printf("cal_num %s\n", S);
	long long ret_val = 0;
	int i = 0;
	int sign = S[i] == '-';
	if(sign) i++;
	while(S[i] != '\0'){
		int char_val = 0;
		 
		if (S[i] >= '0' && S[i] <= '9' )
			char_val = (S[i++] - '0');
		else
			char_val = (S[i++] - 'A') + 10;
		ret_val = ret_val*B + char_val;
	}
	// printf("%d\n", ret_val*(sign == 1 ? -1 :1));
	return ret_val*(sign == 1 ? -1 :1);
}

void covert_numer(char output[100], long long number){
	// printf("%d\n", number);
	int sign  = 0;
	int i=0;
	long long remain = number;
	long long mod;
	// char output[100];
	char tmp[100] = "";
	if(remain == 0) {
		output[0] = '0';
		output[1] = '\0';
		
	}
	if(number < 0){
		sign = 1;
		remain = -remain;
		output[0] = '-';
	}
	
	while(remain != 0){
		mod =  remain % B;
		remain /= B;
		// printf("remain: %d, mod: %d\n", remain, mod);
		if(mod < 10) {
			tmp[i++] = mod + '0';
		} else{
			tmp[i++] = mod + 'A' - 10;
		}
	}
	for(int j = 0 ; j < i ; j++){
		output[j+(sign == 1 ? 1 : 0)] = tmp[i-j-1];
		// printf("%c\n", tmp[i-j-1]);
	}
	
	output[i+1] = '\0';
	// printf("%s\n", tmp);
}

void InputData(){
	cin >> B >> S >> D;
}
int main(){
	int i;
	scanf("%d", &N);
	for(i = 0; i < N; i++){
		InputData();//input function
		//	write the code
		char output[100] = "";
		// cal_num(S);
		if(cal_num(S) == 0 || cal_num(D) == 0){
			printf("%s\n", "0");
		} else{
			covert_numer(output, cal_num(S) * cal_num(D));
			printf("%s\n", output);
		}	
	}
	return 0;
}