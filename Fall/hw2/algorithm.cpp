#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

// O(n^2)
// Append all items in arr1 in the same order to arr3. Then, for all items in arr2 starting from the
// beginning, find the right place to insert in arr3 by shifting the items in arr3 if needed.
int* algorithm1( int arr1[], int arr2[], const int n) {
    // creating the third array and boolean variable
    int* arr3 = new int[2 * n];
    bool shift = false;
    int index = 0;

    // inserting arr1 to arr3
    for ( int i = 0; i < n; i++ ) {
        arr3[i] = arr1[i];
    }

    // compare arr2 and arr3 and insert the values by using shift or not
    for ( int j = 0; j < n; j++ ) {
        for ( int k = 0; k < 2 * n; k++ ) {
            if ( arr3[k] > arr2[j] ) {
                shift = true;
                index = k;
                break;
            }
            else {
                arr3[j + n] = arr2[j];
            }
        }

        // if shift needed, shift values (2n-1 time)
        if ( shift ) {
            for ( int l = 2 * n - 2; l > index - 1; l-- ) {
                arr3[l + 1] = arr3[l];
            }

            // insert the minor value and shift is false
            arr3[index] = arr2[j];
            shift = false;
        }
    }

    return arr3;
}

// Compare pairs of numbers across arr1 and arr2 and insert the smallest to arr3.
// In this algorithm you are allowed to visit every item only once.
int* algorithm2( int arr1[], int arr2[], const int n) {
    // creating the third array and index counters (i, j, k)
    int* arr3 = new int[2 * n];
    int i = 0, j = 0, k = 0;

    // while loop to compare elements and insert to small one to arr3
    while ( i < n && j < n ){
        if ( arr1[i] < arr2[j] ) {
            arr3[k++] = arr1[i++];
        }
        else {
            arr3[k++] = arr2[j++];
        }
    }

    // insert the remaining elements to arr3 by while loops, if any
    while (i < n)
        arr3[k++] = arr1[i++];

    while (j < n)
        arr3[k++] = arr2[j++];

    return arr3;
}

void createRandomArray(int* arr3, const int n, const int division) {
    // to create new seeds for randomness
    srand(time(0));

    // for loop to create and insert random integers to array
    for (int i = 0; i < n; i++) {
        int randomInt = rand() % division;
        arr3[i] = randomInt;
    }

    // sort the array
    sort(arr3, arr3 + n);
}

