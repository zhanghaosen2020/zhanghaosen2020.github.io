"""
元组的操作案例

"""
t1 = ('周杰伦',11,['football','music'])
print(f"年龄的下标是：{t1.index(11)}")
print(f"学生的姓名是：{t1[0]}")
del t1[2][0]
print(f"t1的内容是：{t1}")
t1[2].append("coding")
print(f"t1的内容是：{t1}")
