"""
    对数据的类型标记一下
    变量:类型
    注意：元组类型设置类型详细注解，需要将每一个元素标记出来
"""
import json
import random

# 基础数据类型的注解
var_1: int = 10
var_2: str = "heima"
var_3: bool = True
# 类对象类型注解
class Student:
    pass
stu: Student = Student()

# 基础容器类型注解
my_list: list = [1,2,3]
my_tuple: tuple = (1,2,3)
my_dict: dict = {"heima":666}
# 容器类型详细注解
my_list: list[int] = [1,2,3]
my_tuple: tuple[int,str,bool] = (1,"hiema",True)
my_dict: dict[str,int] = {"heima":666}

# 在注释中进行类型注解  # alt+回车 自动搜索需要导的包
var_4 = random.randint(1,10)  # type: int
var_5 = json.loads('{"name:"张三"}') # type: dict[str,str]
def func():
    return 10
# 函数或者方法的形参和返回值的类型注解
var_6 =func() # type: int

# 一般，无法直接看出变量类型之时会添加变量的类型注解

# 类型注解的限制
var_7:int = "heima" # 一个备注而已，不起决定作用
