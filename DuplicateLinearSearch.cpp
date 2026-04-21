// Duplicates Linear Search 
#include <iostream>
using namespace std;

int main()
{
    int input[5] = {2, 4, 2, 7, 2};
    int target;

    cout << "Enter a target number: ";
    cin >> target;
    
    bool found = false; // flag for checking

    cout << "Target found at indices: ";

    for(int i = 0; i < 5; i++ ) {
        if(input[i] == target){
            cout  << i << " ";
            found = true;
        }
    }
    
    if(!found) {
        cout << "None";
    }

    return 0;
}