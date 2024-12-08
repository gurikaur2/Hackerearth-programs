#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to convert a string to lowercase
void toLowerCase(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to check if a keyword exists in a comment
int containsKeyword(char* comment, char* keyword) {
    char lowerComment[1001], lowerKeyword[101];
    strcpy(lowerComment, comment);
    strcpy(lowerKeyword, keyword);
    toLowerCase(lowerComment);
    toLowerCase(lowerKeyword);

    return strstr(lowerComment, lowerKeyword) != NULL;
}

// Solution function
int solution(int N, char* S, char** comments) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (containsKeyword(comments[i], S)) {
            count++;
        }
    }
    return count;
}

int main() {
    int N;
    printf("Enter the number of comments: ");
    scanf("%d", &N);

    char S[101];
    printf("Enter the keyword to search for: ");
    scanf("%s", S);

    char comments[N][1001];
    printf("Enter the comments:\n");
    for (int i = 0; i < N; i++) {
        scanf(" %[^\n]", comments[i]);
    }

    // Call solution
    char* commentPtrs[N];
    for (int i = 0; i < N; i++) {
        commentPtrs[i] = comments[i];
    }
    int result = solution(N, S, commentPtrs);

    printf("The count of comments containing the keyword is: %d\n", result);
    return 0;
}