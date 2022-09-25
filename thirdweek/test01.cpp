//
// Created by Hleonor on 2022-09-25.
//
#include <iostream>
#include<cstring>

using namespace std;

const int MAXN = 1e5+5;
char record[MAXN];

int start = 0;

int brackets() {
    bool flag = false;//是否遇见了|
    int temp = 0;
    int cnt = 0;
    start++;
    while(record[start] != ')') {
        if(record[start] == 'a') {
            cnt++;
        }
        if(record[start] == '|') {
            flag = true;
            if(flag) {
                temp = max(temp,cnt);
                cnt = 0;
            } else {
                temp = cnt;
                cnt = 0;
            }
        }
        if(record[start] == '(') {
            cnt += brackets();
        }
        start++;
    }
    if(flag) {
        cnt = max(cnt,temp);
    }
    return cnt;
}

int main( ) {
    cin>>record;
    int cnt = 0;
    int temp = 0;
    int len = strlen(record);
    bool flag = false;
    while(start<len) {
        if(record[start] == 'a') {
            cnt++;
        }
        if(record[start] == '|') {
            flag = true;
            if(flag) {
                temp = max(temp,cnt);
                cnt = 0;
            } else {
                temp = cnt;
                cnt = 0;
            }
        }
        if(record[start] == '(') {
            cnt += brackets();
        }
        start++;
    }
    if(flag) {
        cnt = max(cnt,temp);
    }
    cout<<cnt;
    return 0;
}