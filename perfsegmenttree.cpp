#include <bits/stdc++.h>
using namespace std;
#define toiuu ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

unordered_map<int,int> tree;
void build(int n){
    for (int i=0;i<n;i++){
        cin >> tree[i+n];
    }
    for (int i=n-1;i>0;i--){
        tree[i] = tree[i<<1] + tree[i<<1|1];
    }
}
int querySum(int l, int r, int n){ //tính tổng trong nửa khoảng [l,r)
    int sum = 0;
    for (l+=n,r+=n;l<r;l>>=1,r>>=1){
        if (l&1) sum += tree[l++];
        if (r&1) sum += tree[--r];
    }
    return sum;
}
void modify(int p, int k, int n){
    tree[p+n] += k;
    for (int i = (p+n)>>1;i>=1;i>>=1){
        tree[i] = tree[i<<1] + tree[i<<1|1];
    }
}
void showTree(int n){
    for (int i=1;i<2*n;i++){
        cout << tree[i] << " ";
    }
}
int main(){
    int n;
    cout << "Nhap so phan tu mang: ";
    cin >> n;
    cout << "Nhap mang: ";
    build(n);
    cout << "Nhap so truy van: ";
    int t;
    cin >> t;
    while (t--){
        int x,y;
        cin >> x >> y;
        x--;
        cout << "Tong trong doan tu "<<x<<" den "<<y<< " la: " << querySum(x,y,n) << "\n";
    }
}











// #include <bits/stdc++.h>
// using namespace std;
// #define pb push_back
// #define mp make_pair
// #define toiuu ios::sync_with_stdio(false);cin.tie(0);
// unordered_map<int,int> tree;
// int query(int l, int r,int n){ //tính trong nửa khoảng [l,r)
//     int sum = 0;
//     for (l += n,r += n;l<r;l>>=1,r>>=1){
//         if (l&1) sum += tree[l++];
//         if (r&1) sum += tree[--r];
//     }
//     return sum;
// }
// void build(int &n){
//     cin >> n;
//     for (int i=0;i<n;i++){
//         cin >> tree[i+n];
//     }
//     for (int i=n-1;i>0;i--){
//         tree[i] = tree[i<<1] + tree[i<<1|1];
//     }
// }
// void showTree(int n){
//     for (int i=1;i<(n<<1);i++){
//         cout << tree[i] <<" ";
//     }
// }
// void modify(int p,int k,int n){
//     tree[p+n] += k;
//     for (int i=(p+n)/2;i>=1;i>>=1){
//         tree[i] = tree[i<<1] + tree[i<<1|1];
//     }
// }
// int main(){
//     toiuu;
//     int n;
//     build(n);
//     showTree(n);
//     int a,b;
//     cin >> a >> b; a--;b--;
//     cout << "\n" << query(a,b+1,n);
//     cout << "\nmodify: ";
//     int k,p;
//     cin >> p >> k;
//     k;p--;
//     modify(p,k,n);
//     cout << "\n";
//     showTree(n);
//     cout << "\n" << query(a,b+1,n);
// }