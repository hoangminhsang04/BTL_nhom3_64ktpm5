#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include <algorithm>

using namespace std;

// Lop Sinh Vien
class SinhVien
{
	private:
		int soThuTu,maSinhVien;
		float diem;
		string tenSinhVien,ngaySinh,queQuan,soDT;
	public:
		void NhapSinhVien();
		void XuatSinhVien();
		string getname();
		int getmsv();
		float getdiem();
		string xepLoai();
};
void SinhVien::NhapSinhVien()
{
	cout<<"Nhap so thu tu sinh vien: ";cin>> soThuTu;
	cout<<"Nhap ma sinh vien :";cin>> maSinhVien; cin.ignore();
	cout<<"Nhap ten cua sinh vien: "; getline(cin, tenSinhVien);
	cout<<"Nhap ngay sinh cua sinh vien: "; getline(cin, ngaySinh);
	cout<<"Nhap que quan cua sinh vien: "; getline(cin, queQuan);
	cout<<"Nhap so dien thoai cua sinh vien: "; getline(cin, soDT);
	cout<<"Nhap diem cua sinh vien: ";cin>>diem;cin.ignore();
}
void SinhVien::XuatSinhVien()
{
	cout<< soThuTu<< setw(15)<< maSinhVien<< setw(15)<< tenSinhVien<< setw(15)<< ngaySinh<< setw(15)<< queQuan<< setw(15)<< soDT<<endl;
}
string SinhVien::getname(){
	return tenSinhVien;
}
int SinhVien::getmsv()
{
	return maSinhVien;
}
float SinhVien::getdiem(){
	return diem;
}
string SinhVien::xepLoai(){
	if(diem >= 8 && diem < 10) return "Gioi";
	else if(diem >= 6.5 && diem < 8) return "Kha";
	else if(diem >= 4 && diem < 6.5 ) return "Trung Binh";
	else return "Yeu";
}
// Lop Mon Hoc
class MonHoc
{
	private:
		int maMonHoc,soTien,soTinChi;
		string tenMonHoc,giangVienpt;
	public:
		void NhapMonHoc();
		void XuatMonHoc();
		string gettenmh();
		int TienHoc();
};
void MonHoc::NhapMonHoc()
{
	cout<<"Nhap ma mon hoc: "; cin>> maMonHoc; cin.ignore();
	cout<<"Nhap ten mon hoc : "; getline(cin, tenMonHoc);
	cout<<"Nhap giang vien phu trach mon hoc: "; getline(cin, giangVienpt);
	cout<<"Nhap so tien cua 1 tin chi: ";cin>>soTien;
	cout<<"Nhap so tin chi cua mon hoc: ";cin>>soTinChi;cin.ignore();
}
void MonHoc::XuatMonHoc()
{
	cout<< maMonHoc<< setw(15)<< tenMonHoc<< setw(15)<<giangVienpt<<setw(15)<<soTien<<setw(15)<<soTinChi<<endl;
}
string MonHoc::gettenmh()
{
	return tenMonHoc;
}
int MonHoc::TienHoc(){
	return soTien*soTinChi;
}
// Ham de sap xep
bool sapxep( SinhVien a, SinhVien b) {
    return a.getname() < b.getname();
}
int main(){
	vector<SinhVien> DanhSachSV;
	vector<MonHoc> DanhSachMH;
	vector<string> DanhSachDK;
	int luachon;
	do{
		cout<<"\n---------------------MENU---------------------\n";
		cout<<"1.Thong tin lop hoc\n";
		cout<<"2.Thong tin mon hoc\n";
		cout<<"3.Tra cuu diem\n";
		cout<<"4.Dang ki mon hoc\n";
		cout<<"5.Danh sach dang ki mon hoc\n";
		cout<<"6.Thoat\n";
		cout<<"Hay nhap lua chon cua ban: ";
		do{
			cin>>luachon;cin.ignore();
			if(luachon > 6 || luachon < 1){
				cout<<"Ban da nhap sai xin hay nhap lai\n";
			}
		}while(luachon > 6 || luachon < 1);
		// Thông tin cua lop hoc
		if(luachon == 1){
			int lc;
			do{
				cout<<setw(30)<<"Thong Tin Lop Hoc\n";
				cout<<"1.Them sinh vien\n";
				cout<<"2.Danh sach sinh vien\n";
				cout<<"3.Tim kiem sinh vien\n";
				cout<<"4.Sap xep ten sinh vien\n";
				cout<<"5.Thoat\n";
				cout<<"Hay nhap lua chon cua ban: ";
				do{
					cin>>lc;cin.ignore();
					if(lc<1 || lc>5) cout<<"Ban  da nhap sai .Xin hay nhap lai!\n";
				}while(lc<1 || lc>5);
				// Hien thi  danh sach sinh vien
				if(lc == 2){
					cout<<"Danh sach sinh vien lop hoc\n";
					for(int i = 0; i<DanhSachSV.size(); i++){
						DanhSachSV[i].XuatSinhVien();
					}
				}
				// Them sinh vien vao danh sach
				if(lc == 1){
					cout<<"Ban hay nhap thong tin sinh vien\n";
					int n;
					cout<<"Nhap so sinh vien can them vao danh sach: ";cin>>n;cin.ignore();
					for(int i = 0; i < n; i++){
						SinhVien sv;
						sv.NhapSinhVien();
						DanhSachSV.push_back(sv);
					}
				}
				// Tim kiem sinh vien theo ten
				if(lc == 3){
					string ten;
					cout<<"Ban hay nhap ten ban muon tim kiem: ";getline(cin,ten);
					int d=0;
					for(int i = 0; i < DanhSachSV.size(); i++){
						if(DanhSachSV[i].getname()==ten){
							DanhSachSV[i].XuatSinhVien();
							d++;
							cout<<endl;
						}
					}
					if(d==0){
						cout<<"Khong tim thay sinh vien co ten "<<ten<<endl;
					}
				}
				//Sap xep danh sach sinh vien theo ten
				if(lc == 4){
					sort(DanhSachSV.begin(),DanhSachSV.end(),sapxep);
				}
			}while(lc!=5);
		}
		// Thong tin cua mon hoc
		if(luachon==2){
			int lc1;
			do{
				cout<<setw(30)<<"Thong Tin Mon Hoc\n";
				cout<<"1.Danh sach mon hoc\n";
				cout<<"2.Them mon hoc\n";
				cout<<"3.Tim kiem mon hoc\n";
				cout<<"4.So tien phai dong\n";
				cout<<"5.Thoat\n";
				cout<<"Ban hay nhap lua chon: ";
				do{
					cin>>lc1;cin.ignore();
					if(lc1<1 || lc1>5){
						cout<<"Ban da nhap lua chon sai. Hay nhap lai\n";
					}
				}while(lc1<1 || lc1>5);
				// Hien thi danh sach cac mon hoc
				if(lc1==1){
					cout<<"Danh sach cac mon hoc \n";
					for(int i = 0; i < DanhSachMH.size(); i++){
						DanhSachMH[i].XuatMonHoc();
					} 
				}
				// Them mon hoc vao danh sach
				if(lc1==2){
					cout<<"Ban hay nhap thong tin mon hoc\n";
					int m;
					cout<<"Nhap so mon hoc : ";cin>>m;cin.ignore();
					for(int i = 0; i < m; i++){
						MonHoc mh;
						mh.NhapMonHoc();
						DanhSachMH.push_back(mh);
					}
				}
				// Tim kiem mon hoc theo ten
				if(lc1==3){
					string ten1;
					int t=0;
					cout<<"Moi ban nhap ten mon hoc ban muon tim: ";getline(cin,ten1);
					for(int i = 0; i < DanhSachMH.size(); i++){
						if(DanhSachMH[i].gettenmh()==ten1){
							DanhSachMH[i].XuatMonHoc();
							t++;
							cout<<endl;
						}
					}
					if(t == 0){
						cout<<"Khong tim thay mon hoc nay\n";
					}
				}
				if(lc1 == 4){
					for(int i = 0; i < DanhSachMH.size(); i++){
						cout<<"so tien phai dong cho mon hoc "<<DanhSachMH[i].gettenmh()<<": ";
						cout<<DanhSachMH[i].TienHoc()<<endl;
					}
				}
			}while(lc1!=5);
		}
		//Danh sach bang diem cua cac sinh vien
		if(luachon == 3){
			cout<<"Bang diem \n";
			for(int i = 0; i < DanhSachSV.size(); i++){
				cout<<DanhSachSV[i].getmsv();
				cout<<setw(20);
				cout<<DanhSachSV[i].getname();
				cout<<setw(20);
				cout<<DanhSachSV[i].getdiem();
				cout<<setw(20);
				cout<<DanhSachSV[i].xepLoai();
				cout<<endl;
			}
		}
		// Sinh vien dang ki mon hoc
		if (luachon == 4){
			string dk;
			int d=0;
			for(int i = 0; i<DanhSachSV.size(); i++)
			{
				cout<<"Dang ky mon hoc cho sinh vien "<<DanhSachSV[i].getname()<<" co ma sinh vien "<<DanhSachSV[i].getmsv()<<": ";
				getline(cin,dk);
				for(int i = 0;i < DanhSachMH.size(); i++){
					if(DanhSachMH[i].gettenmh() == dk){
						DanhSachDK.push_back(dk);
					}
				}
			}
		}
		//Danh sach sinh vien dang ki mon hoc
		if(luachon == 5){
			cout<<"Danh sach cac sinh vien dang ki mon hoc\n ";
			for(int i = 0; i <DanhSachSV.size(); i++){
				cout<<DanhSachSV[i].getmsv();
				cout<<setw(20);
				cout<<DanhSachSV[i].getname();
				cout<<setw(20);
				cout<<DanhSachDK[i];
				cout<<endl;
			}
		}
	}while(luachon!=6);
	return 0;
}
