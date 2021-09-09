#include<iostream>
#include<vector>
#include<string>
#include<stdio.h>

using namespace std;

string Sum(string s1, string s2) {
    char carry = '0';
    string totalSum = "";


    for(int col = s1.size() - 1; col >= 0; col--) {
        char sum = '0', currentCarry = '0';
        
        if(s1[col] == '0' && s2[col] == '1')
        {
            sum = '1';
            currentCarry = '0';
        }
        else if(s1[col] =='1' && s2[col] == '0')
        {
            sum = '1';
            currentCarry = '0';
        }
        else if(s1[col] == '1' && s2[col] == '1')
        {
            sum = '0';
            currentCarry = '1';
        }
        

        if(carry == '1') {
            if(sum == '1') {
                sum = '0';
                currentCarry = '1';
            }
            else
                sum = '1';
        }

        totalSum = sum + totalSum;
        carry = currentCarry;
    }

    if(carry == '1') {
        for(int col = totalSum.size() - 1; col >= 0; col--) {
            if(totalSum[col] == '0') {
                totalSum[col] = '1';
                carry = '0';
                break;
            }
            else {
                totalSum[col] = '0';
            }
        }
    }

    return totalSum;
}

int main() {
    int n, sLen;
    vector<string> binNum;
    string checkSum;

    
    printf("How many binary numbers involved?: ");
    scanf("%d", &n);
    printf("Enter no. of bits of each binary number: ");
    scanf("%d", &sLen);

    for(int i = 0; i < n; i++) {
        string s;
        if(i+1==1)
            printf("Enter %dst binary number: ", i+1);
        if(i+1==2)
            printf("Enter %dnd binary number: ", i+1);
        if(i+1==3)
            printf("Enter %drd binary number: ", i+1);
        if(i+1>3)
            printf("Enter %dth binary number: ", i+1);
        cin>>s;
        binNum.push_back(s);
    }

    checkSum = binNum[0];
    for(int i=1; i<n; i++) {
        checkSum = Sum(checkSum, binNum[i]);
    }

    printf("CheckSum = ");
    for(int i=0; i<checkSum.size(); i++) {
        printf("%c", checkSum[i]);
    }
}