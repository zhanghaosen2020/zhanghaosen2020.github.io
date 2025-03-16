"""
for循环语句，本质上是遍历：序列类型。
尽管除去字符串外，其他的序列类型目前还没有学到，但是不妨碍我们 通过学习range语句，获得一个简单的数字序列

"""
"""
语法1:
 range(num)
 获取一个从0开始，到num结束的数字序列（不包含num本身）
语法2：
 range(num1,num2)
 获取一个从num1开始到num2结束的数字（不包含num2本身）
语法3：
 range(num1,num2,step)
 获取一个从num1开始，到num2结束的数字序列(不含num2本身)
 数字之间步长为step，step默认为1
 """

# 语法1
for x in range(10):
    print(x)

# 语法2
for x in range(5,10):
    print(x)

# 语法3
for x in range(1,10,3):
    print(x)

# 通过range快速的去确定循环的次数
for x in range(10):
    print("送玫瑰花")