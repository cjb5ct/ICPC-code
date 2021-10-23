#include <iostream>
#include <vector>
using namespace std;

int main() {
    int sets;
    int set_num;
    int num;



    cin >> sets;

    while(sets > 0) {
        cin >> set_num;
        cin >> num;

        vector<int> b_list;

        for (int x=1;x<=num;x++) {
            b_list.push_back(x);
        }
        // we have all possible denoms, now just loop through and find possible a's
        // a's that are possible must be greater than or equal to 0 and less than or equal to b
        vector<int> farey_list;
        int numer = 0;
        for (int denom: b_list) {
            while (numer <= denom) {




                numer++;
            }




        }






        sets--;
    }
}
