#pragma once
#include"ThuocTinh.h"
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
#include<time.h>
#include<math.h>
using namespace std;
class ThongSo
{
protected:
	ThuocTinh thuoctinh;
	double Mau, Cong, Thu, TocDo;
public:
	ThongSo();
	ThongSo(ThuocTinh THUOCTINH,double MAU, double CONG, double THU, double TOCDO);//contructor
	void setThuocTinh(ThuocTinh THUOCTINH);// set thuộc tính
	void setMau(double MAU);//set máu
	void setCong(double CONG);//set công
	void setThu(double THU);//set thủ
	void setTocDo(double TOCDO);//set tốc độ
	ThuocTinh getThuocTinh();//get thuộc tính
	double getMau();//get máu
	double getCong();//get công
	double getThu();//get thủ
	double getTocDo();//get tốc độ
	virtual void display()=0;//in ra màn hình
	virtual~ThongSo();
};

class Hero:public ThongSo
{
private:
	string Ten;
public:
	Hero();
	Hero(string TEN, ThuocTinh THUOCTINH, double MAU, double CONG, double THU, double TOCDO);//contructor
	void setTen(string TEN);//set tên hero
	string getTen();//get tên hero
	Hero setHero(string LINE,DanhSachThuocTinh LIST_THUOCTINH);//set 1 Hero từ thông tin đã cho
	void Buff(float MAU, float CONG, float THU, float TOCDO);//buff(tăng) thông số cho hero
	void DeBuff(float MAU, float CONG, float THU, float TOCDO);//debuff(giảm) thông số cho hero
	void Anh_Huong_Moi_Truong(ThuocTinh Moi_Truong);//thay đổi thông số từ ảnh hưởng của môi trường đến hero
	void display();//in ra màn hình
	string toString();//chuyển thông tin về string
};

class ListHero 
{
private:
	vector<Hero> Listhero;
public:
	ListHero();
	ListHero(vector<Hero> );//contructor
	ListHero setFromLine(string LINE,DanhSachThuocTinh LIST_THUOCTINH,int SIZE);//set Danh sách Hero từ string LINE
	vector<Hero> getListHero();//get ra Danh Sách Hero
	void setFile(string FILENAME,DanhSachThuocTinh LIST_THUOCTINH);//set Danh Sách Hero từ file ListHero.txt và cập nhật thuộc tính cho Hero từ file ThuocTinh.txt
	Hero getHero(string TEN_HERO);//Lấy ra 1 hero từ danh sách
	void setHero(string INFORMATION,DanhSachThuocTinh LIST,string FILENAME);//Thêm 1 Hero vào Danh Sách và File Danh Sách Hero
	void removeHero(string TEN_HERO);//xóa 1 Hero ra khỏi danh sách
	string toString();//chuyển thông tin về string
	void display();//in ra màn hình
	
};
