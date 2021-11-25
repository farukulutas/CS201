#include <iostream>
#include <algorithm>
#include <math.h>
#include <ctime>

using namespace std;

// Linear search (iterative implementation) which works in O(N) time, where N is
// the size of the collection.
int algorithm1(int arr[], int N, int key) {
    int index = 0;
    for ( index = 0; index < N; index++ )
        if ( arr[index] == key )
            return index;
    return -1;
}

// Linear search (recursive implementation) which works in O(N) time, where N is
// the size of the collection.
// cnt should always be given as -1
int algorithm2(int arr[], int key, int N, int cnt ){
    cnt++;
    N = N - 1;
    if ( N < 0 ) {
        return -1;
    }
    if ( arr[N] == key ) {
        return cnt;
    }

    return algorithm2( arr, key, N, cnt);
}

// Binary search which works in O(logN) time, where N is the size of the collection.
int algorithm3( int arr[], int N, int key ){
    int low = 0, high = N - 1;
    while ( low <= high ) {
        int mid = (low + high) / 2;
        if ( arr[ mid ] < key )
            low = mid + 1;
        else if ( arr[ mid ] > key )
            high = mid - 1;
        else
            return mid;
    }
    return -1;
}

// Jump search which works in O(N/m + m) time, where N is the size of the
// collection and m is the block size. Assume m = sqrt(𝑁). So it works in O(sqrt(𝑁)) time.
int algorithm4(int arr[], int N, int key) {
    int step = sqrt(N);
    int prev = 0;

    while ( arr[min(step, N) - 1] < key ) {
        prev = step;
        step = step + sqrt(N);
        if (prev >= N)
            return -1;
    }

    while (arr[prev] < key) {
        prev++;
        if (prev == min(step, N))
            return -1;
    }
    if (arr[prev] == key)
        return prev;

    return -1;
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

    while ( n <= 40000 ) {
        int *arr1 = new int[n];

        createRandomArray(arr1, n, n * 10);

        int akey = arr1[1];
        int bkey = arr1[(n / 2) - 1];
        int ckey = arr1[n - (n / 10)];
        int dkey = -5;

        cout << "N = " << n << endl;

        cout << "Algorithm1 case i (a) the key is close to the beginning" << endl;

        double duration;
        clock_t startTime = clock();

        //Code block
        for ( int i = 0; i < 500000; i++ ) {
            algorithm1( arr1, n, akey);
        }

        //Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Execution took " << duration << " milliseconds." << endl;

        cout << "Algorithm1 case ii  (b) the key is around the middle" << endl;

        startTime = clock();

        //Code block
        for ( int i = 0; i < 500000; i++ ) {
            algorithm1( arr1, n, bkey);
        }

        //Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Execution took " << duration << " milliseconds." << endl;

        cout << "Algorithm1 case iii (c) the key is close to the end" << endl;

        startTime = clock();
        //Code block
        for ( int i = 0; i < 500000; i++ ) {
            algorithm1( arr1, n, ckey);
        }

        //Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Execution took " << duration << " milliseconds." << endl;

        cout << "Algorithm1 case iiii (d) the key does not exist inthe collection" << endl;

        startTime = clock();

        //Code block
        for ( int i = 0; i < 1000000; i++ ) {
            algorithm1( arr1, n, dkey);
        }

        //Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Execution took " << duration << " milliseconds." << endl;

        //////////////////////////////////////////////////////////////////////

        cout << "Algorithm2 case i (a) the key is close to the beginning" << endl;

        //Code block
        algorithm2( arr1, akey, n, -1);

        //Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Execution took " << duration << " milliseconds." << endl;

        cout << "Algorithm2 case ii  (b) the key is around the middle" << endl;

        startTime = clock();

        //Code block
        for ( int i = 0; i < 100000; i++ ) {
            algorithm2( arr1, bkey, n, -1);
        }

        //Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Execution took " << duration << " milliseconds." << endl;

        cout << "Algorithm2 case iii (c) the key is close to the end" << endl;

        startTime = clock();
        //Code block
        for ( int i = 0; i < 1000000; i++ ) {
            algorithm2( arr1, ckey, n, -1);
        }

        //Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Execution took " << duration << " milliseconds." << endl;

        cout << "Algorithm2 case iiii (d) the key does not exist inthe collection" << endl;

        startTime = clock();

        //Code block
        for ( int i = 0; i < 100000; i++ ) {
            algorithm2( arr1, dkey, n, -1);
        }

        //Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Execution took " << duration << " milliseconds." << endl;

        //////////////////////////////////////////////////////////////////////

        cout << "Algorithm3 case i (a) the key is close to the beginning" << endl;

        //Code block
        for ( int i = 0; i < 500000; i++ ) {
            algorithm3( arr1, n, akey);
        }

        //Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Execution took " << duration << " milliseconds." << endl;

        cout << "Algorithm3 case ii  (b) the key is around the middle" << endl;

        startTime = clock();

        //Code block
        for ( int i = 0; i < 500000; i++ ) {
            algorithm3( arr1, n, bkey);
        }

        //Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Execution took " << duration << " milliseconds." << endl;

        cout << "Algorithm3 case iii (c) the key is close to the end" << endl;

        startTime = clock();
        //Code block
        for ( int i = 0; i < 500000; i++ ) {
            algorithm3( arr1, n, ckey);
        }

        //Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Execution took " << duration << " milliseconds." << endl;

        cout << "Algorithm3 case iiii (d) the key does not exist inthe collection" << endl;

        startTime = clock();

        //Code block
        for ( int i = 0; i < 500000; i++ ) {
            algorithm3( arr1, n, dkey);
        }

        //Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Execution took " << duration << " milliseconds." << endl;

            //////////////////////////////////////////////////////////////////////

        cout << "Algorithm4 case i (a) the key is close to the beginning" << endl;

        //Code block
        for ( int i = 0; i < 500000; i++ ) {
            algorithm4( arr1, n, akey);
        }

        //Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Execution took " << duration << " milliseconds." << endl;

        cout << "Algorithm4 case ii  (b) the key is around the middle" << endl;

        startTime = clock();

        //Code block
        for ( int i = 0; i < 500000; i++ ) {
            algorithm4( arr1, n, bkey);
        }

        //Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Execution took " << duration << " milliseconds." << endl;

        cout << "Algorithm4 case iii (c) the key is close to the end" << endl;

        startTime = clock();
        //Code block
        for ( int i = 0; i < 500000; i++ ) {
            algorithm4( arr1, n, ckey);
        }

        //Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Execution took " << duration << " milliseconds." << endl;

        cout << "Algorithm4 case iiii (d) the key does not exist inthe collection" << endl;

        startTime = clock();

        //Code block
        for ( int i = 0; i < 500000; i++ ) {
            algorithm4( arr1, n, dkey);
        }

        //Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Execution took " << duration << " milliseconds." << endl;

        delete[] arr1;

        if ( n >= 10000 ) {
            n = n + 5000;
        }
        else {
            n = n * 10;
        }
    }

    return 0;
}
