#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <string.h>
typedef struct
{
	int MSSV;
	char HoTen[36];
	float DiemQuaTrinh;
	float DiemThi;
} SinhVien;

void menu();
void doc_dsSinhVien_file(SinhVien a[], int *n);
void Xuat_1_SV(SinhVien a);
void xuat_DSSV(SinhVien a[], int n);
void CapNhat_SinhVien_MaX(SinhVien a[], int n, int x);
void SapXepHoTen(SinhVien a[], int n);
void TongKet(SinhVien a[], int n);
int main()
{
	SinhVien DanhSachSinhVien[100];
	int n = 0, x, chon;
	menu();
	do
	{
		printf("> Chon chuc nang: ");
		scanf("%d", &chon);
		switch (chon)
		{
		case 1:
			printf("1. Doc du lieu tu file txt\n");
			doc_dsSinhVien_file(DanhSachSinhVien, &n);
			break;
		case 2:
			printf("2. Xuat danh sach sinh vien\n");
			xuat_DSSV(DanhSachSinhVien, n);
			break;
		case 3:
			printf("3. Cap nhat sinh vien co MSSV x\n");
			printf("> Nhap ma so sinh vien muon cap nhat: ");
			scanf("%d", &x);
			CapNhat_SinhVien_MaX(DanhSachSinhVien, n, x);
			break;
		case 4:
			printf("4. Tinh diem tong ket, xep loai cua tat ca sinh vien\n");
			TongKet(DanhSachSinhVien, n);
			break;
		case 5:
			printf("5. Sap xep giam dan theo ho ten\n");

			SapXepHoTen(DanhSachSinhVien, n);
			break;
		}
	} while (chon != 0);
}
void menu()
{
	printf("1. Doc du lieu tu file txt\n");
	printf("2. Xuat danh sach sinh vien\n");
	printf("3. Cap nhat sinh vien co MSSV x\n");
	printf("4. Tinh diem tong ket, xep loai cua tat ca sinh vien\n");
	printf("5. Sap xep giam dan theo ho ten\n");
}
void doc_dsSinhVien_file(SinhVien a[], int *n)
{
	FILE *f = fopen("dsSinhVien.txt", "r");
	if (!f)
	{
		printf("Khong the mo file!\n");
		return;
	}
	int i = 0;
	SinhVien x;
	while (feof(f) == 0)
	{
		fscanf(f, "%d#%[^#]#%f#%f\n", &x.MSSV, &x.HoTen, &x.DiemQuaTrinh, &x.DiemThi);
		a[i] = x;
		i++;
	}
	*n = i;
	fclose(f);
}
void Xuat1(SinhVien a)
{
	printf("|%-15d|%-30s|%-15.1f|%-15.1f|\n", a.MSSV, a.HoTen, a.DiemQuaTrinh, a.DiemThi);
}
void xuat_DSSV(SinhVien a[], int n)
{
	printf("================================================================================\n");
	printf("|%-15s|%-30s|%-15s|%-15s|\n", "MSSV", "Ho va ten", "Diem qua trinh", "Diem thi");
	printf("================================================================================\n");
	for (int i = 0; i < n; i++)
	{
		Xuat1(a[i]);
	}
	printf("================================================================================\n");
}
void CapNhat_SinhVien_MaX(SinhVien a[], int n, int x)
{
	int vitri = -1;
	for (int i = 0; i < n; i++)
	{
		if (a[i].MSSV == x)
		{
			vitri = i;
			break;
		}
	}
	if (vitri != -1)
	{
		fflush(stdin);
		printf("> Ho ten: ");
		gets(a[vitri].HoTen);
		printf("> Diem qua trinh: ");
		scanf("%d", &a[vitri].DiemQuaTrinh);
		printf("> Diem thi: ");
		scanf("%d", &a[vitri].DiemThi);
	}
	else
	{
		printf("Khong ton tai %d nay trong danh sach\n", x);
		return;
	}
}
void SapXepHoTen(SinhVien a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (strcmp(a[i].HoTen, a[j].HoTen) < 0)
			{
				SinhVien temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
void TongKet(SinhVien a[], int n)
{
	float DiemTK = 0;
	char XL;
	for (int i = 0; i < n; i++)
	{
		printf(" === Sinh vien %d === \n", i + 1);
		printf("MSSV: %d\n", a[i].MSSV);
		printf("Ho ten: %s\n", a[i].HoTen);
		printf("Diem qua trinh: %.1f\n", a[i].DiemQuaTrinh);
		printf("Diem thi: %.1f\n", a[i].DiemThi);
		DiemTK = 0;
		XL = '\0';
		DiemTK = a[i].DiemQuaTrinh * 0.3 + a[i].DiemThi * 0.7;
		if (DiemTK >= 4)
			XL = 'D';
		else
			XL = 'K';
		printf("Diem Tong Ket: %.1f\n", DiemTK);
		printf("Xep loai: %c\n", XL);
	}
}
