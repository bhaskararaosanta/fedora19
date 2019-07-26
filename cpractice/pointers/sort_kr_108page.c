#include<stdio.h>
#include<string.h>

#define	MAXLINES	5000	/* max lines to be sorted */

char *lineptr[MAXLINES];	/* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelinescustom(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

/* sort input lines */
int main()
{
	int nlines;	/* number of input lines read */

	if((nlines = readlines(lineptr, MAXLINES)) >= 0)
	{
		qsort(lineptr, 0, nlines-1);
		writelinescustom(lineptr, nlines);
		return 0;
	}
	else
	{
		printf("Error: input too big to sort\n");
		return 1;
	}
}

#define	MAXLEN	1000	/* max length of any input line */
int getlinecustom(char *, int);
char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while((len = getlinecustom(line, MAXLEN)) > 0)
		if(nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else
		{
			line[len-1] = '\0'; /* delete new line */
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

/* writelines: write output lines */
void writelinescustom(char *lineptr[], int nlines)
{
	int i;
	for(i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
	int i, last;
	void swap(char *v[], int i, int j);
	if(left >= right)	/* do nothing if array contains fewer than two elements */
		return;
	swap(v, left, (left + right)/2);
	last = left;
	for(i = left+1; i <= right; i++)
		if(strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
	char *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

#define	ALLOCSIZE	10000 /* size of available space */

static char allocbuf[ALLOCSIZE];	/* storage for alloc */
static char *allocp = allocbuf;		/* next free position */

char *alloc(int n)	/* return pointer to n characters */
{
	if(allocbuf + ALLOCSIZE - allocp >= n)	/* it  fits */
	{
		allocp += n;
		return allocp - n; /* old p */
	}
	else	/* not enough room */
	{
		return 0;
	}
}

/* getlinecustom: get line into s, return length */
int getlinecustom(char s[], int lim)
{
	int c, i;
	i = 0;
	while(--lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;
	if(c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}
