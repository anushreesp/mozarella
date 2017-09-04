#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int* findTheBug(int grid_size, char** grid, int *result_size){
    int i;
    *result_size = 2;
    int *result = (int*) malloc(sizeof(int) * 2);
    char find = 'X';
    for(i=0; i< grid_size; i++) {
        if((strstr(grid[i], "X")))
            break;;
    }
    
 
  result[0] = i;
    const char *ptr = strchr(grid[i], find);
    if(ptr) {
    int index = ptr - grid[i];
    result[1] = index;
     }
 return result;       
}

int main() {
    int n; 
    printf("Enter n:\n");
    scanf("%d", &n);
    char* *grid = malloc(sizeof(char*) * n);
    for(int grid_i = 0; grid_i < n; grid_i++){
       grid[grid_i] = (char *)malloc(10240 * sizeof(char));
       scanf("%s",grid[grid_i]);
    }
    // Return an array containing [r, c]
    int result_size;
    int* result = findTheBug(n, grid, &result_size);
    for(int result_i = 0; result_i < result_size; result_i++) {
        if(result_i) {
            printf(",");
        }
        printf("%d", result[result_i]);
    }
    puts("");
    

    return 0;
}



