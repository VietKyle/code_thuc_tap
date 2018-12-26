#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <vector>
using namespace std;
struct Contact{
	char ten[20];
	bool gt;
	char sdt[11];
	char mail[20];
	char DC[50];
};
char *fileName = "danhba.dat";
vector <Contact> DBa;
FILE *f;
void docDBaTuFile ();
void ghiDBaVaoFile ();
void ThemMoi(Contact c);
void xuat(Contact c);
void LietKeDB();
void CapNhat(Contact c);
int main()
{
	Contact c,c1;
	strcpy(c.ten,"Thu");
	c.gt = 1;
	strcpy(c.sdt, "012345");
	strcpy(c.mail, "mailduocthem@");
	strcpy(c.DC,"Khanh Hoa");
	strcpy(c1.ten,"Thu1");
	c1.gt = 0;
	strcpy(c1.sdt, "0123456");
	strcpy(c1.mail, "mailthem@");
	strcpy(c1.DC,"Quang Ngai");
	cout << "so danh ba " <<DBa.size();
	ThemMoi(c);
	cout << "so danh ba " <<DBa.size();
	ThemMoi(c1);
	cout << "so danh ba " <<DBa.size();
	LietKeDB();
}
void docDBaTuFile(){
	FILE *f = fopen(fileName,"rb");
	if(f!=NULL){
		Contact c;
		while(!feof(f)){
			fread(&c,sizeof(Contact),1,f);
			DBa.push_back(c);
		}
		DBa.pop_back();
	}
	fclose(f);
}
void ThemMoi(Contact c){
	DBa.push_back(c);
	ghiDBaVaoFile();
	
}
void ghiDBaVaoFile(){
	FILE *f;
	remove(fileName);
	f = fopen(fileName,"wb");
	Contact c;
	for (int i=0;i<DBa.size();i++){
		c = DBa[i];
		fwrite(&c,sizeof(Contact),0,f);
	}
	fclose(f);
}
void xuat(Contact c){
	cout << "\nten:"<<c.ten<<"\ngioi tinh:"<<c.gt<<"\n so dien thoai:"<<c.sdt<<"\nmail:"<<c.mail<<"\ndia chi:"<< c.DC << endl;
}
void LietKeDB(){
	docDBaTuFile();
	for (int i=0;i<DBa.size();i++){
		cout << i <<endl;
		xuat(DBa[i]);
	}
}
