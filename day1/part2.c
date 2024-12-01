#include <stdio.h>

int includes(int array[], int length, int n){
    int times = 0;
    for(int i = 0; i < length; i++){
        if(array[i] == n){
            times++;
        } 
    }
    return times;
}

int main(){
    //Input
    int groups[2][1000];
    int i; 
    for(i = 0; i < 1000 && scanf("%d %d", &groups[0][i], &groups[1][i]) != EOF; i++){}

    int sum = 0;
    for(int j = 0; j < i; j++){
        sum += groups[0][j] * includes(&groups[1][0], i, groups[0][j]);
    }
    printf("%d\n", sum);
}