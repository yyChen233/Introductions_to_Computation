# 第一阶段编程练习4

在写程序时，有一些共性问题需要注意。

1. 大数组的定义不要在函数中。函数都位于栈里，并且大小有限，直接在函数里定义大数组会导致爆栈。解决方案是在函数外定义全局数组，或者使用指针+malloc或new的方式，这样的话，数组会放在堆中，不会爆栈。
2. 所有变量都一定初始化，尤其是指针和数组。
3. 数组开得略大一点，防止越界。
4. 注意溢出问题，要考虑自己使用的数据类型是否合适。int型能表示的最大值为INT_MAX = 0x7fffffff，十进制下的值为2147483647，INT_MAX + 1后会发生溢出，此时值为INT_MIN = 0x80000000，十进制下的值为-2147483648，如下图所示，这种现象就是溢出。

![Overflow](fig/overflow.png)

## 输出连续素数

产生素数序列是一个很经典的问题，最简单的方法是对每个数，检查其有没有不是1或自身的因数，算法如下。

```
给定一个整数num
1. 将i从2到num-1循环
2. 若num % i == 0，说明num有因数i
    2.1 返回num不是素数
3. 否则对所有i，都有num % i != 0，说明num是素数
    3.1 返回num是素数
```

上面这种方法最为简单，但也有很多冗余。可以进行如下改进：不需要测试从2起的所有数字是不是因数，相反的我们只用测试比当前数字小的所有素数即可；若当前数字是素数，那将其加入到已知的素数集合，否则不作操作。算法如下。

```
对于数字num，若已知小于num的所有质数，从小到大存于prime数组中，共n个
1. 将i从0到n-1循环
2. 若num % prime[i] == 0，说明num有质因数prime[i]
    2.1 返回num不是素数
3. 否则所有小于num的质数，都不是num的因数，说明num是素数
    3.1 将num存于prime[n]，n加一
    3.2 返回num是素数
```

使用上述的产生素数的办法解决该题目，首先产生所有小于m的素数，接下来再产生k个素数并输出即可。

## 牛顿迭代方法

按照牛顿法的算法实现即可，注意数据精度问题（double精度在大部分编译器上都高于float）。

## 判断四边形

题目要求已经给出提示，凸多边形整体都在其任意边的同一侧，并且其余点不与该边共线。可以分别检查各个角对应的两边的向量外积，如下图所示，若四个外积都同号，说明是凸多边形，否则不是。

![Example](fig/example.png)

## 数字7游戏

根据题目要求，首先一定需要一个函数用于检查数字是否是7的倍数或包含7这个数码。检查数码时，对于固定位数的数字，是非常容易的，可以直接逐个数码检查；位数不定时，可以采取以下方法来判断。

```
给定数字num
1. 若num == 0，则不包含数码7
    1.1 返回num不包含7
2. 检查num个位数，若num % 10 == 0，则含有数码7
    2.1 返回num包含7
3. num的小数点左移一位，十位变个位，百位变十位，以此类推，对应num /= 10
    3.1 跳到1，迭代进行
```

有了这种简单的判断方法后，需要模拟整个报数的过程来得到结果，直接参考提供的代码即可，比较容易。

## 一种等价类划分问题

与“数字7游戏”比较类似，该问题也需要操作整型数的各位，计算各个数码之和的方法也与上面提供的方法类似，不再赘述。

当有了计算数码之和的函数digit_sum后，我们可以计算并记录从m到n的所有数的数码之和，并且在这一过程中记录数码和的最小值和最大值。之后我们从数码和的最小值起一直检查到最大值，检查的过程中查看之前计算得到的数码和并同时输出结果即可。具体的算法如下。

```
1. 将i从m到n循环，计算digit_sum(i)，存放在数组sum[i]中，并同时记录更新min_sum和max_sum
    1.1 sum[i] = digit_sum(i)
    1.2 若sum[i] < min_sum，更新min_sum
    1.3 若sum[i] > max_sum，更新max_sum
2. 将i从min_sum到max_sum循环，若i为k的倍数，则从m到n扫描sum数组，输出所有数码和与i相同的数
    1.1 若i % k != 0，不符合要求，不向下进行，直接跳过
    1.2 将j从m到n循环，若i == sum[j]，则输出j
```

需要注意输入和输出的格式问题。