#include<stdio.h>
#include<string.h>
#define MAX 100
char data[MAX],stuffed[MAX],frame[MAX];
int main(){
    int i,j=0,k=0,stuffedLen,frameLen;
    printf("Enter the data: ");
    scanf("%s",data);
    int length=strlen(data);
    for(i=0;i<length;i++){
        if(data[i]=='F'||data[i]=='E'){
            stuffed[j]='E';
            j++;
            stuffed[j]=data[i];
            j++;
        }
        else{
            stuffed[j]=data[i];
            j++;
        }
    }
    stuffedLen=j;
    frame[k]='F';
    k++;
    for(j=0;j<stuffedLen;j++){
        frame[k++]=stuffed[j];
    }
    frame[k]='F';
    k++;
    frameLen=k;
    printf("Original Data: ");
    for(i=0;i<length;i++){
        printf("%c",data[i]);
    }
    printf("\n");
    printf("Stuffed Data: ");
    for(j=0;j<stuffedLen;j++){
        printf("%c",stuffed[j]);
    }
    printf("\n");
    printf("Framed Data: ");
    for(k=0;k<frameLen;k++){
       printf("%c",frame[k]);
    }
    return 0;
}
