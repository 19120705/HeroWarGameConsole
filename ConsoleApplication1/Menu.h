#pragma once
#include"XuLy.h"
using namespace std;
void Menu()
{
	cout << "00     00  000000  000000      0000       00     00     00    000      0000000" << endl;
	cout << "00     00  00      00  00    00    00     00     00     00   00 00     00   00" << endl;
	cout << "000000000  000000  00000    00      00     00    00    00   00   00    00000" << endl;
	cout << "00     00  00      00  00    00    00       00 00  00 00   000000000   00  00 " << endl;
	cout << "00     00  000000  00   00     0000          000    00    00       00  00   00" << endl;
	cout << "\n[1] Player vs NPC" << endl;
	cout << "[2] Lich Su" << endl;
	cout << "[3] Gioi Thieu" << endl;
	cout << "[4] Thoat Game" << endl;
}
void XuLyMenu()
{
	Menu();
	int VI_TRI;
	cout << "Nhap Lua Chon:"; cin >> VI_TRI;
	system("cls");
	switch (VI_TRI)
	{
	case 1: {
		XuLy("ListHero.txt", "ThuocTinh.txt", "log.txt");
		int CHON;
		cout << "\nNhap 1 Or 2 De Quay Lai Menu Hoac Thoat Game: "; cin >> CHON;
		if (CHON == 1)
		{
			system("cls");
			XuLyMenu();
		}
		else
		{
			exit(0);
		}
		break;
	}
	case 2: {
		Xem_Lich_Su_Dau();
		int CHON;
		cout << "\nNhap 1 Or 2 De Quay Lai Menu Hoac Thoat Game: "; cin >> CHON;
		if (CHON == 1)
		{
			system("cls");
			XuLyMenu();
		}
		else
		{
			exit(0);
		}
		break;
	}
	case 3: {
		string GIOI_THIEU = "<Game Dau Tuong Hero by Tran Viet Tuan(MSSV:19120705)>";
		for (int i = 0; i < GIOI_THIEU.size(); i++)
		{
			cout << GIOI_THIEU[i];
			Sleep(300);
		}
		XuLyMenu();
	}
	case 4: {
		exit(0);
	}
	}
}
