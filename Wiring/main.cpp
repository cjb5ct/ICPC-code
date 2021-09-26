//
// Created by CJ on 3/16/2021.
//
#include <iostream>
#include "electric.h"
#include <unordered_map>
#include "findUnion.h"
#include <queue>
#include <algorithm>
#include <map>

using namespace std;


// need to check for valid edges before kruskals
// need to properly filter the edges based on the constraints
// have helper methods to determine components example "pre-swtich" - all pre-switches have the same connection type

// ideas for woking on constraints
// if the current node (edge) being worked on start point is a switch,
// then check if the next node in the edge is a light, and if it isn't then
// simply delete that edge and keep going because it cant work

// have a check that if it is a light on the next one than you should
// not connect anything that isn't a switch unless no dependencies listed
// have a separate queue/list of lights and their dependencies
// can take this when reading in input

unordered_map<string,vector<string>> lightDependent;
unordered_map<string,vector<string>> graph_rep;
unordered_map<string,electric*> juncs;

struct edge {

    electric* starts_at;
    electric* connects_to;
    int weight;
    string name;
    string start;
    string start_type;
    string end;
    string end_type;


    bool isValid(edge* edg) {
        /*
         * Conditions to do
         * breaker->light? check
         * box->light check
         * outlet->light check
         * light->breaker check
         * light->box check
         * light->outlet check
         * swith->switch check
         * */

        string start_typ = edg->start_type;
        string end_typ = edg->end_type;

        // LIGHT CHECKS

        if (start_typ == "light" || end_typ == "light") {
            if ((start_typ=="breaker"||start_typ=="box"||start_typ=="outlet") && end_typ == "light") {
                return false;
            }
            if ((end_typ=="breaker"||end_typ=="box"||end_typ=="outlet") && start_typ == "light") {
                return false;
            }
        }

        // SWITCH CHECKS
        if (start_typ == "switch" && end_typ == "switch") {
            return false;
        }

        if (start_typ == "switch" && end_typ == "light") {
            for (string lit : lightDependent[edg->start]) {
                if (lit == edg->end) {
                    return true;
                }
            }
            return false;
        }if (start_typ == "light" && end_typ == "switch") {
            for (string lit : lightDependent[edg->end]) {
                if (lit == edg->start) {
                    return true;
                }
            }
            return false;
        }

        // Light to Light

        if (start_typ == "light" && end_typ == "light") {

            string light1switch;
            string light2switch;

            for (auto& it: lightDependent) {
                for (string lit: lightDependent[it.first]) {
                    if (lit == edg->start) {
                        light1switch = it.first;
                    }
                    if (lit == edg->end) {
                        light2switch = it.first;
                    }
                }
            }
            return light1switch == light2switch;

        }

        // Check switch for connection to multiple components
        if (start_typ == "switch" && (end_typ != "switch" && end_typ != "light")) {
            if (end_typ == "box" || end_typ == "breaker" || end_typ == "outlet") {
                for (string comp:graph_rep[edg->start]) {
                    if (juncs[comp]->type=="breaker"||juncs[comp]->type=="outlet"||juncs[comp]->type=="box"){
                        return false;
                    }
                }
            }
        }
        // end_typ != "light
        if ((start_typ != "switch" && start_typ != "light") && end_typ == "switch") {
            if (start_typ == "box" || start_typ == "breaker" || start_typ == "outlet") {
                for (string comp:graph_rep[edg->end]) {
                    if (juncs[comp]->type=="breaker"||juncs[comp]->type=="outlet"||juncs[comp]->type=="box"){
                        return false;
                    }
                }
            }

        }
        return true;
    }
};

// less_than_key for sorting edge lists
struct less_than_key
{
    inline bool operator() (edge* struct1, edge* struct2)
    {
        return (struct1->weight < struct2->weight);
    }
};

int main() {
    int junctions;
    int possible_connections;

    cin >> junctions;
    cin >> possible_connections;

    vector<edge*> edge_list;
    vector<string> junc_names;
    queue<string> next_switch;
    bool switchCondition = false;
    for (int i=0;i<junctions;i++) {
        switchCondition = false;
        string comp_name;
        string comp_type;
        cin >> comp_name;
        cin >> comp_type;

        junc_names.push_back(comp_name);
        auto* junk = new electric(comp_name,comp_type);
        juncs.emplace(comp_name,junk);

        if (comp_type == "light" || comp_type == "switch") {
            switchCondition = true;
        }

       if (switchCondition) {
            if (comp_type == "switch") {
                next_switch.push(comp_name);
                lightDependent.insert({comp_name,{}});
            }
            else if(comp_type == "light") {
                string current_switch = next_switch.back();
                lightDependent[current_switch].push_back(comp_name);
            }
       }


    }
    edge* minimum_edge = new edge();
    string stored1;
    string stored2;

    for (int i=0;i<possible_connections;i++){

        string j1;
        string j2;
        int cost;
        cin >> j1;
        cin >> j2;
        cin >> cost;

        edge* temp_edge = new edge();
        temp_edge->start = j1;
        temp_edge->end = j2;
        temp_edge->name = std::string(j1 + "->" + j2);
        temp_edge->weight = cost;
        temp_edge->starts_at = juncs.at(j1);
        temp_edge->connects_to = juncs.at(j2);
        temp_edge->start_type = juncs.at(j1)->type;
        temp_edge->end_type = juncs.at(j2)->type;
        edge_list.push_back(temp_edge);



    }


    // Kruksals

    // sort the edge list in ascending order
    std::sort (edge_list.begin(),edge_list.end(),less_than_key());
    // this gives us the minimum (or minimums) as the first elements in the list of edges

    int edgesAccepted = 0;
    auto* merger = new findUnion;
    merger->makeSet(juncs.size());

    vector<edge*> graph;

    int total_weight = 0;

    while (edgesAccepted < merger->set_var.size() - 1) {
        // minimum value is at beginning of edge_list
        edge* e = edge_list.at(0);
        electric* node1 = e->starts_at;
        electric* node2 = e->connects_to;

        int node1_number = std::find(junc_names.begin(),junc_names.end(),node1->name)-junc_names.begin();
        int node2_number = std::find(junc_names.begin(),junc_names.end(),node2->name)-junc_names.begin();

        int set1 = merger->findSet(node1_number);
        int set2 = merger->findSet(node2_number);


        if (set1 != set2 && e->isValid(e)) {
            graph_rep[e->start].push_back(e->end);
            graph_rep[e->end].push_back(e->start);
            graph.push_back(e);
            total_weight += e->weight;
            edge_list.erase(edge_list.begin());
            edgesAccepted++;
            merger->unions(node1_number,node2_number);
        }
        else {
            edge_list.erase(edge_list.begin());
        }

    }

    /*
    cout << "This is all junctions name/type: " << endl;
    auto it = juncs.begin();
    while (it!=juncs.end()){
        cout << it->first << " " << it->second->type << endl;
        ++it;
    }
    */

    /*
    cout << "This is all the edges found and their weights: ";
    cout << edge_list.size() << endl;
    for (edge* e: edge_list) {
        cout << e->name << ":" << e->weight << ":" << e->connects_to->name << endl;
    }
     */

    /*
    cout << "This should be e: ";
    cout << minimum_edge->name << endl;
    cout << "The minimum edge connects to: " << minimum_edge->connects_to->name << endl;
*/


/*
    for (edge* tac:graph){
        cout << tac->name << " ";
    }
    cout << endl;
*/
    cout << total_weight;

    return 0;
}
