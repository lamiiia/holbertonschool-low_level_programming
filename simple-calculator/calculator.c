#include <stdio.h>

/**
 * main - simple calculator: add, subtract, multiply and divide
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char opt;
	int num1, num2;
	float result;

	printf(" Simple Calculator\n");
	printf(" 1) Add\n");
	printf(" 2) Subtract\n");
	printf(" 3) Multiply\n");
	printf(" 4) Divide\n");
	printf(" 0) Quit\n");
	printf(" Choose : ");
	scanf(" %c", &opt);

	if (opt == '0')
	{
		printf("Bye.\n");
		return (0);
	}
	if (opt < '1' || opt > '4')
	{
		printf(" Enter a valid option (0-4)\n");
		return (0);
	}

	printf("\n Enter the first number: ");
	scanf(" %d", &num1);
	printf("\n Enter the second number: ");
	scanf(" %d", &num2);

	switch (opt)
	{
	case '1':
		result = num1 + num2;
		printf(" Addition of %d and %d is: %.2f\n",
		       num1, num2, result);
		break;
	case '2':
		result = num1 - num2;
		printf(" Subtraction of %d and %d is: %.2f\n",
		       num1, num2, result);
		break;
	case '3':
		result = num1 * num2;
		printf(" Multiplication of %d and %d is: %.2f\n",
		       num1, num2, result);
		break;
	case '4':
		while (num2 == 0)
		{
			printf("\n Cannot divide by zero. Enter another: ");
			scanf(" %d", &num2);
		}
		result = (float)num1 / num2;
		printf(" Division of %d and %d is: %.2f\n",
		       num1, num2, result);
		break;
	}
	return (0);
}
