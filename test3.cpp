#include <bits/stdc++.h>
using namespace std;
void menu(){
    cout << "Lựa chọn công việc:\n";
    cout << "1. Mã hóa một chuỗi ceasar\n";
    cout << "2. Giải mã chuỗi ceasar\n";
}
void nhapThongTin(string &s){
    cout << "Nhập vào chuỗi ký tự cần thao tác: ";
    cin >> s;
}
void maHoa(string &s,string &ss){
    ss = "";
    int a;
    for(int i=0;i<s.size();i++){
        a = (int)(s[i])+3;
        if (a > 'z') a-=26;
        ss += (char)(a);
    }
    cout << "Chuỗi sau khi mã hóa ceasar: "<<ss;
}
void giaiMa(string &s, string &ss){
    ss = "";
    int a;
    for(int i=0;i<s.size();i++){
        a = (int)(s[i])-3;
        if (a < 'a') a+=26;
        ss += (char)(a);
    }
    cout << "Chuỗi sau khi giải mã hóa ceasar: "<<ss;
}
void luaChon(int a, string &s, string &ss){
    if (a==1){
        nhapThongTin(s);
        maHoa(s,ss);
    }
    if (a==2){
        nhapThongTin(s);
        giaiMa(s,ss);
    }
}
int main(){
    system("chcp 65001");
    string s,ss;
    int a;
    menu();
    cout << "Nhập lựa chọn: "; 
    cin >> a;
    luaChon(a,s,ss);
    cout << "\n";
    system("pause");
}