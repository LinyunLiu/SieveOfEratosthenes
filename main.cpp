/*
Name: Linyun Liu
Title: Finding Primes Numbers Using Sieve of Eratosthenes Algorithm
*/
#include <iostream>
#include <chrono>
using namespace std;

bool* compute_primes(int MAX){

    // To fill the arrays with consecutive numbers with the size MAX
    bool* numbers = new bool[MAX];
    for (int i=0; i<MAX; i++){
        numbers[i] = true;
    }
    /* In this algorithm, the array index is used to represent the
     * prime number. Since the prime number start at 2, we make the
     * index 0 and 1 false, which means 0 and 1 is not prime number
    */
    numbers[0] = false;
    numbers[1] = false;

    // To initialize the next_prime number with 2
    // which is also the first prime number
    int next_prime = 2;
    int limit;
    int count = 0;

    while (next_prime*next_prime < MAX) {
        /*
         * Starting from a prime number, there are only a limited
         * numbers that are multiple of the prime number under the MAX
         */
        limit = ((MAX-next_prime*next_prime)/next_prime);
        while (count <= limit){
            numbers[next_prime*next_prime+(next_prime*count)] = false;
            count++;
        }
        count = 0;

        // a for loop tp find out which is the next prime number
        for (int j = next_prime + 1; j < MAX; j++) {
            if (numbers[j]) {
                next_prime = j;
                break;
            }
        }
    }
    return numbers;
}

int main() {

    // To demonstrate that the algorithm output correct results
    // The result should be all prime numbers under 100
    cout << "=== Sieve of Eratosthenes Algorithm in C++ ===" << "\n";
    cout << "Example result (prime numbers under 100):" << "\n";
    bool* nums = compute_primes(100);
    for (int i=0; i<100; i++){
        if (nums[i]){
            cout << i;
            cout << " ";
        }
    }

    /* This part of code uses while loop to compute the time it takes to run
     * the same algorithm multiple times
    */
    cout << "\nTesting the run time by running the algorithm 10000 time...." << "\n";
    auto start = chrono::high_resolution_clock::now();
    int count = 0;
    while (count <= 10000){
        compute_primes(11000);
        count++;
    }
    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    cout << "Time Taken: ";
    cout << duration;
    cout << " nanoseconds";


    return 0;
}


