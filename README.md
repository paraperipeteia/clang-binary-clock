# Binary clock in C

This is a simple binary clock written in C. 

It displays the current time in binary format.

Two versions were done, one with bitflags and another with a recursive function.

This was primarily a learning exercise for me to get more familiar with bitwise operations and plain-old C. 

Also threw in a couple examples for using scoped functions and other C features.

Via GCC compiler with the -lm flag to compile the math library.
```bash;
gcc binaryClock.c -o compiledBinaryClock -lm
```
Sample output: 

```
Fri May 24 00:20:23 2024
Standard 24-hr time:0 hours, 20 minutes, 23 seconds

bitflag version: 
000000 - hours
0|0|00 - minutes
0|0||| - seconds

Recursive version: 
000000 - hours
0|0|00 - minutes
0|0||| - seconds
```
