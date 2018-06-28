## c_safe_lib  ![start this repo](https://img.shields.io/github/stars/1158114251/c_safe_lib.svg) ![license](https://img.shields.io/github/license/1158114251/c_safe_lib.svg)

c线程安全库,这个项目的目的是创造一套可以工程使用的c数据结构库，在实际工程中一套优秀高效的数据结构库是必不可少的。
主要解决俩个方面：

- 1.线程安全 
- 2.跨平台 linux 、windows


### 实现原理
1.list
底层实现是基于双向循环链表,在该库中不会实现单向链表，因为单链表能解决的问题，双向循环链表可以更好解决！

2.rfifo
底层是一个环形队列。一般用作缓存区，初始化的时候就申请固定大小。

3.queue
底层是普通的队列。



## 注意：

 这个库支持linux和windows，但是windows目前没有时间测试，现在主要是linux平台。为了保证线程安全库中使用了互斥锁，这可能会影响效率，但已经尽可能减小锁粒度。

Note:

This library supports linux and windows, but windows does not have time to test. Currently, it is mainly linux. 
Some mutexes are used in the library. This may affect efficiency, but for the sake of thread safety, 
the granularity of the lock has been reduced as much as possible.




 
