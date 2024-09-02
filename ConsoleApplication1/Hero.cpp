#include "Hero.h"
//////////////////////////////class ThongSo////////////////////////////
ThongSo::ThongSo()
{
}
//set thộng số
ThongSo::ThongSo(ThuocTinh THUOCTINH, double MAU, double CONG, double THU, double TOCDO)
{
	this->thuoctinh = THUOCTINH;
	this->Mau = MAU;
	this->Cong = CONG;
	this->Thu = THU;
	this->TocDo = TOCDO;
	
}
//set ThuocTinh từ Thuộc tính cho sẵn
void ThongSo::setThuocTinh(ThuocTinh THUOCTINH)
{
	this->thuoctinh = THUOCTINH;
}
//set máu
void ThongSo::setMau(double MAU)
{
	this->Mau = MAU;
}
//set công
void ThongSo::setCong(double CONG)
{
	this->Cong = CONG;
}
//set thủ
void ThongSo::setThu(double THU)
{
	this->Thu = THU;
}
//set tốc độ
void ThongSo::setTocDo(double TOCDO)
{
	this->TocDo = TOCDO;
}
//get thông số
ThuocTinh ThongSo::getThuocTinh()
{
	return this->thuoctinh;
}
//get máu
double ThongSo::getMau()
{
	return this->Mau;
}
//get công
double ThongSo::getCong()
{
	return this->Cong;
}
//get thủ
double ThongSo::getThu()
{
	return this->Thu;
}
//get tốc độ
double ThongSo::getTocDo()
{
	return this->TocDo;
}
//hàm hủy
ThongSo::~ThongSo()
{
}
////////////////////////////////class Hero///////////////////////
Hero::Hero()
{
}
//set hero
Hero::Hero(string TEN, ThuocTinh THUOCTINH, double MAU, double CONG, double THU, double TOCDO):ThongSo(THUOCTINH,MAU,CONG,THU,TOCDO)
{
	this->Ten = TEN;
}
//set Hero từ string LINE
Hero Hero::setHero(string LINE,DanhSachThuocTinh LIST_THUOCTINH)
{

	string TEN, THUOCTINH, MAU, CONG, THU, TOCDO;
	stringstream line(LINE);
	getline(line, TEN, ';');
	getline(line, THUOCTINH, ';');
	getline(line, MAU, ';');
	getline(line, CONG, ';');
	getline(line, THU, ';');
	getline(line, TOCDO, ' ');
	ThuocTinh TT = LIST_THUOCTINH.getThuocTinh(THUOCTINH);
	Hero x = Hero(TEN, TT, stof(MAU), stof(CONG), stof(THU), stof(TOCDO));
	return x;
}
//hàm buff cho Hero
void Hero::Buff(float MAU, float CONG, float THU, float TOCDO)
{
	this->Mau *= MAU+1;
	this->Cong *= CONG+1;
	this->Thu *= THU+1;
	this->TocDo *= TOCDO+1;
}
//hàm debuff cho Hero
void Hero::DeBuff(float MAU, float CONG, float THU, float TOCDO)
{
	this->Mau *= 1-MAU;
	this->Cong *= 1-CONG;
	this->Thu *= 1-THU;
	this->TocDo *= 1-TOCDO;
}
//hàm cập nhật thông số từ ảnh hưởng môi trường
void Hero::Anh_Huong_Moi_Truong(ThuocTinh Moi_Truong)
{
	if (Moi_Truong.getTuongKhac() == getThuocTinh().getTen())//Nếu môi trường tương khắc với thuộc tính của A
	{
		DeBuff(0.03, 0, 0, 0);//chỉ số máu giảm 3%
	}
	if (Moi_Truong.getTuongSinh() == getThuocTinh().getTen())//Nếu môi trường tương sinh với thuộc tính của A
	{
		Buff(0.05, 0, 0, 0);//chỉ số máu tăng 5%
		DeBuff(0, 0, 0, 0.1);//chỉ số tốc độ giảm đi 10%
	}
}
//set ten
void Hero::setTen(string TEN)
{
	this->Ten = TEN;
}
//get ten
string Hero::getTen()
{
	return this->Ten;
}
//in ra man hinh
void Hero::display()
{
	cout << this->Ten + ";" + this->thuoctinh.getTen() + ";"<< this->Mau
		<<";" << this->Cong
		<<";" << this->Thu
		<<";" << this->TocDo;
}
//đưa về string
string Hero::toString()
{
	return this->Ten+";"+this->thuoctinh.getTen()+";"+to_string(this->Mau)+";"+to_string(this->Cong)+";"+to_string(this->Thu)+";"+to_string(this->TocDo);
}
//======================class ListHero============================
ListHero::ListHero()
{
}
//set ListHero
ListHero::ListHero(vector<Hero> x)
{
	this->Listhero = x;
}
//set danh sách hero từ 1 chuổi với danh sách thuộc tính và số lượng Hero đã biết
ListHero ListHero::setFromLine(string LINE,DanhSachThuocTinh LIST_THUOCTINH,int SIZE)
{
	stringstream line(LINE);
	//push size-1 Hero vào danh sách Hero trước
	for (int i = 0; i < SIZE - 1; i++)
	{
		Hero Y;
		string HERO;
		getline(line, HERO, ',');
		this->Listhero.push_back(Y.setHero(HERO, LIST_THUOCTINH));
	}
	//push Hero còn lại của chuổi
	Hero Y;
	string HERO;
	getline(line, HERO, ' ');
	this->Listhero.push_back(Y.setHero(HERO, LIST_THUOCTINH));
	return this->Listhero;
}
//get listhero
vector<Hero> ListHero::getListHero()
{
	return this->Listhero;
}
//set listherp từ file
void ListHero::setFile(string FILENAME, DanhSachThuocTinh LIST_THUOCTINH)
{
	fstream F;
	F.open(FILENAME, ios::in);
	if (F.is_open()) {
		string s;
		Hero x;
		while (!F.eof()) {
			getline(F, s);
			this->Listhero.push_back(x.setHero(s,LIST_THUOCTINH));
		}
		F.close();
	}
}
//get hero từ listhero
Hero ListHero::getHero(string TEN_HERO)
{
	vector<Hero> LIST = this->Listhero;
	vector <Hero>::iterator i;
	for (i = LIST.begin(); i != LIST.end(); i++)
	{
		Hero y = *i;
		if (TEN_HERO == y.getTen()) {
			return y;
		}
	}
}
//set hero vào listhero
void ListHero::setHero(string INFORMATION, DanhSachThuocTinh LIST,string FILENAME)//Thêm 1 Hero vào Danh sách và file ListHero.txt
{
	Hero X= X.setHero(INFORMATION, LIST);
	this->Listhero.push_back(X);//Thêm vào danh sách
	fstream F;
	F.open(FILENAME, ios::app);
	if (F.is_open()) {
		F << X.toString();//Thêm vào cuối file
		F.close();
	}
	else cout << "Failed to open this file!" << endl;
}
//xóa hero khỏi listhero
void ListHero::removeHero(string TEN_HERO)
{
	vector<Hero> LIST = this->Listhero;
	vector <Hero>::iterator i;
	for (i = LIST.begin(); i != LIST.end(); i++)
	{
		Hero y = *i;
		if (TEN_HERO == y.getTen()) {
			LIST.erase(i);
			this->Listhero = LIST;
			break;
		}
	}
}
//đưa về string
string ListHero::toString()
{
	string LISTHERO="";
	vector<Hero> LIST = this->Listhero;
	vector <Hero>::iterator i;
	for (i = LIST.begin(); i != LIST.end(); i++)
	{
		Hero y = *i;
		LISTHERO = LISTHERO + y.toString() + ",";
	}
	 return LISTHERO.substr(0, LISTHERO.size() - 1);//return ra LISTHERO ở dạng string và xóa dấu "," ở cuối chuổi

}
//in ra màn hình
void ListHero::display()
{
	vector<Hero> LIST = this->Listhero;
	vector <Hero>::iterator i;
	for (i = LIST.begin(); i != LIST.end(); i++)
	{
		Hero y = *i;
		cout << y.toString() << endl;
	}
}



