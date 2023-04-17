# Introduction
This project uses two languages C++ and PHP to implement an ancient algorithm, Sieve of Eratosthenes, 
to generate all the prime numbers with a given limit. The purpose is to compare the C++ compiler and PHP interpreter 
in terms of their efficiency, in another words, to compare and find out which language and its compiler or interpreter 
can produce the fastest code on the same computing machine using the same algorithm (In this case, the program will be 
designed to use similar structure and memory allocation)

# How Does the Algorithm Works?
The Sieve of Eratosthenes is a well-known algorithm for finding prime numbers up to a certain limit. The basic idea is to 
create a list of numbers from 2 up to the limit, and then iterate through the list, marking off all multiples of each number 
as composite (i.e., not a prime number). By the end of the algorithm, all unmarked numbers will be prime.  

**Here are the steps that will be implemented in a computer program:**
* Create an array with all Boolean True value with the size of the limit we want to find primes for.
* In this program, we use the array indices to represent consecutive integer numbers, and the items in the 
array will be Boolean values that represent whether or not the index (number) is prime. Initially, all items 
in array will be True -> [true, true, true, true, ……].
* Assign the index 0 and 1 with False value as they are not prime number -> [false, false, true, true, true, true, ……].
* Start with the first prime number (which is 2 or say index at 2) as next prime. Mark all of its multiples as composite 
by updating their corresponding indices in the array. For example, if 2 is the first prime number, then we would mark the indices 4, 6, 8, 10, etc. 
as false (not a prime number, it is composite).
* Find the next prime number which is the index of next True value in the array (3 in this case) and mark all of its multiples as composite. 
Again, update the corresponding indices in the array.
* Repeat the process of 5 until the multiple of the next prime number is out of array index bounds (in other words, until there are no 
composite index number left).
* Iterate though the array, if the value is marked True, then we print out the index of that value.
