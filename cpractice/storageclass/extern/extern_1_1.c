/* declare link to variable defined in extern_1.c file */
extern int num;

/* declare link to function defined in extern_1.c file */
extern void display();

int main()
{
	/* accessing external variable */
	num = 5;

	/* accessing external function */
	display();

	return 0;
}
