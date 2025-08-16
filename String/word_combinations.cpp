#include <bits/stdc++.h>
using namespace std;

const int mod=1e9+7;
vector<long long> dp;

long long waysFrom(int i, string& s, vector<string>& v){
   int n=(int)s.length();
   if(i==n) return 1;
   if(dp[i]!=-1) return dp[i];
   long long ans=0;
   for(auto& it:v)  if(i+it.size()<=n && s.compare(i, it.size(), it)==0) ans=(ans+waysFrom(i+it.size(), s, v))%mod;
   return dp[i]=ans;
}

int main(){
   string s;
   cin>>s;
   int k;
   cin>>k;
   vector<string> v(k);
   for(int i=0; i<k; i++) cin>>v[i];
   dp.assign(s.length()+1, -1);
   cout<<waysFrom(0, s, v)<<endl;

   return 0;
}