#include <bits/stdc++.h>
using namespace std;
#define int long long 

// Brute Force Approach
// vector<int> solve1(string s){
//     int n=s.length();
//     vector<int> ans;

//     for(int i=1; i<=n; i++){
//         bool f=true;
//         for(int j=0; j<n; j++){
//             if(s[j]!=s[j%i]){
//                 f=false;
//                 break;
//             }
//         }
//         if(f) ans.push_back(i);
//     }
//     return ans;
// }

// Better Approach

// const long long mod=1e9+7;
// const long long p=31;

// long long hashed_val(int l, int r, vector<long long>& hash, long long power[]){
//     long long h=(hash[r+1]-(power[r-l+1]*hash[l])%mod+mod)%mod;
//     return h;
// }

// vector<int> solve2(string s){
//     int n=s.length();
//     long long power[n+5];
//     power[0]=1;

//     for(int i=1; i<=n; i++) power[i]=power[i-1]*p%mod;

//     vector<long long> hash(n+10, 0);

//     for(int i=1; i<=n; i++) hash[i]=(hash[i-1]*p+(s[i-1]-'a'+1))%mod;

//     vector<int> ans;

//     for(int i=0; i<n; i++){
//         int curr=0;
//         bool f=true;
//         while(curr<n){
//             int len=min(i+1, n-curr);
//             f&=(hashed_val(0, len-1, hash, power)==hashed_val(curr, curr+len-1, hash, power));
//             curr+=len;
//         }
//         if(f) ans.push_back(i+1);
//     }
//     return ans;
// }

vector<int> z_func(string s){
    int n=s.length();
    vector<int> z(n);
    int l=0, r=0;
    for(int i=1; i<n; i++){
        if(i<=r) z[i]=min(r-i+1, z[i-l]);
        while(i+z[i]<n && s[z[i]]==s[i+z[i]]) z[i]++;
        if(i+z[i]-1>r){
            l=i;
            r=i+z[i]-1;
        }
    }
    return z;
}

vector<int> solve3(string s){
   int n=s.length();
   vector<int> z=z_func(s);
   vector<int> ans;
   for(int i=1; i<n; i++) if(z[i]>=n-i) ans.push_back(i);
   ans.push_back(n);
   return ans;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin>>s;

    vector<int> ans=solve3(s);
    for(int& it:ans) cout<<it<<" ";
    cout<<endl;
    
    return 0;
}