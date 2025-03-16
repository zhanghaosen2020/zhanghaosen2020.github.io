"""
快速写入操作
按键演示：
    #1、打开文件
    f = open('python','w')
    #2、文件写入
    f.write('hello world')
    #3、内容刷新
    f.flush()
注意：直接调用write()，内容并未真正写入文件，而是会积攒在程序的内存中，称之为缓冲区
     当直接调用flush()的时候，内容才会真正接入文件
     这样做是避免频繁的操作硬盘，导致效率下降（攒一堆，一次性写磁盘）

"""
import time

# 打开文件，不存在的文件,r,w,a
f = open("D:/test.txt","w",encoding="UTF-8") # w模式会创建新内容
# write写入
f.write("Hello World!!!") # 此时类容写在了内存缓冲区中

# flush刷新
f.flush() # 将积攒的内容，写入到硬盘的文件中
# time.sleep(10000)
# close关闭
f.close()     # close方法中内置了flush()功能

# 打开一个存在的文件
f = open("D:/test.txt","w",encoding="UTF-8")
# write写入，flush刷新
f.write("黑马程序员")
f.flush()
# 注意：w模式的两个特点：1、文件存在，会清空原来文件的内容，再写  2、文件不存在会把文件创建出来
