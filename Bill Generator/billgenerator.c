#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *ReplaceWord(const char *str, const char *OldWorld, const char *NewWord)
{
    char *ResultString;
    int i, count = 0;
    int NewWordLength = strlen(NewWord);
    int OldWordLength = strlen(OldWorld);

    // Now I'll Count The Number Of Times Old Occures In The String.

    for (i = 0; str[i] != '\0'; i++)

    {
        if (strstr(&str[i], OldWorld) == &str[i])
        {
            count++;
            i = i + OldWordLength - 1; // For Loop Will increment.
        }
    }
    // I'll Have To Make A New String To Replace The Old Word.
    ResultString = (char *)malloc(i + count * (NewWordLength - OldWordLength) + 1);

    i = 0;
    while (*str)
    {
        // Comparing The Substring.

        if (strstr(str, OldWorld) == str)
        {
            strcpy(&ResultString[i], NewWord);
            i += NewWordLength;
            str += OldWordLength;
        }
        else
        {
            ResultString[i] = *str;
            i += 1;
            str += 1;
        }
    }
    ResultString[i] = '\0';
    return ResultString;
}
int main()
{
    FILE *ptr = NULL;
    FILE *ptr2 = NULL;

    ptr = fopen("bill.txt", "r");
    ptr2 = fopen("genbill.txt", "w");
    char str[200];
    fgets(str, 200, ptr);
    printf("The Given Bill Template was %s\n", str);

    // Now Callling The Function I Made Above Then Give The New str.
    char *Newstr;
    Newstr = ReplaceWord(str, "{{name}}", "LEO");
    Newstr = ReplaceWord(Newstr, "{{item}}", "COFEE");
    Newstr = ReplaceWord(Newstr, "{{outlet}}", "COFEE SHOP");
    printf("The Actual Bill Generated Is- %s\n", Newstr);

    fprintf(ptr2, "%s", Newstr);

    fclose(ptr);
    fclose(ptr2);
    return 0;
}