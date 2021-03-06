# 北京邮电大学国际学院数据结构课程答案
*本人对于答案正确性不负责*

*本仓库仅供学习参考使用*

*请不要抄袭，对一切抄袭产生的不利后果，本人将凭本repository作为依据**维权到底***

北邮OJ：http://10.105.242.83/ 请在连接校内网络或使用校内VPN的情况下访问

## 索引       
- [2238](#2238)       
- [2236](#2236)
- [2239](#2239)
- [第一次作业](#第一次作业)

### 2238

这是一道典型的线性表合并题目，从题目中给出的有序条件来看，本题属于较为简单的排序问题。
为了优化本题的空间复杂度，我们把其中的一个原始数组就作为输出目标。为了优化时间复杂度并且避免嵌套两层循环，我们分别在两个原始数组和输出目标分别设立游标，一共设置三个游标。尔后，就是简单的比较排序问题了。

### 2236

约瑟夫环问题。本题相对简明，只要用恰当的数据结构对过程加以模拟就很轻松可以得到一低复杂度的结果了。
本题的难点在于循环链表本身，可以照搬《数据结构（C语言版）》的风格，直接定义一系列的循环链表初始化、操作函数，并复用这些函数。我给出的解法具体的写出了初始化函数，以及“删除当前节点”模块。应当注意循环链表的首尾连接问题，以及删除当前节点需要有游标指向前驱即可。

### 2239

后缀表达式问题。本题两问，看似让你先利用中缀表达式求值，再将中缀表达式（正常表达式）转化为后缀表达式，实则不然。让我们不妨看一下后缀表达式求值有多么简单：
1. 遍历后缀表达式，向栈中压入数字
2. 遇到运算符则弹出两个元素，执行对应的操作，把结果压回栈中
3. 直到栈里只有最后一个数字，输出，得到结果
后缀表达式求值利用栈法实现并不难，在这里不多加赘述了，详见源码。难点主要在于一些值类型的转化处理上面，例子中选用switch-case语句来处理复杂的char-float转化情况。在解决这一问之后，题的难点就集中在了如何从中缀表达式向后缀表达式转化上面。比较好的解法仍然是使用栈法，属于括号匹配问题的一个超集。建议通过回顾括号匹配问题，再在括号匹配代码为模版的基础上，拓展对于运算优先级的处理。

### 第一次作业
1. <img src="https://latex.codecogs.com/gif.latex?O(n)&space;=&space;\log_2(n)" title="O(n) = \log_2(n)" />
2. <img src="https://latex.codecogs.com/gif.latex?O({(\frac{2}{3})}^n)&space;<&space;O(2^{100})&space;<&space;O(\log_2(\log_2n))&space;<&space;O(\log_2n)&space;<&space;O({(\log_2n)}^2)&space;<&space;O(\sqrt{n})&space;<&space;O(n^{\frac{2}{3}})&space;<&space;O(n)&space;<&space;O(n\log_2n)&space;<&space;O(n^{\frac{3}{2}})&space;<&space;O(n^{\log_2n})&space;<&space;O((\frac{4}{3})^n)&space;<&space;O((\frac{3}{2})^n)&space;<&space;O(n!)&space;<&space;O(n^n)" title="O({(\frac{2}{3})}^n) < O(2^{100}) < O(\log_2(\log_2n)) < O(\log_2n) < O({(\log_2n)}^2) < O(\sqrt{n}) < O(n^{\frac{2}{3}}) < O(n) < O(n\log_2n) < O(n^{\frac{3}{2}}) < O(n^{\log_2n}) < O((\frac{4}{3})^n) < O((\frac{3}{2})^n) < O(n!) < O(n^n)" />
3. (4) (1) // (7) (11) (8) (4) (1) // (5) (12)// (9) (6) (1) 
4. (11) (3) (14) // (10) (12) (8) (11) (3) (14) // (10) (12) (7) (3) (14) // (12) (11) (3) (14) // (9) (11) (14)
5. 321 // S1S2S3S4X4X3S5S6X5X6 剩余12，无法先1后2 // S1X1S2S3X3S4S5X5X4X2S6X2 可行
6. 队列倒排