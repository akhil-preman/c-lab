#include <stdio.h>
#include <ctype.h>

char U[26] = {
    'a','b','c','d','e','f','g','h','i','j','k','l','m',
    'n','o','p','q','r','s','t','u','v','w','x','y','z'
};

char set1[26], set2[26];
int bit1[26], bit2[26], result[26];

// Initialize bit vectors and result array
void initializeSets()
{
    for (int i = 0; i < 26; i++)
    {
        bit1[i] = 0;
        bit2[i] = 0;
        result[i] = 0;
    }
}

// Build bit vector using only n elements
void bitvector(char set[], int bit[], int n)
{
    for (int j = 0; j < n; j++)
    {
        char c = tolower(set[j]);
        for (int k = 0; k < 26; k++)
        {
            if (c == U[k])
            {
                bit[k] = 1;
            }
        }
    }
}

void set_union(int A[26], int B[26])
{
    for (int i = 0; i < 26; i++)
        result[i] = A[i] | B[i];
}

void set_intersection(int A[26], int B[26])
{
    for (int i = 0; i < 26; i++)
        result[i] = A[i] & B[i];
}

void set_complement(int A[26])
{
    for (int i = 0; i < 26; i++)
    {
        if (A[i] == 0)
            result[i] = 1;
        else
            result[i] = 0;
    }
}

void set_difference(int A[26], int B[26])
{
    for (int i = 0; i < 26; i++)
    {
        if (A[i] == 1 && B[i] == 0)
            result[i] = 1;
        else
            result[i] = 0;
    }
}


void display_result_as_set()
{
    printf("Set form : { ");
    for (int i = 0; i < 26; i++)
    {
        if (result[i] == 1)
            printf("%c ", U[i]);
    }
    printf("}\n");
}

void display_bitvector(int bit[26])
{
    printf("Bit vector: ");
    for (int i = 0; i < 26; i++)
        printf("%d ", bit[i]);
    printf("\n");
}

int main()
{
    int n1, n2;
    initializeSets();

    printf("Enter number of elements in Set 1: ");
    scanf("%d", &n1);

    printf("Enter elements of Set 1:\n");
    for (int i = 0; i < n1; i++)
        scanf(" %c", &set1[i]);

    printf("Enter number of elements in Set 2: ");
    scanf("%d", &n2);

    printf("Enter elements of Set 2:\n");
    for (int i = 0; i < n2; i++)
        scanf(" %c", &set2[i]);

    // Use n1 and n2 in bitvector function
    bitvector(set1, bit1, n1);
    bitvector(set2, bit2, n2);

    int choice;
    do {
        printf("\n\n===== MENU =====\n");
        printf("1. Union (A ∪ B)\n");
        printf("2. Intersection (A ∩ B)\n");
        printf("3. Difference (A - B)\n");
        printf("4. Complement of Set 1\n");
        printf("5. Complement of Set 2\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                set_union(bit1, bit2);
                printf("\nResult: A ∪ B\n");
                break;

            case 2:
                set_intersection(bit1, bit2);
                printf("\nResult: A ∩ B\n");
                break;

            case 3:
                set_difference(bit1, bit2);
                printf("\nResult: A - B\n");
                break;

            case 4:
                set_complement(bit1);
                printf("\nResult: Complement of Set 1\n");
                break;

            case 5:
                set_complement(bit2);
                printf("\nResult: Complement of Set 2\n");
                break;

            case 6:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
                continue;
        }

        display_result_as_set();
        display_bitvector(result);

    } while (1);

    return 0;
}

