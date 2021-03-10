#include <iostream>
using namespace std;

int demander_annee();
void affiche_date(int year, int number);
int date_Paques(int year);

int date_Paques(int year){
    int century(year/100);
    int p((13+century*8)/25);
    int q(century/4);
    int M((15-p+century-q)%30);
    int N((4+century-q)%7);
    int d(((M+19*(year%19))%30));
    int e((2 * (year % 4) + 4 * (year % 7) + 6 * d + N) % 7);
    int day(e+d+22);

    if(((e==6) && ((d==29) || ((d==28) && (((11*(M+1))%30)<19)))))
        day-=7;
    return day;

}

void affiche_date(int year, int number){
    if (number<31)
        cout << "Date de Paques en " << year << ": " << number << " mars" << endl;
    else
        cout << "Date de Paques en " << year << ": " << number-31 << " avril" << endl;
}

int demander_annee(){
    int annee(0);
    do{
        cout << "Entrez une annee (1583-4000) : ";
        cin >> annee;
    }while(annee<1583 || annee>4000);
    return annee;
}


int main(){
    int year, day;
    year = demander_annee();
    day = date_Paques(year);
    affiche_date(year, day);

    return 0;
}
