//Q.Link: https://practice.geeksforgeeks.org/problems/unique-rows-in-boolean-matrix/1

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()

void solve(ll cs) {
    int n, m;
    cin >> n >> m;
    int arr[n][m];

    map<string, bool>mp;
    vector<vector<int>> ans;
    for(int i=0; i<n; i++){
        string tempS = "";
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
            tempS += arr[i][j]+'0';
        }
        if(!mp[tempS]){
            mp[tempS] = true;
            vector<int>tempV;
            for(int k=0; k<tempS.size(); k++)
                tempV.push_back(tempS[k]-'0');
            ans.push_back(tempV);
        }
    }

    for(int i=0; i<ans.size(); i++){
        for(auto v:ans[i])
            cout << v << " ";
        cout << "$";
    }
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

