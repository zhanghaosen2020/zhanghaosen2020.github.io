#将数字类型转化为字符串
str_name=str(11)
print(type(str_name),str_name)
float_name=str(1.00)
print(type(float_name),float_name)

#将字符串转化为数字
num=int("111")
print(type(num),num)

num1=float("111.222")
print(type(num1),num1)
#所有类型均可以转化为字符串，因为任何类型加一个双引号进变成了字符串类型。若要将字符串转化为数字，则需要要求字符串内容为数字才可。
#整数转化为浮点数
num=float(111)
print(type(num),num)
#浮点数转化为整数，要注意可能会丢失精度
int_num=int(991.220)
print(type(int_num),int_num)