#include <stdio.h>

struct stud
{
    int number;
    char name[31];
};

int main(void)
{
    struct stud student;

    scanf("%d", &student.number);
    scanf("%s", student.name);

    printf ("%s: %d\n", student.name, student.number);

    return 0;
}
