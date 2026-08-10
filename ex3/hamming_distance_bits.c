#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
    int data[100], hamming[100], received[100];
    int m, r = 0, totalBits;
    int i, j, k, parity, errorPos = 0;

    printf("HAMMING CODE - SINGLE BIT ERROR CORRECTION\n");

    // Read number of data bits
    printf("\nEnter number of data bits: ");
    scanf("%d", &m);

    printf("Enter the data bits:\n");
   // for(i = 1; i <= m; i++)
     //   scanf("%d", &data[i]);
    for(i = 1; i <= m; i++){
            scanf("%d", &data[i]);
            if(data[i] != 0 && data[i] != 1){
                    printf("\nInvalid input! Enter only 0 or 1.\n");
                    return 0;
            }
    }

    // Step 1: Calculate number of parity bits
    while(pow(2, r) < (m + r + 1))
        r++;

    totalBits = m + r;

    printf("\nNumber of parity bits = %d", r);
    printf("\nTotal bits = %d\n", totalBits);

    // Step 2: Place data bits and parity positions
    j = 1;
    for(i = 1; i <= totalBits; i++)
    {
        if((i & (i - 1)) == 0)      // Power of 2
            hamming[i] = 0;
        else
            hamming[i] = data[j++];
    }

    // Step 3: Calculate parity bits
    for(i = 0; i < r; i++)
    {
        int pos = pow(2, i);
        parity = 0;

        for(j = 1; j <= totalBits; j++)
        {
            if(j & pos)
                parity ^= hamming[j];
        }

        hamming[pos] = parity;
    }

    printf("\nGenerated Hamming Code:\n");
    for(i = 1; i <= totalBits; i++)
        printf("%d ", hamming[i]);

    // Step 4: Simulate error
    for(i = 1; i <= totalBits; i++)
        received[i] = hamming[i];

    srand(time(NULL));
    int randomBit = rand() % totalBits + 1;

    received[randomBit] ^= 1;

    printf("\n\nBit %d is flipped during transmission.\n", randomBit);

    printf("Received Code:\n");
    for(i = 1; i <= totalBits; i++)
        printf("%d ", received[i]);

    // Step 5: Calculate syndrome
    printf("\n\nSyndrome Calculation:");

    errorPos = 0;

    for(i = 0; i < r; i++)
    {
        int pos = pow(2, i);
        parity = 0;

        for(j = 1; j <= totalBits; j++)
        {
            if(j & pos)
                parity ^= received[j];
        }

        printf("\nP%d = %d", pos, parity);

        if(parity)
            errorPos += pos;
    }

    printf("\n\nSyndrome Value = %d", errorPos);

    // Step 6: Correct error
    if(errorPos == 0)
    {
        printf("\nNo Error Detected.\n");
    }
    else
    {
        printf("\nError detected at bit position %d", errorPos);

        received[errorPos] ^= 1;

        printf("\nCorrected Hamming Code:\n");
        for(i = 1; i <= totalBits; i++)
            printf("%d ", received[i]);
    }

    // Step 7: Recover original data
    printf("\n\nRecovered Data:\n");

    for(i = 1; i <= totalBits; i++)
    {
        if((i & (i - 1)) != 0)
            printf("%d ", received[i]);
    }

    printf("\n");

    return 0;
}
