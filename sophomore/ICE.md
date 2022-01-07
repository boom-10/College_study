<script type="text/javascript" src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=default"></script>

## 计基复习 By 江野

### 第一章 计算机系统概述

- ENIAC，ABC的“世界第一台电子计算机”之争。冯**·**诺依曼被美军军方负责人戈尔斯坦邀请加入了ENIAC研制组。**冯·诺依曼计算机的基本思想**（4个方面，最主要是**存储程序**，**程序控制**）。

  1. 采用**存储程序**工作方式

  2. 计算机由**运算器**、**控制器**、**存储器**、**输入设备**、**输出设备**5个基本部件组成

  3. 存储器可以存放数据和指令，形式上无区别，但计算机需要能够区分；控制器自动执行指令；运算器可以实现算术运算和逻辑运算；操作人员可以通过输入\输出设备使用计算机。

  4. 计算机内部以二进制形式表示指令和数据，每条指令由**操作码**（操作类型）、**地址码**（操作数的地址）两部分构成。 

- “计算机内部以二进制形式表示指令和数据”，CPU从存储器中取出指令和数据，如何区分？

  1. 从时间来说：取指令事件发生在“取指周期”；取数据事件发生在“执行周期”。
  2. 从空间来说：取出的二进制代码是指令，一定送往指令寄存器（控制器）；取出的二进制代码是数据，一定送往数据寄存器（运算器）。

- 计算机软件分为：**系统软件**(电脑系统)和**应用软件**(网站、界面程序、爬虫、自动化程序)

- 源程序到可执行目标文件的转换过程：预处理、编译、汇编、链接。P10

  ![image-20211225164435759](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20211225164435759.png)

- 计算机系统抽象层：![image-20211225165352889](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20211225165352889.png)

- **ISA**：指令体系集结构，计算机硬件和软件之间的桥梁

  -  微体系结构和ISA的区别：ISA只是描述了CPU应该支持的每条指令是做什么事的，即**指令的功能**。而微体系结构是描述处理器**实际实现**的。

- 应用程序员与系统程序员、应用软件和系统软件

- **CPI**：执行一条指令所需的时钟周期数
  $$
  用户CPU时间=\frac{程序总时钟周期数}{时钟频率}=程序总时钟周期数\times时钟周期
  		 =CPI\times程序总时钟周期数\times时钟周期
  $$

  $$
  程序总时间周期数=程序总指令条数\times CPI
  $$

-  **MIPS(Million Instructions Per Second)**：平均每秒执行多少百万条指令

   
   $$
   MIPS=\frac{f(频率)}{CPI\times10^6}=\frac{指令条数}{执行时间\times10^6}=\frac{指令条数}{CPU时钟周期总数\times10^6/f}
   $$

   $$
   程序的执行时间T=\frac{指令条数}{MIPS\times10^6}
   $$

   

   ***

   #### 第一章课后习题(6,7,8,10,11)

   - ![image-20211225203537724](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20211225203537724.png)
     1. 单问速度只看执行时间： 
        - 对于P1来说*M1*(10000ms)>*M2*(5000ms)
        - 对于P2来说*M1*(3ms)<*M2*(6ms)
     2. 注：*MIPS*是每**秒**($10^3ms=1s$)执行多少**百万条**（$10^6$）指令
        - *M1*上
          - $p1=\frac{200}{10}=2MIPS$
          - $p2=\frac{0.3}{0.003}=100MIPS$
        - *M2*上
          - $p1=\frac{150}{5}=3MIPS$
          - $p2=\frac{0.42}{0.003}=70MIPS$
     3. 注：$1MHz=10^6Hz$   $1GHz=10^9Hz$ 
        - $M1上CPI=\frac{f(频率)}{MIPS\times10^6}=\frac{800\times10^6}{2\times10^6}=\frac{周期数}{指令条数}=\frac{800\times10}{200}=40$
        - $M2上CPI=\frac{f(频率)}{MIPS\times10^6}=\frac{1.2\times10^9}{3\times10^6}=40$

   - ![image-20211225230907391](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20211225230907391.png)
     1. 
        - $M1的MIPS(f小MIPS大)=\frac{f}{CPI\times10^6}=\frac{1\times10^9}{1\times10^6}=1000$
        - $M2的MIPS(f小MIPS大)=\frac{f}{CPI\times10^6}=\frac{1.5\times10^9}{2\times10^6}=750$
     2.  
        - $M1的平均CPI=\frac{1+2+2+3+4}{5}=2.4$
        - $M2的平均CPI=\frac{2+2+4+5+6}{5}=3.8$
        - $M1的执行时间=\frac{2.4n}{f}=2.4n$
        - $M2的执行时间=\frac{3.8n}{f}=2.53n$
   - ![image-20211226102729547](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20211226102729547.png)
     - $M1的执行时间=0.8n\times4=3.2n$
     - $M2的执行时间=1.2n\times2=2.4n$

   - ![image-20211226103100601](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20211226103100601.png)
     - *S1有10条指令*   *平均CPI为1.9*  $时间周期数为10\times1.9=19$ $执行时间为\frac{19}{500M}$
     - *S2有8条指令*     *平均CPI为3.25* $时间周期数为8\times3.25=26$$$执行时间为\frac{26}{500M}$$
   - ![image-20211226103820244](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20211226103820244.png)
     - 优化的时间为2s，左移减少的CPI为3
     -  $2s=\frac{指令条数\times3}{f}$

