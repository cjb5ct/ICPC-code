// Proble B Dvaput solution
using namespace std;

#include <iostream>
#include <map>


int main() {

    int s_length;
    string to_search;

    cin >> s_length;
    cin >> to_search;

    int start = s_length / 2;

    map<string, int> string_map;
    // find letter frequencies
    // map<string,bool> truth_map;
    int max_size = 0;

    while (start > 1) {
        int counter = 0;
        bool first = true;

        while (counter <= s_length - (start - 1)) {
           // cout << counter << endl;
            int test = 0;
            string temp_string = "";
            if (first) {
               // cout << counter + (start -1) << endl;
                test = counter + (start-1);
                temp_string = to_search.substr(counter,start);
                first = false;
            }
            else {

                //cout << counter + (start) << endl;
                temp_string = to_search.substr(counter,start);
                test = counter+start;
            }

            cout << temp_string << endl;
            string_map[temp_string] += 1;
            if (string_map[temp_string] >= 2) {
                cout << temp_string.size() << endl;
                return 0;
            }
            temp_string = "";

            counter = test;




        }




        // string temp = "";

        //int increm = start;
        /*
        int current_pos = 0;

        for (int k = current_pos; k < current_pos + start; k++) {
            //current_pos++;
            // temp += to_search[k];
            string temp = str.substr(current_pos)
            if (temp.size() == start) {

                current_pos += start;
                string_map[temp] += 1;
                int test = string_map[temp];
                if (test >= 2) {
                    cout << temp.size() << endl;
                    return 0;
                }

                cout << temp << " " << string_map[temp] << endl;

            }

        }
        // cout << temp << endl;
        current_pos = 0;
        //temp = "";
        */

        start--;
    }



    return 0;
}
