#include <iostream>
#include <iomanip> // pour setprecision()
using namespace std;

int main()
{
  // Réduire le format d'affichage
  cout << setprecision(4);

  // Paramètres
  double taux_croissance_lapins(0.3);
  double taux_attaque(0.01);
  double taux_croissance_renards(0.008);
  double taux_mortalite(0.1);
  int duree(50);

  double renards_i(0.0);
  double lapins_i(0.0);

  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/

  // ===== PARTIE 1 =====
  // Saisie des populations initiales
  do {
    cout << "Combien de renards au départ (>= 2) ? ";
    cin >> renards_i;
  } while(renards_i<2);

  do {
    cout << "Combien de lapins au départ  (>= 5) ? ";
    cin >> lapins_i;
  } while(lapins_i<5);

  // ===== PARTIE 2 =====
  // Première simulation

  cout <<  endl << "***** Le taux d'attaque vaut "<< taux_attaque * 100 << "%" <<  endl;

  double AuxL(lapins_i), AuxR(renards_i);
  for(int i(1); i<=duree; ++i){
    double AuxLprev(AuxL);
    AuxL *= (1.0 + taux_croissance_lapins - taux_attaque * AuxR);
    AuxR *= (1.0 + taux_attaque * AuxLprev * taux_croissance_renards - taux_mortalite);
    if (AuxL<0)
        AuxL = 0;
    if (AuxR<0)
        AuxR = 0;
    cout << "Après " << i << " mois, il y a " << AuxL << " lapins et " << AuxR << " renards" << endl;
  }

  // ===== PARTIE 3 =====
  // Variation du taux d'attaque

  cout << endl;

  double taux_depart(0.0), taux_fin(0.0);

  do{
  cout << "taux d'attaque au départ en % (entre 0.5 et 6) ? ";
  cin >> taux_depart;
  } while(taux_depart<0.5 or taux_depart>6);

  do{
  cout << "taux d'attaque à la fin  en % (entre " << taux_depart << " et 6) ? ";
  cin >> taux_fin;
  } while(taux_fin<taux_depart or taux_fin>6);

  taux_depart /= 100;
  taux_fin /= 100;

  for(double taux_attaque(taux_depart); taux_attaque<taux_fin; taux_attaque+=0.01) {
      double AuxL(lapins_i), AuxR(renards_i);
      int i(1);
      bool DangerL(false), DangerR(false), CameBackL(false), CameBackR(false), DisparuL(false), DisparuR(false);
      for(i; i<=50; ++i){
        double AuxLprev(AuxL);
        AuxL *= (1.0 + taux_croissance_lapins - taux_attaque * AuxR);
        AuxR *= (1.0 + taux_attaque * AuxLprev * taux_croissance_renards - taux_mortalite);
        if (AuxL<5)
            DangerL = true;
            if (AuxL<2){
                AuxL = 0;
                DisparuL = true;
            }
        if (AuxR<5)
            DangerR = true;
            if (AuxR<2){
                AuxR = 0;
                DisparuR = true;
            }

        if (DangerL)
            if (AuxL>5)
                CameBackL = true;
        if (DangerR)
            if (AuxR>5)
                CameBackR = true;
        if(DisparuL and DisparuR){
            ++i;
            break;
        }

      }

      cout <<  endl << "***** Le taux d'attaque vaut "<< taux_attaque * 100 << "%" <<  endl;
      cout << "Après " << --i << " mois, il y a " << AuxL << " lapins et " << AuxR << " renards" << endl;
      if (DangerR){
        cout << "Les renards ont été en voie d'extinction" << endl;
        if (CameBackR)
          cout << "mais la population est remontée ! Ouf !" << endl;
        else if (DisparuR)
          cout << "et les renards ont disparu :-(" << endl;
      }

      if (DangerL){
            cout << "Les lapins ont été en voie d'extinction" << endl;
        if (CameBackL)
            cout << "mais la population est remontée ! Ouf !" << endl;
        else if (DisparuL)
            cout << "et les lapins ont disparu :-(" << endl;
      }
      if (!DisparuL and !DisparuR)
        cout << "Les lapins et les renards ont des populations stables." << endl;

 }


  /*******************************************
   * Ne rien modifier après cette ligne.
   *******************************************/

  return 0;
}
