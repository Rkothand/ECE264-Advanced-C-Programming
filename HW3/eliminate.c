// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h> 

#ifdef TEST_ELIMINATE
// 100% of the score
void eliminate(int n, int k)
{
  // allocate an arry of n elements
	int * arr = malloc(sizeof(* arr) * n);
  // check whether memory allocation succeeds.
  // if allocation fails, stop
	if (arr == NULL)
    {
		fprintf(stderr, "malloc fail\n");
		return;
    }
	
  // initialize all elements
	for(int l=0; l<n; l++){
	 arr[l]=l;
	}

  
  // counting to k,
  	int count = 1;
  // mark the eliminated element
  // print the index of the marked element
  // repeat until only one element is unmarked
	
	int loop = n;
	while(loop>1){
		for (int i = 0; i < n; i++) {
			if (arr[i] == 'x'){
				arr[i]='y';
			}
		}	
		for (int i = 0; i < n; i++) {
			if (count == k&&(arr[i] != 'x' )&& (arr[i] != 'y')){
				arr[i] = 'x';
				printf("%i\n",i);
				loop--;
				count = 1;
			}
			else if ((arr[i] != 'x' )&& (arr[i] != 'y')){
				count++;
			}
		}
	}
	



  // print the last one
	for (int j = 0; j < n; j++) {
		if (arr[j] != 'x' && arr[j] != 'y') {
			printf("%i\n",j);
		}
	}


  // release the memory of the array
  free (arr);
}
#endif
