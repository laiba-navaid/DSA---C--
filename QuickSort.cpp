#include <iostream>
using namespace std;

void quickSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int left = l;      // original left
        int right = r;     // original right
        int p = (l + r) / 2;   // midpoint pivot index

        while (l < r)
        {
            // Right Side
            while (r != p)
            {
                if (arr[r] < arr[p])   // compare with pivot value
                {
                    swap(arr[r], arr[p]);
                    p = r;            // update pivot index
                    break;
                }
                else
                {
                    r--;
                }
            }

            // Left Side
            while (l != p)
            {
                if (arr[l] > arr[p])   // compare with pivot value
                {
                    swap(arr[l], arr[p]);
                    p = l;            // update pivot index
                    break;
                }
                else
                {
                    l++;
                }
            }
        }

        // Recursive calls
        quickSort(arr, left, p - 1);
        quickSort(arr, p + 1, right);
    }
}

int main()
{
    // int arr[] = {22, 92, 18, 17, 11};
    // int n = 5;

    // quickSort(arr, 0, n - 1);

    // cout << "Sorted array: ";
    // for (int i = 0; i < n; i++)
    //     cout << arr[i] << " ";

    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = 6;

    quickSort(arr, 0, n-1);

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

// #include <iostream>
// using namespace std;

// void quickSort(int arr[], int l, int r) {
// if(l < r) {
//     int left = l;
//     int right = r;
//     int p = (l + r) / 2;

//     while(l < r) {

//         while(r != p) {
//             if( arr[r] > arr[p]) {
//                 swap(arr[r], arr[p]);
//                 p = r;
//                 break;
//             }
//             else {
//                 r--;
//             }
//         }

//         while( l != p) {
//             if(arr[l] < arr[p]) {
//                 swap(arr[l], arr[p]);
//                 p = l;
//                 break;
//             }
//             else {
//                 l++;
//             }
//         }
//     }
// }
// }

// // void quickSort(int arr[], int L, int R) 
// // {
// //     if(L < R) 
// //     {
// //         int left = L;
// //         int right = R;
// //         int P_ind = (left+ right) / 2;

// //         while(left < right) 
// //         {
// //             while(arr[P_ind] <= arr[right] && P_ind != right) 
// //                 right--;


// //             if(P_ind == right) 
// //             {
// //                 while(arr[P_ind] >= arr[left] && P_ind != left)
// //                     left++;
// //                 if(P_ind == left)
// //                      break;
// //                 else 
// //                 {
// //                     swap(arr[P_ind], arr[left]);
// //                     P_ind = left; 
// //                 }
            
// //             }
// //         }    

// //         quickSort(arr, L, P_ind-1);
// //         quickSort(arr, P_ind + 1, R);
// //     }
// // }                

// int main() {
//     int arr[] = {10, 7, 8, 9, 1, 5};
//     int n = 6;

//     quickSort(arr, 0, n-1);

//     for(int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }

//     return 0;
// }