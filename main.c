#include <stdio.h>

#define ADDITIONAL_PRECISION 100

struct calculator
{
	long desired_decimal_digits;
	long desired_binary_digits;
	long real_binary_digits;
	long buffer_size;
} typedef calculator;

int main(int argc, char* argv[])
{
	calculator calc;

	//getting the desired precision from the user
	printf("Welcome to the PI calculator made by the totally awesome T3V\n");
	printf("How many decimal digits do you want to have calculated? ");
	scanf("%lu", &calc.desired_decimal_digits);
	calc.desired_binary_digits = (long)((float)calc.desired_decimal_digits * 3.4f);
	printf("%lu decimal digits will be caluclated and %lu binary ones\n",
		calc.desired_decimal_digits,
		calc.desired_binary_digits);

	calc.real_binary_digits=calc.desired_binary_digits + ADDITIONAL_PRECISION;
	int modulo=calc.real_binary_digits%8;
	if(modulo != 0)
	{
		calc.real_binary_digits+=(8 - modulo);
	}
	calc.buffer_size=calc.real_binary_digits/8;
	printf("BUFFER: %lu bytes\n", calc.buffer_size);

	return 0;
}