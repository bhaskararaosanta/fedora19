/* not allowed global register assignment register int u = 400; */

extern int b;

#define	BHASKAR	10000		/* it will not store in any memory segment and 
				 * directly attached to variable */

int r;				/* stores in bss segment */
int q = 200;			/* stores in data segment */
static int p;			/* stores in bss segment */	
static int n = 100;		/* stores in data segment */
int  main()
{
	int i = 10;		/* stores in stack segement */
	int j = 20;		/* stores in stack segment */
	static int k;		/* stores in bss segment */
	static int m = 10;	/* stores in data segment */
	register int s;		/* stores in register */
	register int t = 300;	/* stores in register */
	extern int a;
	
	return 0;
}
