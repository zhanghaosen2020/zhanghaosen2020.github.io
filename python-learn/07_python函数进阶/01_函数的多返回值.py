"""
知道函数如何返回多个返回值及其语法
如果一个函数要返回多个函数值该如何书写代码 return 1，2
按照返回值的顺序，写对应顺序的多个变量接收即可，变量之间用逗号隔开，支持不同类型的数据return
"""
# 演示多个变量，接收多个返回值。
def test_return():
    return 1,"nihao",True

x,y,z = test_return()
print(x)
print(y)
print(z)