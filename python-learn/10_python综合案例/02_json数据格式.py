"""
1、json是啥？
作为一个中转数据站来用
json是一种轻量级的数据交互格式，可以按照json指定的格式去封装和组织数据
json本质上是一个带有特定格式的字符串

2、主要功能：json这是一种在各个编程语言中流通的数据格式，负责不同编程语言中的数据传递和交互。

格式是：字典，列表内嵌字典

用json.dumps(data)方法把python数据转化为json数据类型
  json.loads(data) 方法把json数据转化为了python的列表或字典
"""
import json
# 准备列表，列表内每一个元素都是字典，将其转化为json
data = [{"name":"张哥","age":19},{"name":"理解","age":23},{"name":"王叔","age":22}]
json_str = json.dumps(data,ensure_ascii = False)
print(type(json_str))
print(json_str) # 中文会输出"\u5f20\u54e5"，因为涉及到编码格式的问题。
                # 为了解决这个问题输入ensure_ascii = False

# 准备一个字典，将字典转化为json
d = {"name":"周杰伦","addr":"台北"}
json_str = json.dumps(d,ensure_ascii=False)
print(type(json_str))
print(json_str)

# 将JSON字符串转化为python数据类型{k: v,k: v},{k: v,k: v}
# s = '[{"name": "张哥", "age": 19}, {"name": "理解", "age": 23}, {"name": "王叔", "age": 22}]'
# list = json.loads(s)
# print(type(list))
# print(list)

# 将json字符串转化为python数据类型{k: v,k: v}
s = '{"name": "周杰伦", "addr": "台北"}'
d = json.loads(s)
print(type(d))
print(d)
