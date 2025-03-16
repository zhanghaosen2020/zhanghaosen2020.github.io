"""
按键演示：
    #1、打开文件
    f = open('python','a')
    #2、文件追加
    f.write('hello world')
    #3、内容刷新
    f.flush()
"""
# 打开文件，不存在的文件
f = open("D:/test1.txt","a",encoding="UTF-8")
# write()写入
f.write("王咕咕，又咕视频\n")
# flush()刷新
f.flush()
# close()关闭

# 打开一个存在的文件
f = open("D:/test1.txt","a",encoding="UTF-8")
# write写入，flush刷新
f.write("学python的最佳选择")
f.close()