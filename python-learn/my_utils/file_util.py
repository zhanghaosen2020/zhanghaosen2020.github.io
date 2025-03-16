"""
文件处理相关的工具模块

"""
def print_file_info(file_name):
    """
    将给定路径的文件类容输出到控制台
    :param file_name: 即将读取的文件路径
    :return:None
    """
    f = None # 文件对象初始值是空
    try:
       f = open(file_name,"r",encoding="UTF-8")
       content = f.read() # 接收文件的全部内容
       print("文件的全部内容为：")
       print(content)
    except Exception as e:
        print(f"文件出现异常了，原因是：{e}")
    finally:
        if f: # 如果变量是None，表示False，如果有任何的内容，就是True
            f.close()

def append_to_file(file_name,data):
    """
    将指定的数据追加到指定的文件中
    :param file_name: 指定的文件类容
    :param data: 指定的数据
    :return: None
    """
    f = open(file_name , "a",encoding="UTF-8")
    f.write(data)
    f.write("\n")
    f.close()
if __name__ == '__main__':
    print_file_info("D:/bill.txt")
    # print_file_info("D:/bill.tt")
    append_to_file("D:/bill.txt","张小虎，2023-01-03，400000，消费，测试")