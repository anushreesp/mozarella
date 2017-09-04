#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

char* timeCompare(char* t1, char* t2){
    int t1_amflag=0;
    int t2_amflag=0;
    int h1 =0;
    int h2 =0;
    char *result = NULL;
    
    
    if(strstr(t1, "AM" ) != NULL)
        t1_amflag = 1;
    else if(strstr(t2, "AM") != NULL)
        t2_amflag = 1;
    
    if(t1_amflag && !t2_amflag) 
        result = "First";
    else if(t2_amflag && !t1_amflag)
        result = "Second";
    else if(!t2_amflag && !t1_amflag) {
        h1= atoi(strtok(t1, ":"));
        h2 = atoi(strtok(t2, ":"));
        if(h1>h2)
            result = "First";
        else 
            result = "Second";
    }
    return result;
}

int main() {
    int q; 
    scanf("%d", &q);
    for(int a0 = 0; a0 < q; a0++){
        char* t1 = (char *)malloc(512000 * sizeof(char));
        char* t2 = (char *)malloc(512000 * sizeof(char));
        scanf("%s %s", t1, t2);
        int result_size;
        char* result = timeCompare(t1, t2);
        printf("%s\n", result);
    }
    return 0;
}

