"""
ATM存取款
定义两个全局变量：money ，name来分别记录银行卡余额（默认5000000）和客户姓名（启动程序时输入）
定义如下函数：1、查询余额函数
            2、存款函数
            3、取款函数
            4、主菜单函数
要求： 1、程序启动后要求输入客户姓名
      2、查询余额、存款、取款后都会返回主菜单
      3、存款、取款后、都应显示一下 当前余额
      4、客户选择退出或者输入错误，程序会自动退掉否则一直运行
"""

# 定义全局变量
money = 5000000
name = input("请输入你的姓名：")
# 主菜单函数
def main_menu():
    print("----------------主菜单----------------")
    print(f"{name}您好，欢迎来到工商银行ATM，请选择操作："
          f"\n查询余额\t[输入1]\n存款\t\t[输入2]\n取款\t\t[输入3]\n退出\t\t[输入4]")
    global choose
    choose = int(input("请输入您的选择："))
    return choose
# 定义查询余额函数
def query_balance(show_header):
    if show_header:
        print("----------------查询余额----------------")
    print(f"{name}您好，您的账户余额：{money}元")
# 定义取款函数
def withdraw_money():
    print("----------------取款----------------")
    print(f"您当前账户余额：{money}元")
    witndraw = int(input(("请输入您要取款的金额：")))
    global balance
    balace = money - witndraw
    print(f"{name}您好，您取款{witndraw}元成功\n{name}您好，您的账户余额：{balace}")

# 定义存款函数
def save_money():
    print("----------------存款----------------")
    savemoney = int(input("请输入您的存款金额："))
    global balance
    balance = money + savemoney
    print(f"{name}您好，您存款{savemoney}元成功\n{name}您好，您的账户余额：{balance}")
while True:
    main_menu()
    if choose == 1:
       query_balance(False)
       continue
    elif choose == 2:
        save_money()
        continue
    elif choose == 3:
        withdraw_money()
        continue
    else:
        print("程序结束啦！")
        break










