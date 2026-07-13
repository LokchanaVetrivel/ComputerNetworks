#include<stdio.h>
#include <string.h>
#define MAX 100

// Function to print bits of a character
void printBits(char c, int bitLength) {
    int i;
    for (i = bitLength - 1; i >= 0; i--) {
        printf("%d", (c >> i) & 1);
    }
}
int main() {
    char data[MAX], stuffed[MAX * 2], frame[MAX * 2], destuffed[MAX * 2];
    int i, j = 0, k = 0, stuffedLen, frameLen, destuffedLen = 0;

    printf("Enter the data: ");
    scanf("%s", data);

    int length = strlen(data);

    // Stuffing: escape 'F' and 'E' by prefixing 'E'
    for (i = 0; i < length; i++) {
        if (data[i] == 'F' || data[i] == 'E') {
            stuffed[j++] = 'E';
            stuffed[j++] = data[i];
        } else {
            stuffed[j++] = data[i];
        }
    }
    stuffedLen = j;

    // Framing: add 'F' at start and end
    frame[k++] = 'F';
    for (j = 0; j < stuffedLen; j++) {
        frame[k++] = stuffed[j];
    }
    frame[k++] = 'F';
    frameLen = k;

    // Print Original Data bits
    printf("Original Data bits:\n");
    for (i = 0; i < length; i++) {
        if (data[i] == 'F') {
            printf("01111110 ");
        } else if (data[i] == 'E') {
            printf("111000 ");
        } else {
            printBits(data[i], 8);
            printf(" ");
        }
    }
    printf("\n");

    // Print Stuffed Data and bits
    printf("Stuffed Data chars: ");
    for (j = 0; j < stuffedLen; j++) {
        printf("%c", stuffed[j]);
    }
    printf("\nStuffed Data bits: ");
    for (j = 0; j < stuffedLen; j++) {
        if (stuffed[j] == 'F') {
            printf("01111110 ");
        } else if (stuffed[j] == 'E') {
            printf("111000 ");
        } else {
            printBits(stuffed[j], 8);
            printf(" ");
        }
    }
    printf("\n");

    // Print Framed Data chars and bits
    printf("Framed Data chars: ");
    for (k = 0; k < frameLen; k++) {
        printf("%c", frame[k]);
    }
    printf("\nFramed Data bits: ");
    for (k = 0; k < frameLen; k++) {
        if (frame[k] == 'F') {
            printf("01111110 ");
        } else if (frame[k] == 'E') {
            printf("111000 ");
        } else {
            printBits(frame[k], 8);
            printf(" ");
        }
    }
    printf("\n");

    // --- Destuffing ---

    int start = 1, end = frameLen - 1;

    for (i = start; i < end; i++) {
        if (frame[i] == 'E') {
            i++;
            if (i < end) {
                destuffed[destuffedLen++] = frame[i];
            }
        } else {
            destuffed[destuffedLen++] = frame[i];
        }
    }

    // Print Destuffed Data bits
    printf("Destuffed Data bits:\n");
    for (i = 0; i < destuffedLen; i++) {
        if (destuffed[i] == 'F') {
            printf("01111110 ");
        } else if (destuffed[i] == 'E') {
            printf("111000 ");
        } else {
            printBits(destuffed[i], 8);
            printf(" ");
        }
    }
    printf("\n");

    // Print recovered string
    printf("Recovered String: ");
    for (i = 0; i < destuffedLen; i++) {
        printf("%c", destuffed[i]);
    }
    printf("\n");

    return 0;
}
