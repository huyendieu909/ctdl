/*tool auto bài tập xác suất thống kê*/
#define pb push_back
#define mp make_pair
#define toiuu ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#include <bits/stdc++.h>
using namespace std;
map<int,int> mapa;
deque<int> q;
int main(){
    // toiuu;
    double n;
    int t1,t2;
    cout << "Nhap so luong gia tri n: ";
    cin >> n;
    cout << "Nhap thoi gian hoc toi thieu: ";
    cin >> t1;
    cout << "Nhap thoi gian hoc toi da: ";
    cin >> t2;
    t2 = t2 - t1 + 1;
    srand(time(0));
//random n 
    for (int i=0;i<n;i++){
        int x = rand() % t2 + t1; // random 10 số từ 1 đến 10
        q.pb(x); 
        mapa[x]++;
    }
// //  nếu như không thích random thì sao?
//     for (int i=0;i<n;i++){
//         int x;
//         cin >> x;
//         q.pb(x); 
//         mapa[x]++;
//     }
//in ra các số đã random
    cout << "\n";
    for (auto c: q){
        cout << c << " ";
    }
//kết quả đếm
    cout << "\n";
    for (auto c: mapa){
        cout << "\t"<< c.first << " : " << c.second << "\n";
    }
//tính x ngang
    double ex = 0;
    for (auto c: mapa){
        ex += c.first * c.second;
    }
    ex /= n;
    cout << fixed << setprecision(4) << "x ngang = " << ex <<"\n";

//Tính s2,s
    double s2=0,s=0;
    for (auto c: mapa){
        s2 += c.first * c.first * c.second;
    }
    s2 /= n; s2 = s2-(ex*ex);
    cout << "s2 = " << s2<<"\n";
    s = sqrt(s2);
    cout << "s = " << s << "\n";
//tính s'
    double shc = sqrt(((double)n/(double)(n-1))*s2);
    cout << "s' = " << shc << "\n";    
//tính khoảng cho giá trị trung bình
    cout << "E(x) = ("<<(ex-1.96*(shc/sqrt(n)))<<","<<(ex+1.96*(shc/sqrt(n)))<<")\n";
//tính khoảng cho tỉ lệ
    double f = rand() % 100 + 1;
    f/=100;
    cout << "f = " << f << "\n";
    cout << "p = ("<<(f-1.96*(sqrt(f*(1-f)/n)))<<","<<(f+1.96*(sqrt(f*(1-f)/n)))<<")\n";
}