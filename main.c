#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "shapes.h"
#include "calculator.h"


void shapesMenu();
void calculatorMenu();

// A helper function to convert a string to lowercase
void to_lower_string(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    int choice;
    char input[100];

    while (1) {
        printf("\nWelcome! Choose an option:\n");
        printf("1. Shapes\n");
        printf("2. Calculator\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        fgets(input, sizeof(input), stdin);
        to_lower_string(input);

        if (strstr(input, "shapes") || strstr(input, "shaps") || strcmp(input, "1\n") == 0) {
            choice = 1;
        } else if (strstr(input, "calculator") || strstr(input, "calculatr") || strcmp(input, "2\n") == 0) {
            choice = 2;
        } else if (strstr(input, "exit") || strcmp(input, "3\n") == 0) {
            choice = 3;
        } else {
            choice = -1;
        }

        switch (choice) {
            case 1:
                shapesMenu();
                break;
            case 2:
                calculatorMenu();
                break;
            case 3:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void shapesMenu() {
    char shape[20];
    double height, width, base, side, side1, side2, side3, radius;
    int input_check;

    while (1) {
        printf("\nChoose a shape or type 'back' to return to the main menu:\n");
        printf("Rectangle\n");
        printf("Parallelogram\n");
        printf("Triangle\n");
        printf("Circle\n");
        printf("Enter your choice: ");
        fgets(shape, sizeof(shape), stdin);
        shape[strcspn(shape, "\n")] = '\0';
        shape[0] = tolower(shape[0]);

        if (strcmp(shape, "back") == 0) {
            break;
        }

        if (strcmp(shape, "rectangle") == 0) {
            printf("Enter height and width separated by space: ");
            input_check = scanf("%lf %lf", &height, &width);
            if (input_check != 2 || height <= 0 || width <= 0) {
                printf("Sorry. Invalid input. Please try again.\n");
            } else {
                printf("Area or your shape is: %.2lf\n", rectangle_area(height, width));
                printf("Perimeter is: %.2lf\n", rectangle_perimeter(height, width));
            }
        } else if (strcmp(shape, "parallelogram") == 0) {
            printf("Enter base, height, and side separated by space: ");
            input_check = scanf("%lf %lf %lf", &base, &height, &side);
            if (input_check != 3 || base <= 0 || height <= 0
|| side <= 0) {
                printf("Invalid input. Please try again.\n");
            } else {
                printf("Area: %.2lf\n", parallelogram_area(base, height));
                printf("Perimeter: %.2lf\n", parallelogram_perimeter(base, side));
            }
        } else if (strcmp(shape, "triangle") == 0) {
            printf("Enter base, height, side1, side2, and side3 separated by space: ");
            input_check = scanf("%lf %lf %lf %lf %lf", &base, &height, &side1, &side2, &side3);
            if (input_check != 5 || base <= 0 || height <= 0 || side1 <= 0 || side2 <= 0 || side3 <= 0) {
                printf("Invalid input. Please try again.\n");
            } else if (side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1) {
                printf("Invalid triangle. The sum of any two sides must be greater than the third side.\n");
            } else {
                printf("Area: %.2lf\n", triangle_area(base, height));
                printf("Perimeter: %.2lf\n", triangle_perimeter(side1, side2, side3));
            }
        } else if (strcmp(shape, "circle") == 0) {
            printf("Enter radius: ");
            input_check = scanf("%lf", &radius);
            if (input_check != 1 || radius <= 0) {
                printf("Invalid input. Please try again.\n");
            } else {
                printf("Area: %.2lf\n", circle_area(radius));
                printf("Circumference: %.2lf\n", circle_circumference(radius));
            }
        } else {
            printf("Invalid choice. Please try again.\n");
        }
       
        while ((getchar()) != '\n');
    }
}

void calculatorMenu() {
    double a, b, result;
    char operator;
    char input[100];
    int ret;

    while (1) {
        printf("\nEnter two numbers and an operator (+, -, *, /, %%) separated by space, or type 'back' to return to the main menu: ");
        fgets(input, sizeof(input), stdin);

        if (strncmp(input, "back", 4) == 0) {
            return;
        }

        ret = sscanf(input, "%lf %lf %c", &a, &b, &operator);

        if (ret != 3) {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        switch (operator) {
            case '+':
                result = add(a, b);
                break;
            case '-':
                result = subtract(a, b);
                break;
            case '*':
                result = multiply(a, b);
                break;
            case '/':
                if (b == 0) {
                    printf("Division by zero is not allowed. Please try again.\n");
                    continue;
                }
                result = divide(a, b);
                break;
            case '%':
                result = modulus(a, b);
                break;
            default:
                printf("Invalid operator. Please try again.\n");
                continue;
        }

        printf("Result: %.2lf\n", result);
    }
}
