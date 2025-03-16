"""
猜数字
"""
# 获取范围在1~100的随机数
import random
num = random.randint(1,100)
# 定义一个变量，记录猜测了多少次（即进入循环的次数）
count = 0
print("猜测的数为",num)

# 通过一个布尔类型的变量，做循环是否继续的标记
flag = True
while flag:
    guess_num = int(input("请输入你猜测的数字(1~100)："))
    count += 1
    if guess_num == num:
        print("猜中了")
        # 设置循环终止条件
        flag = False
    else:
        if guess_num > num:
            print("猜大了哦")
        else:
            print("猜小了哦")

print("你总共猜了%s次数"%count)