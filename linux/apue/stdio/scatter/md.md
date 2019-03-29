# scatter-gather I/O


```
#include <sys/uio.h>

ssize_t readv (int fd,

               const struct iovec *iov,

               int count)

#include <sys/uio.h>

ssize_t writev(int fd,

               const struct iovec *iov,

               int count)


```


## 返回值
操作成功时，readv() 函数和 write() 函数分别返回读写的字节数。该返回值应该等于所有 count 个 iov_len 的和。出错时，返回-1，并相应设置errno值。这些系统调用可能会返回任何 read() 和 write() 可能返回的错误，而且出错时，设置的 errno 值也与 read(), write() 相同。此外，标准还定义了另外两种错误场景。

第一种场景，由于返回值类型是 ssize_t , 如果所有 count 个iov_len 的和超出SSIZE_MAX, 则不会处理任何数据，返回-1，并把errno值设置为EINVAL。

第二种场景，POSIX指出count值必须大于0，且小于等于IOV_MAX(IOV_MAX在文件<limits.h>定义。在Linux中，当前IOV_MAX的值是1024。如果count为0，该系统调用会返回0。如果count大于IOV_MAX,不会处理任何数据，返回-1，并把errno值设置为EINVAL。

## 优化count值
在向量 I/O 操作中，Linux内核必须分配内部数据结构来表示每个段(segment)。一般来说，是基于count的大小动态分配进行的。然而，为了优化，如果count值足够小，内核会在栈上创建一个很小的段数组，通过避免动态分配段内存，从而获得性能上的一些提升。count 的阀值一般设置为8，，因此如果count值小于或等于8时，向量I/O操作会以一种高效的方式，在进程的内核栈中运行。

大多数情况下，无法选择在指定的向量I/O操作中一次同时传递多少个段。当你认为可以调试一个较小值时，选择8或更小的值肯定会得到性能的提升。

Linux内核把readv() 和writev() 作为系统调用实现，在内部使用分散/聚集 I/O模式。实际上，Linux内核中的所有I/O都是向量I/O，read() 和 write() 是作为向量 I/O来实现的，且向量中只有一个段。

## other
```
#include<unistd.h>

1. int close(int fd);

#include <sys/types.h>

#include <sys/stat.h>

#include <fcntl.h>

1. int open(const char *pathname, int flags);

2. int open(const char *pathname, int flags, mode_t mode);

```
