#include <iostream>
#include <vector>
using namespace std;

int somme_consecutifs_max(vector<int> row);
vector<size_t> lignes_max(vector<vector<int>> matrix);
vector<vector<int>> tranches_max(vector<vector<int>> matrix);

vector<vector<int>> tranches_max(vector<vector<int>> matrix) {
    vector<vector<int>> desired_lines;
    vector<size_t> max_indexes(lignes_max(matrix));
    for (auto index: max_indexes)
        desired_lines.push_back(matrix[index]);
    return desired_lines;
}

vector<size_t> lignes_max(vector<vector<int>> matrix) {
    if (matrix.empty())
        return vector<size_t>();
    vector<size_t> ret_vect;
    int max_somme(0);
    for(size_t i(0); i<matrix.size(); ++i) {
        vector<int> row(matrix[i]);
        int current_somme(somme_consecutifs_max(row));
        if(current_somme>=max_somme) {
            if (current_somme>max_somme) {
                max_somme = current_somme;
                ret_vect.clear();
            }
            ret_vect.push_back(i);
        }
    }
    return ret_vect;
}
int somme_consecutifs_max(vector<int> row) {
    if (row.empty())
        return 0;
    int max_sum(0);
    int j(0);
    do{
        int current_sum(row[j]);
        while(j<row.size()-1 and row[j+1]) {
            ++j;
            current_sum += row[j];
        }
        if (current_sum>max_sum)
            max_sum = current_sum;
        j+=1;
    }while(j<row.size());
    return max_sum;
}

void print_matrix(vector<vector<int>> matrix);

void print_matrix(vector<vector<int>> matrix) {
    for(auto row: matrix){
        for (auto element: row)
            cout << element  << " " ;
        cout << endl;
    }
}


int main(){
    vector<vector<int>> matrix;

    size_t qRows(0);
    cout << "qRows: ";
    cin >> qRows;

    while(matrix.size()<qRows) {
        vector<int> row;
        size_t qElemRow(0);
        cout << "qElemRow: ";
        cin >> qElemRow;
        for(size_t i(0); i<qElemRow; ++i){
            int element(0);
            cin >> element;
            row.push_back(element);
        }


        matrix.push_back(row);
    }

    cout << "Considered Matrix" << endl;
    print_matrix(matrix);

    matrix = tranches_max(matrix);

    cout << "Maximum of Matrix" << endl;
    print_matrix(matrix);

    return 0;
}
