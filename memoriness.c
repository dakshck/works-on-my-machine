#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
	
int askQ(int size);

int main(void) {
	int *temp = calloc(3, sizeof(int));
	int *arrptr;

	int num = 0;
	int size = 0;
	int capacity = 3;
	int totalval = 0;

	if(temp == NULL) {
		printf("ERROR: Initial allocation failed\n");
		return -1;
	}
	else{
		arrptr = temp;
	}
	
	printf("How many numbers you have to enter: ");
	scanf("%d", &num);
	
	for(int i = 0; i < num; i++) {
		if(capacity == size) {
			temp = realloc(arrptr, sizeof(int) * (capacity + 3));
				
				if(temp == NULL) {
					printf("ERROR: reallocation failed\n");
					break;
				}
				else {
					arrptr = temp;
					capacity = capacity + 3;
					temp = NULL;
				}
			
			*(arrptr + i) = askQ(size);
			size++;
		}
		else{
			*(arrptr + i) = askQ(size);
			size++;
		}
	}
	printf("The numbers are: ");
		for(int j = 0; j < size; j++) {
			printf("%d ", *(arrptr + j));
		}
	printf("\n");
		for(int k = 0; k < size; k++) {
			totalval = totalval + *(arrptr + k);
		}
	printf("Total addition of array: %d\n", totalval);
	
	free(arrptr);
	arrptr = NULL;

	return 0;
}

int askQ(int size) {
	int answer = 0;
	printf("Enter number %d: ", (size + 1));
	scanf("%d", &answer);
	return answer;
}
