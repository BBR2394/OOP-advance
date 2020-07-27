# My Atoi Base
The aim of this project is to create a number converter in different base
## How it works
The program must be compile with a main file/function.
There are two main to test (that I have done for me)
- main_test.c
- main-deux.c

## Compile it ?
you just need to use gcc
```
gcc myatoibase.c main-deux.c -o ./myab-test
```
For example. Or you change with another main file.

## Function signature
```
int myatoibase(const char *nptr, const int base) 
```
The first parameter is the pointer to the array that contain the data to compute. the valu we want to convert into another base.
The second is the base used. It must be between 2 and 37 (2 <= base <= 37)
