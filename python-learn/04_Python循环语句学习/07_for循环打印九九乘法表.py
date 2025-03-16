"""
九九乘法表的打印
"""
print("九九乘法表")
# 外层循环控制有几行，内层循环控制输出的内容
for i in range(1,10):
    for j in range(1,i+1):
        print(f"{j}*{i}={i * j}\t",end='')
    print()
