#include <bits/stdc++.h>
using namespace std;
struct HangHoa{
	char maHang[20];
	char tenHang[50];
	char donViTinh[20];
	long donGia;
	long soLuong;
	long thanhTien;
};
struct Node{
	HangHoa infor;
	Node* next;	
};
typedef Node* TRO;
void create(TRO &L){
	L = NULL;
}
int isEmpty(TRO &L){
	return L == NULL;
}
void add(TRO &L, HangHoa X){
	TRO P = new Node;
	P->infor = X;
	P->next = NULL;
	if (isEmpty(L)) L = P;	
	else {
		TRO Q = L;
		while (Q->next!=NULL) Q = Q->next;
		Q->next = P;
	}
}
void nhap1PT(HangHoa &X){
	cout << "\tNhap ma hang: ";
	cin >> X.maHang;
	cout << "\tNhap ten hang: ";
	fflush(stdin);
	cin.getline(X.tenHang,50);
	cout << "\tNhap don vi tinh: ";
	fflush(stdin);
	cin.getline(X.donViTinh,20);
	cout << "\tNhap don gia: ";
	cin >> X.donGia;
	cout << "\tNhap so luong: ";
	cin >> X.soLuong;
	X.thanhTien = X.donGia * X.soLuong;
}
void nhapDS(TRO &L, int &n){
	cout << "Nhap so luong mat hang: ";
	cin >> n;
	for (int i=0;i<n;i++){
		cout << "Nhap thong tin hang hoa thu "<<(i+1)<<": \n";
		HangHoa X;
		nhap1PT(X);
		add(L,X);
	}
}
void inDS(TRO L){
	if (isEmpty(L)) cout << "Danh sach rong\n";
	else {
		cout << setw(3) << "STT";
		cout << setw(16) << "Ma hang";
		cout << setw(16) << "Ten hang";
		cout << setw(16) << "Don vi tinh";
		cout << setw(16) << "Don gia";
		cout << setw(16) << "So luong";
		cout << setw(16) << "Thanh tien\n";
		TRO Q = L;
		int i = 1;
		while (Q!=NULL){
			cout << setw(3) << i;
			cout << setw(16) << Q->infor.maHang;
			cout << setw(16) << Q->infor.tenHang;
			cout << setw(16) << Q->infor.donViTinh;
			cout << setw(16) << Q->infor.donGia;
			cout << setw(16) << Q->infor.soLuong;
			cout << setw(15) << Q->infor.thanhTien;
			cout << "\n";
			i++;
			Q = Q->next;
		}
	}
}
void xoaPT3(TRO &L){
	int i=1;
	TRO Q = L;
	while (Q->next!=NULL&&i<2){
		Q = Q->next;
		i++;
	}
	if (Q->next == NULL) cout << "Khong co phan tu thu 3\n";
	else {
		TRO P = Q->next;
		Q->next = P->next;
		delete(P);
	}
}
int main(){
	TRO L;
	int n;
	create(L);
	nhapDS(L,n);
	cout << "\n============================================================================================\n";
	cout << setw(70) << "---------Danh sach ban dau---------\n";
	inDS(L);
	cout << "\n============================================================================================\n";
	cout << setw(70) << "---------Xoa phan tu thu 3---------\n";
	xoaPT3(L);
	inDS(L);
}