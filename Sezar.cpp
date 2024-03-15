#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;
string sezarSifreleme(char metin[]) 
{	
	for(int i=0;i<=strlen(metin)-1;i++)
		metin[i]+=5;
	
	return metin;
}
string sezarDesifreleme(char sifre[]) 
{
	for(int i=0;i<=strlen(sifre)-1;i++)
		sifre[i]-=5;
		
	return sifre;
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
	
	cout<<"Sezar sifreleme yöntemini kullacanaksiniz\n1-Sifreleme\n2-Desifreleme\n";
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
            
            dosyaKaydet("Sezar / ");
            dosyaKaydet(metin);
            dosyaKaydet(" = ");
			dosyaKaydet(sezarSifreleme(metin));
			dosyaKaydet("\n");
			cout<<"Metniniz ve sifreniz sifrelemeLog.txt isimli log dosyasina kaydedildi.\n";
			
			cout<<"Metnin sifrelenmis hali: "<<metin;
			break;
		case 2:
			cout<<"Sifre gir: ";
			cin.ignore();
            cin.getline(metin, 50);
            
			dosyaKaydet("Sezar \\ ");
            dosyaKaydet(metin);
            dosyaKaydet(" = ");
			dosyaKaydet(sezarDesifreleme(metin));
			dosyaKaydet("\n");
			cout<<"Sifreniz ve metniniz sifrelemeLog.txt isimli log dosyasina kaydedildi.\n";
			
			cout<<"Metnin desifrelenmis hali: "<<metin;
			break;
		default:
			cout<<"1 veya 2 giriniz.\n";
			goto a;
	}	
}

