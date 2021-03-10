#include<iostream>
using namespace std;

int main() {
    int ans(0);
    cout << "Pensez à un champignon : amanite tue-mouches, pied bleu, girolle,"     << endl
    << "cèpe de Bordeaux, coprin chevelu ou agaric jaunissant." << endl << endl;

    cout << "Est-ce que votre champignon a un anneau (1 : oui, 0 : non) ? ";
    cin >> ans;

    if (ans) {
        cout << "Est-ce que votre champignon vit en forêt (1 : oui, 0 : non) ? ";
        cin >> ans;
        if (ans){
            cout << "==> Le champignon auquel vous pensez est " << "l'amanite tue-mouches";
        } else {
            cout << "Est-ce que votre champignon a un chapeau convexe (1 : oui, 0 : non) ? ";
            cin >> ans;
            if (ans)
                cout << "==> Le champignon auquel vous pensez est " << "l'agaric jaunissant";
            else
                cout << "==> Le champignon auquel vous pensez est " << "le coprin chevelu";
            }
    }  else {
        cout << "Est-ce que votre champignon a des lamelles (1 : oui, 0 : non) ? ";
        cin >> ans;
        if (!ans){
            cout << "==> Le champignon auquel vous pensez est " << "le cèpe de Bordeaux";
        } else {
            cout << "Est-ce que votre champignon a un chapeau convexe (1 : oui, 0 : non) ? ";
            cin >> ans;
            if (ans)
                cout << "==> Le champignon auquel vous pensez est " << "le pied bleu";
            else
                cout << "==> Le champignon auquel vous pensez est " << "la girolle";
        }

    }
}
