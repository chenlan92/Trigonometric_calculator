# Trigonometric_calculator
Chongqing University software Engineering course assignment
>1 程序简介  
    本程序实现了一个三角函数计算器，能够通过交互界面输入数值和计算指令，程序内部完成三角函数计算后在交互界面显示计算结果。  

>2 总体设计
>>2.1 交互模块
    界面输入：按键值
    界面输出：计算数值（结果）、数据类型、错误信息 
    交互面板按键：交互面板具有0-9数字按键、正负号按键、小数点按键、清零按键、退格按键、角度/弧度（数据类型）切换按键、sin、cos、arcsin、arctan三角函数按键
    交互面板显示：数据显示、数据类型显示、错误显示
    功能：根据按键输入进行响应，调用三角函数计算模块完成运算
    
>>2.2 sin函数计算模块
    输入：计算数值
    输出：计算结果
    功能：完成sin函数运算
    
>>2.3 cos函数计算模块
    输入：计算数值
    输出：计算结果
    功能：完成cos函数运算
    
>>2.4 arcsin函数计算模块
    输入：计算数值
    输出：计算结果
    功能：完成arcsin函数运算
    
>>2.5 arctan函数计算模块
    输入：计算数值
    输出：计算结果
    功能：完成arctan函数运算
    
>>3详细设计
>>3.1 UI设计与交互部分

1）	输入显示和输出结果显示。

2）	数字、小数点、正负符号、复位、删除、函数通过按键实现

3）	对于sin、cos函数，计算器输入单位为角度值，输入角度值后点击对应的函数按键，输出显示对应的结果值。

4）	对于arcsin、arctan函数，计算器输入值后点击对应的函数按键，输出显示对应的角度值，当输入值超出取值范围，输出为“error”


>>3.2中间数据处理部分

1）	若UI界面输入的数据的类型为string，中间调取函数传递参数计算时，需要对需要计算的数据进行类型转换将string数据类型转成double类型。 

2）	调取函数返回值是double类型，若输出的窗口对应输出类型为string，则需要进行数据转换。


>>3.3函数计算部分

1）函数算法实现

函数设计采用泰勒级数展开，对sin、cos、arcsin、arctan计算逼近函数值。四个上层函数对应的泰勒级数展开式如下：

sin(x)=x-x^3/3!+x^5/5!-x^7/7!+⋯ 

cos(x)=1-x^2/2!+x^4/4!-x^6/6!+⋯

arcsin(x)=x+1/2×x^3/3+(1×3)/(2×4)×x^5/5+(1×3×5)/(2×4×6)×x^7/7+⋯

arctan(x)=x-x^3/3+x^5/5-x^7/7+⋯

查阅相关资料，在|x|≤1中在泰勒级数展开中arcsin与arctan函数在x→1收敛性不好，可以选择采用近似公式计算，近似公式如下：

a=1.507288,b=-0.2121144,c=0.0742610,d=-0.0187293

arcsin⁡(x)=PI/2-√(1-x)×(a+bx+cx^2+dx^3)

arctan⁡(x)=PI/4 x-x(|x|-1)(0.2447+0.0663|x|)

当arctanx中x>1可以采用arctan⁡(x)=PI/2-arctan⁡(1/x)，当arctanx中x<0可以采用arctan⁡(x)=-arctan⁡(x)，当arctanx中x=0可以采用arctan⁡(0)=0.0来实现，其中最大近似误差0.0015rad。

判断函数输入值的取值范围是否合理后，指定泰勒展开式的逼近精度后利用函数的泰勒级数展开逼近函数值或者采用近似公式来计算，最终对函数计算值取根据需要的精确度近似得出最终输出结
果，并将其输出UI界面。

2）函数输入和返回值的类型描述

为了区别于调取math.h的函数名，采用下列的命名格式，同时调取对应函数时传递参数类型采用的double类型的变量，返回计算值也为double类型。并且计算传递的参数为弧度值，如果输入的函数值为角度，应进行角度转弧度，在调取函数计算。

(a) double mysin(double x)

(b) double mycos(double x)

(c) double myasin(double x)

(d) double myatan(double x)
