"""
用for循环判断奇偶
"""
list = [1,2,3,4,5,6,7,8,9,10]
even = []
odd = []
for index in list:
    if index % 2 == 0:
        even.append(index)
    else:
        odd.append(index)
print(f"偶数列表：{even}")
print(f"奇数数列表：{odd}")