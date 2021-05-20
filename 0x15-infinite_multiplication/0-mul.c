#include "holberton.h"

void putarray(int *buffer, int size);
void carryover(int *buffer, int size);
int *lit_mul(int *w1, int l1, int n, int *buffer, int size);
int *make_buffer(int l1, int l2);
int *big_mul(int *w1, int *w2, int l1, int l2);
void pr_int_arr(int *arr, int len);
int *ca_to_ia(char *word, int len);
int get_len(char *word);
void bad_exit(void);
/**
* main - multiplies two numbers
* Return: 0 or exit 98
* @argc: size of argv
* @argv: numbers to multiply
*/
int main(int argc, char *argv[])
{
	int l1, l2, *w1, *w2, *ret;

	if (argc != 3)
		bad_exit();
	l1 = get_len(argv[1]);
	l2 = get_len(argv[2]);
	w1 = ca_to_ia(argv[1], l1);
	w2 = ca_to_ia(argv[2], l2);
/*
*	pr_int_arr(w1, l1);
*	pr_int_arr(w2, l2);
*
*	printf("both arrays made\n");
*	printf("l1 %i, l2%i\n", l1, l2);
*/
	ret = big_mul(w1, w2, l1, l2);
/*	pr_int_arr(ret, (l1 + l2) * 1.5);*/
	putarray(ret, (l1 + l2) * 1.5);
	free(ret);
	free(w1);
	free(w2);
	exit(0);

	if (w1 && w2)
		_putchar('l');
	else
	{
		_putchar('i');
	}
	return (0);
}
/**
* putarray - print the array using putchar
* Return: void
* @buffer: the buffer to print
* @size: the size of the buffer to print
*/
void putarray(int *buffer, int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		if (buffer[i] != 0)
			break;
	}
	for (; i < size; i++)
	{
		_putchar(buffer[i] + '0');
	}
	_putchar('\n');
}
/**
* carryover - carry the tens place in int arr
* Return: void
* @buffer: the array
* @size: sizeof the buffer
*/
void carryover(int *buffer, int size)
{
	int i;

/*
*	printf("begin carryover\n");
*	pr_int_arr(buffer, size);
*/
	for (i = size - 1; i > 0; i--)
	{
		if (buffer[i] > 9)
		{
			buffer[i - 1] += buffer[i] / 10;
			buffer[i] = buffer[i] % 10;
		}
	}
/*
*	printf("end carryover\n");
*	pr_int_arr(buffer, size);
*/
}
/**
* lit_mul - mutiply array by one int
* Return: updated buffer
* @w1: the array to multiply
* @l1: length of array w1
* @n: the int to mutply with
* @buffer: where to store product
* @size: size of the buffer
*/
int *lit_mul(int *w1, int l1, int n, int *buffer, int size)
{
	int i, j;

	j = size - 1;
	for (i = l1 - 1; i >= 0; i--)
	{
/*		printf("in loop i %i j %i \n", i, j);*/
		buffer[j] += w1[i] * n;
		j--;
	}
/*	printf("finished loop in lit mul\n");*/
	carryover(buffer, size);
	return (buffer);
}
/**
* big_mul - multiple two int arrays
* Return: a big int array
* @w1: first int array
* @w2: second int arr
* @l1: len of first int arry
* @l2: len of second int arr
*/
int *big_mul(int *w1, int *w2, int l1, int l2)
{
	int *buffer, size, i, j = 0;

/*	printf("in big mul\n");*/
	size = (l1 + l2) * 1.5;
	buffer = make_buffer(l1, l2);

/*	printf("buffer made in big mul, calling lit mul\n");*/
	for (i = l2 - 1; i >= 0; i--)
	{
		buffer = lit_mul(w1, l1, w2[i], buffer, size - j);
		j++;
	}
/*
* for doing just one number
*	return (lit_mul(w1, l1, w2[l2 - 1], buffer, size));
*/
	return (buffer);
}
/**
* make_buffer - makes a large buffer full of 0
* Return: int array
* @l1: length of first array
* @l2: length of secodn array
*/
int *make_buffer(int l1, int l2)
{
	int size, i, *buffer;

/*	printf("in make buffer\n");*/
	size = (l1 + l2) * 1.5;
/*	printf("size if %i", size);*/
	buffer = malloc(size * sizeof(int));
	if (!buffer)
		bad_exit();
/*	printf("right after malloc in make buffer\n");*/
	for (i = 0; i < size; i++)
		buffer[i] = 0;
/*	pr_int_arr(buffer, size);*/
	return (buffer);
}
/**
* pr_int_arr - prints int array
* Return: void
* @arr: the array to print
* @len: length of it
*/
void pr_int_arr(int *arr, int len)
{
	int i;

	printf("printing array\n");
	for (i = 0; i < len; i++)
		printf("%i ", arr[i]);
	printf("done\n");
}
/**
* add_intas - add two int arrays, elementwise
* Return: the elementiwse sum of two int arrays
* @w1: first int* (also buffer)
* @w2: second int*
* @len1: length of first
* @len2: length of second
*/
int *add_intas(int *w1, int *w2, int len1, int len2)
{
	int maxlen, i, tmp = 0;

	maxlen = len1;
	if (len2 > maxlen)
		maxlen = len2;

	(void) i;
	(void) tmp;
	(void) w1;
	(void) w2;
	(void) len1;
	(void) len2;

	return (w1);
}

/**
* ca_to_ia - char array to int array
* Return: a new int array
* @word: the word to change (and check numbers)
* @len: the length of the c array
*/
int *ca_to_ia(char *word, int len)
{
	int *retval, counter;

	retval = malloc(len * sizeof(int));
	if (!retval)
		bad_exit();
	counter = len - 1;
	while (counter >= 0)
	{
		if (word[counter] < '0' || word[counter] > '9')
		{
			free(retval);
			bad_exit();
		}
		else
		{
			retval[counter] = word[counter] - 48;
/*			printf("in catoia %i\n", retval[counter]);*/
		}
		counter--;
	}

	return (retval);
}
/**
* get_len - get length of char *
* Return: int length
* @word: the number to check
*/
int get_len(char *word)
{
	int size;

	for (size = 0; word[size] != 0; size++)
		;
	return (size);
}
/**
* bad_exit - prints error message
* Return: void
*/
void bad_exit(void)
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
	exit(98);
}
