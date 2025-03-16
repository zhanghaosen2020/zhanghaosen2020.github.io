"""
列表的定义格式
问：有一个人的姓名（Tom）怎么在程序中存储
答：字符串变量
问：有100个人的姓名，每个人的姓名都需要存储，该如何书写程序？声明100个变量吗？
答：NO，使用列表即可解决问题，列表一次可以存储多个数据

"""
# 基本语法
# 字面量
[1,2,3,4]
# 定义变量
num_list = [1,2,3,4]
# 定义空变量
num_list = []

# 第二种定义空列表
num_list = list()


# 案例演示，使用[]的方法定义列表
name_list = ['itheima','itcast',666,True,False]
print(name_list)
print(type(name_list)) # 列表可以一次存储多个数据，且可以为不同类型数据类型，支持嵌套

# 嵌套列表演示
my_list = [[1,2,3],[4,5,6,]]
print(name_list)
print(type(name_list))

