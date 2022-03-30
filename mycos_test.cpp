#include<stdio.h>
#include<math.h>
double mycos(double x)
{
	int n;
	int sign;
	double deno, nume, term;
	double sum;
	sum = 1;
	nume = x*x;
	deno = 2;
	term =-nume / deno;
	sign = -1;
	n = 2;
	while (fabs(term) >= 1e-3)
	{
		sum += term;
		n += 2;
		sign = -sign;
		nume *= x*x;
		deno *= n*(n - 1);
		term = sign*nume / deno;
	}
	return sum;
}
double cosrandian(double x)
{
	double sum;
	x=x*3.1415/180;
	sum = mycos(x);
	return sum;
}
int main()
{
	double x;
	int chose;
	printf("Please 请选择输入的量 角度选择1 弧度选择2  \r\n");
	scanf("%d", &chose);
    switch(chose)
    {
       case 1:
        printf("请输入角度值 \r\n");
        scanf("%lf", &x);
        printf("cosx=%.3lf\n", cosrandian(x));
        break;
       case 2:
        printf("请输入弧度值 \r\n");
        scanf("%lf", &x);
        printf("cosx=%.3lf\n", mycos(x));
        break;
       default:
        printf("error \r\n");
        break;
    }
	return 0;
}

