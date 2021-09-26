
// Charles Brady, cjb5ct, 2/15/21, BasicHomework1

#include <iostream>

#include <vector>



using namespace std;





// Global Variables

int tables;

int people;



vector<int> tablespos;

vector<int> peoplepos;

vector<int> park;

int maxTablePos = 0;





bool canBeSeated(int middle,int tablez,int peoples,vector<int> parc) {



    // Initial Position of the first seated person

    int position = parc.at(0);

    // Counter for how many people have been seated starting at 1 b/c first person placed

    int count = 1;





    for (int i=1;i<tablez;i++) {

        if (parc.at(i)-position >= middle) {

            position = parc.at(i);

            count++;



            if (count == peoples) {

                return true;

            }



        }

    }

    return false;



}



int findSocialDistance(int tablez,int peoples, vector<int> parc) {

    int final = -1;



    int left = 1;

    int right = parc.at(tablez-1) - parc.at(0);



    while (left < right) {

        int middle = (left + right) / 2;

        if (canBeSeated(middle,tablez,peoples,parc)) {

            final = max(final, middle);

            left = middle + 1;

        }

        else {

            right = middle;

        }

    }

    return final;

}





/*

*** Unused Method ***

bool tableHere(int i) {

  for (int j:tablespos) {

    if (i == j) {

      return true;

    }

  }

  return false;

}

*/



int main(){



    cin >> tables;

    cin >> people;



    int i = 0;

    int temp;

    while (i < tables) {

        cin >> temp;

        if (temp > maxTablePos) {

            maxTablePos = temp;

        }





        tablespos.push_back(temp);

        i++;

    }



    for(int i=0;i <= maxTablePos;i++) {

        park.push_back(i);

    }



    cout << findSocialDistance(tables,people,tablespos) << endl;



    return 0;





}


