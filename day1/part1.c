#include <stdio.h>

void sort(int array[], int length){
    int ordered[length];
    int smallest; 
    int smallest_index;
    for(int i = 0; i < length; i++){
        smallest = array[0];
        smallest_index = 0;
        for(int j = 1; j < length; j++){
            if(array[j] < smallest){
                smallest = array[j];
                smallest_index = j;
            }
        }
        ordered[i] = smallest;
        array[smallest_index] = 1000000000;
    }
    for(int i = 0; i < length; i++){
        array[i] = ordered[i];
    }
}

int main(){
    int groups[2][1000];
    int i; 
    for(i = 0; i < 1000 && scanf("%d %d", &groups[0][i], &groups[1][i]) != EOF; i++){}
    sort(&groups[0][0], i);
    sort(&groups[1][0], i);
    int distance;
    int sum = 0;
    for(int j = 0; j < i; j++){
        distance = groups[0][j] - groups[1][j];
        if(distance < 0){
            distance *= -1;
        }
        sum += distance;
    }
    printf("%d\n", sum);
}