***

### 第二章 数据的机器级表示及处理

- 数值转换

  - 整数部分：除基取余，从下往上P34
  - 小数部分：乘积取整，从上往下P34(**存在循环的情况**)

- 机器码的表示方式

  - 原码：*符号位+数值位*，0的表示不唯一
    $$
    -10=(-1010)_2=(1000 1010)_B//8位原码表示
    $$

  - 补码：对于具有一位符号位和n-1的数值位的二进制整数而言，0的表示唯一

    $$
    [X_T]_补=2^n+X_T(-2^{n-1}\leq X_T<2^{n-1})\\
    各位取反，末位+1,即从右往左数第一个1不动，前面各位取反\\
    补码表示范围与移码相同:2^{n-1}-2^{n-1}-1
    $$
    
    - 例题：设补码位数为8位
    
    $$
    [1101100]_补=1101100=01101100\\
    [-1101100]_补=0010100=10010100
    $$
    
  - 反码：各位取反，0的表示不唯一

  - 移码，0的表示唯一
    $$
    [E]_移=偏置常数+E (E为阶数)
    $$
    

- 例2.2.1 P43

  ![image-20211230192218908](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20211230192218908.png)

  ![image-20211230192241882](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20211230192241882.png)

- 浮点数的表示：**IEEE754**

  - 32位浮点数：第1位符号位(1为负) 8位移码表示阶码E(偏置常数128) 23位尾数（默认第一位为1隐藏位可缺省，规格化成0.1bbb的形式）

    - 例题：

    - $$
      19_{10}=10011_B\\
      阶码E=127+4=131=1000 0011\\
      浮点数表示：0\quad10000011\quad100 1100 0000 0000 0000 0000
      $$


  ![image-20211230202247549](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20211230202247549.png)

  - 大端和小端方式P57
    - 大端排序：最高有效字节存放在小地址单元中
    - 小端排序：最高有效字节存放在大地址单元中
    - ![image-20211230203450977](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20211230203450977.png)
  - 位扩展及位截断P63
    - 位扩展
      - 0扩展：无符号数扩展，补0
      - 符号扩展：带符号数扩展，补符号位
    - 位截断：长数转换为短数，可能因为溢出而改变原来的值

***

#### 第二章课后习题(9,10,21,22,23,28,29,34)

- ![image-20211230204949641](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20211230204949641.png)

  ![image-20211230210749386](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20211230210749386.png)

  ![image-20220102161051820](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20220102161051820.png)

  注： unsigned 4个字节
  $$
  \begin{align*}
  & (1)-32768=-2^{15}=1000 0000 0000 0000符号位扩展后=FFFF8000H\\
  & (2)522=512+10=2^9+10=1000 0000 00+1010=080AH\\
  & (3)65530=2^{16}-6=1111 1111 1111 1010=FFFAH扩展到32位=0000FFFAH\\
  & (4)'@'=40H\\
  & ***(5)尾数为-1.1= -1.000 11 0011 0011 0011……    [0011]循环\\
                &\quad = -1.000 1100 1100 1100 1100 1100 1100  舍入处理后最低位加1\\
                &\quad= -1.000 1100 1100 1100 1100 1101\\
       &\quad阶码为 0+127=0111 1111\\
      &\quad所以机器数为：1 0111 1111 000 1100 1100 1100 1100 1101=BF8CCCCDH\\
  &(6)10.5= 1010.1B=1.0101*23\\
        &所以  阶码为 3+1023=100 0000 0010\\
  &故： 机器数为 0 100 0000 0010 0101 0000 0000……
                          =4025 0000 0000 0000H    
  
  
  \end{align*}
  $$

