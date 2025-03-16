"""
账户余额1w，给20名员工发放工资
员工编号1到20，从编号1开始，依次领取工资，没人可领取1000元
领工资时，财务判断绩效，低于五分则，不发工资，下一位
工资发完了，结束发工资
"""
money = 10000
for i in range(1,21):
    import random
    score = random.randint(1,10)
    if score < 5:
        print(f"员工{i}，绩效{score}，你的绩效低于5，表现不好，不予发放工资")
        continue
    else:
        money -= 1000
        print(f"员工{i}，绩效{score}，你的绩效高于5，表现良好，发放1000元，账户余额{money}")
        if money == 0:
            print("账户的钱发完了，下个月早点来吧")
            break
