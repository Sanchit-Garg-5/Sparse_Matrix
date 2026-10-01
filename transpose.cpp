#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  //given only 3 sparse arrays of corresponding rows, cols,values
    vector<ll>rows(n); vector<ll>cols(n); vector<ll>val(n); //given to us with values
    vector<ll>frows(n); vector<ll>fcols(n); vector<ll>fval(n);
    ll n=rows.size(); ll maxi=LLONG_MIN; ll mini=LLONG_MAX;
    for(int i=0;i<n;i++){
        if(cols[i]<mini){mini=cols[i];}
        if(cols[i]>maxi){maxi=cols[i];}
    }
    vector<ll>freq(maxi-mini+1,0);
    for(int i=0;i<n;i++){
        freq[cols[i]-mini]++;
    }
    for(int i=1;i<freq.size();i++){
        freq[i]+=freq[i-1];
    }
    for(int i=n-1;i>-1;i--){
        ll temp=cols[i];
        frows[freq[temp-mini]-1]=temp;
        fcols[freq[temp-mini]-1]=rows[i];
        fval[freq[temp-mini]-1]=val[i];
        freq[temp-mini]--;
    }
}