- ![image-20211230214918630](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20211230214918630.png)

- $$
    \begin{align*}
    &(1)0006=0000 0000 0000 0110=a=-1111 1111 1111 1010=-(65535-5)=-65530\\
    &(2)DFFC=-010 0000 0000 0100=-(8192+4)=-8196\\
    &(3)FFFFFFFFa=1....1010=(2^{32}-1)-5=2^{32}-6\\
    &(4)2A=0010 1010=42\\
    &(5)C448 0000=1100 0100 0100 00..0\\
    &阶码E=10001000=128+8=136-127=9\\
    &尾数=-1.1001\\
    &a=-1.10001*2^9=-800
    \end{align*}
    $$

- ​	![image-20220102162318185](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20220102162318185.png)

  ![image-20220102162344598](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20220102162344598.png)

  ```c
  int t=x;
  x<<=4;//x=16x
  x-=t;//x=15x
  if(y<0)y+=3;
  y>>=2;//y=y/4
  return x+y;//所以M=3，N=4
  ```

- ![image-20220102162812688](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20220102162812688.png)

  ![image-20220102163016824](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20220102163016824.png)

- ![image-20220102163327598](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20220102163327598.png)

  ![image-20220102163401675](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20220102163401675.png)

- ![image-20220102163435879](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20220102163435879.png)

  ![image-20220102163504601](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20220102163504601.png)

- ![image-20220102163525589](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20220102163525589.png)

  ![image-20220102163549590](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20220102163549590.png)

- ![image-20220102163636521](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20220102163636521.png)

  ![image-20220102163701250](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20220102163701250.png)

  ![image-20220102163743618](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20220102163743618.png)

  ![image-20220102163823845](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20220102163823845.png)

***

### 第三章 程序的转换及机器级表示

- P87计算机的指令有微指令、机器指令和伪（宏）指令之分。

  - **微指令**属于硬件范畴，微程序命令；
  - **伪指令**是若干机器指令组织的指令序列，属于软件范畴；
  - **机器指令**介于二者之间，处于硬件和软件的交界面。一般指令是指机器指令，**汇编指令**是机器指令的汇编语言表示形式。机器指令与汇编指令一一对应，都与具体机器结构有关，都属于**机器级指令**。

- IA-32各类寻址方式。（P99）

  ![image-20220102164458073](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20220102164458073.png)

  ```c
  movl(%ebx,%esi,4),%eax//a[i]的每个元素长度是4，eax=ebx+4*esi
  ```

- **寄存器编号**

  - ![image-20220107110834206](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20220107110834206.png)

