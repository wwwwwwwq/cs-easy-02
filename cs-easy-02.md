<mark style="background-color：green">常用数据结构类型</mark>   
  
1.  
随机存取就是以恒定时间复杂度直接访问任意位置的数据元素，就是不需从前逐一访问。
从此定义来看，链表显然不支持随机存取，因为其是从前往后的。而数组属于随机存取，可以以恒定的时间复杂度访问某个位置的元素。  
   
2.  
指针，简而言之就是存储地址类型的变量，可以灵活控制数据。可以用来构建链表。  
在c语言中有两种定义方法  
(1).在变量名称前加* 如int *a  
(2).在类型名称后加* 如int* a  
容易看出两种表述等价  
指针变量的大小不是固定的，取决于操作系统的位数  
·在32位系统中，指针通常为4字节  
·在64位系统中，指针通常为8字节  
   
3.  
顺序表(数组)：排序算法中的数据存储、学生成绩的存储（可能要用到结构体）、临时变量（存储状态，计数器）的存储等；  
    
链表：链表适合插入与删除，因此可用在：音乐播放列表、约瑟夫环问题（刚好做到qwq）等等（更多的可参见算法导论第三版中文译本机械工业出版社P131）  
   
栈：先进后出，因此可以用来：迷宫算法、车厢重排问题（也做过qwq）等等；  
   
队列（queue）：先进先出、因此可以用来：bfs（广度优先搜索）、迷宫算法等；  
（ps：还有双端队列和优先队列哦qwq）  
   
图：由点和线构成，更多的应用参考图论，这里简单举几个：拓扑问题，计算几何问题、GPS导航等等；  
   
（无了吗？我的树呢qwq）  
   
4.  
(1)用邻接矩阵图（可以是二维数组来储存）  
  
(2)用邻接表（可以用链表来存储）  