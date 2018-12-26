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
void nhap(Contact &c);
void xuat(Contact c);
void LietKeDB();
int Tim(char Data[], char kieu[]);
void Xoa(char sdt[]);
void Sua(char sdt[]); 
int main()
{
	int a;
	char s[50];
	Contact c;
	f = fopen(fileName,"rb");
	do{ 
		cout << "chon thao tac------------------------------ "<<endl;;
		cout << "1.Them Contact\n";
		cout << "2.Xem Danh ba\n";
		cout << "3.Xoa Contact\n";
		cout << "4.Sua Contact\n";
		cout << "5.Tim Contact theo sdt\n";
		cout << "6.Tim Contact theo ten\n";
		cout << "7.Thoat\n-----------------------------------\n";
		cin >> a;
		switch(a){
			case 1: cout<< "nhap Contact can them:\n";cin.sync();
					nhap(c);
					ThemMoi(c);break;
			case 2: LietKeDB();break;
			case 3: cout << "nhap sdt can xoa:";cin.sync();
					cin.getline(s,50);
					cin.sync();
					Xoa(s);
					break;
			case 4: cout << "nhap sdt can sua:";cin.sync();
					cin.getline(s,50);cin.sync();
					Sua(s);
					break;
			case 5: cout << "nhap sdt can tim:";cin.sync();
					cin.getline(s,50);
					cin.sync();
					if (Tim(s,"sdt")!=-1)
						xuat(DBa[Tim(s,"sdt")]);
					else cout << "ko tim thay sdt\n";
					break;
			case 6: cout << "nhap ten can tim:";cin.sync();
					cin.getline(s,50);cin.sync();
					if (Tim(s,"ten")!=-1)
						xuat(DBa[Tim(s,"ten")]);
					else cout << "ko tim thay ten\n";
					break;
			case 7: break;
			}
		}
 	while(a!=7);
}

// ket thuc ham main
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
}
void ThemMoi(Contact c){
	DBa.push_back(c);
	ghiDBaVaoFile();
	
}
void ghiDBaVaoFile(){
	FILE *f;
	f = fopen(fileName,"wb");
	Contact c;
	for (int i=0;i<DBa.size();i++){
		c = DBa[i];
		fwrite(&c,sizeof(Contact),1,f);
	}
}
void nhap(Contact &c){
	char s[50];
	cout << "ten:"; cin.getline(s,50); strcpy(c.ten,s);cin.sync();
	cout << "gioi tinh:"; cin.getline(s,50); c.gt = atoi(s); cin.sync();
	cout << "SDT:"; cin.getline(s,50); strcpy(c.sdt,s);cin.sync();
	cout << "mail:"; cin.getline(s,50); strcpy(c.mail,s);cin.sync();
	cout << "Dia chi:"; cin.getline(s,50); strcpy(c.DC,s);cin.sync();
}
void xuat(Contact c){
	cout<<"-----------------------------------------------\n";
	cout << "\nten:"<<c.ten<<"\ngioi tinh:"<<c.gt<<"\n so dien thoai:"<<c.sdt<<"\nmail:"<<c.mail<<"\ndia chi:"<< c.DC << endl;
	cout<<"-----------------------------------------------\n";
}
void LietKeDB(){
	docDBaTuFile();
	if (DBa.size()==0)
		cout << "danh ba trong:\n";
	else 
	for (int i=0;i<DBa.size();i++){
		cout<<"["<<i<<"]\n";
		xuat(DBa[i]);
	}
}
int Tim(char Data[], char Loai[]){
	docDBaTuFile();
	Contact c;
	
	for (int i=0;i<DBa.size();i++){
		c = DBa[i];
		if (strcmp(Loai,"sdt")==0){
			if (strcmp(c.sdt,Data)==0)
				return i;
			}
		else if (strcmp(Loai,"ten")==0){
			if (strcmp(c.ten,Data)==0)
				return i;
			}
			
	}
	return -1;
}
void Xoa(char sdt[]){
	docDBaTuFile();
	int i=Tim(sdt,"sdt");
	if (i!=-1){
		DBa.erase(DBa.begin()+i);
		ghiDBaVaoFile ();
	}
	else cout << "ko tim thay sdt\n";
}
void Sua(char sdt[]){
	docDBaTuFile();
	Contact c;
	char s[50];
	int i=Tim(sdt,"sdt");
	if (i!=-1){
		cout << "nhap thong tin da chinh sua:--------------\n";cin.sync();
		cout << "ten:"; cin.getline(s,50); strcpy(c.ten,s);
		cout << "gioi tinh:"; cin.getline(s,50); c.gt = atoi(s); cin.sync();
		cout << "SDT:"; cin.getline(s,50); strcpy(c.sdt,s);
		cout << "mail:"; cin.getline(s,50); strcpy(c.mail,s);
		cout << "Dia chi:"; cin.getline(s,50); strcpy(c.DC,s);
		DBa.insert(DBa.begin()+i,c);
		DBa.erase(DBa.begin()+i+1);
		ghiDBaVaoFile ();
	}
	else cout << "ko tim thay sdt ==> ko xoa\n";	
}
