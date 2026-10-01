#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    vector<ll>rows1(n1); vector<ll>cols1(n1); vector<ll>val1(n1); //given to us with values
    vector<ll>rows2(n2); vector<ll>cols2(n2); vector<ll>val2(n2); //given to us with values
    vector<ll>rows; vector<ll>cols; vector<ll>val;
    int i=0,j=0;
    while(i<n1 && j<n2){
        if(rows1[i]<rows2[j] || (rows1[i]==rows2[j] && cols1[i]<cols2[j])){
            rows.push_back(rows1[i]); 
            cols.push_back(cols1[i]);
            val.push_back(val1[i]);
            i++;
        }
        else if(rows2[j]<rows1[i] || (rows1[i]==rows2[j] && cols2[j]<cols1[i])){
            rows.push_back(rows2[j]); 
            cols.push_back(cols2[j]);
            val.push_back(val2[j]);
            j++;
        }
        else{
            ll sum=val1[i]+val2[j];
            if(sum!=0){
            rows.push_back(rows2[j]); 
            cols.push_back(cols2[j]);
            val.push_back(sum);
            }
            i++; j++;
        }
    }
    while(i<n1){
        rows.push_back(rows1[i]); 
        cols.push_back(cols1[i]);
        val.push_back(val1[i]);
        i++;
    }
    while(j<n2){
        rows.push_back(rows2[j]); 
        cols.push_back(cols2[j]);
        val.push_back(val2[j]);
        j++;
    }
}
