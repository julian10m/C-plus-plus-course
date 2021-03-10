#include <iostream>
#include <vector>
using namespace std;

char code(char c, int decalage);
char decale(char c, char debut, int decalage);
string code(string chain, int decalage);
string decode(string chain, int decalage);

string decode(string chain, int decalage) {
    return code(chain, -decalage);
}

string code(string chain, int decalage) {
    for(auto& letter: chain)
        letter = code(letter, decalage);
    return chain;
}

char decale(char c, char debut, int decalage){
    while(decalage<0)
        decalage+=26;
    return debut + (((c - debut) + decalage) % 26);
}

char code(char c, int decalage){
    if (c>='a' and c<='z')
        return decale(c, 'a', decalage);
    else if (c>='A' and c<='Z')
        return decale(c, 'A', decalage);
    else
        return c;
}


int main(){
  string input;
  int decalage(0);

  cout << "Input: ";
  getline (cin, input);
  cout << "Decalage: ";
  cin >> decalage;

  input = code(input, decalage);
  cout << "Coded: " << input << endl;
  input = decode(input, decalage);
  cout << "Decoded: " << input << endl;
  return 0;
}
