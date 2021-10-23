// A Rank Problem

using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>


int main() {

    int teams;
    int games;

    cin >> teams;
    cin >> games;

    vector<string> rankings;

    for(int i=1;i<=teams;i++) {
        rankings.push_back("T" + to_string(i));
    }

    /*
    for (string ele: rankings) {
        cout << ele << " ";
    }
    cout << endl;
     */

    // now we have the teams, get their order
    while (games > 0) {
        string team1;
        string team2;
        cin >> team1;
        cin >> team2;

        // go through the team names
        auto it = find(rankings.begin(),rankings.end(),team1);
        auto it2 = find(rankings.begin(),rankings.end(),team2);

        int post1 = it - rankings.begin();
        int post2 = it2 - rankings.begin();
        if (post1 < post2) {
            // the first team is alread ranked higher, dont do anything
        }
        else {
            // you have to move the team to the right position
            // remove team2 from its spot
            rankings.erase(it2);
            // now add it behind the second team
            rankings.insert(it,team2);
        }



        /*
        for (string ele: rankings) {
            cout << ele << " ";
        }
        cout << endl;
         */
        games--;
    }

  //  cout << "final: " << endl;
    for (string ele: rankings) {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}
