/*dijkstra tìm đường đi ngắn nhất*/
#define pb push_back
#define toiuu ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v[101];
unordered_map<int,int> kc;
unordered_map<int,int> check;
priority_queue<pair<int,int>> q;
void add(int x,int y,int w){
    v[x].pb({y,w});
    v[y].pb({x,w});
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
//dijkstra
    q.push({0,xp});
    while (!q.empty()){
        int a = q.top().second;
        q.pop();
        if (check[a]==1) continue;
        check[a] = 1;
        for (auto c: v[a]){
            int b = c.first;
            int w = c.second;
            if (kc[b] > kc[a] + w) kc[b] = kc[a]+w; q.push({-kc[b],b});
        }
    }
//đưa ra khoảng cách ngắn nhất tới đỉnh đích
    cout << "Nhập đỉnh đích: ";
    int d; cin >> d;
    cout << kc[d];
//nếu muốn có thêm truy vấn để không phải nhập lại thì
//tạo thêm một biến t rồi dùng vòng while(t--)
}