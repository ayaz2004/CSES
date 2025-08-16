#include <bits/stdc++.h>
using namespace std;

// int solve1(string s1, string s2){
//    int ans=0, n=s1.length(), m=s2.length();
//    for(int i=0; i<=n-m; i++){
//     string temp="";
//     for(int j=0; j<m; j++){
//         temp+=s1[i+j];
//     }
//     if(temp==s2) ans++;
//    }
//    return ans;
// }

//KMP 

vector<int> lps(string s){
   int n=s.length();
   vector<int> v(n, 0);
   int len=0, i=1;
   while(i<n){
    if(s[i]==s[len]){
        len++;
        v[i]=len;
        i++;
    }else{
        if(len!=0) len=v[len-1];
        else{
            v[i]=0;
            i++;
        }
    }
   }
   return v;
}

int solve2(string s1, string s2){
  int n=s1.length(), m=s2.length();
  vector<int> v=lps(s2);
  int i=0, j=0, ans=0;
  while(i<n){
    if(s1[i]==s2[j]){
        i++;
        j++;
    }
    if(j==m){
        ans++;
        j=v[j-1];
    }else if(i<n && s1[i]!=s2[j]){
        if(j!=0) j=v[j-1];
        else i++;
    }
  }
  return ans;
}

int main(){
   string s1, s2;
   cin>>s1>>s2;

   cout<<solve2(s1, s2)<<endl;

   return 0;
}