#include <iostream>
#include <ctime>

// pour les nombres aléatoires
#include <random>
#include <cstring> // strlen

using namespace std;

// ======================================================================
// Couleur au hasard
std::uniform_int_distribution<int> distribution;
std::default_random_engine generateur(time(NULL)); /* NOT using std::random_device since not
                                                    * all compilers seems to support it :-( */

char tirer_couleur()
{
  static const char* const couleurs = ".RGBCYM";
  static const int nb = strlen(couleurs) - 1;

  return couleurs[distribution(generateur,
                               std::uniform_int_distribution<int>::param_type {0, nb})];
}

// ======================================================================
char poser_question()
{
  char lu(' ');
  cout << "Entrez une couleur : ";
  cin >> lu;
  return lu;
}

// ---- prototype -------------------------------------------------------
bool couleur_valide(char c);

// ======================================================================
char lire_couleur()
{
  char lu(poser_question());
  while (not couleur_valide(lu)) {
    cout << "'" << lu << "' n'est pas une couleur valide." << endl;
    cout << "Les couleurs possibles sont : ., R, G, B, C, Y ou M." << endl;
    lu = poser_question();
  }
  return lu;
}

// ======================================================================
void afficher_couleurs(char c1, char c2, char c3, char c4)
{
  cout << ' ' << c1 << ' ' << c2 << ' ' << c3 << ' ' << c4;
}

// ======================================================================
void afficher(int nb, char c)
{
  while (nb-- > 0) {
    cout << c;
  }
}

// ---- prototype -------------------------------------------------------
void afficher_reponses(char c1, char c2, char c3, char c4,
                       char r1, char r2, char r3, char r4);

// ======================================================================
void afficher_coup(char c1, char c2, char c3, char c4,
                   char r1, char r2, char r3, char r4)
{
  afficher_couleurs(c1, c2, c3, c4);
  cout << " : ";
  afficher_reponses(c1, c2, c3, c4,
                    r1, r2, r3, r4);
  cout << endl;
}

// ======================================================================
void message_gagne(int nb_coups)
{
  cout << "Bravo ! Vous avez trouvé en " << nb_coups << " coups." << endl;
}

// ======================================================================
void message_perdu(char c1, char c2, char c3, char c4)
{
  cout << "Perdu :-(" << endl;
  cout << "La bonne combinaison était : ";
  afficher_couleurs(c1, c2, c3, c4);
  cout << endl;
}

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/

// ======================================================================
bool couleur_valide(char c);
bool couleur_valide(char c)
{
    if (c == '.' || c == 'R' || c == 'G' || c == 'B' || c == 'C' || c == 'Y' || c == 'M')
        return true;
    else
        return false;
}

// ======================================================================
bool verifier(char col, char& guess, int& score);
bool verifier(char col, char& guess, int& score)
{
    if (col==guess){
        guess = 'x';
        score+=1;
        return true;
    }
    else
        return false;
}

// ======================================================================
void apparier(char color_test, char& ctest1, char& ctest2, char& ctest3, int& score);
void apparier(char color_test, char& ctest1, char& ctest2, char& ctest3, int& score)
{
    bool result;
    result = verifier(color_test, ctest1, score);
    if (!result){
        result = verifier(color_test, ctest2, score);
        if (!result)
            result = verifier(color_test, ctest3, score);
    }
}

// ======================================================================
void afficher_reponses(char c1, char c2, char c3, char c4,
                       char r1, char r2, char r3, char r4)
{
    bool comp1, comp2, comp3, comp4;
    int ok(0), badplaced(0);

    comp1 = verifier(c1, r1, ok);
    comp2 = verifier(c2, r2, ok);
    comp3 = verifier(c3, r3, ok);
    comp4 = verifier(c4, r4, ok);
    afficher(ok, '#');

    if (!comp1)
        apparier(c1, r2, r3, r4, badplaced);
    if (!comp2)
        apparier(c2, r1, r3, r4, badplaced);
    if (!comp3)
        apparier(c3, r1, r2, r4, badplaced);
    if (!comp4)
        apparier(c4, r1, r2, r3, badplaced);
    afficher(badplaced, '+');

    afficher(4-ok-badplaced, '-');
}

// ======================================================================
bool gagne(char c1, char c2, char c3, char c4,
           char r1, char r2, char r3, char r4);

bool gagne(char c1, char c2, char c3, char c4,
           char r1, char r2, char r3, char r4)
{
    int ok(0);
    if(verifier(c1, r1, ok) && verifier(c2, r2, ok) && verifier(c3, r3, ok) && verifier(c4, r4, ok))
        return true;
    else
        return false;
}

// ======================================================================
void jouer(int chances = 8);
void jouer(int chances)
{
    char r1, r2, r3, r4, c1, c2, c3, c4;
    int tried(0);
    r1 = tirer_couleur();
    r2 = tirer_couleur();
    r3 = tirer_couleur();
    r4 = tirer_couleur();
    do{
        c1 = lire_couleur();
        c2 = lire_couleur();
        c3 = lire_couleur();
        c4 = lire_couleur();
        afficher_coup(c1, c2, c3, c4, r1, r2, r3, r4);
        tried+=1;
    } while((!gagne(c1,c2,c3,c4,r1,r2,r3,r4)) && tried<chances);
    if (gagne(r1,r2,r3,r4,c1,c2,c3,c4))
        message_gagne(tried);
    else
        message_perdu(r1,r2,r3,r4);
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  jouer();
  return 0;
}
