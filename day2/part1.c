#include <stdio.h>

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
    level_n = 0;
    int safe;
    int safe_reports = 0;
    int distance;
    int ascendent;
    for(; report_n < reports_length; report_n++){
        level_n = 0;
        safe = 1;
        ascendent = -1;
        while(reports[report_n][level_n] != -1 && safe){
            if(reports[report_n][level_n + 1] != -1){
                distance = reports[report_n][level_n] - reports[report_n][level_n + 1];
                if(distance < 0){
                    distance *= -1;
                }
                if(distance < 1 || distance > 3){
                    printf("Incorrect distance between %d and %d in line %d\n", reports[report_n][level_n], reports[report_n][level_n + 1], report_n + 1);
                    safe = 0;
                    continue;
                }
                if(ascendent == -1){
                    if(reports[report_n][level_n] - reports[report_n][level_n + 1] < 0){
                        ascendent = 1;
                    }else{
                        ascendent = 0;
                    } 
                }else if(ascendent && reports[report_n][level_n] - reports[report_n][level_n + 1] > 0){
                    printf("Expected greater than %d but found %d in line %d\n", reports[report_n][level_n], reports[report_n][level_n + 1], report_n + 1);
                   safe = 0;
                   continue; 
                }else if(!ascendent && reports[report_n][level_n] - reports[report_n][level_n + 1] < 0){
                    printf("Expected less than %d but found %d in line %d\n", reports[report_n][level_n], reports[report_n][level_n + 1], report_n + 1);
                    safe = 0;
                    continue;
                }
            }
            level_n++;
        }
        if(safe){
            safe_reports++;
        }
    }
    printf("\nThere are %d safe reports\n", safe_reports);
}