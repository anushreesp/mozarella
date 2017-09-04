#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void removeSpace(char* str);

int main(){
    char* s = (char *)malloc(10240 * sizeof(char));
    printf("Enter your text\n");
    scanf("%s",s);
    
    removeSpace(s);
    printf("String after space removal is %s\n", s);
        
    
    return 0;
}

void removeSpace(char *str) {
    int count=0;
    for(int i=0; str[i]; i++) {
	if(str[i] != ' ') 
	   str[count++]= str[i];
    }
    str[count] = '\0';
   printf("RemoveSpace str is %s\n", str); 
}

