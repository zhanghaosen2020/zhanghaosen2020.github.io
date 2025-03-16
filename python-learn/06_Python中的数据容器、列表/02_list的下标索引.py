"""
掌握列表的下标（索引）取出特定位置的数据
"""
# 语法：列表[下标索引]
name_list = ['Tom','Lily','Rose']
print(name_list[1])
print(name_list[0])
print(name_list[2])
# 也可以反向索引即从定义的列表（从右往左）从-1开始
print(name_list[-1])
print(name_list[-2])
print(name_list[-3])
# 如果列表是嵌套的列表，同样支持下标索引
num_list = [['Tom','Lily','Rose'],[1,2,3]]
print(num_list[1][2])
print(num_list[0][0])
print(num_list[1][0])
print(num_list[-2][-1])
# 下标索引的注意事项 要注意下标索引的取值范围