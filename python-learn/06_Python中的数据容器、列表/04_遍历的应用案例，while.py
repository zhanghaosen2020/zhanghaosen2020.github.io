"""
取出列表内的偶数
"""
list = [1,2,3,4,5,6,7,8,9,10]
even = []
odd = []
index = 0
while index < len(list):
    element = list[index]
    if element % 2 == 0:
        even.append(element)
    else:
        odd.append(element)
    index += 1
print(f"偶数列表：{even}")
print(f"奇数数列表：{odd}")