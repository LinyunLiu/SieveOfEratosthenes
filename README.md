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

> A visual demonstration below:
While the program is finding the composite numbers, there will be overlay with the multiples of the previous prime number, 
for example, 12 is the multiple of both 2 and 3. But this does not affect the algorithm itself. 
![iamge.png](https://github.com/LinyunLiu/SieveOfEratosthenes/blob/main/image.png?raw=true)  
[Reference](https://www.algolist.net/Algorithms/Number_theoretic/Sieve_of_Eratosthenes)  

# First 1000 Primes Example:
```
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 101 103 107 109 113 127 131 137 139 
149 151 157 163 167 173 179 181 191 193 197 199 211 223 227 229 233 239 241 251 257 263 269 271 277 281 283 
293 307 311 313 317 331 337 347 349 353 359 367 373 379 383 389 397 401 409 419 421 431 433 439 443 449 457 
461 463 467 479 487 491 499 503 509 521 523 541 547 557 563 569 571 577 587 593 599 601 607 613 617 619 631 
641 643 647 653 659 661 673 677 683 691 701 709 719 727 733 739 743 751 757 761 769 773 787 797 809 811 821 
823 827 829 839 853 857 859 863 877 881 883 887 907 911 919 929 937 941 947 953 967 971 977 983 991 997
```


