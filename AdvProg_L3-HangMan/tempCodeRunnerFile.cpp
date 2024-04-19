#include<iostream>
#include<map>
#include<vector>
using namespace std;
int a[1000];
int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int>L(n,1);
    map<int,int>parent;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[i]>a[j]){
                if(L[i]<L[j]+1) {
                    L[i]=L[j]+1;
                    parent[i]=j;
                }
            }

        }
    }
    int Max=0;
    int i_max;
    for(int i=0;i<n;i++){
        if(Max<L[i]){
            Max=L[i];i_max=i;
        }
    }
    while(1){
        cout<<a[i_max]<<" ";
        if(parent[i_max]<=0) break; 
        i_max=parent[i_max];
    }
    return 0;
}