#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

char* timeCompare(char* t1, char* t2){
    // Complete this function
    int t1_amflag=0;
    int t2_amflag=0;
    char *result = (char *)malloc(12 * sizeof(char));
    int split1[10];
    int split2[10];
    char *ptr;
    result = "Same";
     
    if(!(strcmp(t1,t2)))
       return result;

    if(strstr(t1, "AM" ) != NULL)
        t1_amflag = 1;
    if(strstr(t2, "AM") != NULL)
        t2_amflag = 1;

    if(t1_amflag && !t2_amflag)
        result = "First";
    else if(t2_amflag && !t1_amflag)
        result = "Second";
    else if((!t2_amflag && !t1_amflag) || (t1_amflag && t2_amflag)) {
        split1[0] = strtol(strtok(t1, ":"), &ptr, 10);
        split1[1] = strtol(strtok(NULL, ":"), &ptr, 10);
        
        split2[0] = strtol(strtok(t2, ":"), &ptr, 10); //hours
        split2[1] = strtol(strtok(NULL, ":"), &ptr, 10); //minutes
        if(split1[0]== 12)
            split1[0]=0;
        if(split2[0]==12)
            split2[0]=0;
        printf("mins are %d %d", split1[1], split2[1]);    
        if(split1[0] < split2[0]) 
            result = "First";
        else if(split1[0] > split2[0])
            result = "Second";
        else if(split1[0] == split2[0]) {
            if(split1[1] < split2[1])
                result = "First";
            else
                result = "Second";
        }
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

