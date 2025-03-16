"""
 信息去重
"""

my_list = ['黑马程序员','传智播客',
           '黑马程序员','传智播客','itheima','itcast','itheima','itcast']
# 定义一个空集合
set_empty = set()

# 通过for循环遍历列表
for element in my_list:
    # 在for循环中将列表的元素添加如集合
    set_empty.add(f"{element}")
# 得到的输出结果是
print(f"去重后的内容是：{set_empty}")

