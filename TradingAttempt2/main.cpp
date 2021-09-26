// Charles Brady, cjb5ct, 3/8/20201
// CS 4102 Algorithms, Advanced Homework 1 Trading
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;



struct starTools {

    int star_count;
    vector<vector<double>> star_cords;
    double minDistance = 99999999999;
/*
    bool CompareStarx(int star1, int star2) {
        return star_cords[star1][0] > star_cords[star2][0];
    }
*/
    bool CompareStarx(vector<double> star1, vector<double> star2){
       return star1[0] > star2[0];
    }

/*
    bool CompareStary(int star1, int star2) {
        return star_cords[star1][1] > star_cords[star2][1];
    }
*/
    bool CompareStary(vector<double> star1, vector<double> star2){
       return star1[1] > star2[1];
    }
    /*
    bool CompareStarz(int star1, int star2) {
        return star_cords[star1][2] > star_cords[star2][2];
    }
*/
    bool CompareStarz(vector<double> star1, vector<double> star2) {
        return star1[2] > star2[2];
    }

    double GetDistance (vector<vector<double>> cords_list,int star1, int star2) {
        double squaredX = (cords_list[star1][0] - cords_list[star2][0]) * (cords_list[star1][0] - cords_list[star2][0]);
        double squaredY = (cords_list[star1][1] - cords_list[star2][1]) * (cords_list[star1][1] - cords_list[star2][1]);
        double squaredZ = (cords_list[star1][2] - cords_list[star2][2]) * (cords_list[star1][2] - cords_list[star2][2]);

        return sqrt(squaredX + squaredY + squaredZ);
    }


    double bruteForceMethod(vector<vector<double>> cords_list){
        // star count
        int stars = cords_list.size();
        for (int i = 0; i < stars; i++){
            for (int j = i + 1; j < stars; j++){

             double distance = GetDistance(cords_list,i,j);
              //  cout << "i: " << i << " j: " << j << " " << distance << endl;
                if (distance < minDistance)
                    minDistance = distance;


            }

        }

        return minDistance;

    }


    double RecursiveSearch(int Xpos, vector<vector<double>> sortedY)

    {

        int size = sortedY.size();
        // 100
        if (size < 100)
            return bruteForceMethod(sortedY);

        //Get middle star for X axis
        int mindex = Xpos + size / 2;

        vector<double> midStar = star_cords[mindex];

        //Initiliaze left and right subarrays
        vector<vector<double>> leftSide;
        vector<vector<double>> rightSide;

        //other stars might have the same x as mid star
        bool directRightSide = true;

        //Distribute stars to their subarrays
        for (int i = 0; i < size; i++){
            if (sortedY[i][0] < midStar[0])
                // if the x coordinate of the sorted y list is liess than that of the mid star point
                leftSide.push_back(sortedY[i]);

            else if (sortedY[i][0] > midStar[0])
                // if the x coordinate of the sorted y list is greater than that of the mid star point
                rightSide.push_back(sortedY[i]);

            else{
                if (directRightSide)
                    rightSide.push_back(sortedY[i]);
                else
                    leftSide.push_back(sortedY[i]);

                directRightSide = !directRightSide;
            }
        }
        //Pass subarrays
        double minimumLeftDistance = RecursiveSearch(Xpos, leftSide);
        double minimumRightDistance = RecursiveSearch(Xpos + leftSide.size(), rightSide);

        //Initiliaze strip
        vector<vector<double>> strip;

        double stripDistance = std::min(minimumLeftDistance, minimumRightDistance);

        //balls close to middle go in strip.
        for (int i = 0; i < size; i++){
            double distanceToMiddle = sortedY[i][0] - midStar[0];

            if (distanceToMiddle < 0)
                distanceToMiddle *= -1;

            if (distanceToMiddle < stripDistance)
                strip.push_back(sortedY[i]);
        }

        //Search in strip and return
        return min(stripSearch(strip, stripDistance),stripDistance);

    }


