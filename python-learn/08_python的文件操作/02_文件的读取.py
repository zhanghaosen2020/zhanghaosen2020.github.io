"""
1,了解文件操作的作用
2,掌握文件的打开，读写，关闭操作
文件的操作步骤：想想我们平常对文件的基本操作，大概分为三个步骤 1、打开文件 2、读写文件 3、关闭文件
打开文件的语法： open(name,mode,encoding)
    name:是要打开目标文件名的字符串（可以包含文件所在的具体路径）
    mode：设置打开文件的模式（访问模式）：只读、写入、追加等
    encoding：编码格式(推荐使用UTF-8）
示例代码：
    f = open('python.txt','r',encoding=" UTF-8)
    注意：此时的’f‘是’open‘函数的文件对象，对象是python中一种特殊的数据类型，拥有属性和方法
         可以使用对象.属性或对象.方法对其经行访问，在面向对象的课程中会详细介绍
读操作相关方法
read()方法：  文件对象.read(num)  num 表示要从文件中读取的数据的长度（单位是字节），如果没有传入
            num，那么就表示读取文件中所有的数据
readlines()方法： readlines可以按照行的方式把整个文件中的内容进行一次性读完，并且返还一个列表
                 其中每一行的数据为一个元素
readline()方法： 一次读取一行内容，调用一次读一行在调用接着读取下一行内容

for循环读取文件行
                for line in open("python.txt","r")
                    print(line)

关闭文件：close()关闭文件对象
 f = open('python.txt','r')
 f.close()
 最后通过close，关闭文件对象，也就是关闭对文件的占用
 如果不调用close，同时程序没有关闭，那么这个文件将一直被python程序占用
 with open('python.txt','r')as f:
    f.readlins()
 通过witn open的语句块中对文件进行操作
 可以在操作完成后自动关闭close文件，避免遗忘掉close方法

"""
import time

# 打开文件
f = open("D:/测试.txt","r",encoding="UTF-8") # 前两个为位置传参，后边为键值传参
print(type(f)) # 输出结果是：<class '_io.TextIOWrapper'>表示对文本文件进行IO操作的类
# 读取文件 ——read()
# print(f"读取10个字节的结果：{f.read(10)}")
# print(f"read方法读取全部内容的结果是：{f.read()}") # 连续调用两次f.read()会从上次读的结尾继续
# 读取文件 ——readlines()
# lines = f.readlines() # 读取文件的全部行，封装到列表中
# print(f"lines对象的类型是：{type(lines)}")  # 注意：文件读取时会续接上一次读取的位置，小指针
# print(f"lines对象的内容是：{lines}")

# 读取文件 —— readline()
line1 = f.readline()
line2 = f.readline()
line3 = f.readline()
line4 = f.readline()
print(f"第一行数据是：{line1}")
print(f"第二行数据是：{line2}")
print(f"第三行数据是：{line3}")
print(f"第四行数据是：{line4}")

# for循环读取数据
for line in f:
    print(f"每一行数据是：{line}")

# 文件的关闭
# time.sleep(50000)
f.close()
# time.sleep(50000)

# with open() 语法操作
with open("D:/测试.txt","r",encoding="UTF-8") as f:
    for line in f:
        print(f"每一行的数据是：{line}") # 会在对文件的操作完成之后，自动关闭文件
time.sleep(50000) # 第86个视频结尾

