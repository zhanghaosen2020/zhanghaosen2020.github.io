"""
多条件判断
if elif else语句来实现
"""
# print("欢迎来到游乐场")
# height = int(input("请输入你的身高（cm）："))
# vip_level = int(input("请输入你的VIP等级（1~5）："))
# day = int(input("请输入今天的日期（1~31）："))
# if height < 120:
#     print("您的身高小于120cm，可以免费游玩")
# elif vip_level > 3: #多条件判断下，条件是互斥的，if满足了elif就不再执行
#     print("您的VIP等级大于3，可以免费游玩")
# elif day == 1:
#     print("今天1号免费日，可以免费游玩") # 空格缩进必须要有
# else:
#     print("不好意思，11所有条件均不满足，需要购票游玩")
# print('祝您游玩愉快！')
print("欢迎来到游乐园:")
if int(input("请输入你的身高（cm）：")) < 120:
    print("您的身高小于120cm，可以免费游玩")
elif int(input("请输入你的VIP等级（1~5）：")) > 3:
    print("您的VIP等级大于3，可以免费游玩")
elif int(input("请输入今天的日期（1~30）：")) == 1:
    print("1号是免费日，可以免费游玩")
else:
    print("抱歉，所有条件均不满足，请您花10元购票")
print("祝您游玩愉快！")