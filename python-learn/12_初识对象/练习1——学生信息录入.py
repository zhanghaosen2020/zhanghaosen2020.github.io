"""

"""
class Student:
    def __init__(self,name,age,add):
        self.name = name
        self.age = age
        self.add = add
for num in range(1,11):
    print(f"当前录入第{num}位学生信息，总共需录入10位学生信息")
    # name = input("请输入学生姓名：")
    # age = input("请输入学生年龄：")
    # add = input("请输入学生地址：")
    # stu = Student(name,age,add)
    stu = Student(str(input("请输入学生姓名：")),input("请输入学生年龄："),
                  input("请输入学生地址：") )
    print(f"第{num}位学生信息录入完成，信息为:【学生姓名：{stu.name},"
          f"年龄：{stu.age},地址：{stu.add}】")
