#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fi("INPUT.txt");
    ofstream fo("OUTPUT.txt");
    int n, a, b, i, sum = 0;
  
    // nhap du lieu tu file input
    fi >> n >> a >> b;
    int G[n][n];
    int S[n], Len[n], P[n];
  
    // nhap ma tran va tinh gia tri vo cung (sum)
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            fi >> G[i][j];
            sum += G[i][j];
        }
    // dat vo cung cho tat ca cap canh khong noi voi nhau
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && G[i][j] == 0)
                G[i][j] = sum;
        }
    }
  
    /* Do mang tinh tu G[0][0] nen can giam vi tri
     di 1 don vi de tinh toan cho phu hop*/
    a--;
    b--;
  
    for (int i = 0; i < n; i++) {
        Len[i] = sum;                   // khoi tao do dai tu a toi moi dinh la vo cung
        S[i] = 0;                       // danh sach cac diem da xet
        P[i] = a;                       // dat diem bat dau cua moi diem la a
    }
  
    Len[a] = 0;                         // dat do dai tu a -> a la 0
  
    // tim duong di ngan nhat tu 1 dinh den moi dinh khac thi thay bang vong for:
    //for (int k = 0; k < n; k++)
    while (S[b] == 0) {                 // trong khi diem cuoi chua duoc xet
        for (i = 0; i < n; i++)          // tim 1 vi tri ma khong phai la vo cung
            if (!S[i] && Len[i] < sum)
                break;
  
        // i >=n tuc la duyet het cac dinh ma khong the tim thay dinh b -> thoat
        if (i >= n) {
            cout << "tim hoan thanh\n";
            break;
        }
  
        for (int j = 0; j < n; j++) {    // tim diem co vi tri ma do dai la min
            if (!S[j] && Len[i] > Len[j]) {
                i = j;
            }
        }
  
        S[i] = 1;                       // cho i vao danh sach xet roi
  
        for (int j = 0; j < n; j++) {    // tinh lai do dai cua cac diem chua xet
            if (!S[j] && Len[i] + G[i][j] < Len[j]) {
                Len[j] = Len[i] + G[i][j];      // thay doi len
                P[j] = i;                       // danh dau diem truoc no
            }
        }
    }
  
    cout << "tim thoan thanh\n";
  
    /* Do ta dang tinh toan tu dinh 0 nen
     muon hien thi tu dinh 1 thi can dung i + 1 de phu hop */
  
    printf("tim duong\n");
  
    if (Len[b] > 0 && Len[b] < sum) {
        fo << "chieu dai of "<< a + 1 <<" den "<< b + 1 <<" la " << Len[b] << "\n";
  
        // truy vet
        while (i != a) {
            fo << i + 1 << " <-- " ;
            i = P[i];
        }
        fo << a + 1;
    } else {
        fo << "khong co duong di tu" << a + 1 <<" den "<< b + 1 << endl;
    }
  
    printf("tim duong xong\n");
  
    fi.close();
    fo.close();
}
