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
    system("chcp 65001");
    double n;
    int t1,t2;
    cout << "Nhập số lượng giá trị n: ";
    cin >> n;
    cout << "Nhập thời gian học tối thiểu: ";
    cin >> t1;
    cout << "Nhập thời gian học tối đa: ";
    cin >> t2;
    t2 = t2 - t1 + 1;
    srand(time(0));
//random n 
    for (int i=0;i<n;i++){
        int x = rand() % t2 + t1; // random t2-t1+1 số từ t1 đến t2
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
//chọn độ tin cậy
    int g1;
    double g;
    do {
        cout << "Độ tin cậy bao nhiêu?\n1.95%\t\t\t2.98%\t\t\t3.99%\n";
        cin >> g1;
    } while (g1!=1&&g1!=2&&g1!=3);
    switch(g1){
        case 1:
            g = 1.96;
            cout << "g = " << g << "\n";
            break;
        case 2:
            g = 2.33;
            cout << "g = " << g << "\n";
            break;
        case 3: 
            g = 2.58;
            cout << "g = " << g << "\n";
            break;
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
    cout << "E(x) = ("<<(ex-g*(shc/sqrt(n)))<<","<<(ex+g*(shc/sqrt(n)))<<")\n";
//tính khoảng cho tỉ lệ
    int choose;
    double f;
    do{
        cout << "Có random không?\n 1.Có\t\t\t2.Tự nhập\n";
        cin >> choose;
    } while(choose != 1 && choose != 2);
    switch(choose){
        case 1:
            f = rand() % 100 + 1;
            break;
        case 2:
            cout << "Nhập vào giá trị của f%(0=>100): ";
            cin >> f;
            break;
    }
    f/=100;
    cout << "f = " << f << "\n";
    cout << "p = ("<<(f-g*(sqrt(f*(1-f)/n)))<<","<<(f+g*(sqrt(f*(1-f)/n)))<<")\n";
}