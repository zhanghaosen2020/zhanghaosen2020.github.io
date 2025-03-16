f = open("D:/常用文件/word.txt", "r", encoding="UTF-8")
i = 0
for line in f:
    if line.count("itheima") > 0:
        i += line.count("itheima")
f.close()
print(f"文本word.txt中“itheima”，出现的次数是：{i}")
    