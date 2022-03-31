# Trigonometric_calculator
Chongqing University software Engineering course assignment
>1.简介  
    本程序实现了一个三角函数计算器，能够通过交互界面输入数值和计算指令，程序内部完成三角函数计算后在交互界面显示计算结果。  

>2.主要模块及功能描述  
>>2.1 Sin计算模块  
    描述：

>>2.2 Cos计算模块  
    描述：

>>2.3 Arcsin计算模块  
    描述：输入待计算数值x，判断是否在定义域[-1,1]中，对范围[-1,0]的数利用三角函数性质arcsin(-x)=-arcsin(x)计算，x取绝对值，flag置1。
计算采用泰勒展开式逼近法和近似公式计算法，近似公式在x趋于1时有更高的准确度，经测试得出在[0.9996615,1]的范围内近似公式计算结果比泰勒展开式计算结果更准确，故选择在此范围用近似公式计算。最后返回计算出的弧度值。

>>2.4 Arctan计算模块  
    描述：
    （1）输入double，返回值double
    （2）近似公式：arctan⁡(x)=PI/4 x-x(|x|-1)(0.2447+0.0663|x|) 其中0<x<=1;
    （3）当arctanx中x>1可以采用arctan⁡(x)=PI/2-arctan⁡(1/x)，当arctanx中x<0可以采用arctan⁡(x)=-arctan⁡(x)，当arctanx中x=0可以采用arctan⁡(0)=0.0来实现，其中最大近似误差0.0015rad。
