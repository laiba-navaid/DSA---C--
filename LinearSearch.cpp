// Linear Search
#include <iostream>
using namespace std;

int main() {
    // int i;
    // int flag = 0;
    
    int input[10] = {99, 72, 27, 11, 36, 88, 72, 82, 19, 57}; // Array declared

    cout << "Enter a target number: ";
    int tosearch;
    cin >> tosearch;

    bool found = false; // flag for checking
    
    for(int i = 0; i < 10; i++) 
    {
        if(input[i] ==  tosearch)
        {
            cout << "Target is found at index " << i << endl;
            found = true;
            // flag = 1;
            break;
        }
    }
    
    if(!found) 
    { // (i == 10) // (flag == 0)
        cout << "Value not found" << endl;
    }
       
    return 0;
}