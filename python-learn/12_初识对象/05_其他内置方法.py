"""
掌握常用的类内置方法，内置方法各有各自特殊的功能，这些内置方法我们称为：魔术方法

"""
class Student:
    def __init__(self,name,age):
        self.name = name
        self.age =age

# stu =Student("周杰伦",31)
# print(stu)
# print(str(stu))
#__str__
    def __str__(self):
        return f"Student类对象，name：{self.name},age:{self.age}"

#__lt__用于小于或者大于的比较
    def __lt__(self, other):
        return self.age < other.age

#__le__用于大于等于的比较 和上边的写法一样

#__eq__用于等于比较==，如果不用这个方法就默认比较地址，所以是False，这里可以用
# eq方法用法 和上一样

# 比较
stu1 = Student("张学友",31)
stu2 = Student("哥哥",22)
print(stu1 < stu2) # 比较两个类对象的年龄，返回的是bool
# 如果想获得类的对象变成字符串就通过这个魔术方法，不然就会输出地址
stu =Student("周杰伦",31)
print(stu)
print(str(stu))