#include<stdio.h>
#define MAX 100
int data[MAX],stuffed[MAX],frame[MAX];
int main(){
    int n,i,j=0,k=0,ones=0,stuffedLen,frameLen;
    int flag[]={0,1,1,1,1,1,1,0};
    int flagLen=8;
    printf("Enter the number of bits: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the bit %d : ",i+1);
        scanf("%d",&data[i]);
    }
    for(i=0;i<n;i++){ //Bit Stuffing
        stuffed[j++]=data[i];
        if(data[i]==1){
            ones++;
        }
        else{
            ones=0;
        }
        if(ones==5){
        stuffed[j++]=0;
        ones=0;
        }
    }
    stuffedLen=j;
    for(i=0;i<flagLen;i++){
        frame[k++]=flag[i];
    }
    for(j=0;j<stuffedLen;j++){
        frame[k++]=stuffed[j];
    }
    for(i=0;i<flagLen;i++){
        frame[k++]=flag[i];
    }
    frameLen=k;
    printf("Original Data: ");
    for(i=0;i<n;i++){
        printf("%d",data[i]);
    }
    printf("\n");
    printf("Stuffed Data: ");
    for(j=0;j<stuffedLen;j++){
        printf("%d",stuffed[j]);
    }
    printf("\n");
    printf("Framed Data: ");
    for(k=0;k<frameLen;k++){
       printf("%d",frame[k]);
    }
    return 0;
}
