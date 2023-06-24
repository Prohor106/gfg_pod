//Q.Link: https://practice.geeksforgeeks.org/problems/prefix-match-with-other-strings/1

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()

void solve(ll cs) {
    int n;
    cin >> n;
    string arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    string temp;
    cin >> temp;
    int k;
    cin >> k;
    int cnt=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<=k; j++){
            if(j==k){
                cnt++;
                break;
            }
            else if(arr[i][j]=='\0') break;
            else if(arr[i][j]!=temp[j]) break;
        }
    }

    cout << cnt << endl;
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

