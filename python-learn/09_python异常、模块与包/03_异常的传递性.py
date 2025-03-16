"""
异常是具有传递性的
"""
# 定义一个出现异常的方法
def func1():
    print("func1 开始执行")
    num = 1 / 0 # 肯定有异常，初以0异常
    print("func1 结束执行")

# 定义一个无异常的方法，调用上边的方法
def func2():
    print("func2 开始执行")
    func1()
    print("func2 结束执行")
# 定义一个方法，调用上边的方法
def main():
    try:
        func2()
    except Exception as e:
        print(f"出现异常了，异常信息是：{e}")
main()