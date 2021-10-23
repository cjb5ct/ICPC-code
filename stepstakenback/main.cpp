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


            // make another sorted array to delete from

/*
           deque<int> sorted_delete = sorted;
           for (int i=0;i<student_heights.size();i++) {
               if (student_heights[i] == sorted[i]){
                   sorted_delete.erase(sorted_delete.begin() + i);
               }
               else {

               }

           }
*/
           /*
            int first_pos;
            for (int a = 1;a<student_heights.size();a++) {
                temp2 = student_heights[a];
                if (temp1 < temp2) {
                    // increment 1 up the list
                    auto it = find(sorted.begin(),sorted.end(),temp1);
                    sorted.erase(it);
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

            */




            int current_student;
            int current_spot;
           // deque<int> sorted_delete = sorted;
            deque<int> current_copy = student_heights;
            int count = 0;
            for (int stud: current_copy) {
                current_student = stud;
               // cout << "cs: " << current_student << " ";



                count++;
               // cout << "cs: " << current_spot << " ";
                auto it = find(student_heights.begin(),student_heights.end(), current_student);

                current_spot = it - student_heights.begin();
               // int pos_cur_stud =
                // take the student out of line
               // student_heights.erase(student_heights.begin()+i);

                student_heights.erase(it);

                // compare the students height to the rest of the line
                // find the first person that is taller than them and put the student in front of then, add the numebr of steps
                // if the person is the tallest then put them in the back and add no steps
                bool tallest = true;
                for (int x=0;x<19;x++) {
                    if (current_student <= student_heights[x]) {
                        student_heights.insert(student_heights.begin()+x,current_student);
                        // if they are in the same spot we don't want to add any steps

                        //cout << current_spot << " == " << x << endl;
                        if (current_spot == x) {
                            // same spot, don't add any steps

                        }
                        else {
                           // cout << "x: " << x << " ";
                            // changed spot add steps
                            cout << 20 - (x+1) << " ";
                            step_count += 20 - (x+1);
                        }



                        tallest = false;
                        break;
                    }

                }


                if (tallest) {
                    // put the student in the back, don't add any steps
                    student_heights.push_back(current_student);

                }
                //cout << tallest << " ";

                /*
                cout << "after: " << endl;
                for (int ele: student_heights) {
                    cout << ele << " ";
                }
                cout << endl;
*/


                //sorted_delete.erase(sorted_delete.begin());

                /*
                if (student_heights == sorted) {
                    break;
                }
                 */


            }
            cout << endl;




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
        sorted.clear();
        sets--;

    }



    return 0;
}
