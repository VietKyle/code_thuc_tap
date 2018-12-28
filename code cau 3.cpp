#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <vector>
using namespace std;
struct Question{
	string Q;
	string dA;
	string dB;
	string dC;
	string A;
};
struct Player{
	string Name;
	int diem;
};
vector <Question> CauHoi;
Question CH;
//FILE *f = fopen("de 1","rt");
char De[5];
Player NC;
void ChonDe();
int BangDiem[50];
ifstream f;
void docDe();
void QandA(); 
void Luudiem(Player &NC);
void Xuatdiem();
int main()
{
	ChonDe();
	QandA();
	Luudiem(NC);
	Xuatdiem();
}
void ChonDe(){   // --------- Chon de va luu lai ten nguoi choi ----------
	fstream fo("Diem.txt",ios::out | ios::app);
	cout << "nhap ten nguoi choi: "; cin >> NC.Name; cin.sync(); // nhap ten nguoi choi
	fo <<"\n"<< NC.Name;
	cout << "nhap ma de (De 1, De 2, De 3, De 4):"; // chon de: co 4 bo de
	cin.getline(De,5);
	strcat(De,".txt\0"); // noi duoi .txt vao ten bo de de mo file
}
void docDe(){ // doc du lieu tu bo de
	ifstream f(De);
	if(f!=NULL){
		Question ch;
		string s;
		while (!f.eof()){
			getline(f,ch.Q);
			getline(f,ch.dA);
			getline(f,ch.dB);
			getline(f,ch.dC);
			getline(f,ch.A);
			getline(f,s);
			CauHoi.push_back(ch); // luu vao mot vector de quan ly
		}
	f.close();
	}
}
void QandA(){
	docDe();
	Question CH;
	string s;
	for(int i=0;i<CauHoi.size();i++){ // tra loi tung cau hoi
		CH = CauHoi[i];
		cout << "cau " << i+1 << ": "<< CH.Q <<endl;
		cout <<"A) " << CH.dA <<endl;
		cout <<"B) " << CH.dB <<endl;
		cout <<"C) " << CH.dC <<endl;
		s=CH.A;
		string tl;
		cout << "tra loi:"; cin >> tl; // nhap cau tra loi
		if (tl==s)
			NC.diem++; // tang bo dem diem neu tra loi dung;
	}
	f.close();
}
void Luudiem(Player &NC){ // luu diem vao file Diem
	fstream fo("Diem.txt", ios::out | ios::app);
	fo << "\n" << NC.diem;
	fo.close();
}
void Xuatdiem(){
	int s;
	string st;
	getline(f,st);
	ifstream f("Diem.txt");
	if (f!=NULL)
	while (!f.eof()){
		f >> NC.Name; // doc ten nguoi choi
		f >> NC.diem; // doc diem
		cout << "ten: " << NC.Name << "\tdiem" << NC.diem << endl;
	}
	f.close();
}

