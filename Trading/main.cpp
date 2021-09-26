
// Charles Brady, cjb5ct, 2/15/21, AdvancedHomework1
#include "starTools.h"
#include "starTools.cpp"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
// ARRAY IS LAID OUT BY XYZ FOR EXMPALE X[0][0] will get the x coordinate of the first star
// x[0][1] will get the y coodinate of the first star x[0][2] will get z coordinate etc. etc.
int main(){

    int starCount;
    vector<vector<float>> starCords;
    bool started = false;
    cin >> starCount;
    while (starCount != 0){
       // cin >> starCount;'
        if (started) {
            cin >> starCount;
        }
        //float star_cords[starCount][3];
        cout << "Accepting input for " << starCount << " stars now: " << endl;
        int count = 0;

        float temp;
        int z = 0;
        while (count < starCount) {
            cout << "Star " << count << endl;
            vector<float> templist;

            while (z < 3) {
                cin >> temp;
               // star_cords[count][z] = temp;
                templist.push_back(temp);
                z++;
            }
            z = 0;


            count++;

            starCords.push_back(templist);
        }




        auto* starUser = new starTools();
        starUser-> star_count = starCount;
        starUser-> star_cords = starCords;

        for (int i = 0; i < starCount; ++i) {
            // access columns of the array
            for (int j = 0; j < 3; ++j) {
                cout << "star_cords[" << i << "][" << j << "] = " << starUser->star_cords[i][j] << endl;
            }
        }

        cout << "Comparex... should be 0 " << starUser->CompareStarx(0, 2) << endl;

        started = true;



    }
    // this prints out all the star cords in the vector of vectors
    /*
    for (vector<float> cords:star_cords2) {
        for (float cord:cords) {
            cout << cord << " ";
        }
        cout << endl;
    }
*/



/*
    string x;
    while(cin) {
        cin>>x;
        cout<<x<<endl;


    }
    return 0;
*/


   // cout << "This is comparing 2 stars " << GetDistance(0,1) << endl;


    return 0;



}


