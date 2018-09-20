int g;

int main()
{
	static int a, b, c, rv;

	a = 4;
	b = 3;

	a++;

	g = sum(a, b, 1, 2);

	rv = g;
}
