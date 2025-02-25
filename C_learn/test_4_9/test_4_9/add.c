#define _CRT_SECURE_NO_WARNINGS
//全局变量  具有外部链接属性的
 int g_val = 2022; 

//static修饰全局变量时时候的作用
// 这个全局变量的外部链接属性就变为了内部链接属性了，其他源文件就不能再使用到全局变量了
//static int g_val = 2022;

 //该函数和全局变量一样，具有外部链接属性，只不过在其他源文件调用前，需要事先声明
 int Add(int x, int y)
 {
	 return x + y;
 }
 
 //加了static之后会和全局变量一样，使用范围变小，其他源文件不能再调用
 /*static int Add(int x, int y)
 {
	 return x + y;
 }*/
