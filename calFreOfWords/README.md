
main.cc 为统计词频程序
stopList.txt 为停用词列表，请保证其和main.cc在同一文件夹下
billgates.txt、The_Holy_Bible.txt 测试文件
程序执行方式：./a.out billgates.txt（文件名即可）

如果想查看前10个词频最高的单词，可按如下执行程序：
./count test.txt | head -n 10
