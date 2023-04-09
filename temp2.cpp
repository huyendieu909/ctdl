#include <bits/stdc++.h> 
using namespace std;
void tinh_ty_le_gt_tren_kl(int m[], int c[], int value[], int n){
    for (int i=0;i<n;i++){
        value[i] = c[i]/m[i];
    }
}
void selection_sort(int value[], int n, int m[], int c[]){
    for (int i = 0;i<n-1;i++){
        int p = i;
        for (int j = i+1;j<n;j++){
            if (value[j] > value[p]) p = j;
        }
        int temp = value[i];
        value[i] = value[p];
        value[p] = temp;
        temp = m[i];
        m[i] = m[p];
        m[p] = temp;
        temp = c[i];
        c[i] = c[p];
        c[p] = temp;
    }
}
void greedy(int value[], int n, int w,int m[], int c[]){
    //sort(a,a+n,greater<>());
    selection_sort(value,n,m,c);
    int i = 0; int p = 0;
    while(i<n && p<w){
        if (p+m[i]<=w) p+=m[i], i++;
        else break;
    }
    if (p <= w) {
        cout << "Can lay so do vat la: " << i << "\n";
        cout << "Cac do vat lay (khoi luong, gia tri): ";
        for (int j = 0;j<i;j++){
            cout << "("<<m[j]<<","<<c[j]<<");";
        }
    }
    else cout << -1;
}
int main(){
    int w;
    cout << "Nhap khoi luong toi da ba lo co the chua: ";
    cin >> w;
    int n;
    cout << "Nhap so do vat: ";
    cin >> n;
    int value[n],m[n],c[n];
    cout << "Nhap khoi luong va gia tri cua moi do vat: \n";
    for (int i = 0;i<n;i++){
        cout << "\tDo vat thu "<<(i+1)<<": ";
        cin >> m[i] >> c[i];
    }
    tinh_ty_le_gt_tren_kl(m,c,value,n);
    greedy(value,n,w,m,c);
}