//Q.link: https://practice.geeksforgeeks.org/problems/95bb244da24edd6214086ff934886ccda6ed9da8/1

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()

unordered_map<int,int> mm1, mm2;

ll help(int pos, int index, vector<int>&temp, vector<vector<ll>> &dp, int indication){
    if(index==temp.size()) return 0;
    if(dp[index][indication]!=-1) return dp[index][indication];

    ll one=0, two=0;
    
    int left = mm1[temp[index]];
    int right = mm2[temp[index]];

    one = abs(pos-left)+abs(left-right)+help(right, index+1, temp, dp, 1);
    if(index==temp.size()-1) one+=abs(right-0);
    two = abs(pos-right)+abs(right-left)+help(left, index+1, temp, dp, 0);
    if(index==temp.size()-1) two+=abs(left-0);

    return dp[index][indication] = min(one, two);
}

ll mintime(int n, int location[], int type[]){

    int mx= *max_element(type, type+n);

    mm1.clear(), mm2.clear();
    vector<int> ele(mx+1, 0);
    for(int i=0; i<n; i++){
        ele[type[i]] = 1;
        if(mm1.find(type[i])==mm1.end()){
            mm1[type[i]] = location[i];
            mm2[type[i]] = location[i];
        }
        else{
            mm1[type[i]] = min(mm1[type[i]],location[i]);
            mm2[type[i]] = max(mm2[type[i]],location[i]);
        }
    } 
    
    vector<int> temp;
    for(int i=0; i<=mx; i++){
        if(ele[i]==1) temp.push_back(i);
    } 

    vector<vector<ll>> dp(temp.size(), vector<ll>(2,-1));
    return help(0, 0, temp, dp, 0);

}

void solve(ll cs) {
    int n;
    cin >> n;
    int arr[n], arr1[n];
    for(int i=0; i<n; i++) cin >> arr[i];
    for(int i=0; i<n; i++) cin >> arr1[i];
    cout << mintime(n, arr, arr1) << endl;
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

