"""
案例需求：
    定义一个数字（1~10，随机产生），通过3次判断来猜出数字。
案例要求：
    1、数字随机产生，范围1~10
    2、有三次机会猜测数字，通过3层嵌套判断实现
    3、每次猜不中，会提示大了小了
"""
# 1、构建一个随机的数字变量
import random
num = random.randint(1,10)# 随机产生一个数 1~10
print(num)
guess_num = int(input("输入你心里猜的数字："))
# 2、通过if判断语句经行数字的猜测
if guess_num == num:
    print("恭喜你，一次就猜中了！！")
else:
    if guess_num > num:
        print("猜大了哦")
    else:
        print("猜小了哦")
    guess_num = int(input("重新输入你心里猜的数字："))
    if guess_num == num:
        print("两次就猜到了我心意，不错哈！")
    else:
        if guess_num > num:
            print("猜大了哦")
        else:
            print("猜小了哦")
        guess_num = int(input("最后一次输入你心里猜的数字："))
        if guess_num == num:
            print("怎么才猜中嘞~~~")
        else:
            print("三次都没猜中，我很伤心，我心里想的数字是：%d"%num)
