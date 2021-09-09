#include<stdio.h> 
int main() { 
    int q[20], ref[50], c = 0, c1, d, frames, i, j, k = 0, pages, r, t, b[20], c2[20]; 

    printf("Enter the no of pages: "); 
    scanf("%d", &pages); 

    printf("Enter reference string: "); 
    for(i = 0; i < pages; i++) { 
        scanf("%d", &ref[i]); 
    } 
    printf("Enter the no of frames: "); 
    scanf("%d", &frames); 
    q[k] = ref[k];                          //take reference pages one by one into frames. 
    printf("\n\t%d\n", q[k]); 
    c++;                                    //incrememnt page fault whenever a new frame is taken.
    k++;                                    //first page is just taken as frames are empty and page fault will occur
    for(i = 1; i < pages; i++) { 
        c1 = 0; 
        for(j = 0; j < frames; j++) {       // if next ref page is not present in frame, page fault
            if(ref[i] != q[j]) { 
                c1++; 
            } 
        } 
        if(c1 == frames) {                  // if all frames dont match with reference page
            c++; 
            if(k < frames) {                // if frames not full, just add new frame and increment page fault
                q[k] = ref[i]; 
                k++; 
                for(j = 0; j < k; j++) 
                    printf("\t%d", q[j]); 
                printf("\n"); 
            } 
            else {                              // if frames full we need to replace
                for(r = 0; r < frames; r++) { 
                    c2[r] = 0; 
                    for(j = i-1; j < pages; j--) {          // calculate which is the least used frame
                        if(q[r] != ref[j]) { 
                            c2[r]++; 
                        } 
                        else { 
                            break; 
                        } 
                    } 
                } 
                for(r = 0; r < frames; r++) { 
                    b[r] = c2[r];                               
                } 
                for(r = 0; r < frames; r++) {                  // traverse to least used frame and replace it
                    for(j = r; j < frames; j++) { 
                        if(b[r] < b[j]) { 
                            t = b[r]; 
                            b[r] = b[j]; 
                            b[j] = t; 
                        } 
                    } 
                } 
                for(r = 0; r < frames; r++) { 
                    if(c2[r] == b[0]) 
                        q[r] = ref[i]; 
                    printf("\t%d", q[r]); 
                } 
                printf("\n"); 
            } 
        } 
    } 
    printf("\nThe no of page faults is %d",c); 
    return 0; 
}
