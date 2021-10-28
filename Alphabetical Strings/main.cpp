#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;
int main() {

    int test_cases;
    cin >> test_cases;
    string alphabet = "bcdefghijklmnopqrstuvwxyz";



    int left_bound;
    int right_bound;
    while (test_cases > 0) {
        string is_alph;
        cin >> is_alph;

        string a_string = "a";
        int a_index = is_alph.find(a_string);
        left_bound = a_index-1;
        right_bound = a_index+1;
        //cout << a_index << endl;
        if (a_index == -1) {
            cout << "NO" << endl;
        }
        else if (a_index == 0 && is_alph.size() == 1){
            cout << "YES" << endl;
        }
        else {
            int counter = 1;
            for(char c: alphabet){
             // cout << test_cases << ": " << left_bound << " " << right_bound << " counter " << counter << endl;

                if (is_alph[left_bound] == c && left_bound >= 0) {
                   // cout << is_alph[left_bound] << " " << c << endl;
                    left_bound--;
                    counter++;
                }
                else if(is_alph[right_bound] == c && right_bound <= is_alph.size()-1) {
                  //  cout << is_alph[right_bound] << " " << c << endl;
                    right_bound++;
                    counter++;
                }
                else {
                    cout << "NO" << endl;
                    break;
                }
                if (counter >= is_alph.size()) {
                    cout << "YES" << endl;
                    break;
                }



            }

        }







        test_cases--;
    }








    return 0;
}
