#include <iostream>
#include <string>
#include <cctype> 
using namespace std;
string FPLSC(const string& text) 
{
  string sifrelenmis_metin = "";
  const string part1 = "abcdefg";
  const string part2 = "hijklm";
  const string part3 = "nopqrs";
  const string part4 = "tuvwxyz";
	
	const string part5 = "abcdefg";
	const string part6 = "hijklm";
	const string part7 = "nopqrst";
	const string part8 = "uvwxyz";
	
    for (string::size_type i = 0; i < text.length(); ++i) 
	{
        char c = text[i];
        if (isalpha(c)) 
		{
            if (islower(c)) 
			{
                if (part1.find(c) != string::npos) 
                    sifrelenmis_metin += part4[part1.find(c)];
            
				        else if (part2.find(c) != string::npos) 
                    sifrelenmis_metin += part3[part2.find(c)];
                    
                else if (part3.find(c) != string::npos) 
                    sifrelenmis_metin += part2[part3.find(c)];
                    
                else if (part4.find(c) != string::npos) 
                    sifrelenmis_metin+= part1[part4.find(c)];
            } 
            
			      else 
			      {
                if (part5.find(tolower(c)) != string::npos) 
                    sifrelenmis_metin += toupper(part7[part5.find(tolower(c))]);
                
				        else if (part6.find(tolower(c)) != string::npos) 
                    sifrelenmis_metin += toupper(part8[part6.find(tolower(c))]);
                
				        else if (part7.find(tolower(c)) != string::npos) 
                    sifrelenmis_metin += toupper(part5[part7.find(tolower(c))]);
                
				        else if (part8.find(tolower(c)) != string::npos) 
                    sifrelenmis_metin += toupper(part6[part8.find(tolower(c))]);
            }
        } 
        
		    else 
            sifrelenmis_metin += c; 
    }

    return sifrelenmis_metin;
}

int main() 
{
    string text;
    cout<<"Metni girin: ";
    getline(cin, text);

    string sifrelenmis_metin = FPLSC(text);
    cout << "Sifrelenmis Metin: " << sifrelenmis_metin << endl;
}
