# 字典中修改元素
# 1新增元素    语法：字典[Key] = Value ,结果是字典被修改，新增的元素
# 2更新元素    与上一致
my_dict = {"周杰伦":99,"林俊杰":88,"张学友":77}
# 新增元素
my_dict["张信哲"] = 66
print(f"字典经过新增元素后，结果：{my_dict}")
# 更新元素
my_dict["林俊杰"] = 90
print(f"字典经过新增元素后，结果：{my_dict}")

# 字典中删除元素：字典.pop(Key)   结果是获得指定Key的Value，同时字典被修改，指定的Key的数据被删除
score = my_dict.pop("周杰伦")
print(f"字典中被移除了一个元素，结果：{my_dict}，周杰伦的考试分数是：{score}")

# 清空元素，clear方法
my_dict.clear()
print(f"字典被清空了，内容是{my_dict}")

# 获取全部Key
my_dict = {"周杰伦":99,"林俊杰":88,"张学友":77}
keys = my_dict.keys()
print(f"字典的全部Keys是：{keys}，类型是：{type(keys)}")

# 遍历字典
# 方式1，结合上例通过获取全部的key来完成遍历
for key in keys:
    print(f"字典的key是：{key}")
    print(f"字典的value是：{my_dict[key]}")
# 方式2，直接对字典进行for循环，每一次循环都是直接得到key
for key in my_dict:
    print(f"2字典的key是：{key}")
    print(f"2字典的value是：{my_dict[key]}")

# 统计字典的元素数量len()
num = len(my_dict)
print(f"字典中的元素数量有：{num}")

"""
字典的特点总结
经过上述对字典的学习，可以总结出字典有如下特点：
可以容纳多个数据
可以容纳不同萨型的数据
每一份数据是KexValue键值对
可以通过Key获取到Value， Key不可重复（重复会覆盖）
不支持下标索引
可以修改（增加或删除更新元素等）
支持for循环，不支持while循环
"""