#include <iostream>
#include <fstream>
using namespace std;
// phan khai bao;
ifstream fi("INPUT2.txt");
ofstream fo("OUTPUT2.txt");
int n,sum,b;
int G[100][100];
struct DinhChon{
	int Dinh;
	int TS;
};
// cac ham cân thiet
void DocMaTran();  // doc ma tran trong so tu file du lieu
void TimDuong(int b); // tim duong di tu dinh bat dau b toi tat ca cac dinh con lai
int main(){
	cout << "hello world\n";
	DocMaTran();
	TimDuong(b);
}
void DocMaTran(){
	fi >> n >> b;
	for (int i = 0; i < n; i++)
    	for (int j = 0; j < n; j++){
	    	fi >> G[i][j];
	    	sum+=G[i][j];
	    }
	cout << "tong:" <<sum <<endl;
	for (int i = 0; i < n; i++)
    	for (int j = 0; j < n; j++){
    		if (G[i][j]==0 && i!=j)
    			G[i][j] = sum;
    		}
}
void TimDuong(int b){
	DinhChon T[n][n];
	int min;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++){
			T[i][j].Dinh = -1;
			T[i][j].TS = -1;
		}
	int KT[n];
	int dinhchon = b;
	for (int i = 0;i<n;i++){
		KT[i] = 0;
		T[0][i].TS = G[dinhchon][i];
		T[0][i].Dinh = dinhchon;
		fo << T[0][i].Dinh << "," <<T[0][i].TS << "\t";
	}
	
	for (int i=0;i<n;i++){
		
		if (i>0){
			fo  << dinhchon <<"\n";
			for (int j=0;j<n;j++){
				if (KT[j]==0){
					if (G[dinhchon][j]+min <= T[i-1][j].TS){
						T[i][j].TS = G[dinhchon][j]+min;
						T[i][j].Dinh = dinhchon;
					}
					else {
						T[i][j].TS = T[i-1][j].TS;
						T[i][j].Dinh = T[i-1][j].Dinh;
						}
				}
			fo << T[i][j].Dinh << "," << T[i][j].TS <<"\t";
			}
		}
		min = sum;
		for (int j = 0;j<n;j++){
			if (T[i][j].TS <= min && T[i][j].TS > 0){
				min = T[i][j].TS;
				dinhchon = j;
			}	
		}
		KT[dinhchon] = 1;
	}
	cout << "da ghi vao file OUTPUT2.txt";
}
