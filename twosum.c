#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

int* findsum(int target, int* nums, int n) {
    int* answer = (int*)malloc(2 * sizeof(int));
    if(answer == NULL) { exit(2); }
    int i, j;
    long a, b;
    for(i = 0; i < n; i++) {
        a = nums[i];
        for(j = 0; j < n; j++) {
            b = nums[j];
            if(((a + b) == target) && (i != j)) {
                answer[0] = i;
                answer[1] = j;
                return answer;
            }
        }
    }
    return NULL;
}

int main(int argc, char* argv[]) {
    char tag[] = "[ main ]: ";
    if(argc < 4) {
        printf("\n%sUsage is: (TARGET, ELEMENT, ELEMENT...)\n", tag);
        printf("\n%sExiting...\n\n", tag);
        exit(1); 
    }

    const int target = strtol(argv[1], NULL, 0);
    printf("\n%sTarget is: %d\n\n%sArray is:\n", tag, target, tag);
    const int n = argc - 2;

    int nums[n]; 
    for(int i = 0; i < n; i++) {
        nums[i] = strtol(argv[i + 2], NULL, 0);
        printf("          nums[%d] = %d\n", i, nums[i]);
    }

    int* sols = findsum(target, nums, n);
    if(sols == NULL) { printf("\n%sReturned no indices.\n\n", tag); }
    else { printf("\n%sReturned indices: %d, %d.\n\n", tag, sols[0], sols[1]); }

    free(sols);
    return 0;
}
