#include "adevent_23.h"
/**
 * main - computes the sum of all of the calibration values.
 *
 * Return: Always 0.
 */
int main(void)
{
	int result = 0;
	FILE *input = NULL;
	size_t len_value = 0;
	char *line = NULL;

	input = fopen("0-input.txt", "r");
	if (!input)
	{
		dprintf(STDERR_FILENO, "Error: Can't open input file\n");
		perror("0-input.txt");
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &len_value, input) != -1)
	{
		result += compute_line(line);
		/*printf("line: %ssum: %d\n\n", line, result);*/
	}
	printf("The sum of all calibration values is: %d\n", result);
	fclose(input);
	free(line);
	return (0);
}
/**
 * compute_line - computes the sum of the first and last digits in @line.
 * @line: line contains the values.
 *
 * Return: The sum on success otherwise 0.
 */
int compute_line(char *line)
{
	int first = 0, last = 0, number = 0;
	char n = '1';

	while (*line)
	{
		if (_isdigit(*line))
		{
		if (n == '1')
		{
			/* Convert chars to digits '\0' => 48*/
			first = *line - 48;
			n = '2';
		}
		last = *line - 48;
		}
		line++;
	}
	number = (first * 10) + last;
	/*printf("first digit: %d\nlast digit: %d\nnumber: %d\n", first, last, number);*/
	return (number);
}
/**
 * _isdigit - checks if a character is a digit.
 * @c: character.
 *
 * Return: 1 if c is a digit, otherwise 0.
 */
int _isdigit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
