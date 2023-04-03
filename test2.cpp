#include <bits/stdc++.h>
using namespace std;
long max(int a[], int l, int r){
    if (l == r) return a[l];
    if (l + 1 == r){
        if (a[l] < a[r]) return a[r];
        return a[l];
    }
    int m = l-(l-r)/2;
    int maxL = max(a,l,m);
    int maxR = max(a,m+1,r);
    if (maxL < maxR) return maxR;
    return maxL;
}
long dem(int a[],int n,int x){
    if (n == 0){
        // if (a[0] == x) return 1;
        return 0;
    }
    if (a[n-1] == x) return 1+dem(a,n-1,x);
    return dem(a,n-1,x);
}
long tinhGT(int n){
    if (n == 1) return 1;
    return n*tinhGT(n-1);
}
long doiNP(int n){
    if(n/2==0) return 1;
    return (n%2) + 10*doiNP(n/2);
}
long tongGT(int n){
    if (n == 1) return 1;
    return tinhGT(n) + tongGT(n-1);
}
long tinh1(int n){
    if (n == 0) return 1;
    return (2*n+1)*tinh1(n-1);
}
int main(){
    int a[] = {1,2,3,4,1,1,1,1,1,1,1,99,8};
    cout << doiNP(19) << "\n"; //dem(a,13,1);
    cout << max(a,0,12);
}