- 常见的汇编指令

  **标志位**

  ```c
  OF//溢出标志，overflow，带符号算数结果是否溢出，溢出即为1
  SF//符号标志，负数即为1
  ZF//零标志，若结果为0，ZF=1
  CF//借位标志，无符号整数运算是否借位，若借位CF=1
  //OF和SF对无符号运算没有意义
  //CF对带符号运算没有意义
  ```

  **指令后缀**：

  ```c
  movb//8位
  movw//16位
  movl//32位 双字
  ```

  **mov指令**

  ```c
  movs//符号扩展传送指令，如movsbw将8位进行符号位扩展传送到另一个16地址中
  movz//零扩展指令，前面补0，如movzwl
  xchg//数据交换，两个寄存器数据交换，如xchgb
  push//压栈，先R[esp]=R[esp]-4，栈的空间向低地址扩展(小端方式存储)，然后将值从指定寄存器送到esp所指单元中
  pop//出栈，先R[esp]=R[esp]+4，将栈顶端的值弹出
  ```

  **lea指令**

  ```c
  //地址传送指令，不能将段寄存器指定为目标寄存器，源操作数必须是存储器寻址方式，
  //可以用作加法
  leal (%edx,%eax),%eax//R[eax]=R[edx]+R[eax]
  leal 8(%ecx,%edx,4),%eax//R[eax]=R[ecx]+4*R[edx]+8
  
  ```

  **算术运算指令**

  ```C
  add/sub//加减指令
  inc/dec//增减指令
  neg//取负指令，各位取反，末位加一
  cmp//比较指令，后接条件转移指令
  mul//乘法指令，结果存放在DX(高16位)-AX(低16位)中
  div//除法指令
  ```

  - **影响的符号位见下表：**

  - ![image-20220103194415732](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20220103194415732.png)

  **逻辑运算**

  ```c
  not//单操作数的取反指令，将操作数的每一位取反，不影响条件标志位
  and//逻辑与&，析取出特定位
  or//逻辑或|，特定位置置1
  xor//异或，改变特定位的值xor 0x1，ax ax最低位取反
  test//两个操作数相与的结果设置条件标志P109
  test $0x1,%al//al-1
  ```

  **移位运算**

  ```c
  shl//逻辑左移，低位补0，高位送进CF shift
  shr//逻辑右移，高位补0，低位送进CF
  sal//算数左移，低位补0，高位送进CF，若移位前后符号位发生变化，OF=1，结果溢出 algorithm
  sar//算数右移，高位补符号位，低位送入CF
  rol//循环左移，左移时将最高位送入最低位和CF rotate
  ror//循环右移，右移时将最低位送入最高位和CF
  rcl//带循环左移，将CF作为操作数的一部分循环左移 rotate CF
  rcl//带循环右移，将CF作为操作数的一部分循环右移
  ```

  **转移指令**

  ![image-20220103200158096](D:\College\大二上\计算机系统基础\image-20220103200158096.png)

  ```c
  n：not
  e：equal =
  a: about >
  b: below <
  o: overflow
  ```

- **过程调用的机器级表示** (*IA-32通过栈来支持过程的嵌套调用*)

  - ![image-20220103201146043](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20220103201146043.png)

  - 约定：
    - 调用者保存寄存器：*EAX ECX EDX*
    - 调用者保存寄存器：*EBX ESI EDI*
    - 现场：通用寄存器中的值

  - 例子：![image-20220103201809476](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20220103201809476.png)

  - ```c
    //汇编代码
    1	.caller
    2	pushl 	%ebp//压入栈底指针
    3	movl	%esp,%ebp//R[ebp]=R[esp]
    4	subl	$24,%esp//R[esp]=R[esp]-24栈空间的初始化
    5	movl	$125,-12(%ebp)//*(R[ebp]-12)=125准备第一个参数即temp1=125
    6	movl	$80,-8(%ebp)//*(R[ebp]-8)=80准备第二个参数即temp2=80
    7	movl	-8(%ebp),%eax//R[eax]=R[ebp]-8 R[eax]=temp2
    8	movl	%eax,4(%esp)//*(R[esp]+4)=R[eax] temp2入栈
    9	movl	-12(%ebp),%eax//R[eax]=R[ebp]-12 eax=temp1
    10	movl	%eax,(%esp)//R[esp]=R[eax] temp1入栈
    11	call	add			//调用add，返回值存入eax
    12	movl	%eax,-4(%ebp)//*(R[ebp]-4)=R[eax]
    13	movl	-4(%ebp),%eax//R[eax]=*(R[ebp]-4) 将eax作为caller的返回值
    14 	leave
    15	ret
        
        
    //add中汇编代码较简单P123
    ```

    

- **选择语句**

  - if语句

    - ![image-20220107101055614](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20220107101055614.png)

      ![image-20220107101122883](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20220107101122883.png)

  - switch语句

    - ```c
      jmp *.L8(,eax,4)//.L8里时起始地址，一位四个字节，通过eax里存放的索引值去跳转到相应地址，具体例子P136
      ```

