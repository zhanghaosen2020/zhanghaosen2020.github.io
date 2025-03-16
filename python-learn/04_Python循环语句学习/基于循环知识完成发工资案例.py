"""
账户余额1w，给20名员工发放工资
员工编号1到20，从编号1开始，依次领取工资，没人可领取1000元
领工资时，财务判断绩效，低于五分则，不发工资，下一位
工资发完了，结束发工资
"""
import random
account = 10000
for i in range(1,21):
    performance = random.randint(1,10)
    if performance > 5:
        account -= 1000
        print(f"员工{i}，绩效{performance}，高于5，发放工资1000元，账户余额{account}")
        if account == 0:
            print("账户的钱发完了，下个月再来领取吧")
            break
    else:
        print(f"员工{i}，绩效{performance}，低于5，表现太差，不予发放工资")




