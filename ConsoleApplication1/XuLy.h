#pragma once
#include"ThuocTinh.h"
#include"Hero.h"
#include"KetQua.h"
#include<ctime>
int random(int min, int max);//random
bool KiemTraTonTai(vector<Hero> A, Hero B);//kiểm tra tồn tại của hero B trong A
bool DoiKhangNhomVsNhom(vector<Hero> A, vector<Hero> B, ThuocTinh Moi_Truong, int SoLuongHero, int TIME);//Tinh Toan Ket Qua Thang Thua Cua 2 Team Hero
bool DoiKhang1vs1(Hero A, Hero B, ThuocTinh Moi_Truong, int TIME);//Kết quả đối kháng 1 vs 1
vector<Hero> randomHero(ListHero DSHero, int m);//tự đông chọn số Hero tương ứng từ danh sách hero có sẵn
vector<Hero> Anh_Huong_Giua_Hero(vector<Hero> x);//ảnh hưởng từ thuộc tính của các Hero trong team
void XuLy(string FILE_HERO_NAME, string FILE_THUOC_TINH_NAME, string FILE_LOG_NAME);//lấy dữ liệu từ file,nhập thông tin in ra kết quả trận đấu và lưu vào lịch sử đấu
void Xem_Lich_Su_Dau();//xem danh sách lịch sử đấu
//random
int random(int min, int max)
{
	return min + rand() % (max + 1 - min);
}
//kiểm tra tồn tại của hero B trong A
bool KiemTraTonTai(vector<Hero> A, Hero B)
{
	vector <Hero>::iterator i;
	for (i = A.begin(); i != A.end(); i++)
	{
		Hero x = *i;
		if (x.getTen() == B.getTen())
		{
			return 1;
			break;
		}
	}
	return 0;
}
//tự đông chọn số Hero tương ứng từ danh sách hero có sẵn
vector<Hero> randomHero(ListHero DSHero, int m)
{
	srand((int)time(0));
	vector<Hero> A;
	vector<Hero> B = DSHero.getListHero();
	int n = B.size();
	for (int j = 0; j < m; j++)
	{
		Hero y = B.at(random(1, n));
		if (KiemTraTonTai(A, y) == 0)
		{
			A.push_back(y);
		}
		else
		{
			m++;
		}
	}
	return A;
}
//Kết quả đối kháng 1 vs 1
bool DoiKhang1vs1(Hero A, Hero B, ThuocTinh Moi_Truong, int TIME)
{
	//xét thuộc tính A có khắc B không
	if (A.getThuocTinh().getTuongKhac() == B.getThuocTinh().getTen())
	{
		B.DeBuff(0, 0, 0.5, 0);//chỉ số thủ của Hero bị khắc sẽ giảm 50% .
		A.Buff(0, 0.1, 0, 0);//công của Hero thuộc tính khắc sẽ được cộng thêm 10%.
	}
	//xet thuộc tính B có khắc A không
	if (B.getThuocTinh().getTuongKhac() == A.getThuocTinh().getTen())
	{
		A.DeBuff(0, 0, 0.5, 0);//chỉ số thủ của Hero bị khắc sẽ giảm 50% .
		B.Buff(0, 0.1, 0, 0);//công của Hero thuộc tính khắc sẽ được cộng thêm 10%.
	}
	//ảnh hưởng từ môi trường đấu đến hero
	A.Anh_Huong_Moi_Truong(Moi_Truong);
	B.Anh_Huong_Moi_Truong(Moi_Truong);
	//Sát thương của A tạo cho B và ngược lại trong thời gian TIME
	float SAT_THUONG_A = (TIME / A.getTocDo()) * (A.getCong() - B.getThu());
	float SAT_THUONG_B = (TIME / B.getTocDo()) * (B.getCong() - A.getThu());
	//so sánh máu của 2 hero sau thời gian TIME đánh nhau
	if (B.getMau() - SAT_THUONG_A > A.getMau() - SAT_THUONG_B)
	{
		return 0;//Máu còn lại của B lớn hơn A return 0
	}
	else if (B.getMau() - SAT_THUONG_A < A.getMau() - SAT_THUONG_B) return 1;//Máu còn lại của A lớn hơn B return 1
	else return -1;
}
//ảnh hưởng từ thuộc tính của các Hero trong team
vector<Hero> Anh_Huong_Giua_Hero(vector<Hero> x)
{
	vector<Hero> y = x;
	vector<Hero>::iterator i;
	vector<Hero> z;
	for (i = x.begin(); i != x.end(); i++)
	{
		Hero m = *i;
		int demTuongKhac = 0;
		int demTuongSinh = 0;
		for (vector<Hero>::iterator j = y.begin(); j != y.end(); j++)
		{
			Hero n = *j;
			if (m.getTen() != n.getTen())
			{
				if (n.getThuocTinh().getTuongKhac() == m.getThuocTinh().getTen())
				{
					demTuongKhac++;
				}
				else if (n.getThuocTinh().getTuongSinh() == m.getThuocTinh().getTen())
				{
					demTuongSinh++;
				}
			}
		}
		m.Buff(0, 0, 0, 0.1 * demTuongKhac);//chỉ số thời gian tung đòn tăng 10% với mỗi tướng khắc
		m.Buff(0.15 * demTuongSinh, 0, 0, 0);//chỉ số máu tăng 15% với mỗi tướng sinh
		z.push_back(m);
	}
	return z;
}
//Tinh Toan Ket Qua Thang Thua Cua 2 Team Hero
bool DoiKhangNhomVsNhom(vector<Hero> A, vector<Hero> B, ThuocTinh Moi_Truong, int SoLuongHero, int TIME)
{
	int A_Win = 0;
	int B_Win = 0;
	for (int i = 0; i < SoLuongHero; i++)
	{
		if (DoiKhang1vs1(A[i], B[i], Moi_Truong, TIME) == 1)
		{
			A_Win++;
		}
		else if (DoiKhang1vs1(A[i], B[i], Moi_Truong, TIME) == 0)
		{
			B_Win++;
		}
	}
	if (A_Win > B_Win) return 1;
	else if (B_Win > A_Win) return 0;
	else return -1;
}
//lấy dữ liệu từ file,nhập thông tin in ra kết quả trận đấu và lưu vào lịch sử đấu
void XuLy(string FILE_HERO_NAME, string FILE_THUOC_TINH_NAME, string FILE_LOG_NAME)
{
	//Tạo Danh Sách Hero, Thuộc Tính và lịch sử các hiệp đấu
	ListHero DSHero;
	DanhSachThuocTinh DSThuocTinh;
	DanhSachHiepDau DSLog;
	DSThuocTinh.setFile(FILE_THUOC_TINH_NAME);
	DSHero.setFile(FILE_HERO_NAME, DSThuocTinh);
	//DSLog.setFile(FILE_LOG_NAME, DSThuocTinh, 3);
	//Tạo 2 vector<hero> ứng với danh sách hero của 2 đội
	vector<Hero> NPC = randomHero(DSHero, 3);
	vector<Hero> PLAYER;
	string NAME_TEAM;
	cout << "Nhap Ten Cua Team: "; cin >> NAME_TEAM;
	cout << "Danh Sach Hero" << endl;
	for (int i = 0; i < DSHero.getListHero().size(); i++)
	{
		cout << "[" << i << "].";
		DSHero.getListHero()[i].display();
		cout << endl;
	}
	cout << "Vui Long Nhap STT tuong ung cua 3 Hero Ban Muon Them Vao Team!" << endl;
	for (int i = 1; i < 4; i++)
	{
		int STT_HERO;
		cout << "Nhap STT Hero["<<i<<"]: "; cin >> STT_HERO;
		PLAYER.push_back(DSHero.getListHero()[STT_HERO]);
	}
	system("cls");
	cout << "Team NPC" << endl;
	for (int i = 0; i < 3; i++)
	{
		NPC[i].display();
		cout << endl;
	}
	cout <<"Team "<< NAME_TEAM << endl;
	for (int i = 0; i < 3; i++)
	{
		PLAYER[i].display();
		cout<< endl;
	}
	//Tạo random thuộc tính môi trường thi đấu
	srand((int)time(0));
	ThuocTinh MOI_TRUONG = DSThuocTinh.getDanhSachThuocTinh().at(random(1, 5));
	string MOITRUONG = "Moi Truong:" + MOI_TRUONG.getTen();
	cout << MOITRUONG << endl;
	//Ảnh hưởng từ thuộc tính giữa những hero trong team
	PLAYER = Anh_Huong_Giua_Hero(PLAYER);
	NPC = Anh_Huong_Giua_Hero(NPC);
	//Lấy thời gian thực
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now);
	Time THOIGIAN = Time(1 + ltm.tm_sec, ltm.tm_min, ltm.tm_hour, ltm.tm_mday, 1 + ltm.tm_mon, 1900 + ltm.tm_year);
	//tính toán thắng thua 2 team
	ListHero DS_NPC = ListHero(NPC);
	ListHero DS_PLAYER = ListHero(PLAYER);
	if (DoiKhangNhomVsNhom(PLAYER, NPC, MOI_TRUONG, 3, 60) == 1)
	{
		//Lưu vào file log hiệp đấu
		HiepDau Hiep_Dau = HiepDau(THOIGIAN, "NPC", DS_NPC, NAME_TEAM, DS_PLAYER, NAME_TEAM+" Win.");
		DSLog.setHiepDau(Hiep_Dau, FILE_LOG_NAME);
		//in kết quả
		string KETQUA = NAME_TEAM + " WIN";
		cout << KETQUA;
	}
	else if (DoiKhangNhomVsNhom(PLAYER, NPC, MOI_TRUONG, 3, 60) == 0)
	{
		//Lưu vào file log hiệp đấu
		HiepDau Hiep_Dau = HiepDau(THOIGIAN, "NPC", DS_NPC, NAME_TEAM, DS_PLAYER, "NPC Win.");
		DSLog.setHiepDau(Hiep_Dau, FILE_LOG_NAME);
		//in kết quả
		string KETQUA = "NPC WIN";
		cout << KETQUA;
	}
}
//xem danh sách lịch sử đấu
void Xem_Lich_Su_Dau()
{
	cout << "Danh Sach Lich Su Thoi Gian Hiep Dau" << endl;
	DanhSachThuocTinh DSThuocTinh;
	DanhSachHiepDau DSDau;
	DSThuocTinh.setFile("ThuocTinh.txt");
	DSDau.setFile("log.txt", DSThuocTinh, 3);
	DSDau.display();
	cout << "Nhap Thoi Gian Hiep Dau Ban Can Xem Chi Tiet!" << endl;
	int sec, min, hour, day, mon, year;
	cout << "SEC: "; cin >> sec;
	cout << "MIN: "; cin >> min;
	cout << "HOUR: "; cin >> hour;
	cout << "DAY: "; cin >> day;
	cout << "MON: "; cin >> mon;
	cout << "YEAR: "; cin >> year;
	Time THOIGIAN = Time(sec, min, hour, day, mon, year);
	system("cls");
	DSDau.getHiepDau(THOIGIAN).display();
	DSDau.getDanhSachDau().clear();
}
