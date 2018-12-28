#include <iostream>
using namespace std;
struct date{
	int day;
	int month;
	int year;
};
int Thang[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int ktnhuan(int year){
	if ((year % 4 == 0 && year % 100!=0) || year % 400 == 0)
		return 1;
	else return 0;
}

void NhapNgay(date &datetime){
	int kt;
	do{
		kt = 0;
		cout << "nhap ngay/thang/nam cach nhau 1 dau cach ' ':";
		cin >> datetime.day >> datetime.month >> datetime.year;
		if (datetime.month == 4 || datetime.month == 6 || datetime.month == 9 || datetime.month == 11){
			if (datetime.day > 30)
				kt = 1;
		}
		else if (datetime.month == 2 && ktnhuan(datetime.year)==1){
			if (datetime.day > 29)
				kt = 1;
			}
		else if (datetime.month == 2 && ktnhuan(datetime.year) == 0){
				if (datetime.day > 28)
					kt = 1;
			}
		else if (datetime.day > 31 || datetime.month > 12)
			kt = 1;
	}while (kt == 1);
}

int demngay(date datetime){
	int dem=0;
	for(int i = 1; i < datetime.month; i++)
		dem += Thang[i];
	dem += datetime.day;
	if (datetime.month>2)
		if (ktnhuan(datetime.year)==1)
			dem++;
	return dem;
}
//--------------------------------------------------------------
date TimNgay(int x,int year){
	date NgayCanTim;
	int i=1;
	while (x > Thang[i]){
		x-=Thang[i];
		i++;
		if (ktnhuan(year)==1 && i==2)
			Thang[i]=29;
	}
	NgayCanTim.month = i;
	NgayCanTim.day = x;
	NgayCanTim.year = year;
	Thang[2]=28;
	return NgayCanTim;
}
date ThemNgay(date datetime, int x){
	int kq = x + demngay(datetime);
	int year = datetime.year;
	if(kq <= 365)
		return TimNgay(kq,year);
	else
		if(ktnhuan(year) == 1)
			if(kq == 366)
				return TimNgay(kq,year);
			else
				return TimNgay(kq - 366, year + 1);
		else
			return TimNgay(kq - 365, year + 1);
	}
date TruNgay(date datetime, int x){
	int kq,year;
	if (x < demngay(datetime)){
		 year = datetime.year;
		 kq = demngay(datetime)-x;
	}
	else {
		year = datetime.year-1; 
		kq = demngay(datetime) + 365 - x;
		if (ktnhuan(datetime.year)==1 && (datetime.month>2 || (datetime.month==2 && datetime.day==29)))
			kq++;
		}
	return TimNgay(kq,year);
}
void InNgay(date datetime){
	cout <<datetime.day << "/" << datetime.month << "/" <<datetime.year <<endl;
}
int main(){
	date datetime;
	NhapNgay(datetime);
	cout << "nhap dung------------\n";
	InNgay(datetime);
	if(ktnhuan(datetime.year)==1)
		cout <<"nam nay la nam nhuan\n";
	else cout <<"nam ko nhuan\n";
	cout << "la ngay thu " <<demngay(datetime) <<" trong nam\n";
	InNgay(ThemNgay(datetime,20));
	InNgay(TruNgay(datetime,61));
}

