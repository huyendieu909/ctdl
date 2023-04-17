#include <bits/stdc++.h>
using namespace std;
void bubbleSort(int x[], int n){
    for (int i = 0;i<n-1;i++){
        for (int j = n-1;j>i;j--){
            if (x[j]>x[j-1]){
                int temp = x[j];
                x[j] = x[j-1];
                x[j-1] = temp;
            }
        }
    }
}
void inDayX(int x[],int n){
    for (int i=0;i<n;i++){
        cout << x[i] << " ";
    }
}
int main(){
    int x[] = {34, 74, 94, 84, 54, 24};
    int n = 6;
    bubbleSort(x,n);
    cout << "Day x sap xep giam dan: ";
    inDayX(x,n);
}