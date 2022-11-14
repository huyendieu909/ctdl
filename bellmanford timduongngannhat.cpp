/*Bellman Ford tìm đường ngắn nhất*/
#define toiuu ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#include <bits/stdc++.h>
using namespace std;
map<pair<int,int>,int> v;
unordered_map<int,int> kc;
void add(int x,int y,int w){
    v[{x,y}] = w;
    v[{y,x}] = w;
}
int main(){
    //toiuu;
    system("chcp 65001");
    cout << "Nhập số đỉnh và số cạnh: ";
    int dinh,canh;
    cin >> dinh >> canh;
//tạo graph
    for (int i = 1;i<=canh;i++){
        int x,y,z;
        cin >> x >> y >> z;
        add(x,y,z);
    }
//chọn đỉnh xuất phát để tính đường đi ngắn nhất
    cout << "Nhập đỉnh xuất phát: ";int xp; cin >> xp;
//set khoảng cách ban đầu
    for (int i=1;i<=dinh;i++) kc[i] = 999999999;
    kc[xp] = 0;
//bellman ford
    for (auto c: v){
        int a = c.first.first;
        int b = c.first.second;
        int w = c.second;
        kc[b] = min(kc[b],kc[a] + w);
    }
    cout << "chọn đỉnh đích: ";
    int m; cin >> m;
    cout << "Khoảng cách ngắn nhất từ " << xp << " đến " << m << " là: " << kc[m];
    // for (auto c: v){
    //     cout << c.first.first << c.first.second << " " << c.second << "\n";
    // }
}