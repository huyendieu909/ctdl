#include <bits/stdc++.h>
using namespace std;
void insertionSort(int x[], int n){
    for (int i=1;i<n;i++){
        int tam = x[i];
        int j = i-1;
        while (j>-1&&x[j]<tam){
            x[j+1] = x[j];
            j--;
        }
        x[j+1] = tam;
    }
}
void inDayX(int x[],int n){
    for (int i =0;i<n;i++){
        cout << x[i] << " ";
    }
}
int main(){
    int x[] = {34, 14, 24, 54, 84, 64, 94, 74, 04};
    int n = 9;
    insertionSort(x,n);
    cout << "Day x sau khi sap xep giam dan: ";
    inDayX(x,n);
}