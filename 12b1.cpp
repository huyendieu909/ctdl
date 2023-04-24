#include <bits/stdc++.h>
using namespace std;
struct sv{
    char maSV[30];
    char hoDem[50];
    char ten[30];
    char gioiTinh[15];
    int namSinh;
    double diemTK;
};
struct Node {
    sv infor;
    Node* next;
};
typedef Node* TRO;
void create(TRO &L) {
    L = NULL;
}
int isEmpty(TRO L) {
    return L == NULL;
}
void add(TRO &L, sv X) {
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
void nhap1SV(sv &X) {
    cout << "\tNhap ma sinh vien: ";    
    cin >> X.maSV;
    cout << "\tNhap ho dem: ";
    fflush(stdin);
    //cin.ignore();
    cin.getline(X.hoDem, 25);
    cout << "\tNhap ten: ";
    fflush(stdin);
    cin.getline(X.ten, 100);
    cout << "\tNhap gioi tinh: ";
    fflush(stdin);
    cin.getline(X.gioiTinh, 100);
    cout << "\tNhap nam sinh: ";
    fflush(stdin);
    cin >> X.namSinh;
    cout << "\tNhap diem tong ket: ";
    cin >> X.diemTK;
}
void nhapSV(int &n, TRO &L) {
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    fflush(stdin);
    cout << "Nhap thong tin cho cac sinh vien\n";
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin sinh vien thu " << (i + 1) << ": \n";
        sv X;
        nhap1SV(X);
        add(L, X);
    }
}
void inDS(TRO L) {
	if (L == NULL) cout << "Danh sach rong\n";
	else{
		TRO Q;
	    cout << setw(3) << right << "\nSTT" << setw(12) << "Ma SV" << setw(16) << "Ho Dem" << setw(8) << "Ten" << setw(14) << "Gioi tinh" << setw(14) << "Nam sinh" << setw(12) << "Diem TK\n";
	    if (!isEmpty(L)) {
	        Q = L;
	        int i = 1;
	        while (Q != NULL) {
	            cout << setw(3) << right << i << setw(12) << Q->infor.maSV << setw(16) << Q->infor.hoDem << setw(8) << Q->infor.ten << setw(14) << Q->infor.gioiTinh << setw(14) << Q->infor.namSinh << setw(11) << Q->infor.diemTK << "\n";
	            cout << "\n";
	            i++;
	            Q = Q->next;
	        }
	    }
	}    
}
void xoaPTDauTien(TRO &L){
	if (L == NULL){
		cout << "Danh sach rong\n";
	}
	else {
		TRO Q = L;
		L = L->next;
		delete(Q);
	}	
}
void chenPTVaoViTri3(TRO &L){
	int j = 1;
	TRO Q = L;
	TRO M;
	while (Q!=NULL && j < 3){
		M = Q;
		Q = Q->next;
		j++;
	}
	if (Q == NULL){
		cout << "Vi tri khong hop le\n";
	}	
	else {
		TRO P = new Node;
		strcpy(P->infor.maSV,"1006");
		strcpy(P->infor.hoDem,"Le Thi");
		strcpy(P->infor.ten,"Doan");
		strcpy(P->infor.gioiTinh,"nu");
		P->infor.namSinh = 1998;
		P->infor.diemTK = 7.6f;
		P->next = M->next;
		M->next = P;
	}
}
void sapXep(TRO &L){
	TRO M,R,Q;
	R = L;
	while (R->next != NULL){
		M = R;
		Q = R->next;
		while (Q!=NULL){
			if (strcmp(Q->infor.ten,M->infor.ten) < 0) M = Q;
			Q = Q->next;
		}
		sv t = R->infor;
		R->infor = M->infor;
		M->infor = t;
		R = R->next;
	}
}
int main()
{
    int n;
    TRO L;
    create(L);
    nhapSV(n, L); 
    cout << "\n====================================================================================\n";
    inDS(L);
    cout << "\n====================================================================================\n";
    cout << "---------Xoa phan tu dau tien trong danh sach---------\n";
    xoaPTDauTien(L);
    inDS(L);
    cout << "\n====================================================================================\n";
    cout << "---------Chen phan tu thu 3 vao danh sach---------\n";
    chenPTVaoViTri3(L);
    inDS(L);
    cout << "\n====================================================================================\n";
    cout << "---------Sap xep phan tu trong danh sach---------\n";
    sapXep(L);
    inDS(L);
    cout << "\n====================================================================================\n";
	std::cout << "Hello World!\n";
}
