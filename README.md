## c_safe_lib  ![start this repo](https://img.shields.io/github/stars/1158114251/c_safe_lib.svg) ![license](https://img.shields.io/github/license/1158114251/c_safe_lib.svg)

c线程安全库,这个项目的目的是创造一套可以工程使用的c数据结构库，在实际工程中一套优秀高效的数据结构库是必不可少的。
主要解决俩个方面：

- 1.线程安全 
- 2.跨平台 linux 、windows


### 实现原理

功能 | 状态 | 实现原理
---|---|---
list|实现中 |双向循环链表
rfifo|基本实现|环形队列
queue|实现中|普通的队列

## 构建方式

构建该项目需要gcc版本>=4.6 主要原因是该项目中使用了内存屏障实现lock free


## 注意：

 这个库支持linux和windows，但是windows目前没有时间测试，现在主要是linux平台。为了保证线程安全库中使用了互斥锁，这可能会影响效率，但已经尽可能减小锁粒度。

Note:

This library supports linux and windows, but windows does not have time to test. Currently, it is mainly linux. 
Some mutexes are used in the library. This may affect efficiency, but for the sake of thread safety, 
the granularity of the lock has been reduced as much as possible.




## 联系我：
 
若你遇到问题、有了更好的建议或者想要一些新功能，都可以直接在GitHub上提交Issues

或者直接邮件我，我的邮箱是：1158114251@qq.com
