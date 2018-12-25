#include <iostream>
using namespace std;
struct date{
	int day;
	int month;
	int year;
};
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
	int d30=0,d31=0,d2;
	if (ktnhuan(datetime.year)==1)
		d2 = 29;
	else d2 = 28;
	int dem = datetime.day;
	if (datetime.month == 1)
		return dem;
	else
	for (int i=1;i<datetime.month;i++)
		if (i==4 || i==6 || i==9 || i==11)
			d30++;
		else if(i==2)
			dem+=d2;
		else d31++;
	return dem += d30*30 + d31*31;
}
//--------------------------------------------------------------
date addNgay(date datetime, int x){
	int kt1 = x/31;
	int kt2 = x%31;
	int d30=0,d2=0;
	date test;
	test.month = datetime.month + kt1;
	test.day = datetime.day + kt2;
	test.year = datetime.year;
	for (int i = datetime.month;i<test.month;i++){
		if (i==4 || i==6 || i==9 || i==11)
			d30++;
		if (i==2)
			if (ktnhuan(datetime.year)==1)
				d2=1;
			else d2=2;
	}
	test.day -= (d30+d2);
	if (test.day > 30){
		if (ktnhuan(test.year)==1 && test.month==2)
			test.day++;
		test.day-=30;
		test.month++;
	}
	return test;
}	
int main(){
	date datetime;
	NhapNgay(datetime);
	cout << "nhap dung------------\n";
	if(ktnhuan(datetime.year)==1)
		cout <<"nam nay la nam nhuan\n";
	else cout <<"nam ko nhuan\n";
	cout << "la ngay thu " <<demngay(datetime) <<" trong nam\n";
	cout << addNgay(datetime,50).day << "/" << addNgay(datetime,50).month <<"/"<< addNgay(datetime,50).year;
	
}
