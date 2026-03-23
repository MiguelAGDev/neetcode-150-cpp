#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main()
{

    unordered_set <char> unset_row;
    unordered_set <char> unset_col;

    vector<vector<char>> matriz={
        {'1','2','.','.','3','.','.','.','.'},
        {'4','.','.','5','.','.','.','.','.'},
        {'.','9','1','.','.','.','.','.','3'},
        {'5','.','.','.','6','.','.','.','4'},
        {'.','.','.','8','.','3','.','.','5'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','.','.','.','.','.','2','.','.'},
        {'.','.','.','4','1','9','.','.','8'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    for(int row = 0; row< 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            //cout<<matriz[row][col]<< " |";

            unset_row.insert(matriz[row][col]);
            cout <<matriz[col][row]<< " |";
            unset_col.insert(matriz[col][row]);

        }

        cout<<endl;
    }



}
