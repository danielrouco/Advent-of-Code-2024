#include <stdio.h>

int safe(int report[]){
    int safe = 1;
    int abs_distance;
    int real_distance;
    int ascendent = -1;
    int level_n = 0;
    while(report[level_n + 1] != -1 && safe){
        abs_distance = report[level_n] - report[level_n + 1];
        real_distance = abs_distance;
        if(abs_distance < 0){
            abs_distance *= -1;
        }

        if(abs_distance < 1 || abs_distance > 3){
            safe = 0;
        }else if(ascendent == -1){
            if(real_distance < 0){
                ascendent = 1;
            }else{
                ascendent = 0;
            } 
        }else if(ascendent && real_distance > 0){
            safe = 0;
        }else if(!ascendent && real_distance < 0){
            safe = 0;
        }
        level_n++;
    }
    return safe;
}

int main(){
    //Input
    int reports[1000][20];
    int buffer;
    char next_char;
    int report_n = 0;
    int level_n = 0;
    for(int i = 0; scanf("%d%c",&buffer, &next_char) != EOF; i++){
        reports[report_n][level_n] = buffer;
        if(next_char == '\n'){
            reports[report_n][level_n + 1] = -1;
            report_n++;
            level_n = 0;
        }else{
            level_n++;
        }
    }
    reports[report_n][level_n] = -1;
    int reports_length = report_n + 1;
    
    report_n = 0;
    int safe_reports = 0;
    for(; report_n < reports_length; report_n++){
        safe_reports += safe(&reports[report_n][0]);
    }
    printf("There are %d safe reports\n", safe_reports);
}