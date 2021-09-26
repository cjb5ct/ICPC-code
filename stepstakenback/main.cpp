#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <deque>
using namespace std;

int main() {
    int sets;
    cin >> sets;
    int data_set;
    deque<int> student_heights;
    //vector<int> student_heights;
    deque<int> sorted;

    while (sets > 0) {
        int step_count = 0;
        cin >> data_set;
        int temp;
        for (int i=20;i>0;i--) {
            cin >> temp;
            student_heights.push_back(temp);

        }
        sorted = student_heights;
        // check if the list is already sorted and if so steps is 0
        sort(sorted.begin(),sorted.end());
        if (sorted == student_heights) {

        }
        else {


            // find the first position of unsorted students in line and make that the first student to check
            int temp1 = student_heights[0];
            int temp2;
           // int current_student;
            int first_pos;
            for (int a = 1;a<student_heights.size();a++) {
                temp2 = student_heights[a];
                if (temp1 < temp2) {
                    // increment 1 up the list
                    temp1 = temp2;
                }
                else {
                    // make the first student the first instance of unordered
                    first_pos = a;
                   // cout << "starting here: " << first_pos << endl;
                    //current_student = student_heights[a];
                    break;
                }
            }
            int current_student;

            for (int i=first_pos;i<20;i++) {
                current_student = student_heights[i];

                // take the student out of line
                student_heights.erase(student_heights.begin()+i);

                // compare the students height to the rest of the line
                // find the first person that is taller than them and put the student in front of then, add the numebr of steps
                // if the person is the tallest then put them in the back and add no steps
                bool tallest = true;
                for (int x=0;x<20;x++) {
                    if (current_student <= student_heights[x]) {
                        student_heights.insert(student_heights.begin()+x,current_student);
                        //cout << x << " ";
                        step_count += 20 - (x+1);
                        tallest = false;
                        break;
                    }

                }
                if (tallest) {
                    // put the student in the back, don't add any steps
                    student_heights.push_back(current_student);
                }



            }



        }

        // we have our data in the program, now we have to do something with it
        // choose the first person in the line to be the first person


        /*
        auto it = min_element(student_heights.begin(),student_heights.end());
        int first = *it;

        student_heights.erase(it);
        student_heights.push_front(first);
         */

        cout << data_set << " " << step_count << endl;

        /*
        cout << data_set << " ";
        for (int ele: student_heights) {
           cout << ele << " ";
        }
        cout << endl;
*/

        step_count = 0;





        student_heights.clear();
        sets--;

    }



    return 0;
}
