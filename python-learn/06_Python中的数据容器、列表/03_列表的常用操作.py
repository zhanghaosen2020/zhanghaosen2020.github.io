"""
列表除了可以：定义，使用下标索引获取值等
此外还提供了一系列功能：
插入元素
删除元素
清空列表
修改元素
统计元素个数等
上面的功能我们统称为：列表的方法
什么是方法嘞？
在Python中，如果将函数定义为class（类）的成员，那么函数会称之为：方法

"""
# 方法和函数的功能一样，有传入参数，有返回值，只是方法的使用格式不同
# 函数是直接调用函数名
# num = add(1,2)
# 方法使用
#  student = Student()
#  num = student.add(1,2) 所以直接用 list.函数 直接使用，说白了，就是list内部提供了一系列函数
my_list = ['itcast','itheima','python']
# 查询某元素下标的功能，如果找不到，报错 ValueError
# 1.1 查找元素在列表中的下标索引
index = my_list.index('python')
print(f"python在列表中的索引值是：{index}")
# 1.2如果被查找的元素不存在，会报错
# index = my_list.index('p')
# print(f"python在列表中的索引值是：{index}")

# 修改特定位置（索引）的元素值
# 语法：列表[下标] = 值
# 2修改特定下标索引的值
my_list[0] = "教育"
print(f"列表修改后结果是：{my_list}")

# 3插入元素，语法是：列表.insert(下标,元素)
my_list.insert(1,"best")
print(f"列表插入元素后结果是：{my_list}")

# 4.1如何对列表进行追加单个元素，即将指定元素追加到列表的尾部
my_list.append(9)
print(f"列表追加后结果是：{my_list}")
# 4.2对列表追加一批元素 列表.extend(其他数据容器)
my_list1 = [1,2,3]
my_list.extend(my_list1)
print(f"列表追加到最后后结果是：{my_list}")

# 5.1 单个元素的删除：del 列表[下标]
my_list = ['itcast','itheima','python']
del my_list[2]
print(f"列表删除元素后的结果是：{my_list}")
# 5.2列表.pop(下标)这个方法，同时还可以通过变量接收删除的元素
my_list = ['itcast','itheima','python']
element = my_list.pop(2)
print(f"通过pop方法取出元素后列表内容：{my_list}，\n删除的元素是:{element}")
# 5.3 删除某元素在列表中的第一个匹配项
my_list = [1,2,3,2,4]
my_list.remove(2) # 列表.remove(元素) 这个方法来实现
print(my_list) # 如果要实现删除第二个元素就需要再次调用这个方法咯

# 6清空列表
my_list.clear()
print(f"列表被清空，结果是：{my_list}")

# 统计某个元素在列表中的数量
my_list = [1,2,3,2,4]
my_list.count(2)
print(f"列表中2的数量是：{my_list}")

# 统计列表中元素总共的个数
my_list = [1,2,3,2,4]
count = len(my_list)
print(f"列表中的元素数量总共有{count}个")

"""
列表的特点：1、可容纳多个元素(上限为：2**63-1个)
          2、可以容纳不同类型的元素（可以混装）
          3、数据是有序存储的（有下标序号）
          4、允许数据重复存在
          5、可以修改（增删查改）
"""
