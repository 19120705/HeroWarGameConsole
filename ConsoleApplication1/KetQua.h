#pragma once
#include"Hero.h"
#include"ThuocTinh.h"
#include<time.h>
class Time
{
private:
	int Sec;         /* biểu diễn giây*/
	int Min;         /* biểu diễn phút*/
	int Hour;        /* biểu diễn giờ*/
	int Mday;        /* biểu diễn ngày của tháng */
	int Mon;         /* biểu diễn tháng*/
	int Year;        /* biểu diễn năm*/
public:
	Time();
	Time(int SEC, int MIN, int HOUR, int MDAY, int MON, int YEAR);
	Time setTime(string LINE);//set thời gian từ 1 LINE
	string toString();//đưa về string
	void display();//in ra màn hình
};
class HiepDau
{
private:
	Time ThoiGian;
	string TenPlayer1;
	ListHero DanhSachHero_Player1;
	string TenPlayer2;
	ListHero DanhSachHero_Player2;
	string KetQua;
public:
	HiepDau();//contructor
	HiepDau(Time, string, ListHero, string, ListHero, string);//contructor
	HiepDau setHiepDau(string LINE,DanhSachThuocTinh LIST_THUOCTINH,int SO_HERO_MOI_DOI);//set hiệp đấu từ chuổi LINE và danh sách thuộc tính có sẵn
	void setThoiGian(Time);//set thời gian
	void setKetQua(string);//set kết quả
	Time getThoiGian();//get thời gian
	string getKetQua();//get kết quả
	string toString();//đưa về dạng string
	void display();//in ra màn hình
};
class DanhSachHiepDau
{
private:
	vector<HiepDau> Danh_Sach_Dau;
public:
	DanhSachHiepDau();//contructor
	DanhSachHiepDau(vector<HiepDau>);////contructor
	vector<HiepDau> getDanhSachDau();//get ra danh sách hiệp đấu
	void setFile(string FILENAME,DanhSachThuocTinh LIST_THUOCTINH,int SO_HERO);//set danh sách đấu từ file log.txt
	void setHiepDau(HiepDau HIEPDAU, string FILENAME);//thêm 1 hiệp đấu vào dánh sách đấu và file log.txt
	HiepDau getHiepDau(Time THOIGIAN);//đưa ra hiệp đầu từ thời gian đấu tương ứng
	void display();//in ra màn hình các mốc thời gian tương ứng với hiệp đấu
	virtual~DanhSachHiepDau();
};