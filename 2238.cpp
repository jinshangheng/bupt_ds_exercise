#include <stdio.h>
#include <stdlib.h>

int main(){
    int m, n;
    //init m, n
    int * nums1 = (int*)malloc((m+n)*sizeof(int));
    int * nums2 = (int*)malloc(n*sizeof(int));
    //init linear-list nums1, nums2

    scanf("%d%d", &m, &n);
    //input m, n
    for(int i = 0; i < m + n; i++){
        scanf("%d",&nums1[i]);
    }
    //input nums1
    for(int i = 0; i < n; i++){
        scanf("%d",&nums2[i]);
    }
    //input nums2

    for(int k = m + n - 1, i = m - 1, j = n - 1; k > -1 && j > -1; k--){
        //k is the index of result
        //i is the index of nums1
        //j is the index of nums2

        if(i == -1 || nums1[i] <= nums2[j]){
            //test -1 in case of nums1(m part) is empty
            nums1[k] = nums2[j--];
        }else{
            nums1[k] = nums1[i--];
        }
    }
    //merge nums2 to nums1

    for(int i = 0; i < m + n; i++){
        printf("%d ", nums1[i]);
    }
    //output
    return 0;
}