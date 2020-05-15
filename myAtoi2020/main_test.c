#include "stdio.h"

// FW declaration
int myatoibase(const char *nptr, const int base);

// Test main
int main (void)
{
        int res;
        int cmp;

        // Test 1
        res = myatoibase("128", 10);
        cmp = (res == 128);
        printf("Test 1: Pass=%d, (%d)\n", cmp, res);

        // Test 2
        res = myatoibase("-aac", 13);
        cmp = (res == -1832);
        printf("Test 2: Pass=%d, (%d)\n", cmp, res);

        // Ret
        return(0);
}