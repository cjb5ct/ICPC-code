#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

unordered_map<string,vector<string>> desired_classes;

// the courses and how many people can be enrolled in a course
unordered_map<string,int> course_list;

// how many students want a particular course
map<string,int> class_demand_amount; // B
vector<string> class_demand_amount_sorted;

// how many classes a person has been assigned
map<string,int> classes_per_person; // A
vector<string> classes_per_person_sorted;
// Sorted Amount of classes wanted list
vector<pair<string, int> > A;

// Sorted Class Demand Amounts
vector<pair<string, int> > B;

// Representation of the registered classes graph
map<string,vector<string>> enrollment_list;

map<string,int> left_to_enroll;

int total_slots;




struct flow_node{
    string name;
    string type; // source node, class(left node), student(right node), sink node(t)
    int capacity;

};

struct flow_edge {
    string name;
    flow_node* start_node;
    flow_node* end_node;

};


struct flow_graph {
    vector<flow_edge*> middle;
    vector<flow_edge*> left_source;
    vector<flow_edge*> right_sink;

};

flow_graph* graph_rep = new flow_graph;
vector<flow_node*> node_list;




string answer = "Yes";



bool cmp(pair<string, int>& a,
         pair<string, int>& b)
{
    return a.second < b.second;
}

void sort(map<string, int>& M)
{

    // Declare vector of pairs
 //   vector<pair<string, int> > A;
    // Copy key-value pair from Map
    // to vector of pairs
    for (auto& it : M) {
        A.push_back(it);
    }

    // Sort using comparator function
    sort(A.begin(), A.end(), cmp);

    // Print the sorted value
    cout << "A Sorted Amount of classes wanted list" << endl;
    for (auto& it : A) {

        cout << it.first << ' '
             << it.second << endl;

        classes_per_person_sorted.push_back(it.first);
    }

}


bool cmp1(pair<string, int>& a,
         pair<string, int>& b)
{
    return a.second < b.second;
}

void sort1(map<string, int>& M)
{

    // Declare vector of pairs
    //   vector<pair<string, int> > A;
    // Copy key-value pair from Map
    // to vector of pairs
    for (auto& it : M) {
        B.push_back(it);
    }

    // Sort using comparator function
    sort(B.begin(), B.end(), cmp1);

    // Print the sorted value
    cout << "B Sorted Class Demand Amounts" << endl;
    for (auto& it : B) {

        cout << it.first << ' '
             << it.second << endl;

        class_demand_amount_sorted.push_back(it.first);

    }

}


