#include<stdio.h>

int maxRepeating(int* arr, int n, int k)
{
	 for (int i = 0; i< n; i++)
	 {
        	arr[arr[i]%k] += k;
		printf("%d\n",arr[i]);
	 }
	int max = arr[0], result = 0; 
    	for (int i = 1; i < n; i++) 
    	{ 
        	if (arr[i] > max) 
        	{ 
        	    max = arr[i]; 
            	    result = i; 
        	} 
    	}
	return result;
}

int main()
{
    int arr[] = {2, 5, 3, 5, 3, 5, 5, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 8;

    printf("Max number of repeating number = %d\n",maxRepeating(arr, n, k));

    return 0;
}
