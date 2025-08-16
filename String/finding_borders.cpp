#include <bits/stdc++.h>
using namespace std;

vector<int> solve(string s){
  int n=s.length();
  vector<int> v(n, 0);
  for(int i=1; i<n; i++){
    int j=v[i-1];
    while(j>0 && s[i]!=s[j]) j=v[j-1];
    if(s[i]==s[j]) j++;
    v[i]=j;
  }

  vector<int> borders;
  int temp=v[n-1];
  while(temp>0){
    borders.push_back(temp);
    temp=v[temp-1];
  }
  sort(borders.begin(), borders.end());
  return borders;
}

int main(){
    string s;
    cin>>s;
    vector<int> ans=solve(s);
    for(int& it:ans) cout<<it<<" ";
    cout<<endl;
    return 0;
}