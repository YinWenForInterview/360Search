题目内容请通过图片链接阅读：https://github.com/zieckey/interview/blob/master/climber_problem/The%20problem.png 

回答问题：
1.没有资源泄露，readFromStr函数中使用的string类自动调用析构函数销毁，使用new[]生成的mountain结构体数组在退出resolve 函数时调用delelte[]删除了开辟的空间。

2.只叙述resolve函数复杂度（M指字符串长度，N指山的数量）：
	进行readFromStr函数时，遍历字符串，时间复杂度O(M),建立结构体,空间复杂度O(N)。
	进行计算总的高度，遍历一遍数组，时间复杂度O(N)。
	
总复杂度O(N+M),空间复杂度O(N)
