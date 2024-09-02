#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<fstream>
#include<stdlib.h>
#include <windows.h>
using namespace std;
class ThuocTinh 
{
private:
	string Ten;
	string TuongSinh;
	string TuongKhac;
public:
	ThuocTinh();
	ThuocTinh(string TEN, string TUONGSINH, string TUONGKHAC);
	ThuocTinh setThuocTinh(string LINE);//set thuộc tính từ chuổi LINE
	void setTen(string TEN);//set tên thuộc tính
	void setTuongSinh(string TUONGSINH);//set tên thuộc tính tương sinh
	void setTuongKhac(string TUONGKHAC);//set tên thuộc tính tương khắc
	string getTen();//get tên thuộc tính
	string getTuongSinh();//get tên thuộc tính tương sinh
	string getTuongKhac();//get tên thuộc tính tương khắc
	virtual~ThuocTinh();
};
class DanhSachThuocTinh 
{
private:
	vector<ThuocTinh> DanhSach;
public:
	DanhSachThuocTinh();
	DanhSachThuocTinh(vector<ThuocTinh>);//set danh sách thuộc tính
	vector<ThuocTinh> getDanhSachThuocTinh();
	void setFile(string FILENAME);//set danh sách thuộc tính từ file
	void ThemThuocTinh(ThuocTinh a);//set 1 thuộc tính vào danh sách
	ThuocTinh getThuocTinh(string NameThuocTinh);//get 1 thuộc tính từ danh sách
	virtual~DanhSachThuocTinh();
};

