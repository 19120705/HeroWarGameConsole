#include "KetQua.h"
///////////////////////class Time///////////////////////////////////////////////
Time::Time()
{
	Sec = 1;
	Min = 1;
	Hour = 1;
	Mday = 1;
	Mon = 1;
	Year = 1;
}
//set time
Time::Time(int SEC, int MIN, int HOUR, int MDAY, int MON, int YEAR)
{
	this->Sec = SEC;
	this->Min = MIN;
	this->Hour = HOUR;
	this->Mday = MDAY;
	this->Mon = MON;
	this->Year = YEAR;
}
//set thời gian từ chuổi LINE
Time Time::setTime(string LINE)
{
	string SEC, MIN, HOUR, MDAY, MON, YEAR;
	stringstream line(LINE);
	getline(line, SEC, ':');
	getline(line, MIN, ':');
	getline(line, HOUR, ' ');
	getline(line, MDAY, '/');
	getline(line, MON, '/');
	getline(line, YEAR, ' ');
	Time x = Time(atoi(SEC.c_str()), atoi(MIN.c_str()), atoi(HOUR.c_str()), atoi(MDAY.c_str()), atoi(MON.c_str()), atoi(YEAR.c_str()));
	return x;
}
//đưa về dạng string
string Time::toString()
{
	return to_string(this->Sec)+":"+ to_string(this->Min)+":"+ to_string(this->Hour)+" "+ to_string(this->Mday)+"/"+ to_string(this->Mon)+"/"+ to_string(this->Year);
}
//in ra màn hình
void Time::display()
{
	cout << toString();
}
/////////////////////class HiepDau///////////////////////////////////////
HiepDau::HiepDau()
{
}
HiepDau::HiepDau(Time TIME, string TEN1, ListHero DS1, string TEN2, ListHero DS2, string KETQUA)
{
	this->ThoiGian = TIME;
	this->TenPlayer1 = TEN1;
	this->TenPlayer2 = TEN2;
	this->DanhSachHero_Player1 = DS1;
	this->DanhSachHero_Player2 = DS2;
	this->KetQua = KETQUA;
}
//set HiepDau từ chuổi LINE và danh sách thuộc tính có sẵn
HiepDau HiepDau::setHiepDau(string LINE, DanhSachThuocTinh LIST_THUOCTINH, int SO_HERO_MOI_DOI)
{
	string TIME, TEN1, TEN2, DSHERO1, DSHERO2, KETQUA;
	stringstream line(LINE);
	getline(line, TIME, '|');
	getline(line, TEN1, ':');
	getline(line, DSHERO1, '|');
	getline(line, TEN2, ':');
	getline(line, DSHERO2, '|');
	getline(line, KETQUA, '.');
	Time THOIGIAN = THOIGIAN.setTime(TIME);
	ListHero DS1 = DS1.setFromLine(DSHERO1, LIST_THUOCTINH, SO_HERO_MOI_DOI);
	ListHero DS2 = DS2.setFromLine(DSHERO2, LIST_THUOCTINH, SO_HERO_MOI_DOI);
	HiepDau X = HiepDau(THOIGIAN, TEN1, DS1, TEN2, DS2, KETQUA);
	return X;
}
//set thời gian
void HiepDau::setThoiGian(Time TIME)
{
	this->ThoiGian = TIME;
}
//set kết quả
void HiepDau::setKetQua(string KETQUA)
{
	this->KetQua = KETQUA;
}
//get thời gian
Time HiepDau::getThoiGian()
{
	return this->ThoiGian;
}
//get kết quả
string HiepDau::getKetQua()
{
	return KetQua;
}
//đưa về dạng string
string HiepDau::toString()
{
	return this->ThoiGian.toString()+"|"
		+this->TenPlayer1+":"+this->DanhSachHero_Player1.toString()+"|"
		+this->TenPlayer2+":"+this->DanhSachHero_Player2.toString()+"|"
		+this->KetQua;
}
//in ra màn hình thông tin
void HiepDau::display()
{
	cout << this->ThoiGian.toString() << endl;
	cout << this->TenPlayer1 << endl;
	for (int i = 0; i < 3; i++)
	{
		DanhSachHero_Player1.getListHero()[i].display();
		cout << endl;
	}
	cout << this->TenPlayer2 << endl;
	for (int i = 0; i < 3; i++)
	{
		DanhSachHero_Player2.getListHero()[i].display();
		cout << endl;
	}

	cout << this->KetQua;
}
///////////////////////////class DanhSachHiepDau////////////////////////////
DanhSachHiepDau::DanhSachHiepDau()
{
}
//set danh sách hiệp đấu
DanhSachHiepDau::DanhSachHiepDau(vector<HiepDau> DSHIEPDAU)
{
	this->Danh_Sach_Dau = DSHIEPDAU;
}
//get danh sách hiệp đấu
vector<HiepDau> DanhSachHiepDau::getDanhSachDau()
{
	return this->Danh_Sach_Dau;
}
//set danh sách hiệp đấu từ file log.txt và danh sách thuộc tính có sẵn
void DanhSachHiepDau::setFile(string FILENAME,DanhSachThuocTinh LIST_THUOCTINH, int SO_HERO)
{
	fstream F;
	F.open(FILENAME, ios::in);
	if (F.is_open()) {
		string s;
		HiepDau x;
		while (!F.eof()) {
			getline(F, s);
			if (s != "")//bõ qua những hàng trống
			{
				this->Danh_Sach_Dau.push_back(x.setHiepDau(s, LIST_THUOCTINH, SO_HERO));
			}
		}
		F.close();
	}
}
//set 1 hiệp đấu vào danh sách hiệp đấu và file log.txt
void DanhSachHiepDau::setHiepDau(HiepDau HIEPDAU, string FILENAME)
{
	this->Danh_Sach_Dau.push_back(HIEPDAU);
	fstream F;
	F.open(FILENAME, ios::app|ios::ate);
	if (F.is_open()) {
		F << endl << HIEPDAU.toString();
		F.close();
	}
	else cout << "Failed to open this file!" << endl;
}
//get 1 hiệp đấu dựa vào thời gian
HiepDau DanhSachHiepDau::getHiepDau(Time THOIGIAN)
{
	vector<HiepDau> LIST = this->Danh_Sach_Dau;
	vector <HiepDau>::iterator i;
	for (i = LIST.begin(); i != LIST.end(); i++)
	{
		HiepDau y = *i;
		if (y.getThoiGian().toString() == THOIGIAN.toString())
		{
			return y;
		}
	}
}
//in ra màn hình danh sách mốc thời gian ứng với hiệp đấu
void DanhSachHiepDau::display()
{
	vector<HiepDau> LIST = this->Danh_Sach_Dau;
	vector <HiepDau>::iterator i;
	if (LIST.empty())
	{
		cout << "Danh sách trống!";
	}
	for (i = LIST.begin(); i != LIST.end(); i++)
	{
		HiepDau y = *i;
		cout << y.getThoiGian().toString() << endl;
	}
}
//hàm hủy
DanhSachHiepDau::~DanhSachHiepDau()
{
	this->Danh_Sach_Dau.clear();
}
