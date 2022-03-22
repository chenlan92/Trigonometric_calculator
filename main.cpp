#include "stdio.h" 
#include "stdlib.h"   

#include "sct.h"


using namespace std; 
 
int main()
{

	printf("%lf \n", t_sin(1.57));//调取sct.h中t_sin函数计算正弦函数值 
	printf("%lf \n", t_cos(0.52));	 
    printf("%lf \n", t_tan(3.14));
    printf("%lf \n", t_sec(3.14));	 
	printf("%lf \n", t_csc(1.57));
	printf("%lf \n", t_cot(1.57));
	printf("%lf \n", deg2rad(30));
	printf("%lf \n", rad2deg(1.57));
    
	return 0;
}
