"""
函数或方法的形参的类型注解
def 函数方法名 (形参名:类型)->返回值类型：
    pass

"""
# 对形参进行类型注解
def add(x:int,y:int):
    return x+y
add(2,2) #

# 对返回值进行注解
def func(data:list)->list: # 返回值的注解
    return data

print(func(1))