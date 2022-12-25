//
// Created by Hleonor on 2022-11-20.
//
#include<bits/stdc++.h>

#define ll long long
using namespace std;
const int N = 100005;
const int L = 26;
char s[N];
char ans[N];
int cnt[26];
int t;
int n, k;
void inline judgeOk(int & flag){
    for (int i = 0; i < L ; i ++){
        if (cnt[i] % k) {
            flag = 0;break;
        }
    }
}
int main( ){
    cin >> t;
    while (t--){
        cin >> n >> k >> s;
        if (n % k != 0){
            cout << -1 << '\n';
            continue;
        }
        strcpy(ans, s);
        memset(cnt, 0, sizeof cnt);
        int flag = 1;
        for (int i = 0;i < n ; i ++)
            cnt[s[i] - 'a'] ++;
        judgeOk(flag);
        if (flag){
            cout << s << '\n';
            continue;
        }
        int flag2 = 0;
        for (int i = n - 1; i >= 0;i --){
            cnt[s[i] - 'a'] --;
            if (s[i] == 'z')    continue;
            int tot = 0;
            for (int j = 0;j < L; j ++){
                tot += (k - (cnt[j] % k )) % k;
            }
            if (tot > n - i)    continue;
            int left = n - i - tot;
            if (left == 0){
                for (int mx = s[i] + 1; mx <= 'z'; mx ++){
                    int c = (k - (cnt[mx - 'a'] % k)) % k;
                    if (c > 0){
                        ans[i] = mx;
                        int pos = i + 1;
                        for (char ch = 'a'; ch <= 'z'; ch ++){
                            int cc = (k - (cnt[ch - 'a'] % k)) % k;
                            if (ch == mx)   cc--;
                            while (cc --)   ans[pos++] = ch;
                        }
                        cout << ans << '\n';
                        flag2 = 1;
                        break;
                    }
                }
            }
            else{
                char mx = s[i] + 1;
                int c = (k - (cnt[mx - 'a'] % k)) % k;
                if (c > 0){
                    ans[i] = mx;
                    int pos = i + 1;
                    for (char ch = 'a'; ch <= 'z'; ch ++) {
                        int cc = (k - (cnt[ch - 'a'] % k)) % k;
                        if (ch == mx)   cc--;
                        if (ch == 'a')  cc += left;
                        while (cc --)   ans[pos++] = ch;
                    }
                    cout << ans << '\n';
                    flag2 = 1;
                    break;
                }
                else{
                    ans[i] = mx;
                    int pos = i + 1;
                    for (char ch = 'a'; ch <= 'z'; ch ++) {
                        int cc = (k - (cnt[ch - 'a'] % k)) % k;
                        if (ch == mx)   cc = k - 1;
                        if (ch == 'a')  cc += left - k;
                        while (cc --)   ans[pos++] = ch;
                    }
                    cout << ans << '\n';
                    flag2 = 1;
                    break;
                }
            }
            if (flag2)  break;
        }
    }
    return 0;
}