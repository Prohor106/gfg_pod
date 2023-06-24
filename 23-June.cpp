//Q.Link: https://practice.geeksforgeeks.org/problems/task-scheduler/1

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()

void solve(ll cs) {
    int n, k;
    cin >> n >> k;
    map<char, int> mp;
    for(int i=0; i<n; i++){
        char c;
        cin >> c;
        mp[c]++;
    }

    priority_queue<int> pq;
    for(auto u:mp) pq.push(u.second);
    int t=pq.top(), cnt=0;
    pq.pop();
    while(pq.top()==t && pq.size()>0){
        cnt++;
        pq.pop();
    }

    cout << max(n, t+(k*(t-1))+cnt) << endl;


}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    ll t=1, cs=1;
    cin>>t;
    while(t--) {
        solve(cs++);
    }

    return 0;
}

