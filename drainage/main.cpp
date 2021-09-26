// Charles Brady, cjb5ct, 4/10/2021, drainage, basichomework3

#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<vector<int>> grid;
vector<vector<int>> table_check;
map<string,int> answers;
int rows;
int columns;


// variables which I won't touch so i always have the count of the rows and columns
int row_count;
int column_count;


int findPathFromCell(int r, int c) {
    if (r < 0 || r>=row_count || c<0 || c>= column_count ) {
        return 0;
    }
    if (table_check[r][c] != -1) {
        return table_check[r][c];
    }

    // variables for storing the path lengths of the possible directions
    int north = 0, east = 0, south  = 0, west = 0;

    if (c < column_count - 1 && ((grid[r][c]) < grid[r][c+1])) {
        north = 1 + findPathFromCell(r,c+1);
    }
    if (c > 0 && ((grid[r][c]) < grid[r][c-1])) {
        east = 1 + findPathFromCell(r,c-1);
    }
    if (r > 0 && ((grid[r][c]) < grid[r-1][c])) {
        south = 1 + findPathFromCell(r-1,c);
    }
    if (r < row_count - 1 && ((grid[r][c]) < grid[r+1][c])) {
        west = 1 + findPathFromCell(r+1,c);
    }

    return table_check[r][c] = max(north, max(east, max(south, max(west, 1))));

}
// vector<vector<int>> land_grid
int findLongestPath() {

    int final = 1;

    for (int i=0; i<row_count;i++) {
        for (int b = 0; b<column_count;b++) {
            if (table_check[i][b] == -1) {
                findPathFromCell(i,b);
            }

            final = max(final,table_check[i][b]);
        }
    }
    return final;
}


int main() {


    int test_cases;
    cin >> test_cases;

    string title;


    while (test_cases !=0) {

        cin >> title;
        cin >> rows;
        cin >> columns;
        row_count = rows;
        column_count = columns;


        int temp;
        int count = columns;
        int inc = 0;

        while (rows != 0) {
            vector<int> temp_vec;
            grid.push_back(temp_vec);
            table_check.push_back(temp_vec);
            while (count != 0) {
                cin >> temp;
                grid[inc].push_back(temp);
                table_check[inc].push_back(-1);
                count--;
            }
            rows--;
            inc++;
            count = columns;
        }

        answers.emplace(title,findLongestPath());
        grid.clear();
        table_check.clear();
        test_cases--;

    }

    map<string,int>::iterator it = answers.begin();
    while (it != answers.end()) {
        cout << it->first << ": " << it->second << endl;
        ++it;
    }

    /*
     * Printout Statements for the Grids if needed
     *
     *
    for (vector<int> list:grid) {
        for (int num:list) {
            cout << num << " ";
        }
        cout << endl;
    }

    for (vector<int> list:table_check) {
        for (int num:list) {
            cout << num << " ";
        }
        cout << endl;
    }
*/




    return 0;
}
