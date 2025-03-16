num1 = 520
print("让你来猜猜我心里想的(1~520)中那个数字")
if int(input("请输入(1~520)中的任意数：")) == num1:
    print("恭喜你猜对了我想的就是%d，我爱你哟！"%num1)
elif int(input("猜错了，再给你一次机会：")) == num1:
    print("恭喜你猜对了我想的就是%d，我爱你哟！"%num1)
elif int(input("又猜错了，最后给你一次机会哟：")) == num1:
    print("恭喜你猜对了我想的就是%d，我爱你哦！"%num1)
else:
    print("全部猜错了，都不知道人家心里想的是%d，不解风情~~~"%num1)