#include <bits/stdc++.h>
using namespace std;
void selection_sort(int a[], int n){
    for (int i = 0;i<n-1;i++){
        int m = i;
        for (int j = i+1;j<n;j++){
            if (a[j] > a[m]) m = j;
        }
        int temp = a[i];
        a[i] = a[m];
        a[m] = temp;
    }
}
int greedy(int a[], int n, int s){
    //sort(a,a+n,greater<>());
    selection_sort(a,n);
    int i = 0; int p = 0;
    while(i<n && p<=s){
        p+=a[i];
        i++;
    }
    if (p > s) return i;
    else return -1;
}
int main(){
    int n;
    cout << "Nhap so phan tu cua day a: ";
    cin >> n;
    int a[n];
    cout << "Nhap day a: ";
    for (int i = 0;i<n;i++){
        cin >> a[i];
    }
    int s;
    cout << "Nhap so s: ";
    cin >> s;
    cout << "So phan tu can lay trong day a de duoc tong p > s la: " << greedy(a,n,s);
}