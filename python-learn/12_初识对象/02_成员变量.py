"""
1、类的定义和使用 class 里就两类，属性（数据）称为成员变量，行为（函数）称为成员方法
    类内部的函数称为方法
    self关键字是成员方法定义的时候，必须填写的
    1、它用来表示类对象自身的意思
    2、当我们使用类对象 调用方法的时候，self会自动被 Python传入
    3、在方法内部，想要访问类的成员，变量必须使用self
    注意：Self关键字尽管在参数列表中但传参的时候可以忽略它

"""
# 1、定义一个带有成员方法的类
class Student:
    name = None # 表示学生姓名

    def say_hi(self):
        print(f"大家好，我是{self.name}，请大家关照")

    def say_hi1(self,meg):
        print(f"大家好，我是{self.name},{meg}") # meg是外部传入的不需要用self调用
stu = Student() # 这里要带括号
stu.name = "杰伦"
stu.say_hi()
stu.say_hi1("哎呦，不错哟")

stu1 = Student() # 这里要带括号
stu1.name = "kk杰伦"
stu1.say_hi()
stu1.say_hi1("我看好你")
