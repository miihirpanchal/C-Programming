#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        /* code */
        printf("Please Provide The CommanLine Arguments.\n");
    }
    char *Operation;
    int num1, num2;

    Operation = argv[1];
    num1 = atoi(argv[2]); // Atoi Changes A String Into A Number.
    num2 = atoi(argv[3]);

    printf("Operation Is %s\n", argv[1]);
    printf("Num 1 Is %d\n", num1);
    printf("Num 2 Is %d\n", num2);

    if (strcmp(Operation, "add") == 0)
    {
        printf("The Operation {{%s}} Is %d\n", Operation, num1 + num2);
    }

    else if (strcmp(Operation, "subtract") == 0)
    {
        printf("The Operation {{%s}} Is %d\n", Operation, num1 - num2);
    }

    else if (strcmp(Operation, "multiply") == 0)
    {
        printf("The Operation {{%s}} Is %d\n", Operation, num1 * num2);
    }

    else if (strcmp(Operation, "div") == 0)
    {
        printf("The Operation {{%s}} Is %d\n", Operation, num1 / num2);
    }
    else
    {
        printf("Please Enter A Valid Statement.\n");
    }

    return 0;
}
