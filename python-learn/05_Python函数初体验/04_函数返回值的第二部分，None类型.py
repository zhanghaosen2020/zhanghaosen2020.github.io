"""
问：如果函数没有使用return语句返回数据，那么函数有返回值吗？
答：有的，Python中有一个特殊的字面量：None，其类型是：<class 'NoneType'>
    无返回值的函数，实际上就是返回了：None这个字面量
    None表示空的，无实际意义的意思，函数返回的None，就表示，这个函数没有返回什么有意义的内容
    相当于返回了空的意思
"""
# 无return语句的函数返回值
def say_hi():
    print("你好呀")
result = say_hi()
print(f"无返回值函数，返回的内容是：{result}")
print(f"无返回值函数，返回的内容类型是：{type(result)}")
# 主动返回None的函数
def say_hi1():
    print("你好呀")
    return None
result = say_hi1()
print(f"无返回值函数，返回的内容是：{result}")
print(f"无返回值函数，返回的内容类型是：{type(result)}")

"""
None作为一个特殊的字面量，用于表示：空、无意义、其中有非常多的应用场景
1、用在函数无返回值上
2、用在if判断上
    在if判断中，None等同于False
    一般用于函数中主动返回None，配合if判断做相关处理
3、用于声明无意义的变量
    定义变量，暂时不需要要变量有具体值，可以用None来代替
    # 暂时不赋予变量具体值
    name = None
"""
# None用于if判断
def check_age(age):
    if age > 18:
        return "SUCCESS"
    else:
        return None
result = check_age(16)
if not result:
    # 能够进入if表示result是None值 也就是False
    print("你是未成年，不可以进入")

# None用于声明无初始内容的变量
name = None


