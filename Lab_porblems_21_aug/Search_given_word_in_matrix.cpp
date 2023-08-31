#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int N = 4; // Size of the matrix

bool isSafe(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

bool searchInDirection(const vector<vector<char>>& matrix, int row, int col, const string& word, int dx, int dy) {
    int len = word.length();
    int newRow, newCol;

    for (int i = 0; i < len; ++i) {
        newRow = row + i * dx;
        newCol = col + i * dy;

        if (!isSafe(newRow, newCol) || matrix[newRow][newCol] != word[i])
            return false;
    }

    return true;
}

void searchWord(const vector<vector<char>>& matrix, const string& word) {
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    if (dx == 0 && dy == 0)
                        continue;

                    if (searchInDirection(matrix, row, col, word, dx, dy)) {
                        int endRow = row + (word.length() - 1) * dx;
                        int endCol = col + (word.length() - 1) * dy;
                        cout << "Found at (" << row << ", " << col << ") to (" << endRow << ", " << endCol << ")" << endl;
                    }
                }
            }
        }
    }
}

int main() {
    vector<vector<char>> matrix = {
        {'a', 'h', 'a', 't'},
        {'c', 'a', 'p', 'e'},
        {'d', 'p', 'o', 'g'},
        {'t', 'e', 'r', 'b'}
    };

    string word = "tpp";
    searchWord(matrix, word);

    return 0;
}