- **循环语句**

  - *do-while while语句P138*

  - for循环

    - ![image-20220107102023231](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20220107102023231.png)

    - ```c
      1	movl	8(%ebp),ebx//R[ebx]=x;
      2	movl	$0,%eax//R[eax]=0;
      3	movl	$0,%ecx//R[ecx]=0 i=0
      4	.L12
      5	leal	(%eax,%eax),%edx///R[edx]=R[eax]+R[eax]
      6	movl	%ebx,%eax//R[eax]=R[ebx] result=x
      7	andl	$1,%eax//R[eax]&1	x&0x1
      8	orl		%edx,%eax//R[eax]|R[edx] result<<1|x&0x1
      9	shrl	%ebx//R[ebx]<< x=x>>1
      10	addl	$1,%ecx//R[ecx]++ i++
      11	cmpl	$32,%ecx//R[ecx]==32? i!=32
      12	jne		.L12
          
      结果为:
      1	i=0
      2	i!=32
      3	i++
      4	result=result<<1|x&0x1;x=x>>1
      
      
      ```

- **复杂类型的分配与访问**

  - 数组(只有auto型数组被分配在栈中，其他存储型数组都被分配在静态数据区)
    - ![image-20220107104729436](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20220107104729436.png)

  - 数组与指针
    - ![image-20220107104804828](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20220107104804828.png)

- **数据的对齐**

  - ![image-20220107105852265](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20220107105852265.png)


***

#### 第三章课后练习(4、6、11、13、14、19、20、22、23)

- ![image-20220107110941128](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20220107110941128.png)

  - ```js
    1.立即数需要添加$
    2.ax16位mov长度后缀应该是w
    3.目的操作数不能为立即数
    4.立即数大于16位，or后缀应用l
    5.不能用8位寄存器作为目的操作数地址所在寄存器
    6.源操作数寄存器和目的寄存器的宽度不一致
    7.不存在esx寄存器
    8.源操作数地址中缺少变址寄存器
    ```

- ![image-20220107111531859](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20220107111531859.png)

  - ```c
    (1)分别是R[ebp]+8、 R[ebp]+12、 R[ebp]+16。
    
    (2)   函数func的C语言代码如下
                 void func(int *xptr, int *yptr, int *zptr)
                  {
                     int tempx=*xptr;
                     int tempy=*yptr;
                     int tempz=*zptr;
      
                     *yptr=tempx;
                     *zptr=tempy;
                     *xptr=tempz;
                  }
    ```

- ![image-20220107112142986](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20220107112142986.png)

  ![image-20220107112218399](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20220107112218399.png)

  - ```json
    (1)条件转移都是  目标地址=PC+偏移量
     	因为je的操作码是01110100,所以机器代码中7408H中的08H为偏移量，所以转移目标地	   址为：0x804838c+2+0x8=0x8048396
        call中的目标地址0x80483b1=0x804838e+5+0x1e, 由此看出，call指令机器代码中后	   面的4个字节为偏移量，因为IA-32采用小端方式，故偏移量为0000001EH。 Call指令	  本身占5个字节，所以PC=0x804838e+5  
    (2)jb指令中F6H是偏移量，故其转移地址为：0x8048390+2+0xF6=0x8048488
       movl指令中的机器代码有10个字节，前2个字节是操作码，后面8个字节为两个立即数，因	 为是小端方式，所以第一个立即数为0804A800H，即汇编指令中的目的地址0x804a800，    最后4个字节为立即数00000001H,即汇编指令中的常数0x1。
    (3)jle指令中的7EH为操作码，16H为偏移量，其汇编形式中的0x80492e0是转移目的地址，	因此假定后面的mov指令的地址为x，则满足：0x80492e0=x+0x16, 故 
    	x=0x80492e0-0x16=0x80492ca。
    (4)jmp指令中的E9H为操作码，后面4个字节为偏移量，因为是小端方式，故偏移量为FFFFFF00H, 即-100H=-256。后面的sub指令的地址为0x804829b,故jmp指令的转移目标地址为0x804829b+0xffffff00= 0x804829b-0x100=0x804819b
    
    ```

- ![image-20220107112536034](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20220107112536034.png)

  - ```c
    int   func(int x, int y)
    {  int  z=x*y;
        if (x<=-100) {
              if   ( y>x )
                  z=x+y;
              else   
                  z=x-y;
        }else  if (x>=16)
                  z=x&y;
       return z;
    }
    //答案不唯一
    ```

