"""
一,掌握位置参数
二,掌握关键字参数
三,掌握不定长参数
四,掌握缺省参数
"""
# 位置参数
def user_info(name,age,gender):
    print(f"您的名字是{name}，年龄是：{age}，性别是：{gender}")
user_info("张某人",20,"男")

# 关键字参数
def user_info(name,age,gender):
    print(f"您的名字是{name}，年龄是：{age}，性别是：{gender}")
# 调用函数时：通过”键 = 值“的形式传递参数
user_info(name = "小明", age = 22 , gender = "男" )
# 使用使用这种方法时，可以不按照固定的顺序
user_info(age = 22 ,gender = "男",name = "小明" )
# 可以和位置参数混用,位置参数必须在前,且匹配参数顺序。
user_info("小明", age = 22 , gender = "男" )

# 缺省参数：缺省参数也叫默认参数，用于定义函数，为参数提供默认值，调用函数时，可不传该默认参数的值。
# 注意：所有位置参数必须出现在默认参数前，包括函数定义和调用。
# 作用：当调用函数时没有传递参数，就会使用默认是用缺省参数对应的值
def user_info(name,age,gender = '男'): # 注意:默认的参数必须写道最后边
    print(f"您的名字是{name}，年龄是：{age}，性别是：{gender}")
user_info('小天',10)
user_info('小天',10,"女")

# 不定长参数
# 位置不定长传递
def user_inform(*args):
    print(args)
user_inform('Tom',11,True) # 元组类型
# 注意：传进的所有参数都会被args变量接收，他会根据传进参数的位置合并为一个元组（tuple），args元组类型。 这就是位置传递。
# 关键字传递的不定长
def user_infomation(**kwargs):# kw  =  keyword
    print(kwargs)
# 传入的参数必须要是“键=值”这一形式，所有传入的“键=值”都会被kwargs接收，同时根据“键=值”组成字典
user_infomation(name = "Tom", age = "18")