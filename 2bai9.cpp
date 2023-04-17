#include <bits/stdc++.h>
using namespace std;
void selectionSort(int x[],int n){
    for (int i=0;i<n-1;i++){
        int m = i;
        for (int j=i+1;j<n;j++){
            if (x[j] > x[m]) m = j;
        }
        int temp = x[i];
        x[i] = x[m];
        x[m] = temp;
    }
}
void inDayX(int x[],int n){
    for (int i=0;i<n;i++){
        cout << x[i] << " ";
    }
}
int main(){
    int x[] = {50,8,34,6,98,17,83,25,66,42,21,59,63,71,85};
    int n = 15;
    selectionSort(x,n);
    cout << "Day x sau khi sap xep giam dan: ";
    inDayX(x,n);
}