int main() {

    bool contin = true;
    int requests =1;
    int num_courses =1;
    int number_enrolled = 1;

    while (requests!=0 && num_courses!=0 && number_enrolled !=0) {

        cin >> requests;
        cin >> num_courses;
        cin >> number_enrolled;
            int temp1 = requests;
            while (temp1 != 0) {
                string str1;
                string str2;
                string str3;
                string str4;
                cin >> str1;
           //     cout << str1 << " ";
                cin >> str2;
            //    cout << str2 << endl;
                cin >> str3;
                str4.append( str2 + "_" + str3);









                left_to_enroll.emplace(str1,number_enrolled);
                vector<string> temp;
                enrollment_list.emplace(str1,temp);

                auto it = desired_classes.find(str1);


                if (it == desired_classes.end()) {


                    auto* temp_stud = new flow_node;
                    temp_stud->name = str1;
                    temp_stud->type = "Student";
                    temp_stud->capacity = number_enrolled;
                    node_list.push_back(temp_stud);



                    vector<string> tmp = {str4};
                    typedef pair<string, vector<string>> p1;
                    classes_per_person[str1] = 1;
                    desired_classes.insert(p1(str1,tmp));

                    // str4 is the name of the class'
                    auto it4 = class_demand_amount.find(str4);
                    if (it4 == class_demand_amount.end()) {
                        typedef pair<string, int> p2;
                        class_demand_amount.insert(p2 (str4,1));
                    }
                    else {
                        class_demand_amount[it4->first] += 1;
                    }



                    /*
                    for (string s:desired_classes[str1]) {
                        cout << "already found: " ;
                        cout << str1 << endl;
                        cout << s << endl;
                    }
                     */
                }
                else if (it != desired_classes.end()){
                    desired_classes[str1].push_back(str4);
                    classes_per_person[str1] += 1;

                    auto it4 = class_demand_amount.find(str4);
                    if (it4 == class_demand_amount.end()) {
                        typedef pair<string, int> p2;
                        class_demand_amount.insert(p2 (str4,1));
                    }
                    else {
                        class_demand_amount[it4->first] += 1;
                    }
                //    class_demand_amount

                    /*
                    for (string s:desired_classes[str1]) {
                        cout << str1 << endl;
                        cout << s << endl;
                    }
                     */
                }
                temp1--;
            }

            int temp2 = num_courses;
            while (temp2 != 0) {
                string str1;
                string str2;
                int str3;
                string str4;
                cin >> str1;
                cin >> str2;
                cin >> str3;
                str4.append(str1 + "_" + str2);
                course_list.emplace(str4,str3);
                total_slots += str3;
                temp2--;

                auto* temp_class = new flow_node;
                temp_class->name = str4;
                temp_class->type = "Class";
                temp_class->capacity = str3;
                node_list.push_back(temp_class);

            }




            // NEW STUFF
            ///Making the Graph with node_list
            // Source node
            flow_node* source_node = new flow_node;
            source_node->name = "source";
            source_node->type = "source";
            source_node->capacity = classes_per_person.size() * number_enrolled;
            node_list.push_back(source_node);

            // Sink Node
            flow_node* sink_node = new flow_node;
            sink_node->name = "sink";
            sink_node->type = "sink";
            sink_node->capacity = total_slots;
            node_list.push_back(sink_node);

            for (flow_node* n:node_list) {
                cout << n->name << ": " << n->type << ": " << n->capacity << endl;
            }

            for (flow_node* n: node_list) {
                if (n->type == "Student") {
                    flow_edge* temp_edge = new flow_edge;
                    temp_edge->start_node = source_node;
                    temp_edge->end_node = n;
                    temp_edge->name = source_node->name + "->" + n->name;
                    graph_rep->left_source.push_back(temp_edge);

                }
                if (n->type == "Class") {
                    flow_edge* temp_edge = new flow_edge;
                    temp_edge->start_node = n;
                    temp_edge->end_node = sink_node;
                    temp_edge->name = n->name + "->" + sink_node->name;
                    graph_rep->right_sink.push_back(temp_edge);

                }

            }

            cout << "These are the Edges on the left side of the graph (Students): " << endl;
            for (flow_edge* edg: graph_rep->left_source) {
                cout << edg->name << ", ";

            }
            cout << endl;

            cout << "These are the Edges on the right side of the graph (Classes): " << endl;
            for (flow_edge* edg: graph_rep->right_sink) {
                cout << edg->name << ", ";

            }





























    }





























/*
        sort(classes_per_person); // A
        sort1(class_demand_amount); // B

        //enrollment list is the graph representation a map of vector strings


        bool isEmpty = false;
        auto itbit = left_to_enroll.begin();
        while (itbit!=left_to_enroll.end()) {
            cout << itbit->first << " " << itbit->second << endl;
            ++itbit;
        }
        while (!isEmpty) {
            isEmpty = left_to_enroll.empty();

            string temp_class = class_demand_amount_sorted.front();
            string temp_stud = classes_per_person_sorted.back();
            cout << temp_stud << endl;

            if (course_list[temp_class] == 0) {
                course_list.erase(class_demand_amount_sorted.front());
                temp_class = class_demand_amount_sorted.front();
            }

            if (left_to_enroll[temp_stud] == 0) {

                left_to_enroll.erase(temp_stud);
                classes_per_person_sorted.pop_back();
                temp_stud = classes_per_person_sorted.back();
            }

            while(left_to_enroll[temp_stud] != 0) {
                if (course_list[temp_class] != 0){
                    enrollment_list[temp_stud].push_back(temp_class);
                    // the course lost one possible spot for another student
                    course_list[temp_class]--;
                    // the student has one less class left to enroll in
                    left_to_enroll[temp_stud]--;

                    // print out how many classes left to enroll the student in
                    cout << left_to_enroll[temp_stud] << endl;
                    cout << temp_class << " has this many spots left " << course_list[temp_class] << endl;

                }

                else if (course_list[temp_class] == 0) {

                  //  B.erase(B.begin());
                    class_demand_amount_sorted.erase(class_demand_amount_sorted.begin());
                   // cout << "No" << endl;
                  //  return 0;
                }





                // if the class has been enrolled with everyone who wants it then remove it from the course course_desired list
            }


        }
        */
       /*
        auto itest = class_demand_amount.begin();
        while (itest!=class_demand_amount.end()) {
            cout << itest->first << " " << itest->second << endl;
            ++itest;
        }

        cout << "This is the enrollment map: " << endl;
        auto itest1 = enrollment_list.begin();
        while (itest1!=enrollment_list.end()) {
            cout << itest1->first << ": ";
            for (string s:itest1->second) {
                cout << s << ", ";
            }
            cout << endl;
            ++itest1;
        }

        cout << answer << endl;



    }

*/



    /*
    auto it = classes_per_person.begin();
    while (it != classes_per_person.end()) {
        cout << it->first << " ";
        cout << it->second << endl;
        ++it;
    }
*/

/*
    auto it = desired_classes.begin();
    auto it1 = course_list.begin();

    while (it != desired_classes.end()) {
        cout << it->first << " ";
       // cout << it->second;
       for (string s:it->second) {
           cout << s << " ";
       }
        cout << endl;
        ++it;
    }
    while (it1 != course_list.end()) {
        cout << it1->first << " ";

        cout << it1->second;
        cout << endl;
        ++it1;
    }
*/



    return 0;


}