    double stripSearch(vector<vector<double>> strip, double stripDistance)
    {
        //Save the strip distance
        double minimumDistance = stripDistance;

        //If star count in strip is less than 2, return strip distance
        int stripSize = strip.size();

        //If star count in strip is 2 or 3, find distance with the brute force method because faster
        /*
        if (stripSize < 100){
            double tempDistance = bruteForceMethod(strip);
            if (tempDistance < minimumDistance)

                minimumDistance = tempDistance;
            return minimumDistance;
        }
         */
     //   std::sort(sortedY.begin(), sortedY.end(), &starTools::CompareStary);
        // sort strip by Ys
        double Yminimum = 99999999999999;
        double tempDistance;
      //  std::sort(strip.begin(),strip.end(),&starTools::CompareStary);
        std::sort(strip.begin(), strip.end(),
                  [](const std::vector<double>& a, const std::vector<double>& b) {
                      return a[1] < b[1];
                  });

        for (int i=0;i<strip.size();i++) {

            for (int b = i + 1; b < strip.size() && abs(strip[i][1] - strip[b][1]) < stripDistance; b++) {
            //    vector<double> star1 = strip[i];
             //   vector<double> star2 = strip[b];
                tempDistance = GetDistance(strip,i,b);
              //  cout << tempDistance << endl;
            }
            if (tempDistance < Yminimum) {
                Yminimum = tempDistance;
            }
        }
        return Yminimum;

    }


    double ClosestPair()
    {
        //Sort by increasing X order n log n

      //  std::sort(star_cords.begin(), star_cords.end(), &starTools::CompareStarx);
        std::sort(star_cords.begin(), star_cords.end(),
                  [](const std::vector<double>& a, const std::vector<double>& b) {
                      return a[0] < b[0];
                  });

        //sortedY vector
        vector<vector<double>> sortedY;
        for (int i = 0; i < star_count; i++)
            sortedY.push_back(star_cords[i]);

        //Sort by increasing Y order  n log n
      //  std::sort(sortedY.begin(), sortedY.end(), &starTools::CompareStary);
        std::sort(sortedY.begin(), sortedY.end(),
                  [](const std::vector<double>& a, const std::vector<double>& b) {
                      return a[1] < b[1];
                  });
        //Start recursion
        double finalMinimumDistance = RecursiveSearch(0, sortedY);

        //Return the final minimum distance
        return finalMinimumDistance;

    }

};


int main(){

    vector<double> answers;
    starTools finder;
    //int starCount;
   // vector<vector<double>> starCords;
    bool started = false;
    cin >> finder.star_count;
    while (finder.star_count != 0){
        // cin >> starCount;'
        if (started) {
            cin >> finder.star_count;
            if (finder.star_count == 0) {
                break;
            }
        }
        //float starCords[starCount][3];
      // cout << "Accepting input for " << finder.star_count << " stars now: " << endl;
        int count = 0;

        double temp;
        int z = 0;
        while (count < finder.star_count) {
         //   cout << "Star " << count + 1 << endl;
            vector<double> templist;

            while (z < 3) {
                cin >> temp;
                // starCords[count][z] = temp;
                templist.push_back(temp);
                z++;
            }
            z = 0;


            count++;

            finder.star_cords.push_back(templist);
        }



 //This is code for printing out the coordinates in the vector of vectors
 /*
        for (int i = 0; i < finder.star_count; ++i) {
            // access columns of the array
            for (int j = 0; j < 3; ++j) {
                cout << "starCords[" << i << "][" << j << "] = " << finder.star_cords[i][j] << endl;
            }
        }
*/


        started = true;
        /*
        finder.star_count = starCount;
        finder.star_cords = starCords;
*/     // cout << finder.bruteForceMethod() << endl;

        double finalVal = finder.ClosestPair();
        int precValue = finalVal*1;
        int precisionCount = int(log10(precValue) + 1);
    //    cout << precisionCount << endl;
        if (finalVal > 10000 && finder.star_count!=0) {
           // answers.push_back(0);
            cout << "infinity" << endl;
        }
        else {
           cout << setprecision(precisionCount+4)<< finalVal << endl;
          // answers.push_back(finalVal);
        }
        finder.minDistance = 99999999999;
        finder.star_cords.clear();

       // cout << finder.ClosestPair() << endl;
    }



   // cout << "This is comparing 2 stars " << finder.GetDistance(0,1) << endl;
/*
    for (double x:answers) {
        if (x == 0) {
            cout <<"infinity"<< endl;
        }
        else{
            cout << x << endl;
        }

    }
    */
    return 0;



}
