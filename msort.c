#include "msort.h"
#include "student.h"
#include <stdio.h>

#ifndef OMIT_MSORT
void msort(Student * base, int nel, int (*compar)(const void *, const void *)) {
	
	//Base case: if the array has one or fewer elements, it's already sorted
	//so just return.
	if (nel <= 1){
		return;
	}

	//FILL IN
	
	//Inductive case: split the array in two, sort the two pieces with msort,
	//merge the	sorted pieces
		
	//We're going to do this without explicitly creating the two separate arrays
	//We'll take advantage of the fact that to C, an array is just a pointer to
	//a region of memory. If we call msort on base, but pass in a smaller number
	//of elements, it will sort just that subarray. Similarly, if we call msort
	//but pass in the address of an element in the middle of the array, it will
	//sort the array *starting* from that element.
		
	//1. Find the midpoint of the array

	//FILL IN	
	
	int twpe;
	twpe = nel/2;
	//2a. Sort the first half of the array (remember to adjust the # elements)

	//FILL IN
	
	msort(base, twpe, (compar));
	//2b. Sort the second half of the array. Pass in the address of the 
	//beginning of the second half of the array (remember to use the right # of 
	//elements)

	//FILL IN
	
	msort(&((base)[twpe]), nel - twpe, (compar));
	//3a. Merge the two arrays (use merge)

	//FILL IN
	Student * answer = merge(base, twpe, &base[twpe], (nel - twpe), (compar));
	//3b. Copy the merged array over top of the original array (use copy)
	//Don't forget to free the array you no longer need!

	//FILL IN
	copy(base, answer, nel);
	free(answer);
	return;
}
#endif

#ifndef OMIT_MERGE
Student * merge(Student * base1, int nel1, Student * base2, int nel2, int (*compar)(const void *, const void *)) {
	
	//1. Allocate space for the returned merged array
	Student * answer = malloc(sizeof(*answer) * (nel1 + nel2));	
	//FILL IN
	
	//2. Create indices to keep track of where you are in the three arrays
	int ltrack = 0, a1track=0, a2track=0;
	//FILL IN
	int swp;
	//3. Go through base1 and base2, and merge them into the returned array
	
	//FILL IN
	while(a1track < nel1 && a2track < nel2){
		swp = compar(&base1[a1track], &base2[a2track]);
		if(swp == 0){
			answer[ltrack++] = base1[a1track++];
			answer[ltrack++] = base2[a2track++];
		}else if(swp >= 1){
			answer[ltrack++] = base2[a2track++];
		}else{
			answer[ltrack++] = base1[a1track++];
		}
	}		

	if(a1track < nel1){
		for(a1track = a1track; a1track < nel1; a1track++){
			answer[ltrack++] = base1[a1track];
		}
	}
	if(a2track < nel2){
		for(a2track = a2track; a2track < nel2; a2track++){
			answer[ltrack++] = base2[a2track];
		}
	}
		
	//4. Return the merged array
	return(answer);
	//FILL IN

}


void copy(Student * to, Student * from, int nel) {
	/*
	An efficient implementation of this would use memcpy:
	memcpy(to, from, nel * width);

	We will do an element-by-element copy so you can see how it is done
	*/
	
	//loop over the from array and copy it byte by byte to the to array.
	for (int i = 0; i < nel; i++) {
		to[i] = from[i];
	}
	
	return;
}
#endif
