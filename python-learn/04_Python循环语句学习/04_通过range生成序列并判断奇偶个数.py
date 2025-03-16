"""
判断1到100（不含100）中偶数的个数
"""
count = 0
for x in range(1,100):
    if x % 2 == 0:
        count += 1
print(f"1到100（不含100）有：{count}个偶数")