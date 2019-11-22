//longest palindromic substring
//manachers
#include<stdio.h>
#include<string.h>

int main()
{
	
	
	return 0;
}



//
char* longestPalindrome(char* A) {
    int len = strlen(A);
    if(len <= 1) {
        return A;
    }
    int maxLen = 0;
    int i = 0;
    int gLow = 0;
    int gHigh = 0;
    for(i=1;i<len;i++) {
        // for odd palindromes
        int low = i-1;
        int high = i+1;
        int tempLow = 0;
        int tempHigh = 0;
        while(low >= 0 && high < len && A[low] == A[high]) {
            tempLow = low;
            tempHigh = high;
            //printf("1 -> %d, %d: ", tempLow, tempHigh);
            low--;
            high++;
        }
        int tempMax = tempHigh - tempLow + 1;
        if(tempMax > maxLen) {
            maxLen = tempMax;
            gLow = tempLow;
            gHigh = tempHigh;
        }
        
        // for even palindromes
        low = i-1;
        high = i;
        while(low >= 0 && high < len && A[low] == A[high]) {
            tempLow = low;
            tempHigh = high;
            //printf("2 -> %d, %d: ", tempLow, tempHigh);
            low--;
            high++;
        }
        tempMax = tempHigh - tempLow + 1;
        if(tempMax > maxLen) {
            maxLen = tempMax;
            gLow = tempLow;
            gHigh = tempHigh;
        }
    }
    char* ans = (char*) malloc(maxLen*sizeof(char));
    for(i=0;i<maxLen;i++) {
        ans[i] = A[gLow + i];
    }
    ans[i] = '\0';
    return ans;
}
