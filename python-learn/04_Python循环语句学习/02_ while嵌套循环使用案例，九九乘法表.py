"""
打印九九乘法表
print("hello")
print("world")
输出的内容会自动换行
hello
world
1、怎样实现输出不换行呢？
print("hello",end='')
print("world",end='')
end = ''  空字符串
2、制表符，在字符串中，有一个特殊符号：\t,效果等同于在键盘上按下：tab键
   使用它，可以让多行字符串对齐
"""
# 输出不换行
# print("hello")
# print("world")
# print("hello",end='') # end = ''  空字符串
# print("world")
#
# # 制表符的使用
# print("itheima best")
# print("hello world")
# print("hello\tworld")
# print("itheima\tbest")

# 打印九九乘法表
# print("九九乘法表")
# 定义外层循环控制变量
i = 1
while i <= 9:

    # 定义内层循环控制变量
    j = 1
    while j <= i:
        # 内层循环的打印语句，不换行，通过指标符\t对齐
        print(f"%d*%d={j*i}\t"%(j,i),end = '')
        j += 1
    i += 1
    print() # 空内容，就是一个换行
