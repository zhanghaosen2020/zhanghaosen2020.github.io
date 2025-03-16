"""
函数：是组织好的，可重复使用的，用来实现特定功能的代码段。
"""
name = "itheima"
length = len(name)# 这里的len()就是，一个函数，类似的还有：int(),inout(),print()等等
print(length)

# 函数初体验，自己写一个功能类似于len()来统计字符长度
# 需求，统计字符串的长度，不使用内置函数len()
str1 = "itheima"
str2 = "itcase"
str3 = "python"

# 定义一个计数的变量
count = 0
for i in str1:
    count += 1
print(f"字符串{str1}的长度为{count}")

count = 0
for i in str2:
    count += 1
print(f"字符串{str2}的长度为{count}")

count = 0
for i in str3:
    count += 1
print(f"字符串{str3}的长度为{count}")
# 上边的内容重复了，做了大量重复的工作
# 可以使用函数来优化这个过程
def my_len(data):
    count = 0
    for i in data:
        count += 1
    print(f"字符串{data}的长度为{count}")

my_len(str1)
my_len(str2)
my_len(str3)
# 回想函数定义，1、已组织好的    2、可重复使用的    3、针对特定功能
# 提高了程序的复用性，减少了重复性代码，提高了开发效率
