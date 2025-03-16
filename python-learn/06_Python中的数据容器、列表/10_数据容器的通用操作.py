"""
演示数据容器的通用功能
"""
my_list = [1,2,3,4,5]
my_tuple = (1,2,3,4,5)
my_str = "abcdefg"
my_set = {1,2,3,4,5}
my_dict = {"key1":1,"key2":2,"key3":3}

# len元素个数
print(f"列表 元素个数有：{len(my_list)}")
print(f"元组 元素个数有：{len(my_tuple)}")
print(f"字符串 元素个数有：{len(my_str)}")
print(f"集合 元素个数有：{len(my_set)}")
print(f"字典 元素个数有：{len(my_dict)}")

# max最大元素
print(f"列表 最大的元素是：{max(my_list)}")
print(f"元组 最大的元素是：{max(my_tuple)}")
print(f"字符串最大的元素是：{max(my_str)}")
print(f"集合 最大的元素是：{max(my_set)}")
print(f"字典 最大的元素是：{max(my_dict)}")

# min最小元素
print(f"列表 最小的元素是：{min(my_list)}")
print(f"元组 最小的元素是：{min(my_tuple)}")
print(f"字符串最小的元素是：{min(my_str)}")
print(f"集合 最小的元素是：{min(my_set)}")
print(f"字典 最小的元素是：{min(my_dict)}")

# 类型转换：容器的通用转换功能
# 类型转换：容器转列表    list()函数
print(f"列表转列表的结果是：{list(my_list)}")
print(f"元组转列表的结果是：{list(my_tuple)}")
print(f"字符串转列表的结果是：{list(my_str)}")
print(f"集合转列表的结果是：{list(my_set)}")
print(f"字典转列表的结果是：{list(my_dict)}")
# 类型转换：容器转元组
print(f"列表转列表的结果是：{tuple(my_list)}")
print(f"元组转列表的结果是：{tuple(my_tuple)}")
print(f"字符串转列表的结果是：{tuple(my_str)}")
print(f"集合转列表的结果是：{tuple(my_set)}")
print(f"字典转列表的结果是：{tuple(my_dict)}")
# 类型转换：容器转字符串
print(f"列表转字符串的结果是：{str(my_list)}")
print(f"元组转字符串的结果是：{str(my_tuple)}")
print(f"字符串字符串的结果是：{str(my_str)}")
print(f"集合转字符串的结果是：{str(my_set)}")
print(f"字典转字符串的结果是：{str(my_dict)}") # 转成字符串其value会保存，转换成其他类型value会被丢弃
# 注意：转换结果是本体加双引号

# 容器转集合 无序且去重
print(f"列表转集合的结果是：{set(my_list)}")
print(f"元组转集合的结果是：{set(my_tuple)}")
print(f"字符串集合的结果是：{set(my_str)}") #字符串集合的结果是：{'g', 'a', 'd', 'b', 'c', 'f', 'e'}集合的数据无须
print(f"集合转集合的结果是：{set(my_set)}")
print(f"字典转集合的结果是：{set(my_dict)}")

# 容器的通用 排序 注意排完序的结果都被转换为了列表对象
my_list = [3,1,2,5,4]
my_tuple = (3,1,2,5,4)
my_str = "bacedgef"
my_set = {3,1,2,5,4}
my_dict = {"key3":1,"key1":2,"key2":3}
print(f"列表对象的排序结果：{sorted(my_list)}")
print(f"元组对象的排序结果：{sorted(my_tuple)}")
print(f"字符串对象的排序结果：{sorted(my_str)}")
print(f"集合对象的排序结果：{sorted(my_set)}")
print(f"字典对象的排序结果：{sorted(my_dict)}") # 会丢失Value
# 反向排序
print(f"列表对象的排序结果：{sorted(my_list,reverse=True)}")
print(f"元组对象的排序结果：{sorted(my_tuple,reverse=True)}")
print(f"字符串对象的排序结果：{sorted(my_str,reverse=True)}")
print(f"集合对象的排序结果：{sorted(my_set,reverse=True)}")
print(f"字典对象的排序结果：{sorted(my_dict,reverse=True)}") # 会丢失Value




