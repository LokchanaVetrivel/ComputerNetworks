#include<stdio.h>
#include <string.h>
#define MAX 1000
int data[MAX], stuffed[MAX], frame[MAX], destuffed[MAX];
void charToBits(char c, int *arr, int start) {
    int i;
    for (i = 7; i >= 0; i--) {
        arr[start + i] = c & 1;
        c >>= 1;
    }
}
char bitsToChar(int *arr, int start) {
    char c = 0;
    int i;
    for (i = 0; i < 8; i++) {
        c <<= 1;
        c |= arr[start + i];
    }
    return c;
}
int main() {
    char input[MAX], output[MAX];
    int n = 0; // total bits count
    int i, j = 0, k = 0, ones = 0;
    int stuffedLen, frameLen, destuffedLen = 0;
    int flag[] = {0, 1, 1, 1, 1, 1, 1, 0};
    int flagLen = 8;
    printf("Enter the string: ");
    fgets(input, MAX, stdin);
    input[strcspn(input, "\n")] = 0;
    int len = strlen(input);
    for (i = 0; i < len; i++) {
        charToBits(input[i], data, n);
        n += 8;
    }
    j = 0;
    ones = 0;
    for (i = 0; i < n; i++) {
        stuffed[j++] = data[i];
        if (data[i] == 1) {
            ones++;
        } else {
            ones = 0;
        }
        if (ones == 5) {
            stuffed[j++] = 0; // Stuff a 0 after five consecutive 1s
            ones = 0;
        }
    }
    stuffedLen = j;

    // Frame construction: flag + stuffed data + flag
    k = 0;
    for (i = 0; i < flagLen; i++) {
        frame[k++] = flag[i];
    }
    for (j = 0; j < stuffedLen; j++) {
        frame[k++] = stuffed[j];
    }
    for (i = 0; i < flagLen; i++) {
        frame[k++] = flag[i];
    }
    frameLen = k;

    // Print original string
    printf("Original String: %s\n", input);

    // Print original bits
    printf("Original Bits: ");
    for (i = 0; i < n; i++) {
        printf("%d", data[i]);
    }
    printf("\n");

    // Print stuffed bits
    printf("Stuffed Bits: ");
    for (j = 0; j < stuffedLen; j++) {
        printf("%d", stuffed[j]);
    }
    printf("\n");

    // Print framed bits
    printf("Framed Bits: ");
    for (k = 0; k < frameLen; k++) {
       printf("%d", frame[k]);
    }
    printf("\n");

    // --- Destuffing ---

    // Remove flags from frame (assuming flags at start and end)
    int start = flagLen;
    int end = frameLen - flagLen;

    ones = 0;
    destuffedLen = 0;
    for (i = start; i < end; i++) {
        if (frame[i] == 1) {
            ones++;
            destuffed[destuffedLen++] = 1;
            // Check if next bit is stuffed 0
            if (ones == 5) {
                i++; // skip stuffed 0
                ones = 0;
            }
        } else {
            ones = 0;
            destuffed[destuffedLen++] = 0;
        }
    }

    // Print destuffed bits
    printf("Destuffed Bits: ");
    for (i = 0; i < destuffedLen; i++) {
        printf("%d", destuffed[i]);
    }
    printf("\n");

    // Convert destuffed bits back to characters
    int outputLen = destuffedLen / 8;
    for (i = 0; i < outputLen; i++) {
        output[i] = bitsToChar(destuffed, i * 8);
    }
    output[outputLen] = '\0';

    // Print recovered string
    printf("Recovered String: %s\n", output);

    return 0;
}
