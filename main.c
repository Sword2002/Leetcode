///
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define INT_MAX_DIV10 214748364
#define INT_MAX_LAST 7
#define INT_MIN_DIV10 -214748364
#define INT_MIN_LAST -8

bool IsOverInt(int ret, int remain);

char* reverseWords(char* s){

}


int main(void) {
    char *token;
    char s[24] = "   we are   familly    ";
    char **strbuf = (char **)malloc(sizeof(char *));
    int idex = 0;
    token = strtok(s, " ");
    while (token != NULL) {
        //printf("%s\n", token);
        strbuf[idex++] = token;
        strbuf = realloc(strbuf, sizeof(char *) * (idex + 1));
        token = strtok(NULL, " ");
    }

    for (int i = 0; i < idex; i++) {
        printf("%s\n", strbuf[i]);
    }

    if (IsOverInt(INT_MAX_DIV10, INT_MAX_LAST)) {
        printf("超过范围1\n");
    }

    if (IsOverInt(INT_MIN_DIV10, INT_MIN_LAST)) {
        printf("超过范围2\n");
    }

    if (IsOverInt(INT_MAX_DIV10, INT_MAX_LAST + 1)) {
        printf("超过范围3\n");
    }

    if (IsOverInt(INT_MIN_DIV10, INT_MIN_LAST - 1)) {
        printf("超过范围4\n");
    }


    printf("main run end\n");
    return 0;
}

// 判断整数是否会超出int 32位范围
bool IsOverInt(int ret, int remain)
{
    if ((ret < INT_MIN_DIV10 && remain != 0) || 
        (ret == INT_MIN_DIV10 && remain < INT_MIN_LAST) ||
        (ret > INT_MAX_DIV10 && remain != 0) || 
        (ret == INT_MAX_DIV10 && remain > INT_MAX_LAST)) {
            return true;
    }

    return false;
}


