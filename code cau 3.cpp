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
vector <Question> CauHoi;
Question CH;
//FILE *f = fopen("de 1","rt");
char De[5];
void ChonDe();
ifstream f;
void docDe();
void QandA(); 
int main()
{
	ChonDe();
	QandA();
}
void ChonDe(){
	cout << "nhap ma de (De 1, De 2, De 3, De 4):";
	cin.getline(De,5);
	strcat(De,".txt\0");
}
void docDe(){
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
			CauHoi.push_back(ch);
		}
	f.close();
	}
}
int QandA(){
	docDe();
	Question CH;
	string s;
	int diem=0;
	for(int i=0;i<CauHoi.size();i++){
		CH = CauHoi[i];
		cout << "cau " << i+1 << ": "<< CH.Q <<endl;
		cout <<"A) " << CH.dA <<endl;
		cout <<"B) " << CH.dB <<endl;
		cout <<"C) " << CH.dC <<endl;
		s=CH.A;
		string tl;
		cout << "tra loi:"; cin >> tl;
		if (tl==s)
			diem++;
	}
	cout << "diem:" <<diem;
	f.close();
}
