"""
使用各种变量来存贮组织数据形式多样，各种类型，因此，程序中设计生活中的一个表格，
生产表格，填写表格，组织形式
1、在程序中设计表格，我们称之为：设计类(class)
class Student：
    name = None # 记录学生姓名
2、在程序中打印生产表格，我们称之为：创建对象
  基于类创建对象
  stu_1 = Student()
  stu_2 = Student()
3、在程序中填写表格，我们称之为：对象属性赋值
  stu_1.name = "周杰伦"  # 为学生1对象赋予名称属性值。
  stu_2.name = "周杰伦"  # 为学生2对象赋予名称属性值。
"""
# 1.设计一个类，类比生活中设计一张登记表
class Student:
    name = None
    gender = None
    nationality = None
    native_place = None
    age = None

# 2.创建一个对象,类比生活中打印登记表
stu_1 = Student() #stu_1既是对象也是变量

# 3.对象属性进行赋值，类比生活中填写表单
stu_1.age = 20
stu_1.name = "琳琳"
stu_1.gender = "男"
stu_1.nationality = "中国"
stu_1.native_place = "山东"

# 4.获取对象中记录的数据
print(stu_1.name)
print(stu_1.age)
print(stu_1.gender)
print(stu_1.nationality)
print(stu_1.native_place)