#include <stdio.h>
#include <math.h>

void reset(int arr[2][3]){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            arr[i][j] = -1;
        }
    }
}

int number(int num[3]){
    int result = 0;
    for(int i = 0; i < 3; i++){
        if(num[i] != -1){
            result += num[i] * pow(10, 2 - i);
        }
    }
    for(int i = 1; i < 3; i++){
        if(num[i] == -1){
            result /= 10;
        }
    }
    return result;
}

int is_digit(char character){
    if(character - 48 >= 0 && character - 48 <= 9){
        return 1;
    }
    return 0;
}

int condition(int state, char character, int numbers[2][3], int *result){
    char string[] = " mul("; 
    if(state >= 1 && state <= 4 && character == string[state]){
        return ++state;
    }
    if(state >= 5 && state <= 7 && is_digit(character)){
        numbers[0][state - 5] = character - 48; 
        return ++state;
    }
    if(state >= 9 && state <= 11 && is_digit(character)){
        numbers[1][state - 9] = character - 48; 
        return ++state;
    }
    if((state >= 6 && state <= 8 && character == ',')){
        return 9;
    }
    if(state >= 10 && state <= 12 && character == ')'){
        //printf("%d * %d\n", number(&numbers[0][0]), number(&numbers[1][0]));
        *result += number(&numbers[0][0]) * number(&numbers[1][0]);
        reset(numbers);
        return 1;
    }
    reset(numbers);
    return 1;
}

int main(){
    int state = 1;
    char character = ' ';
    int numbers[2][3] = {{-1, -1, -1},{-1, -1, -1}};
    int result = 0;
    while(scanf("%c", &character) != EOF){
        state = condition(state, character, numbers, &result);
    }
    printf("%d\n", result);
}