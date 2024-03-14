#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string sifreleme(const string metin, const string anahtar1, const string anahtar2) 
{
    string sifreli = metin;
    int j = 0;

    for (int i = 0; i < metin.size(); ++i) 
    {
        char karakter = metin[i];
        char baslangic;
        char kayma;
        if (isalpha(karakter)) // Harf kontrolü yapar, harf olmayanları çevirmez
        {
            if (islower(karakter)) 
            {
                baslangic = 'a';
                char harf = anahtar2[j % 14];
                kayma = harf - baslangic + 1;
            } 

            else 
            {
                baslangic = 'A';
                char harf = anahtar1[j % 14];
                kayma = harf - baslangic + 1;
            }
            karakter = baslangic + (karakter - baslangic + kayma) % 26;
            ++j;
        }
        sifreli[i] = karakter;
    }

    return sifreli;
}

string desifreleme(const string sifreli, const string anahtar1, const string anahtar2) 
{
    string orijinal = sifreli;
    int j = 0;

    for (int i = 0; i < sifreli.size(); ++i) 
    {
        char karakter = sifreli[i];
        char baslangic;

        if (islower(karakter)) 
            baslangic = 'a';

        else 
            baslangic = 'A';
        

        char kayma;

        if (isalpha(karakter)) 
        {
            if (islower(karakter)) 
            {
                char harf = anahtar2[j % 14];
                kayma = harf - baslangic + 1;
            } 

            else 
            {
                char harf = anahtar1[j % 14];
                kayma = harf - baslangic + 1;
            }
            karakter = baslangic + (karakter - baslangic - kayma + 26) % 26;
            ++j;
        }
        orijinal[i] = karakter;
    }

    return orijinal;
}

int main() 
{
    ofstream dosya1;
    dosya1.open("sifreleme.txt");

    string sifrelenen;
    
    cout << "Sifrelenecek metininiz nedir? (Turkce karakter girmemeye ozen gosteriniz): ";
    getline(cin, sifrelenen);
    cout << endl;

    dosya1 << sifrelenen;

    dosya1.close();

    ifstream dosya2("sifreleme.txt");

    if (!dosya2) 
    {
        cout << "Dosya acilamadi!" << endl;
        return 1;
    }

    string metin;
    getline(dosya2, metin);
    dosya2.close();
    
    const string anahtar1 = "AZLKDFGHYEEBGP";
    const string anahtar2= "azlkdfghyeebgp";

    string sifreli = sifreleme(metin, anahtar1, anahtar2);
    cout << "Sifrelenmis Metin: " << sifreli << endl;

    string orijinal = desifreleme(sifreli, anahtar1, anahtar2);
    cout << "Cozulen Metin: " << orijinal << endl;

    ofstream dosya3("cozulmus_metin.txt");
    dosya3 << orijinal;
    dosya3.close();

    return 0;
}
