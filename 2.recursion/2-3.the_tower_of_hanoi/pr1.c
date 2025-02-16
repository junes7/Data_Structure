#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    char croaAlpha[8][4] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="}, s[101];
    scanf("%s", s);
    int cnt = 0, len = strlen(s), allen;
    bool flag;
    while (1) {
        for (int i = 0; i < 8; i++) {
            if (strstr(s, croaAlpha[i]) != NULL) {
                allen = strlen(croaAlpha[i]);
                flag = false;
                for (int j = 0; j < len - 1; j++) {
                    if (croaAlpha[i][0] == s[j] && croaAlpha[i][1] == s[j + 1]) {
                        for (int k = j; k < j + allen; k++) {
                            s[k] = 32;
                        }
                        cnt += 1;
                        flag = true;
                        break;
                    }
                }
                if (flag)
                    break;
            }
        }
        flag = true;
        for (int i = 0; i < 8; i++) {
            if (strstr(s, croaAlpha[i]) != NULL) {
                flag = false;
                break;
            }
        }
        if (flag)
            break;
    }
    for (int i = 0; i < len; i++) {
        if (isalpha(s[i])) {
            if (s[i] == 'd' && s[i + 1] == 'z' || (s[i] == 'n' || s[i] == 'l' && s[i + 1] == 'j')) {
                i += 1;
            }
            cnt += 1;
        }
    }
    printf("%d", cnt);
    return 0;
}