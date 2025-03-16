# 打开文件，以读取模式打开
f = open("D:/常用文件/word.txt",'r',encoding="UTF-8")

# 方式1：读取全部内容，通过字符串count方法统计itheima单词数量
content = f.read()
count = content.count("itheima")
print(f"itheima在文件中出现了{count}次")
# 关闭文件
f.close()