//Q.Link: https://practice.geeksforgeeks.org/problems/rearrange-an-array-with-o1-extra-space3142/1

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()

void cng(ll arr[], ll n){
    for(ll i=0; i<n; i++){
        ll x = arr[i];
        ll y = arr[x];
        arr[i] = x + (y%n)*n;
    }

    for(ll i=0; i<n; i++) arr[i] /= n;
}

void solve(ll cs) {
    ll n;
    cin >> n;
    ll arr[n];
    for(ll i=0; i<n; i++) cin >> arr[i];
    cng(arr, n);
    
    for(auto u:arr) cout << u << " ";
    cout << endl;
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
