# Solutions-Sorted&DP

### Climbing Stairs
This question equals to ask you if you are already at stair i-1 or i-2, you can step 1 or 2 steps relatively to the final stair i. Then this question can be splited to find ans(i) = ans(i-1) + ans(i-2).
There are few existing solutions:
1. Fibonacci Sequence.

2. Iteratively Computing c = a + b, a = b, b = c;

3. Let $Q_n$

   ![image-20190412140739396](https://ws2.sinaimg.cn/large/006tNc79ly1g1zthc9kjxj304j01vwea.jpg)

   We can compute $F_{n+1}=Q^n[0,0]$

   Initilize $Q_1 = [1,1;1,0]$,  We can compute $F^{n+1}$ by  $Q^n[0][0]$

   ![image-20190412141308086](https://ws1.sinaimg.cn/large/006tNc79ly1g1ztmzkzjxj30i001mq2v.jpg)

   Also, we can use quick power multipy method to accelerate above progression to $O(log(n))​$ time.

   

   

