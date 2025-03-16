"""
1、掌握函数的嵌套调用
2、理解嵌套调用的执行流程

所谓函数嵌套调用指的是在一个函数中又调用了另外一个函数
"""
# 定义func_b
def func_b():
    print("---2---")
# 定义func_a,在其内部调用func_b
def func_a():
    print("---1---")
    # 嵌套调用func_b
    func_b()
    print("---3---")
func_a()