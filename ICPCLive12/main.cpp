// Math Trade ICPC problem
using namespace std;
#include <vector>
#include <iostream>
#include <unordered_map>


int main() {

    int people;
    cin >> people;

    unordered_map<string,vector<string>> trade_map;
    unordered_map<string,string> wants_map;
    unordered_map<string,string> has_map;
 //   vector<string> items_owned;
   // vector<string> items_wanted;

    while (people > 0) {


        string name;
        string item_has;
        string item_wants;


        cin >> name;
        cin >> item_has;
        cin >> item_wants;

        wants_map.emplace(name,item_wants);
        has_map.emplace(name,item_wants);




        people--;
    }





    /*
     * Uncomment to print out data
     *
    auto it = trade_map.begin();
    while(it != trade_map.end()) {
        cout << it->first << " ";
        for (string ele: it->second) {
            cout << ele << " ";
        }
        cout << endl;
        ++it;
    }

     */
    return 0;
}
