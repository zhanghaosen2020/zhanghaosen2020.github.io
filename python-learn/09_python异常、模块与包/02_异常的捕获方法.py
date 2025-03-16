"""
1、为什么要取捕获异
    我们要在力所能及的范围内，去解决问题
    当我们遇到了BUG，会有两种可能的情况 ①整个程序因为bug停止 ②对bug进行提醒，整个程序继续运行
    捕获异常的作用在于：提前假设某处会出现异常，做好提前准备，当真的出现异常的时候，可以有后续手段
2、掌握捕获异常的语法格式
    基本语法：
    try：
    可能发生错误的代码
    except：
    如果出现异常执行的代码
"""
# 需求：尝试以‘r’模式打开文件，如果文件不存在，则以‘w’方式打开
# 基本捕获语法
try:
    f = open("D:/abc.txt","r",encoding="UTF-8")
except:
    print("出现异常了，因为文件不存在，我将open的模式，改为w模式去打开")
    f = open("D:/abc.txt","w",encoding="UTF-8")

# 捕获指定异常
try:
     print(name)
except NameError as e:
    print("出现了变量未定义的异常")
    print(e)

# 捕获多个异常
try:
    1/0
    print(name)
except (NameError,ZeroDivisionError) as e:
    print("出现了变量为定义 或 初以0的异常错误")

# 捕获所有异常
try:
    # 1/0
    # print("hello")
    open("D:/123.txt","w",encoding="UTF-8")
except Exception as e:
    print("出现异常了")
else: # 表示没有出现异常之后该执行的代码
    print("好高兴，没有异常")
finally: # 表示的是无论是否异常都要执行的代码，例如关闭文件,用于资源关闭，流氓！！
    f.close()
