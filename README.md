# Trigonometric_calculator
Chongqing University software Engineering course assignment
>1简介  
    本程序实现了一个三角函数计算器，能够通过交互界面输入数值和计算指令，程序内部完成三角函数计算后在交互界面显示计算结果。  

>2主要模块及功能描述  
>>2.1交互模块
    输入：计算结果
    输出：计算数值、运算类型、数值类型
    交互面板：交互面板具有0-9数字按键、正负号按键、小数点按键、加减乘除按键、等于号按键、清零按键、退格按键、存储按键、取数按键、
    正弦、余弦、正切、余切、正割、余割三角函数按键，输入显示、输出显示、运算显示、数值类型单选框。
    初始化：计算结果、计算数值显示为0，运算类型显示为空，数值类型选择角度
    功能：
    按下数字键时，若计算数值为0，则计算数值替换为数字键对应数值；若计算数值不为0，则计算数值右端新增一位数字键对应数值。
    按下正负号按键时，若计算数值左端为数字，则左端新增负号；若计算数值左端为负号，则删去负号。
    按下小数点按键，计算数值右端新增小数点。
    按下加减乘除、三角函数、等于号按键时，调用相关函数，输出计算数值、运算类型、数值类型，输入计算结果。相关函数返回值。
    按下清零按键时，计算结果、计算数值显示为0，运算类型显示为空。
    按下退格按键时，若计算数值为0，则计算数值不变；若计算数值不为0，则计算数值删去右端一位。
    按下存储键时，计算结果存储；按下取数键时，计算数值替换为存储的计算结果。
    
>>2.2数值处理模块
    输入：计算数值、运算类型、数值类型
    输出：计算结果
    功能：
    在运算按键按下后响应，根据当前输入情况，判断输入是否合法，
    若合法，调取当前所需运算模块（基本运算模块，三角函数运算模块），返回运算结果；
    若非法，向交互模块返回错误。
    
>>2.3基本运算模块
    输入：计算数值、运算类型、数值类型
    输出：计算结果
    功能：
    输入计算数值，完成加减乘除运算，返回运算结果。
    
>>2.4三角函数运算
    输入：计算数值、运算类型、数值类型
    输出：计算结果
    功能：
    输入计算数值，完成加减乘除运算，返回运算结果。
    
>>2.5功能处理模块
    输入：计算数值、运算类型
    输出：计算数值、运算类型
    功能：
    在功能按键（退格、清零、存储、取出）按下后响应，根据相关功能要求，完成对计算数值、运算类型的变换。
    
>>3详细设计
>>3.1 UI设计与交互部分

1）	输入显示和输出结果显示。

2）	数字、小数点、正负符号、复位、删除、函数通过按键实现

3）	对于sin、cos函数，计算器输入单位为角度值，输入角度值后点击对应的函数按键，输出显示对应的结果值。

4）	对于arcsin、arctan函数，计算器输入值后点击对应的函数按键，输出显示对应的角度值，当输入值超出取值范围，输出为“无效输入或者input error”


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
