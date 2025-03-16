"""
python类可以使用：__int__()方法，称之为构造方法
可以实现：
        1、在创建对象（构造类）的时候，会自动执行
        2、早创建对象（构造类）的时候，会将传入参数自动传递给__int__方法使用
"""
# 演示使用构造方法对成员变量赋值
# 构造方法的名称:__init__
class Student:
    # name = None
    # age = None
    # tel = None  不写也可以
# 注意：1、构造方法也是成员方法不要忘记在参数列表中提供self
    def __init__(self,name,age,tel):
        self.name = name # 内部的（self）成员变量name，赋值为外部传入的name
        self.age = age # 这一步既有赋值的功能也有定义变量的功能
        self.tel =tel
        print("Student类创建了一个类对象")
stu = Student("杰伦",33,"12345699")
print(stu.name,stu.age)
print(stu.age)
print(stu.tel)
