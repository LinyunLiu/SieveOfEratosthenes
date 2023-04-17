<?php
/*
Name: Linyun Liu
Student Number: 613705
CMPT 360 Spring 2021
Lab Assignment #4
Title: Finding Primes Numbers Using Sieve of Eratosthenes Algorithm
*/
function compute_primes($MAX){

    // To fill the arrays with consecutive numbers with the size MAX
    $numbers = array_fill(0, $MAX, true);
    /* In this algorithm, the array index is used to represent the
     * prime number. Since the prime number start at 2, we make the
     * index 0 and 1 false, which means 0 and 1 is not prime number
    */
    $numbers[0] = false;
    $numbers[1] = false;

    // To initialize the next_prime number with 2
    // which is also the first prime number
    $next_prime = 2;
    $count = 0;

    while ($next_prime*$next_prime < $MAX){
        /*
         * Starting from a prime number, there are only a limited
         * numbers that are multiple of the prime number under the MAX
         */
        $limit = (($MAX-$next_prime)/$next_prime);
        while($count <= $limit){
            $numbers[$next_prime*$next_prime+($next_prime*$count)] = false;
            $count++;
        }
        $count = 0;
        // a for loop tp find out which is the next prime number
        for ($i = $next_prime+1; $i<$MAX; $i++){
            if ($numbers[$i]){
                $next_prime = $i;
                break;
            }
        }
    }

    return $numbers;
}

// To demonstrate that the algorithm output correct results
// The result should be all prime numbers under 100
echo "==== Sieve of Eratosthenes Algorithm in PHP ====";
echo "\nExample result (prime numbers under 100):\n";
$nums = compute_primes(100);
for ($i=0; $i<100; $i++){
    if($nums[$i]){
        echo $i;
        echo " ";
    }
}

/* This part of code uses while loop to compute the time it takes to run
 * the same algorithm multiple times
 */
echo "\nNow testing the run time by running the algorithm 10000 times....\n";
$start = microtime(true);
$count = 0;
while ($count <= 10000){
    compute_primes(11000);
    $count++;
}
$end = microtime(true);
echo "Time Taken: ";
echo round(($end-$start)*1000000000);
echo " nanoseconds";
