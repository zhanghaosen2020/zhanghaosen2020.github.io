"""
函数的传入参数：在函数进行计算的时候，接收外部（调用时）提供的数据
"""
# def add():
#     result = 1 + 2
#     print(f"1 + 2的结果是：{result}")
# 上边的写法局限，运用传入参数的方法，可以使其有多种用途
def add(x,y):
    result = x + y
    print(f"{x}+{y}={result}")
add(19,1)
"""
函数定义中，提供的x和y，我们称之为：形式参数（形参），表明函数声明将要使用两个参数
参数之间用逗号分隔
函数调用中，提供的19和1，我们称之为：实际参数（实参），表示函数执行时真正使用的参数值
传入时，按照顺序传入参数，使用逗号分隔
"""