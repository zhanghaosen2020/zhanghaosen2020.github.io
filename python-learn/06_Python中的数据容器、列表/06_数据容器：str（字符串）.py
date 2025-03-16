"""
以数据容器的形式，来看字符串，重新认识字符串
字符串其实也是数据容器，只不过它是字符的容器
一个字符串可以存放任意数量的字符，元素的概念存在
"""
my_str = "itheima and itcast"
# 通过下标索引取值
value = my_str[2]
value1 = my_str[-16]
print(f"从字符串{my_str}取下标为2的元素，值是：{value}\n"
      f"从字符串{my_str}取下标为-16的元素，值是：{value1}")
# 同元组一样字符串的值是不可以修改的 只读的
# 查找特定字符串的下标索引值 index方法
value = my_str.index("and")
print(f"在字符串{my_str}中查找and，其起始下标是：{value}")

"""
语法：字符串.replace(字符串1,字符串2)
功能：将字符串内的全部：字符串1，替换为字符串2
注意：不是修改字符串本身，而是得到了一个新的字符串哦，就是replace会有返回值
"""
# 字符串的替换replace方法
new_mystr = my_str.replace("it","程序")
print(f"将字符串{my_str},进行替换后得到的：{new_mystr}")

"""
语法：字符串.split(分割符字符串)
功能：按照指定的分隔字符串，将字符串划分为多个字符串，并存入列表对象中
注意：字符串本身不变，而是得到了一个“列表对象”
e g：  "hello python itheima itcast"
得到：  ["hello","python","itheima","itcast"]
"""
# split方法
my_str = "hello python itheima itcast"
my_str_list = my_str.split(" ")
print(f"将字符串{my_str}进行split切分后得到：{my_str_list}\n"
      f"它的类型是：{type(my_str_list)}")
# 字符串的规整操作 （去前后空格）
# strip方法
my_str = "  hello python itheima itcast  "
new_mystr = my_str.strip() # 不传入参数去除首尾巴空格和换行符
print(f"字符串{my_str}被strip后结果是：{new_mystr}")
my_str = "12hello python itheima itcast2221"
new_mystr = my_str.strip("12") # 不入参数去除首尾
print(f"字符串{my_str}被strip('12')后结果是：{new_mystr}")
# 12被划分为两个小的字符1，2满足其中的一个就可以去除（首尾）

# 统计字符串中某个字符串的次数，count方法
my_str = "hello python itheima itcast"
count = my_str.count('it')
print(f"字符串{my_str}中it出现的次数是：{count}")

# 统计字符串的长度，len()
# num = len(my_str)
print(f"字符串{my_str}的长度是：{len(my_str)}")
# 字符串的遍历 while 与for

"""
作为数据容器，宇符串有如下特点：
只可以存储字符軍
去度任意（取决于内存大小）
支持下标索引
允许重复字符串存在
不可以修改（增加或删除元素等）
支持for循环
"""