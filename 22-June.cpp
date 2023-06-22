//Q.Link : https://practice.geeksforgeeks.org/problems/lemonade-change/1

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()

void solve(ll cs) {
    ll n;
    cin >> n;
    ll arr[n];
    for(ll i=0; i<n; i++) cin >> arr[i];
    ll five=0, ten=0;
    for(ll i=0; i<n; i++){
        if(arr[i]==20){
            if(five && ten){
                five--;
                ten--;
            }
            else if(five>=3) five -= 3;
            else {
                cout << "False" << endl;
                return;
            }
        }
        else if(arr[i]==10){
            if(five){
                five--;
                ten++;
            }
            else {
                cout << "False" << endl;
                return;
            }
        }
        else{
            five++;
        }
    }

    cout << "True" << endl;

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

