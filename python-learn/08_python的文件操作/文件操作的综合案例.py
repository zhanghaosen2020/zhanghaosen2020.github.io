"""
文件操作综合案例
1、读取文件
2、将文件写出到bill.txt.bak文件作为备份
3、将文件内标记为测试的数据行丢弃

"""
fr = open("D:/bill.txt","r",encoding="UTF-8")
fw = open("D:/bill.txt.bak","w",encoding="UTF-8")
for line in fr:
    if line.count("测试") == 0:
        fw.write(line)
    else:
        continue
fr.close()
fw.close()