int main() {
    int n = 10;

    int* arr = NULL;

    int *arr1 = new int[n];
    int *arr2 = new int[n];
    int *arr3 = new int[n];
    int *arr4 = new int[n];
    int *arr5 = new int[n];
    int *arr6 = new int[n];

    createRandomArray(arr1, n, 100);
    createRandomArray(arr2, n, 1000);
    createRandomArray(arr3, n, 1000);
    createRandomArray(arr4, n, 100);
    createRandomArray(arr5, n, 1000);
    createRandomArray(arr6, n, 1000);

    cout << "N = 10" << endl;

    cout << "Algorithm1 case i (arr1 < arr2)" << endl;

    double duration;
    clock_t startTime = clock();

    //Code block
    arr = algorithm1( arr1, arr2, n);

    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;

    delete[] arr;

    cout << "Algorithm2 case i (arr1 < arr2)" << endl;

    startTime = clock();

    //Code block
    arr = algorithm2( arr1, arr2, n);

    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;


    delete[] arr;

    cout << "Algorithm1 case ii (arr1 > arr2)" << endl;

    startTime = clock();
    //Code block
    arr = algorithm1( arr3, arr4, n);

    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;

    delete[] arr;

    cout << "Algorithm2 case ii (arr1 > arr2)" << endl;

    startTime = clock();

    //Code block
    arr = algorithm2( arr3, arr4, n);

    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;

    delete[] arr;

    cout << "Algorithm1 case iii no such ordering" << endl;

    startTime = clock();

    //Code block
    arr = algorithm1( arr5, arr6, n);

    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;

    delete[] arr;

    cout << "Algorithm2 case iii no such ordering" << endl;

    startTime = clock();

    //Code block
    arr = algorithm2( arr5, arr6, n);

    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;

    cout << endl;

    delete[] arr;
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;

    n = 100;

    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[n];
    arr4 = new int[n];
    arr5 = new int[n];
    arr6 = new int[n];

    createRandomArray(arr1, n, 1000);
    createRandomArray(arr2, n, 10000);
    createRandomArray(arr3, n, 10000);
    createRandomArray(arr4, n, 1000);
    createRandomArray(arr5, n, 10000);
    createRandomArray(arr6, n, 10000);

    cout << "N = 100" << endl;

    cout << "Algorithm1 case i (arr1 < arr2)" << endl;

    startTime = clock();

    //Code block
    arr = algorithm1( arr1, arr2, n);

    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;

    delete[] arr;

    cout << "Algorithm2 case i (arr1 < arr2)" << endl;

    startTime = clock();

    //Code block
    arr = algorithm2( arr1, arr2, n);

    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;

    delete[] arr;

    cout << "Algorithm1 case ii (arr1 > arr2)" << endl;

    startTime = clock();

    //Code block
    arr = algorithm1( arr3, arr4, n);

    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;

    delete[] arr;

    cout << "Algorithm2 case ii (arr1 > arr2)" << endl;

    startTime = clock();

    //Code block
    arr = algorithm2( arr3, arr4, n);

    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;

    delete[] arr;

    cout << "Algorithm1 case iii no such ordering" << endl;

    startTime = clock();

    //Code block
    arr = algorithm1( arr5, arr6, n);

    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;

    delete[] arr;

    cout << "Algorithm2 case iii no such ordering" << endl;

    startTime = clock();

    //Code block
    arr = algorithm2( arr5, arr6, n);

    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;

    delete[] arr;
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;

    n = 1000;

    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[n];
    arr4 = new int[n];
    arr5 = new int[n];
    arr6 = new int[n];

    createRandomArray(arr1, n, 10000);
    createRandomArray(arr2, n, 100000);
    createRandomArray(arr3, n, 100000);
    createRandomArray(arr4, n, 10000);
    createRandomArray(arr5, n, 100000);
    createRandomArray(arr6, n, 100000);

    cout << "N = 1000" << endl;

    cout << "Algorithm1 case i (arr1 < arr2)" << endl;

    startTime = clock();

    //Code block
    arr = algorithm1( arr1, arr2, n);

    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;

    delete[] arr;

    cout << "Algorithm2 case i (arr1 < arr2)" << endl;

    startTime = clock();

    //Code block
    arr = algorithm2( arr1, arr2, n);

    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;

    delete[] arr;

    cout << "Algorithm1 case ii (arr1 > arr2)" << endl;

    startTime = clock();
    //Code block
    arr = algorithm1( arr3, arr4, n);

    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;

    delete[] arr;

    cout << "Algorithm2 case ii (arr1 > arr2)" << endl;

    startTime = clock();

    //Code block
    arr = algorithm2( arr3, arr4, n);

    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;

    delete[] arr;

    cout << "Algorithm1 case iii no such ordering" << endl;

    startTime = clock();

    //Code block
    arr = algorithm1( arr5, arr6, n);

    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;

    delete[] arr;

    cout << "Algorithm2 case iii no such ordering" << endl;

    startTime = clock();

    //Code block
    arr = algorithm2( arr5, arr6, n);

    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;

    delete[] arr;
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;

    n = 10000;

    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[n];
    arr4 = new int[n];
    arr5 = new int[n];
    arr6 = new int[n];

    createRandomArray(arr1, n, 10000);
    createRandomArray(arr2, n, 100000);
    createRandomArray(arr3, n, 100000);
    createRandomArray(arr4, n, 10000);
    createRandomArray(arr5, n, 100000);
    createRandomArray(arr6, n, 10000);

    cout << "N = 10000" << endl;

    cout << "Algorithm1 case i (arr1 < arr2)" << endl;

    startTime = clock();

    //Code block
    arr = algorithm1( arr1, arr2, n);

    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;

    delete[] arr;

    cout << "Algorithm2 case i (arr1 < arr2)" << endl;

    startTime = clock();

    //Code block
    arr = algorithm2( arr1, arr2, n);

    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;

    cout << "Algorithm1 case ii (arr1 > arr2)" << endl;

    startTime = clock();

    //Code block
    arr = algorithm1( arr3, arr4, n);

    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;

    delete[] arr;

    cout << "Algorithm2 case ii (arr1 > arr2)" << endl;

    startTime = clock();

    //Code block
    arr = algorithm2( arr3, arr4, n);

    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;

    delete[] arr;

    cout << "Algorithm1 case iii no such ordering" << endl;

    startTime = clock();

    //Code block
    arr = algorithm1( arr5, arr6, n);

    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;

    delete[] arr;

    cout << "Algorithm2 case iii no such ordering" << endl;

    startTime = clock();

    //Code block
    arr = algorithm2( arr5, arr6, n);

    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;

    delete[] arr;
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;

    n = 100000;

    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[n];
    arr4 = new int[n];
    arr5 = new int[n];
    arr6 = new int[n];

    createRandomArray(arr1, n, 10000);
    createRandomArray(arr2, n, 100000);
    createRandomArray(arr3, n, 100000);
    createRandomArray(arr4, n, 10000);
    createRandomArray(arr5, n, 100000);
    createRandomArray(arr6, n, 10000);

    cout << "N = 100000" << endl;

    cout << "Algorithm1 case i (arr1 < arr2)" << endl;

    startTime = clock();

    //Code block
    arr = algorithm1( arr1, arr2, n);

    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;

    delete[] arr;

    cout << "Algorithm2 case i (arr1 < arr2)" << endl;

    startTime = clock();

    //Code block
    arr = algorithm2( arr1, arr2, n);

    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;

    delete[] arr;

    cout << "Algorithm1 case ii (arr1 > arr2)" << endl;

    startTime = clock();

    //Code block
    arr = algorithm1( arr3, arr4, n);

    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;

    delete[] arr;

    cout << "Algorithm2 case ii (arr1 > arr2)" << endl;

    startTime = clock();

    //Code block
    arr = algorithm2( arr3, arr4, n);

    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;

    delete[] arr;

    cout << "Algorithm1 case iii no such ordering" << endl;

    startTime = clock();

    //Code block
    arr = algorithm1( arr5, arr6, n);

    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;

    delete[] arr;

    cout << "Algorithm2 case iii no such ordering" << endl;

    startTime = clock();

    //Code block
    arr = algorithm2( arr5, arr6, n);

    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;

    delete[] arr;
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;

    n = 1000000;

    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[n];
    arr4 = new int[n];
    arr5 = new int[n];
    arr6 = new int[n];

    createRandomArray(arr1, n, 10000);
    createRandomArray(arr2, n, 100000);
    createRandomArray(arr3, n, 100000);
    createRandomArray(arr4, n, 10000);
    createRandomArray(arr5, n, 100000);
    createRandomArray(arr6, n, 10000);

    cout << "N = 1000000" << endl;

    cout << "Algorithm2 case i (arr1 < arr2)" << endl;

    startTime = clock();

    //Code block
    arr = algorithm2( arr1, arr2, n);

    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;

    delete[] arr;

    cout << "Algorithm2 case ii (arr1 > arr2)" << endl;

    startTime = clock();

    //Code block
    arr = algorithm2( arr3, arr4, n);

    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;

    delete[] arr;

    cout << "Algorithm2 case iii no such ordering" << endl;

    startTime = clock();

    //Code block
    arr = algorithm2( arr5, arr6, n);

    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;

    delete[] arr;
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;

    n = 10000000;

    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[n];
    arr4 = new int[n];
    arr5 = new int[n];
    arr6 = new int[n];

    createRandomArray(arr1, n, 10000);
    createRandomArray(arr2, n, 100000);
    createRandomArray(arr3, n, 100000);
    createRandomArray(arr4, n, 10000);
    createRandomArray(arr5, n, 100000);
    createRandomArray(arr6, n, 10000);

    cout << "N = 10000000" << endl;

    cout << "Algorithm2 case i (arr1 < arr2)" << endl;

    startTime = clock();

    //Code block
    arr = algorithm2( arr1, arr2, n);

    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;

    delete[] arr;

    cout << "Algorithm2 case ii (arr1 > arr2)" << endl;

    startTime = clock();

    //Code block
    arr = algorithm2( arr3, arr4, n);

    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;

    delete[] arr;

    cout << "Algorithm2 case iii no such ordering" << endl;

    startTime = clock();

    //Code block
    arr = algorithm2( arr5, arr6, n);

    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;

    delete[] arr;
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;

    n = 100000000;

    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[n];
    arr4 = new int[n];
    arr5 = new int[n];
    arr6 = new int[n];

    createRandomArray(arr1, n, 10000);
    createRandomArray(arr2, n, 100000);
    createRandomArray(arr3, n, 100000);
    createRandomArray(arr4, n, 10000);
    createRandomArray(arr5, n, 100000);
    createRandomArray(arr6, n, 10000);

    cout << "N = 100000000" << endl;

    cout << "Algorithm2 case i (arr1 < arr2)" << endl;

    startTime = clock();

    //Code block
    arr = algorithm2( arr1, arr2, n);

    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;

    delete[] arr;

    cout << "Algorithm2 case ii (arr1 > arr2)" << endl;

    startTime = clock();

    //Code block
    arr = algorithm2( arr3, arr4, n);

    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;

    delete[] arr;

    cout << "Algorithm2 case iii no such ordering" << endl;

    startTime = clock();

    //Code block
    arr = algorithm2( arr5, arr6, n);

    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;

    delete[] arr;
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;

    return 0;
}
