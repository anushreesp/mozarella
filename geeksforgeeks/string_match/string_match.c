#include<stdio.h>
#include<string.h>

void search(char a[], char b[]);

int main() {

char txt[50]= "aaaaaaaaaabbbbbbbbbcccccccc";
char path[6]= "aaaa";;

search(path, txt);


}

void
search(char path[],char txt[]) {

int i, j=0;
int n, m;

n = strlen(txt);
m = strlen(path);

for(i=0; i <= (n-m); i ++) {
	for(j=0; j < m; j++) {
		if(txt[i+j] != path[j])
			break;
	}
	if(j == m) {
		printf("Match found at index %d\n", i);
	}
		
}
}
