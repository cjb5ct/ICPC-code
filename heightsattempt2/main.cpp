#include <iostream>
#include <deque>
using namespace std;

int main() {
    int sets;
    cin >> sets;
    int data_set;
    deque<int> student_heights = {};
    //vector<int> student_heights;
    deque<int> sorted = {};

    while (sets > 0) {
        int step_count = 0;
        cin >> data_set;
        int temp;
        for (int i=20;i>0;i--) {
            cin >> temp;
            student_heights.push_back(temp);

        }


        for (int i=0;i<student_heights.size();i++) {
            int current_student = student_heights[i];
            bool test = true;
            for (int x = 0;x<sorted.size();x++) {
                if (current_student < sorted[x]) {
                    step_count += sorted.size() - x;
                    sorted.insert(sorted.begin() + x,current_student);
                    test = false;
                    break;
                }
            }
            if (test) {
                sorted.push_back(current_student);
            }

        }


        cout << data_set << " " << step_count << endl;


        step_count = 0;

        student_heights.clear();
        sorted.clear();
        sets--;

    }



    return 0;
}
