#include <bits/stdc++.h>
using namespace std;
struct sv{
	char maSV[30];
	char hoDem[100];
	char ten[30];
	int namSinh;
	double diemTK;
};
struct Node{
	sv infor;
	Node* next;
};
typedef Node* TRO;
void create(TRO &L){
	L = NULL;
}
int isEmpty(TRO L){
	return L == NULL;
}
void add(TRO &L, sv X){
	TRO P = new Node;
	P->infor = X;
	P->next = NULL;
	if (isEmpty(L)) L = P;
	else {
		TRO Q = L;
		while (Q->next != NULL) Q = Q->next;
		Q->next = P;
	}
}
int lengthL(TRO L){
	if (isEmpty(L)) return 0;
	int i=0;
	while (L!=NULL){
		L = L->next;
		i++;
	}
	return i;
}
void nhap1SV(sv &X){
	cout << "\tNhap ma sinh vien: ";
	fflush(stdin);
	gets(X.maSV);
	if (strcmp(X.maSV,"***") == 0) return;
	cout << "\tNhap ho dem: ";
	fflush(stdin);
	gets(X.hoDem);
	cout << "\tNhap ten: ";
	fflush(stdin);
	gets(X.ten);
	cout << "\tNhap nam sinh: ";
	cin >> X.namSinh;
	cout << "\tNhap diem tong ket: ";
	cin >> X.diemTK;
}
void nhapDSSV(TRO &L){
	sv X;
	int i=1;
	do{
		cout << "Nhap thong tin cho sinh vien thu "<<i<<": \n";
		nhap1SV(X);
		if (strcmp(X.maSV,"***") != 0){
			add(L,X);
			i++;
		}
	} while (strcmp(X.maSV,"***") != 0);
}
void hienThiDS(TRO L){
	if (isEmpty(L)) cout << "Danh sach rong.\n";
	else {
		cout << setw(3) << right << "STT";
		cout << setw(10) << right << "Ma SV";
		cout << setw(15) << right << "Ho dem";
		cout << setw(12) << right << "Ten";
		cout << setw(15) << right << "Nam sinh";
		cout << setw(20) << right << "Diem tong ket\n";
		TRO Q = L;
		int i = 1;
		while (Q != NULL){
			cout << setw(3) << right << i;
			cout << setw(10) << right << Q->infor.maSV;
			cout << setw(15) << right << Q->infor.hoDem;
			cout << setw(12) << right << Q->infor.ten;
			cout << setw(15) << right << Q->infor.namSinh;
			cout << setw(13) << right << Q->infor.diemTK << "\n";
			Q = Q->next;
			i++;
		}
	}
}
void xoaSVDauTien(TRO &L){
	if (isEmpty(L)) cout << "Danh sach rong, khong the xoa!\n";
	else {
		TRO Q = L;
		L = L->next;
		delete(Q);
	}
}
TRO search(TRO &L, const char* c){
	TRO Q = L;
	while (Q!=NULL){
		if (strcmp(Q->infor.maSV,c)==0) return Q;
		Q = Q->next;
	}
	return NULL;
}
void remove(TRO &L, TRO Q){
	if (isEmpty(L)) cout << "Danh sach rong.\n";
	else{
		TRO K = L;
		while (K->next != Q) K = K->next;
		K->next = Q->next;
		delete(Q);
	}
}
void xoaSV_sv8089(TRO &L){
	TRO Q = search(L,"sv8089"); 
	while (Q != NULL){
		if (Q == L) xoaSVDauTien(L);
		else remove(L,Q);
		Q = search(L,"sv8089"); 
	}
}
void chenSVVaoDauDS(TRO &L, TRO P){
	P->next = L;
	L = P;
}
void chenSVVaoViTriK(TRO &L){
	int k;
	do {
		cout << "Nhap vi tri k(1<=k<="<<lengthL(L)<<") can chen: ";
		cin >> k;
	} while (k < 1 || k > lengthL(L));
	cout << "Nhap thong tin cho sinh vien can chen: \n";
	sv X;
	nhap1SV(X);
	TRO P = new Node;
	P->infor = X;
	if (k == 1) chenSVVaoDauDS(L,P);
	else {
		TRO Q = L;
		int dem = k-2;
		while (dem--){
			Q = Q->next;
		}
		P->next = Q->next;
		Q->next = P;
	}
}
void DSTenDoanh(TRO L){
	if (isEmpty(L)) cout << "Danh sach rong.\n";
	else {
		cout << setw(3) << right << "STT";
		cout << setw(10) << right << "Ma SV";
		cout << setw(15) << right << "Ho dem";
		cout << setw(12) << right << "Ten";
		cout << setw(15) << right << "Nam sinh";
		cout << setw(20) << right << "Diem tong ket\n";
		TRO Q = L;
		int i = 1;
		while (Q != NULL){
			if (strcmp(Q->infor.ten,"Doanh") == 0){
				cout << setw(3) << right << i;
				cout << setw(10) << right << Q->infor.maSV;
				cout << setw(15) << right << Q->infor.hoDem;
				cout << setw(12) << right << Q->infor.ten;
				cout << setw(15) << right << Q->infor.namSinh;
				cout << setw(13) << right << Q->infor.diemTK << "\n";
				i++;
			}
			Q = Q->next;
		}
	}
}
void doiCho(TRO &L, TRO &R){
	sv temp = L->infor;
	L->infor = R->infor;
	R->infor = temp;
}
void sapXepDS(TRO &L){
	TRO R = L;
	while (R->next!=NULL){
		TRO Q = R->next;
		TRO M = R;
		while(Q!=NULL){
			if (Q->infor.diemTK > M->infor.diemTK) M = Q;
			Q = Q->next;
		}
		doiCho(R,M);
		R = R->next;
	}
}
void chenKhongDoiTratTu(TRO &L){
	cout << "Nhap thong tin sinh vien can chen: \n";
	sv X;
	nhap1SV(X);
	TRO P = new Node;
	P->infor = X;
	if (X.diemTK > L->infor.diemTK) chenSVVaoDauDS(L,P);
	else {
		TRO Q = L;
		while (Q != NULL && Q->infor.diemTK > X.diemTK){
			Q = Q->next;
		}
		TRO R = L;
		while (R->next != Q) R = R->next;
		P->next = R->next;
		R->next = P;
	}
	
}
int main(){
	TRO L = new Node;
	create(L);
	nhapDSSV(L);
	cout << "\n=======================================================================\n";
	cout << setw(70) << "-----Hien thi danh sach ban dau-----\n";
	hienThiDS(L);
	cout << "\n=======================================================================\n";
	cout << setw(70) << "-----Danh sach sau khi xoa phan tu dau tien-----\n";
	xoaSVDauTien(L);
	hienThiDS(L);
	cout << "\n=======================================================================\n";
	cout << setw(70) << "-----Danh sach sau khi xoa sinh vien ma sv8089-----\n";
	xoaSV_sv8089(L);
	hienThiDS(L);
	cout << "\n=======================================================================\n";
	cout << setw(70) << "-----Danh sach sau khi nhap them sinh vien-----\n";
	chenSVVaoViTriK(L);
	hienThiDS(L);
	cout << "\n=======================================================================\n";
	cout << setw(70) << "-----Danh sach sinh vien ten Doanh-----\n";
	DSTenDoanh(L);
	cout << "\n=======================================================================\n";
	cout << setw(70) << "-----Danh sach sinh vien sau khi sap xep-----\n";
	sapXepDS(L);
	hienThiDS(L);
	cout << "\n=======================================================================\n";
	cout << setw(70) << "-----Danh sach sinh vien nhap them khong thay trat tu-----\n";
	chenKhongDoiTratTu(L);
	hienThiDS(L);
}