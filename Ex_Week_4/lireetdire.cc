#include <iostream>
using namespace std;

int separer_chiffre_gauche(int& nombre)
{
  int dix(1);
  int temp(nombre);
  while (temp >= 10) {
    dix  *= 10;
    temp /= 10;
  }
  nombre %= dix;
  return temp;
}

/*****************************************************
 * Compléter le code �  partir d'ici
 *****************************************************/

void ajouter_chiffre_droit(int& nombre, int chiffre)
{
    nombre = 10*nombre + chiffre;
}

void dire_chiffre(int& nombre, int repetitions_chiffre, int chiffre)
{
    ajouter_chiffre_droit(nombre, repetitions_chiffre);
    ajouter_chiffre_droit(nombre, chiffre);
}

int lire_et_dire(int nombre)
{
    int chiffre_a_gauche(0);

    int qRepetitions(1);
    int resultado(0);

    chiffre_a_gauche = separer_chiffre_gauche(nombre);
    do {
        int Aux(separer_chiffre_gauche(nombre));
        if (Aux == chiffre_a_gauche)
            qRepetitions+=1;
        else {
            dire_chiffre(resultado, qRepetitions, chiffre_a_gauche);
            chiffre_a_gauche = Aux;
            qRepetitions = 1;
        }
    } while(nombre);
    if (chiffre_a_gauche)
        dire_chiffre(resultado, qRepetitions, chiffre_a_gauche);

    return resultado;
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

void repeter_lire_et_dire(int& nombre, int fois)
{
  while (fois-- > 0) {
    nombre = lire_et_dire(nombre);
  }
}

int main()
{
  int nombre(1);
  int fois(1);
  cin >> nombre >> fois;
  repeter_lire_et_dire(nombre, fois);
  cout << nombre << endl;
  return 0;
}
