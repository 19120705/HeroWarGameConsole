#include "ThuocTinh.h"

ThuocTinh::ThuocTinh()
{

}
//set thuộc tính
ThuocTinh::ThuocTinh(string TEN, string TUONGSINH, string TUONGKHAC)
{
	this->Ten = TEN;
	this->TuongSinh = TUONGSINH;
	this->TuongKhac = TUONGKHAC;
}
//set thuộc tính từ 1 string LINE
ThuocTinh ThuocTinh::setThuocTinh(string LINE)
{
	string TEN, TUONGSINH, TUONGKHAC;
	stringstream line(LINE);
	getline(line, TEN, ';');
	getline(line, TUONGSINH, ';');
	getline(line, TUONGKHAC, ' ');
	ThuocTinh x=ThuocTinh(TEN, TUONGSINH, TUONGKHAC);
	return x;
}
//set tên
void ThuocTinh::setTen(string TEN)
{
	this->Ten = TEN;
}
//set tương sinh
void ThuocTinh::setTuongSinh(string TUONGSINH)
{
	this->TuongSinh = TUONGSINH;
}
//set tương khắc
void ThuocTinh::setTuongKhac(string TUONGKHAC)
{
	this->TuongKhac = TUONGKHAC;
}
//get tên
string ThuocTinh::getTen()
{
	return this->Ten;
}
//get tương sinh
string ThuocTinh::getTuongSinh()
{
	return this->TuongSinh;
}
//get tương khắc
string ThuocTinh::getTuongKhac()
{
	return this->TuongKhac;
}
//hàm hũy
ThuocTinh::~ThuocTinh()
{
}
//===================danh sách thuộc tính=================
DanhSachThuocTinh::DanhSachThuocTinh()
{
}
//set danh sách thuộc tính
DanhSachThuocTinh::DanhSachThuocTinh(vector<ThuocTinh> x)
{
	this->DanhSach = x;
}
//get danh sách thuộc tính
vector<ThuocTinh> DanhSachThuocTinh::getDanhSachThuocTinh()
{
	return this->DanhSach;
}
//set danh sách thuộc tính từ file
void DanhSachThuocTinh::setFile(string FILENAME)
{
	fstream F;
	F.open(FILENAME, ios::in);
	if (F.is_open()) {//kiểm tra mở file
		string s;
		ThuocTinh x;
		while (!F.eof()) {
			getline(F, s);
			this->DanhSach.push_back(x.setThuocTinh(s));//đưa vào danh sách thuộc tính
		}
		F.close();
	}
}
//thêm thuộc tính vào danh sách thuộc tính
void DanhSachThuocTinh::ThemThuocTinh(ThuocTinh a)
{
	this->DanhSach.push_back(a);
}
//lấy 1 thuộc tính từ danh sách thuộc tính
ThuocTinh DanhSachThuocTinh::getThuocTinh(string NameThuocTinh)
{
	vector<ThuocTinh> LIST = this->DanhSach;
	vector <ThuocTinh>::iterator i;
	for (i = LIST.begin(); i != LIST.end(); i++)
	{
		ThuocTinh y = *i;
		if (NameThuocTinh == y.getTen()) {
			return y;
			break;
		}
	}
}
//hàm hũy
DanhSachThuocTinh::~DanhSachThuocTinh()
{

}
