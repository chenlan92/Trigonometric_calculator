# Trigonometric_calculator
Chongqing University software Engineering course assignment
>1.简介  
    本程序实现了一个三角函数计算器，能够通过交互界面输入数值和计算指令，程序内部完成三角函数计算后在交互界面显示计算结果。  

>2.主要模块及功能描述  
>>2.1主控模块(Trigonometric_calculator)  
    描述：主程序，协调控制计算模块、数据模块和交互模块。  

>>2.2计算模块(Calculation_module)  
    描述：完成三角函数sin、cos、tan、cot、sec、csc运算。
    
    （1）sct.h内有deg2rad()、rad2deg()、t_sin()、t_cos()、t_tan()、t_sec()、t_csc()、t_cot()的计算函数，传递参数采用double类型，返回的函数也为double类型。
    
    （2）t_sin()、t_cos()、t_tan()、t_sec()、t_csc()、t_cot()计算时传入的为弧度制的角。
    
    （3）若传入的数值为角度，可调取deg2rad()函数转成弧度，在进一步调取三角函数的计算函数。
    
>>2.3数据模块(Data_module)  
    描述：定义数据类型、长度属性，缓存待处理和已完成数据。  

>>2.4交互模块(Interaction_module)  
    描述：具有显示界面和交互按钮，显示输入数据、输出结果，键入数据和运算函数，键入清除、结果指令。  
    
>>2.5异常模块(Abnormal_module)  
    描述：检查输入，判断是否存在错误，反馈错误信息。
