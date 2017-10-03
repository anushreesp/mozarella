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
int n, m, count=0;

n = strlen(txt);
m = strlen(path);

printf("Length of txt is %d", n);

for(i=0; i < (n-m); i ++) {
	for(j=0; j < m; j++) {
		if(txt[i] == path[j]) {
			count++;
		if(count == m) {
			printf("Match found at index %d\n", i);
			count = 0;
		}
		}
	}
}
}
