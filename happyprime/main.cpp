#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int,int> already_checked;


bool checkHappy(int num) {
    if (already_checked.count(num) > 0) {
        // already checked it, so break
        return false;
    }
    pair<int,int> to_insert (num, num);
    already_checked.insert(to_insert);
   // already_checked.emplace(num,num);


    if (num == 1) {
        return false;
    }
    int total = 0;
    // extract digits
    while (num > 0)
    {
        int digit = num%10;
        //cout << digit << endl;
        // square the digit and add it to the total
        total += digit * digit;
        num /= 10;

    }

    if (total == 1) {
        return true;
    }
    else {
        checkHappy(total);
    }


}


bool primeCheck(int n)
{
    int i, m=0, flag=0;
    m=n/2;
    for(i = 2; i <= m; i++)
    {
        if(n % i == 0)
        {
            //cout<<"Number is not Prime."<<endl;
            flag=1;
            return false;
        }
    }
    if (flag==0) {
        //cout << "Number is Prime."<<endl;
        return true;
    }

}




int main() {
    /*
    cout << "primeCheck: " << primeCheck(1) << endl;
    cout << "primeCheck: " << primeCheck(7) << endl;
    cout << "primeCheck: " << primeCheck(383) << endl;
    cout << "primeCheck: " << primeCheck(1000) << endl;
*/
    int sets;
    cin >> sets;
    int set_number;
    int to_check;
    while (sets > 0) {

        cin >> set_number;
        cin >> to_check;

        if (primeCheck(to_check) == true) {
            if(checkHappy(to_check) == true) {
                cout << set_number << " ";
                cout << to_check << " ";
                cout << "YES" << endl;
            }
            else {
                cout << set_number << " ";
                cout << to_check << " ";
                cout << "NO" << endl;
            }
        }
        else {
            cout << set_number << " ";
            cout << to_check << " ";
            cout << "NO" << endl;
        }
        sets --;
        already_checked.clear();
    }

    /*
    cout << checkHappy(1);
    cout << checkHappy(7);
    cout << checkHappy(383);
    cout << checkHappy(1000);
     */
    return 0;
}




