"""
循环中断语句
问：无论是在while还是for循环中，都是重复性的执行特定操作，
    在这个重复过程中我们可能要
    1、暂时跳过某次循环，直接进行下一次
    2、提前退出循环，不再继续
    该如何实现嘞？
答：使用continue和break关键字，对循环进行临时跳过和直接结束
1、continue关键字用于，中断本次循环，直接进入下一次循环，可用于while和for中，效果一致
2、break关键字用于，直接结束循环，while和for中使用，效果一致
"""
# 演示continue
for i in range(1,6):
    print("语句1")
    continue# 每次执行到这里，都跳过，直接跳转到下一次的for，不执行语句2
    print("语句2")
# 演示continue在循环嵌套中的应用
for i in range(1,6):
    print("语句1")
    for j in range(1,6):
        print("语句2")
        continue # 这里只影响内层循环
        print("语句3")
    print("语句4")

# 演示break语句
for i in range(1,101):
    print("语句1")
    break # 遇到break循环直接结束
    print("语句2")
print("语句3")
# 演示break在循环嵌套的使用
for i in range(1,6):
    print("语句1")
    for j in range(1,6):
        print("语句2")
        break # 这里只影响内层循环
        print("语句3")
    print("语句4")


