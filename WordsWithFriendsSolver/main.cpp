#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    int word_size = 7;
    vector<string> letters = {"i","t","l","r","h","e","p"};
    string line;


        while (word_size > 1) {
            ifstream myfile ("dictionary.txt");
            if (myfile.is_open()) {

                while (getline(myfile, line)) {
                    //   cout << line << '\n';
                    int req = 0;

                    for (string s: letters) {
                        std::size_t found = line.find(s);
                        // cout << "found " << found << endl;
                        if (found != std::string::npos) {
                            //std::cout << "first 'needle' found at: " << found << '\n';
                            req++;
                        } else {
                            // req--;


                        }


                    }
                    // had req == line.length() here and it works good
                    // trying 7
                    //
                    // cout << "this should only print when 7 req: " << req << endl;
                    if (req >= word_size && line.size() <= word_size) {
                        cout << line << " " << line.size() << endl;
                    }


                }




            }
            else {
                cout << "unable to open file" << endl;
            }
            myfile.close();
            word_size--;
        }






    return 0;
}
