#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;
string transpositionSifreleme(char metin[], int anahtar) 
{
	int satirSayisi=ceil((float)strlen(metin)/anahtar); 
	char sifre[satirSayisi][anahtar];
	
	int sayac=0;
	for (int i=0;i<satirSayisi;i++) 
		for (int j=0;j<anahtar;j++) 
		{
			sifre[i][j]=metin[sayac];
			sayac++;
		}
			
	char sifre2[anahtar*satirSayisi];
	sayac=0;
	for (int i=0;i<anahtar;i++) 
		for (int j=0;j<satirSayisi;j++)
			{
			sifre2[sayac]=sifre[j][i];
			sayac++;
			}
			
	return sifre2;

}
string transpositionDesifreleme(char sifre[], int anahtar) 
{
    int satirSayisi=ceil((float)strlen(sifre)/anahtar);
    char sifreMatris[satirSayisi][anahtar];

    int sayac=0;
    for (int i=0;i<anahtar;i++) 
        for (int j=0;j<satirSayisi;j++) 
		{
            sifreMatris[j][i]=sifre[sayac];
            sayac++;
        }

    char desifrelenmisMetin[strlen(sifre)];
    sayac=0;
    for (int i=0;i<satirSayisi;i++) 
        for (int j=0;j<anahtar;j++) 
		{
            desifrelenmisMetin[sayac]=sifreMatris[i][j];
            sayac++;
        }

	return desifrelenmisMetin;
}
int dosyaKaydet(string metin)
{
	ofstream kaydet("sifrelemeLog.txt", ios::app);
	
	kaydet<<metin;
	kaydet.close();
}
int main()
{
	int secim;
	char metin[50];
	
	cout<<"Transposition sifreleme yöntemini kullacanaksiniz\n1-Sifreleme\n2-Desifreleme\n";
	a:
	cout<<">-<\n ";
	cin>>secim;
	cout<<">-<\n";
	
	switch(secim)
	{
		case 1:
			cout<<"Metin gir: ";
			cin.ignore();
            cin.getline(metin, 50);
			
			dosyaKaydet("Transposition / ");
            dosyaKaydet(metin);
            dosyaKaydet(" = ");
			dosyaKaydet(transpositionSifreleme(metin, 3));
			dosyaKaydet("\n");
			cout<<"Metniniz ve sifreniz sifrelemeLog.txt isimli log dosyasina kaydedildi.\n";
			
			cout<<"Metnin sifrelenmis hali: "<<transpositionSifreleme(metin, 3);
			break;
		case 2:
			cout<<"Sifre gir: ";
			cin.ignore();
            cin.getline(metin, 50);
			
			dosyaKaydet("Transposition \\ ");
            dosyaKaydet(metin);
            dosyaKaydet(" = ");
			dosyaKaydet(transpositionDesifreleme(metin, 3));
			dosyaKaydet("\n");
			cout<<"Sifreniz ve metniniz sifrelemeLog.txt isimli log dosyasina kaydedildi.\n";

			cout<<"Metnin desifrelenmis hali: "<<transpositionDesifreleme(metin, 3);
			break;
		default:
			cout<<"1 veya 2 giriniz.\n";
			goto a;
	}	
}
