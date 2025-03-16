"""
通过while循环来遍历，即依次从容器内取出元素
问：如何遍历列表的元素？
答：可以使用前面学到的while循环
问：如何在循环中取出列表的元素？
答：使用列表[下标]的方式取出
问：循环条件如何控制？
答：定义一个下标，从0开始，循环条件为 下标值 < 列表的元素数量
for循环遍历
for 临时变量 in 数据容器：
    对临时变量进行处理
"""
def list_while_func():
    """
    使用while循环遍历列表的演示函数
    :return: None
    """
    my_list = ["教育","程序员","Python"]
    # 循环控制变量通过下标索引来控制，默认为0
    # 每一次循环将下标索引变量＋1
    # 循环条件：下标索引标量 < 列表数量
    index = 0
    while index < len(my_list):
        # 通过index变量取出对应下标的元素
        element = my_list[index]
        print(f"列表的元素：{element}")
        # 将循环变量+1
        index += 1
list_while_func()

def list_for_func():
    """
    使用for循环遍历列表的演示函数
    :return: None
    """
    my_list = ['1','2','3','4','5']
    # for 临时变量 in 数据容器：
    # 对临时变量进行处理
    for element in my_list:
        print(f"列表的元素有{element}")
list_for_func()

"""
while循环和for循环，都是循环语句，但细节不同：
1、在循环控制上：
    wrile循环可以自定循环条件，＃自行控制
    for循环不可以自定盾环条年，只可以一个个从容器内取出数据
2、在无限循环上：
    while循环可以通过条件控制做到无 限循环
    for循环理论上不可以，因为被遍历的容器容量不是无限的
3、在使用场景上：
    while循环适用于任何想要循环的场景
    for循环适用于，遍历数据容器的场景或简单的固定次数循环场景
"""