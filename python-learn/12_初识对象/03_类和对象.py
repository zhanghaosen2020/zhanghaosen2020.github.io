"""
使用程序的类可以描述现实事物
什么是面向对象编程：面向对象编程就是使用对象进行编程，即，
                 设计一个类，基于类创建对象并使用对象来完成具体的工作

"""
# 设计一个闹钟类
class Clock:
    id = None
    price = None

    def ring(self):
        import winsound
        winsound.Beep(2000,3000)
# 构建两个闹钟对象并让其工作 ,类设计好之后就构建对象就好啦
clock1 = Clock()
clock1.id = "2333"
clock1.price = 19.99
print(f"闹钟id：{clock1.id},价格：{clock1.price}")
clock1.ring()

clock2 = Clock()
clock2.id = "2333"
clock2.price = 19.99
print(f"闹钟id：{clock2.id},价格：{clock2.price}")
clock2.ring()
