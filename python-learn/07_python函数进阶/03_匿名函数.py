"""
函数作为参数传递
在前面学习的函数中，我们使用的函数都是接受数据作为参数传入
"""
# 传入逻辑，而非传入数据
# 定义1个函数，接收另一个函数作为传入参数
def test_func(compute):
    result = compute(1,2) # 确定compute是函数
    print(f"compute参数的类型是：{type(compute)}") # 参数类型是函数
    print(f"计算结果：{result}")
# 定义1个函数，准备作为参数传入另一个函数
def compute(x,y):
    return x + y
# 调用，并传入参数
test_func(compute)