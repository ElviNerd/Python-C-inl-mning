##include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> // Include ctype.h for the tolower() function
#include "shapes.h"
#include "calculator.h"

void shapes_menu();
void calculator_menu();
void main_menu();
void to_lower(char *str); // Declare the to_lower() function

int main() {
    main_menu();
    return 0;
}

// Helper function to convert a string to lowercase
void to_lower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void main_menu() {
    char choice[20];

    while (1) {
        printf("\nWelcome! Choose an option:\n");
        printf("1. Shapes\n");
        printf("2. Calculator\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        fgets(choice, sizeof(choice), stdin);
        choice[strcspn(choice, "\n")] = '\0';
        to_lower(choice); // Convert the input to lowercase

        if (strcmp(choice, "shapes") == 0 || strcmp(choice, "1") == 0) {
            shapes_menu();
        } else if (strcmp(choice, "calculator") == 0 || strcmp(choice, "2") == 0) {
            calculator_menu();
        } else if (strcmp(choice, "exit") == 0 || strcmp(choice, "3") == 0) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
}

void shapes_menu() {
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
        to_lower(shape); // Convert the input to lowercase


        if (strcmp(choice, "shapes") == 0 || strcmp(choice, "1") == 0) {
            shapes_menu();
        } else if (strcmp(choice, "calculator") == 0 || strcmp(choice, "2") == 0) {
            calculator_menu();
        } else if (strcmp(choice, "exit") == 0 || strcmp(choice, "3") == 0) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
}
void shapes_menu() {
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

        if (strcmp(shape, "back") == 0) {
            break;
        }

        if (strcmp(shape, "Rectangle") == 0) {
            printf("Enter height and width separated by space: ");
            input_check = scanf("%lf %lf", &height, &width);
            if (input_check != 2 || height <= 0 || width <= 0) {
                printf("Invalid input. Please try again.\n");
            } else {
                printf("Area: %.2lf\n", rectangle_area(height, width));
                printf("Perimeter: %.2lf\n", rectangle_perimeter(height, width));
            }
        } else if (strcmp(shape, "Parallelogram") == 0) {
            printf("Enter base, height, and side separated by space: ");
            input_check = scanf("%lf %lf %lf", &base, &height, &side);
            if (input_check != 3 || base <= 0 || height <= 0 || side <= 0) {
                printf("Invalid input. Please try again.\n");
            } else {
                printf("Area: %.2lf\n", parallelogram_area(base, height));
                printf("Perimeter: %.2lf\n", parallelogram_perimeter(base, side));
            }
        } else if (strcmp(shape, "Triangle") == 0) {
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
            } else if (strcmp(shape, "Circle") == 0) {
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
            // Clear input buffer
            while ((getchar()) != '\n');
            }
            }

            void calculator_menu() {
            char input[50], operator[2];
            double a, b;
            int input_check;
            while (1) {
            printf("\nEnter two numbers and an operator (+, -, *, /, %%) separated by space, or type 'back' to return to the main menu: ");
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = '\0';

            if (strcmp(input, "back") == 0) {
                break;
            }

            input_check = sscanf(input, "%lf %lf %s", &a, &b, operator);

            if (input_check != 3) {
                printf("Invalid input. Please try again.\n");
            } else if (strcmp(operator, "+") == 0) {
                printf("Result: %.2lf\n", add(a, b));
            } else if (strcmp(operator, "-") == 0) {
                printf("Result: %.2lf\n", subtract(a, b));
            } else if (strcmp(operator, "*") == 0) {
                printf("Result: %.2lf\n", multiply(a, b));
            } else if (strcmp(operator, "/") == 0) {
                if (b == 0) {
                    printf("Error: Division by zero is not allowed.\n");
                } else {
                    printf("Result: %.2lf\n", divide(a, b));
                }
            } else if (strcmp(operator, "%%") == 0) {
                if ((int)b == 0) {
                    printf("Error: Division by zero is not allowed.\n");
                } else {
                    printf("Result: %.2lf\n", modulus(a, b));
                }
            } else {
                printf("Invalid operator. Please try again.\n");
            }
        }
    }