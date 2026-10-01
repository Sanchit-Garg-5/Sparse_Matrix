//tc is (n1*n2)+(r1*maxcol(2))
//sc is maxcol(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    vector<ll>rows1(n1); vector<ll>cols1(n1); vector<ll>val1(n1); //given to us with values
    vector<ll>rows2(n2); vector<ll>cols2(n2); vector<ll>val2(n2); //given to us with values
    vector<ll>rows; vector<ll>cols; vector<ll>val;
    ll maxcolb=LLONG_MIN;
    for(int i=0;i<n2;i++){
        maxcolb=max(cols2[i],maxcolb);
    }
    vector<ll>acc(maxcolb+1,0);
    int i=0;
    while(i<n1){
        int curr_row=rows1[i];
        while(i<n1 && curr_row==rows1[i]){
            int k=cols1[i] //col of 1 or row of 2
            int value=val1[i];
            for(int j=0;j<n2;j++){
                if(rows2[j]==k){
                    acc[cols2[j]]+=val1*val2[j];
                }
            }
            i++;
        }
        for(int l=0;l<maxcolb+1;l++){
            if(acc[l]!=0){
                rows.push_back(curr_row);
                cols.push_back(l);
                val.push_back(acc[l]);
            }
            acc[l]=0;
        }
    }
}
