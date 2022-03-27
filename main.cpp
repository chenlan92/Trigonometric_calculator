#include "stdio.h" 
#include "stdlib.h"   

#include "sct.h"


using namespace std; 
 
int main()
{
    //调取sct.h中函数计算函数值
	printf("%lf \n", t_sin(1.22)); 
	printf("%lf \n", t_cos(0.52));	 
    printf("%lf \n", t_tan(3.14));
    printf("%lf \n", t_sec(3.14));	 
	printf("%lf \n", t_csc(1.57));
	printf("%lf \n", t_cot(1.57));
	printf("%lf \n", deg2rad(30));
	printf("%lf \n", rad2deg(1.57));
	printf("%lf\n", t_acos(0.99999988888887));
	printf("%lf\n", t_asin(0.1));
	printf("%lf\n", t_atan(20));
	//调取math.h中函数计算函数值
	printf("%lf \n", sin(1.22)); 
	printf("%lf \n", cos(0.52));	 
	printf("%lf \n", tan(3.14));
	printf("%lf\n", acos(0.99999988888887));
	printf("%lf\n", asin(0.1));
	printf("%lf\n", atan(20));     
	return 0;
}
