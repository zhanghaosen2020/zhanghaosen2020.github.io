"""
布尔类型的数据，不仅可以通过定义得到，也可以通过比较运算符进行内容比较获得
"""
result = 10>5
print(f"10>5的结果是：{result},结果的数据类型是：{type(result)}")

result = "itheima"=="itcase"
print(f"字符串itheima是否和字符串itcase相等，结果是：{result}，结果的数据类型是：{type(result)}")
"""
==判断内容是否相等，满足为True，不满足为False
！=判断内容是否不相等，满足为True，不满足为False
>判断内容是否大于，满足为True，不满足为False
<判断内容是否小于，满足为True，不满足为False
<=判断内容是否大于等于，满足为True，不满足为False
>=判断内容是否小于等于，满足为True，不满足为False
"""
# 定义变量存储数据布尔类型的数据
bool_1 = True
bool_2 = False
print(f"bool_1变量的内容是：{bool_1}，变量类型是：{type(bool_1)}")
print(f"bool_2变量的内容是：{bool_2}，变量类型是：{type(bool_2)}")

# 比较运算符的使用，来得到bool类型的结果
num1 = 10
num2 = 10
print(f"10 == 10的结果是：{num1 == num2}")
num1 = 11
num2 = 10
print(f"11 != 10的结果是：{num1 != num2}")
num1 = 19
num2 = 12
print(f"19 >= 12的结果是：{num1 >= num2}")
print(f"19 < 12的结果是：{num1 < num2}")

name1 = "itheima"
name2 = "itcase"
print(f"itheima == itcase的结果是：{name1 == name2}")
