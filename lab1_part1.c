#include <stdio.h>
#include <stdlib.h>

#define Name "Vladislav"
#define LastName "Rokotianskiy"
#define GroupName "RS-51"
#define Faculty "RTF"
#define University "Igor Sikorsky KPI"

int main(void) {
    unsigned int semestr, age;
    float admissionScore;
    int grade1, grade2, grade3, grade4, grade5;
    double averageGrade;

    printf("%s %s, виконайте наступні дії.\n", Name, LastName);

    printf("Введіть номер семестру: ");
    if (scanf("%u", &semestr) != 1) return 1;

    printf("Введіть ваш вступний бал: ");
    if (scanf("%f", &admissionScore) != 1) return 1;

    printf("Введіть оцінку за предмет #1: "); scanf("%d", &grade1);
    printf("Введіть оцінку за предмет #2: "); scanf("%d", &grade2);
    printf("Введіть оцінку за предмет #3: "); scanf("%d", &grade3);
    printf("Введіть оцінку за предмет #4: "); scanf("%d", &grade4);
    printf("Введіть оцінку за предмет #5: "); scanf("%d", &grade5);

    printf("Введіть свій вік: ");
    if (scanf("%u", &age) != 1) return 1;

    averageGrade = (double)(grade1 + grade2 + grade3 + grade4 + grade5) / 5.0;

    system("cls"); /* або "clear" під Linux */

    for (int i = 0; i < 15; ++i) putchar('*');
    putchar('\n');
    for (int i = 0; i < 15; ++i) putchar('=');
    putchar('\n');

    printf("%s\n", University);
    printf("Faculty: %s\n", Faculty);
    printf("Group: %s\n", GroupName);
    printf("---------------------------\n");
    printf("student: %s %s\n", Name, LastName);
    printf("age: %u\n", age);
    printf("semestr: %u\n", semestr);
    printf("---------------------------\n");
    printf("admission score: %.1f\n", admissionScore);
    printf("average grade: %.2lf\n", averageGrade);

    return 0;
}