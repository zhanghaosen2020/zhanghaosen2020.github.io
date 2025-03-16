"""
多态，指的是：多种状态，即完成某个行为时，使用不同的对象会得到不同的状态
如何理解？
同样的行为(函数)，传入不同的对象，得到不同的状态
多态常作用在继承关系上
重要总结：一个抽象的父类来做顶层设计 规定要完成哪些功能 但不涉及具体功能实现
        构建多个子类对象它继承父类功能因为父类没有具体功能的实现所以我们需要
        对父类顶层设计的功能来具体实现也就是复写，然后运用多态 来实现
        给予不同的输入 实现同一功能

"""
# 构建父类对象  顶层设计
class Animal:
    def speak(self):
        pass

# 构建两个子类对象
class Dog(Animal):# 继承
    def speak(self):
        print("汪汪汪")
class Cat(Animal):# 继承
    def speak(self):
        print("喵喵喵")

def make_noise(animal: Animal):
    """制造点噪音，需要传入Animal对象"""
    animal.speak()

# 演示多态，使用2个子类对象来调用函数
dog = Dog()
cat = Cat()
# 父类引用指向子类对象
make_noise(dog)
make_noise(cat)

# 父类决定有哪些方法，具体的方法实现由子类自行决定（抽象类，接口），含有抽象方法的类称为抽象类
# 抽象方法：方法是空实现的（pass）称之为抽象方法