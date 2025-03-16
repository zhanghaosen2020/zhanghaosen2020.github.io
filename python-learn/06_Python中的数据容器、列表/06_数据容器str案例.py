"""
分割字符串

"""
str = "itheima itcast boxuegu"
count = str.count("it")
print(f"字符串{str}，中有{count}个'it'")
new_str = str.replace(" ","|")
print(f"被替换后的字符串为：{new_str}")
new_str1 = new_str.split("|")
print(f"被|分隔后的字符串为：{new_str1}")

