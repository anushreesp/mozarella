#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
	char* time = (char *)malloc(10240 * sizeof(char));
    	printf("Enter string:\n");
    	scanf("%s",time);
    	bool aflag =0;
        long split[10];
	char *ptr;
	long hours = 00;

    	if(strstr(time, "AM" ) != NULL) 
		aflag = 1;
    	else
		aflag = 0;
       
        split[0] = strtol(strtok(time, ":"), &ptr, 10);
	split[1] = strtol(strtok(NULL, ":"), &ptr, 10);
	split[2] = strtol(strtok(NULL, ":"), &ptr, 10);

	if(aflag) {
		if(split[0] != 12)
			printf("%ld:%ld:%ld\n", split[0],split[1], split[2]);
		else
			printf("%ld:%ld:%ld\n", hours ,split[1], split[2]);
	}
	else  {
			printf("%ld:%ld:%ld\n", split[0]+12, split[1], split[2]);  
}   
return 0;

}

