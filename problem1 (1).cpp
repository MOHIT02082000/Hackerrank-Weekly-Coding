#include<bits/stdc++.h>

using namespace std;

int vis[20];
int a2[22];
int len;
int res[22];
bool tag = false;

void dfs(int idx,bool flg) {
    if(tag) return ;
    if(idx == len) {
        tag = true;return;
    }
    int t;
    for(int i = 9;i >= 0;i--) {
        if(vis[i] > 0) {
            if(flg || i == a2[idx]) {
                vis[i]--;
                res[idx] = i;
                dfs(idx+1,flg);
                if(tag) return ;
                vis[i]++;
            } else if(i < a2[idx]) {
                vis[i]--;
                res[idx] = i;
                dfs(idx+1,true);
                if(tag) return ;
                vis[i]++;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    string s1,s2;cin>>s1>>s2;
    if(s1.size() < s2.size()) {
        sort(s1.rbegin(),s1.rend());
        cout<<s1<<endl;
    } else {
        len = s1.size();
        for(int i = 0;i < len;i++) {
            vis[s1[i] - '0']++;
        }

        for(int i = 0;i < len;i++) {
            a2[i] = s2[i] - '0';
        }
        dfs(0,false);
        for(int i = 0;i < len;i++) {
            cout<<res[i];
        }cout<<endl;
    }

    return 0;
}

