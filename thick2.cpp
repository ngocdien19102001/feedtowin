#include <iostream>
using namespace std;
struct HOPSUA
{
	char thuonghieu[50];
	float dungtich;
	char loaisua[100];
	char xuatxu[50];
	long giatien;
};
struct NGAY
{
	int ngay, thang, nam;
};
struct NGAYX
{
	int ngayx, thangx, namx;
};
void nhap1hopsua(HOPSUA &hs, NGAY &handung)
{
	cin >> hs.loaisua >> hs.dungtich >> hs.thuonghieu >> hs.xuatxu >> handung.ngay >> handung.thang >> handung.nam >> hs.giatien;
}
void nhaphopsua(HOPSUA hs[], NGAY handung[],NGAYX &x, int &n)
{
	cin >> n;
	for (int i = 0; i < n; i++)
		nhap1hopsua(hs[i], handung[i]);
	cin >> x.ngayx >> x.thangx >> x.namx;
}
void xuat1hopsua(HOPSUA &hs, NGAY &handung)
{
	cout << hs.loaisua << ", " << hs.dungtich << ", " << hs.thuonghieu << ", " << hs.xuatxu << ", " << handung.ngay << "/" << handung.thang << "/" << handung.nam << ", " << hs.giatien << endl;
}
void xuathopsua(HOPSUA hs[], NGAY handung[], int &n)
{
	cout << n << endl;
	for (int i = 0; i < n; i++)
		xuat1hopsua(hs[i], handung[i]);
}
void hansudung(HOPSUA hs[], NGAY handung[],NGAYX &x, int& n )
{
	int tam = 0;
	int tong = 0;
	for (int i = 0; i < n; i++)
	{
		if (handung[i].nam < x.namx)
		{
			tam += 1;
			tong += hs[i].giatien;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (handung[i].thang < x.thangx)
		{
			tam += 1;
			tong += hs[i].giatien;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (handung[i].ngay < x.ngayx)
		{
			tam += 1;
			tong += hs[i].giatien;
		}
	}
	cout << "So hop sua het han sau ngay " << x.ngayx << "/" << x.thangx << "/" << x.namx << " la:" << tam << endl;
	cout << "Tong gia tri: " << tong << endl;
	for (int i = 0; i < n; i++)
	{
		if (handung[i].nam < x.namx)
		{
			xuat1hopsua(hs[i], handung[i]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (handung[i].thang < x.thangx)
		{
			xuat1hopsua(hs[i], handung[i]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (handung[i].ngay < x.ngayx)
		{
			xuat1hopsua(hs[i], handung[i]);
		}
	}
}
int main()
{
	HOPSUA hs[100];
	NGAY handung[100];
	NGAYX x;
	int n;
	nhaphopsua(hs, handung, x, n);
	xuathopsua(hs, handung, n);
	hansudung(hs,handung, x, n);
	return 0;
}