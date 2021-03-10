#include <iostream>
#include <vector>
using namespace std;

/*******************************************
 * Complétez le programme à partir d'ici.
 *******************************************/
typedef vector<vector<int>> Carte;

struct Position {
  size_t i; // row index
  size_t j; // column index
} ;

bool binaire(Carte const& carte);
bool binaire(Carte const& carte){
    if(carte.empty())
        return false;

    for (auto row: carte){
        for (auto element: row){
            if (element!=0 and element!=1)
                return false;
        }
    }
    return true;
}

void affiche(Carte const& carte);
void affiche(Carte const& carte){
    for (auto row: carte){
        for (auto element: row){
            cout << element;
        }
        cout << endl;
    }
    cout << "----" << endl;
}

size_t find_fst_ind(vector<int> row);
size_t find_fst_ind(vector<int> row){
    for(size_t i(0); i<row.size(); ++i){
        if (row[i]==1){
                return i;
        }
    }
}

size_t find_lst_ind(vector<int> row);
size_t find_lst_ind(vector<int> row){
    for(size_t i(row.size()-1); ; --i){
        if (row[i]==1){
            return i;
        }
    }
}

void find_lst_and_fst_ind(vector<int> row, size_t& fst_ind, size_t& lst_ind);
void find_lst_and_fst_ind(vector<int> row, size_t& fst_ind, size_t& lst_ind){
    fst_ind = find_fst_ind(row);
    lst_ind = find_lst_ind(row);
}

void effacer_etangs(Carte& carte);
void effacer_etangs(Carte& carte){
    for (auto& row: carte){
        size_t fst_ind(0), lst_ind(0);
        find_lst_and_fst_ind(row, fst_ind, lst_ind);
        for(size_t ind(fst_ind+1); ind<lst_ind; ++ind){
            if (row[ind]==0)
                row[ind]=1;
        }
    }
}

bool verifie_et_modifie(Carte& carte);
bool verifie_et_modifie(Carte& carte){
    if (!binaire(carte)){
        cout << "Votre carte du terrain ne contient pas que des 0 et des 1." << endl;
        return false;
    }
    effacer_etangs(carte);
    return true;
}

double longueur_cloture(Carte const& carte, double echelle = 2.5);
double longueur_cloture(Carte const& carte, double echelle){
    double longueur(0);
    vector<int> row;
    size_t fst_ind(0), lst_ind(0);

    for(size_t i(1); i<carte.size()-1; ++i){
        row = carte[i];
        find_lst_and_fst_ind(row, fst_ind, lst_ind);
        for(size_t ind(fst_ind); ind<=lst_ind; ++ind)
            longueur+= 2 - carte[i-1][ind] - carte[i+1][ind];
    }

    row = carte[0];
    find_lst_and_fst_ind(row, fst_ind, lst_ind);
    if (carte.size()>1){
        for(size_t ind(fst_ind); ind<=lst_ind; ++ind)
            longueur+= 2 - carte[1][ind];
        row = carte[carte.size()-1];
        find_lst_and_fst_ind(row, fst_ind, lst_ind);
        for(size_t ind(fst_ind); ind<=lst_ind; ++ind)
            longueur+= 2 - carte[carte.size()-2][ind];
    }
    else {
        longueur = 2*(lst_ind-fst_ind+1);
    }

    longueur+= 2*carte.size();
    return longueur * echelle;
}

void marque_composantes(Carte& carte);
void marque_composantes(Carte& carte){
    vector<Position> under_consideration;
    int composante(1);
    for (size_t i(0); i<carte.size(); ++i){
        for(size_t j(0); j<carte[i].size(); ++j){
            if (!carte[i][j]){
                cout << i << " " << j << endl;
                composante += 1;
                Position aux_pos;
                aux_pos.i = i;
                aux_pos.j = j;
                under_consideration.push_back(aux_pos);
                cout << "Composante: " << composante << endl;
                while(!under_consideration.empty()){
                    for (auto pos: under_consideration)
                        cout << "[" << pos.i << ", " << pos.j <<  "]";
                    cout << endl;
                    Position last_pos(under_consideration.back());
                    under_consideration.pop_back();
                    if(!carte[last_pos.i][last_pos.j]){
                        carte[last_pos.i][last_pos.j]=composante;
                        Position checked_pos;
                        if(last_pos.i){
                            if(!carte[last_pos.i-1][last_pos.j]){
                                checked_pos.i = last_pos.i-1;
                                checked_pos.j = last_pos.j;
                                under_consideration.push_back(checked_pos);
                            }
                        }
                        if(last_pos.i<carte.size()-1){
                            if(!carte[last_pos.i+1][last_pos.j]){
                                checked_pos.i = last_pos.i+1;
                                checked_pos.j = last_pos.j;
                                under_consideration.push_back(checked_pos);
                            }
                        }
                        if(last_pos.j){
                            if(!carte[last_pos.i][last_pos.j-1]){
                                checked_pos.i = last_pos.i;
                                checked_pos.j = last_pos.j-1;
                                under_consideration.push_back(checked_pos);
                            }
                        }
                        if(last_pos.j<carte[last_pos.i].size()-1){
                            if(!carte[last_pos.i][last_pos.j+1]){
                                checked_pos.i = last_pos.i;
                                checked_pos.j = last_pos.j+1;
                                under_consideration.push_back(checked_pos);
                            }
                        }
                    }
                }
            }
        }
    }
}


void ajoute_unique(vector<int>& ensemble, int valeur);
void ajoute_unique(vector<int>& ensemble, int valeur){
}

bool convexite_lignes(Carte& carte, vector<int> const& labels_bords);
bool convexite_lignes(Carte& carte, vector<int> const& labels_bords){
return true;
}

bool convexite_lignes(Carte& carte);
bool convexite_lignes(Carte& carte){
return true;
}

      /*    cout << "Votre carte du terrain n'est pas convexe par lignes :" << endl;
          cout << "bord extérieur entrant trouvé en position [";
          cout << "][";
          cout << "]" << endl;
*/


/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  Carte carte = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0},
    {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
  };

  cout << "Carte au départ :" << endl;
  affiche(carte);
  if (verifie_et_modifie(carte)) {
    cout << "Carte après modification :" << endl;
    marque_composantes(carte);
    affiche(carte);
    cout << "Il vous faut " << longueur_cloture(carte)
         << " mètres de clôture pour votre terrain."
         << endl;
  }

  return 0;
}