- ![image-20220107112709792](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20220107112709792.png)

  ![image-20220107112730204](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20220107112730204.png)

  - ```c
    (1)   每个入口参数都要按4字节边界对齐，因此x,y,k入栈时都占4个字节。
     1 movw  8(%ebp), %bx        // R[bx]←M[R[ebp]+8], 将x送BX
     2 movw  12(%ebp), %si       // R[bx]←M[R[ebp]+12], 将y送SI
     3 movw  16(%ebp), %cx       // R[bx]←M[R[ebp]+16], 将k送CX
     4 .L1                                
     5  movw  %si, %dx           // R[dx]←R[si],  将y送DX
     6  movw  %dx, %ax           // R[ax]←R[dx], 将y送AX
     7  sarw $15,%dx             // R[dx]← R[dx]>>15, 将y的符号扩展16位送DX
     8  idiv %cx      			//R[dx]←R[dx-ax]÷R[cx]的余数,将y%k送DX 									R[ax]←R[dx-ax]÷R[cx]的商 ，将y/k送AX
     9  imulw %dx, %bx       	 // R[bx]←R[bx]*R[dx], 将x*(y%k)送BX
     10 decw  %cx                // R[cx]←R[cx]-1, 将k-1送CX 
     11 testw %cx, %cx    		// R[cx] and R[cx],得OF=CF=0, 负数则SF=1, 零则ZF=1
     12 jle .L2                 //若k<=0,则转.L2
     13 cmpw  %cx, %si     	    //R[si]-R[cx]  将y与k相减得到各标志
     14 jg  .L1                 //若y>k 则转.L1
     15 .L2
     16 movswl %bx, %eax   		//R[eax] ← R[ebx]  ,将x*(y%k) 送EAX
    
    
    (2)被调用者保存寄存器有：BX  SI， 调用者保存寄存器有：AX  CX  DX，在该函数过程体前面的准备阶段，被调用者保存的寄存器EBX  ESI必须保存到栈中。
    
    
    (3)因为执行第8行除法指令前，必须将被除数扩展为32位，而这里是带符号除法，采用算术右移以扩展16位符号，放在高16位的DX中，低16位放在AX中。
     
    
    ```

- ![image-20220107113313297](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20220107113313297.png)

  ![image-20220107113325528](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20220107113325528.png)

  - ```c
    1 movl  8(%ebp),%ebx
    2 movl $0,%eax
    3  testl %ebx,%ebx
    4  je .L2
    5  movl %ebx,%eax 
    6  shrl $1,%eax
    7  movl  %eax, (%esp)
    8  call refunc 
    9  movl %ebx, %edx
    10 andl $1,%edx 
    11 leal (%edx,%eax), %eax
    12.L2:
         …
         ret
    第1行汇编，说明参数x存放在EBX中，根据第4行判断x=0，则转L2；否则继续执行第5-11行指令。根据第5，6，7行指令可知，入栈参数nx的计算公式为x>>1;根据第9、10、11行指令可知，返回值为(x&1)+rv。
        缺失C代码如下：
    int refunc(unsigned x){
       if (x==0)
             return 0  ;
        unsigned nx= x>>1;
        int rv= refunc(nx);
        return x&0x1+rv;
    }
    
    ```

- ![image-20220107113537684](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20220107113537684.png)

- ![image-20220107113608656](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20220107113608656.png)

  ![image-20220107113617124](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20220107113617124.png)

  - ```c
    根据汇编指令功能可以最终推断最终在EAX中返回的值为：
    M[a+4*(7i+j)]+M[b+4*(5j+i)],
    因数组a和b都是int型，每个数组元素占4B，因此M=5， N=7。
    
    ```

- ![image-20220107113708667](C:\Users\24617\AppData\Roaming\Typora\typora-user-images\image-20220107113708667.png)

  - ```c
    执行第9行指令后，a[i][j][k]的地址为a+4*(63*i+9*j+k),所以，可以推断出中间的N =9 M=63/9=7 .根据第12行指令，可知数组a的大小为4536字节，故L=4536/(4*N*M)=18。
    
    ```

    





