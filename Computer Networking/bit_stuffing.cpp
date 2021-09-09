#include<bits/stdc++.h>
using namespace std;

int main() {
	int i, j,count=0,nl;
	char str[100];

	cout <<endl<< "enter the bit string:  ";
	cin >> str;
	for (i = 0; i < strlen(str); i++) {             //iterate until end of string
		count=0;
		for (j = i; j <= (i + 5); j++) {            //checking 6-bit sequences
			if(str[j] == '1') {                     //if input bit is 1, increment count
				count++;
			}
		}
		if(count == 6) {                            //if all 6 bits are 1s
			nl = strlen(str) + 2;                   //before the 6th 1, insert a zero. so 111111 becomes 1111101
			for (nl; nl >= (i+5); nl--) {
				str[nl] = str[nl-1];
			}
			str[i + 5] = '0';
			i = i + 7;
		}
	}
	cout << "Output: "<<str;
	return 0;
}