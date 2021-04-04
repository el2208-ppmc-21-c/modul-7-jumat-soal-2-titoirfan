#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct StackNode
{
    char data;
    struct StackNode *next;
};

char pop(struct StackNode **root)
{
    struct StackNode *temp = *root;
    char popped = temp->data;
    *root = (*root)->next;
    free(temp);
    return popped;
}

char push(struct StackNode **root, char data)
{
    struct StackNode *new = (struct StackNode *)malloc(sizeof(struct StackNode));
    new->data = data;
    new->next = *root;
    *root = new;
}

int isOperand(char data)
{
    if (data == '*' || data == '+' || data == '/' || data == '-')
    {
        return 1;
    }
}

void intoPost(struct StackNode **root, char string[], char outString[])
{
    int length = strlen(string);
    // printf("Length: %d\n", length);
    int indexOut = 0;
    int found = 0;
    for (int i = 0; i < length; i++)
    {
        char temp = string[i];

        // DEBUGGING
        // printf("i: %d\n", i);
        // printf("temp: %c\n", temp);
        // printf("outIndex: %d\n", indexOut);
        found = 0;
        if (isOperand(temp) == 1)
        {
            // printf("OP\n");
            if (*root != NULL && (*root)->data != '(')
            {
                // printf("NULL\n");
                if ((*root)->data == '*' || (*root)->data == '/' && (temp == '*' && temp == '/')) // kalo prioritas temp sama root sama pop satu
                {
                    outString[indexOut] = pop(root);
                    indexOut++;
                }
                else if ((*root)->data == '*' || (*root)->data == '/') // kalo current lebih rendah dari root pop semua tapi gak sampe parentheses
                {
                    while (*root != NULL && isOperand((*root)->data) == 1)
                    {
                        outString[indexOut] = pop(root);
                        indexOut++;
                    }
                }
                else if (temp == '+' || temp == '-') // kalo current head sama sama rendah pop satu
                {

                    outString[indexOut] = pop(root);
                    indexOut++;
                }
            }
            push(root, temp);
        }

        else if (temp == '(')
        {
            push(root, temp);
        }

        else if (temp == ')')
        {
            while (!found)
            {
                char curr = pop(root);
                // printf("CURR: %c\n", curr);
                if (curr == '(')
                {
                    found = 1;
                }

                else
                {
                    outString[indexOut] = curr;
                    indexOut++;
                }
            }
        }

        else
        {
            // printf("TEMP: %c\n", temp);
            outString[indexOut] = temp;
            indexOut++;
        }
        // printf("STRING: %s\n", outString);
        if (*root != NULL)
        {
            // printf("ROOT: %c\n", (*root)->data);
        }
    }

    while (*root != NULL)
    {
        char curr = pop(root);
        outString[indexOut] = curr;
        indexOut++;
    }
}

int main()
{
    char input[50];
    char output[50];
    printf("Masukkan operasi: ");
    scanf("%s", input);

    struct StackNode *root = (struct StackNode *)malloc(sizeof(struct StackNode));
    root = NULL;

    intoPost(&root, input, output);

    printf("Postfix: %s\n", output);
}
