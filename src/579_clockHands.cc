#include <stdio.h>
#include <math.h>

double calAngle(double h, double m);

int main()
{
	char str[10] = {0};

	while( gets(str) != NULL )
	{
		int h, m;
		sscanf(str, "%d:%d", &h, &m);

		if(h == 0 && m == 0)
			break;

		double angle = calAngle(h, m);

		printf("%.3f\n", angle);

	}
	return 0;
}

double calAngle(double h, double m)
{
	double angle = fabs(30*h-5.5*m);

	if(angle > 180)
		angle = 360 - angle;

	return angle;
}