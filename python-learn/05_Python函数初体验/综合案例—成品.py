money = 5000000
name = input("请输入你的姓名：")
# 主菜单函数
def main_menu():
    print("----------------主菜单----------------")
    print(f"{name}您好，欢迎来到工商银行ATM，请选择操作："
          f"\n查询余额\t[输入1]\n存款\t\t[输入2]\n取款\t\t[输入3]\n退出\t\t[输入4]")
    global choose
    choose = int(input("请输入您的选择："))
# 定义查询余额函数
def query_balance(show_header):
    if show_header:
        print("----------------查询余额----------------")
    print(f"{name}您好，您的账户余额：{money}元")
# 定义取款函数
def withdraw_money(num):
    print("----------------取款----------------")
    global money
    money -= num
    print(f"{name}您好，您取款{num}元成功")

# 定义存款函数
def save_money(num):
    print("----------------存款----------------")
    global money
    money += num
    print(f"{name}您好，您存款{num}元成功")
while True:
    main_menu()
    if choose == 1:
       query_balance(False)
       continue
    elif choose == 2:
        num = int(input("请输入你要存款的金额："))
        save_money(num)
        query_balance(False)
        continue
    elif choose == 3:
        num = int(input("请输入你要取款的金额："))
        withdraw_money(num)
        query_balance(False)
        continue
    else:
        print("程序结束啦！")
        break