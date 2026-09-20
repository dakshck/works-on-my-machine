#include <stdio.h>
#include <stdlib.h>

int main() {
	char *temp;
	char *strptr;

	temp = calloc(6, sizeof(char));

	if(temp == NULL) {
		printf("ERROR: initial allocation failed\n");
		return -1;
	}
	else{
		strptr = temp;
		temp = NULL;
	}
	
	*strptr = 'd';
	*(strptr + 1) = 'a';
	*(strptr + 2) = 'k';
	*(strptr + 3) = 's';
	*(strptr + 4) = 'h';
	*(strptr + 5) = '\0';

	for(int i = 0; i < 5; i++) {
		printf("%c", *(strptr + i));
	}

	printf("\n");

	*strptr = 'D';
        *(strptr + 1) = 'A';
        *(strptr + 2) = 'K';
        *(strptr + 3) = 'S';
        *(strptr + 4) = 'H';

        for(int j = 0; j < 5; j++) {
                printf("%c", *(strptr + j));
        }
	printf("\n");

	free(strptr);
	strptr = NULL;
	
	return 0;

}
