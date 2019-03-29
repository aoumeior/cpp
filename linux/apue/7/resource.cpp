/*************************************************************************
    > File Name: resource.cpp
    > Author: aoumeior
    > Mail: aoumeior@outlook.com 
    > Created Time: 2018年02月19日 星期一 14时20分50秒
 ************************************************************************/

#include <sys/types.h>
#include <sys/times.h>
#include <sys/resource.h>
#include <stdio.h>

#define doit(name) \
	pt_limits(#name, name)

static void pt_limits(char *, int);
int main()
{

	doit(RLIMIT_CORE);  /* core文件的最大字节数，若数值为0 则阻止创建core文件 */
	doit(RLIMIT_CPU);   /* cpu 时间的最大量值，当超过此软限制时，向该进程佛送SIGXCPU 信号*/
	doit(RLIMIT_DATA);  /* 数据段的最大字节长度，这是初始化数据、非初始化数据以及堆的总和。*/
	doit(RLIMIT_FSIZE); /* 可以创建文件的字节的最大长度，超此软限制时，则向该进程发送SIGXFSZ信号*/

#ifdef RLIMIT_MEMLOCK
	doit(RLIMIT_MEMLOCK); /* 锁定在存储器地址空间（没有实现）*/
#endif

#ifdef RLIMIT_NOFILE
	doit(RLIMIT_NOFILE); /* 每个进程能打开最大的文件数量，更改此限制将影响到sysconf函数在参数_SC_OPEN_MAX中返回的数值 */
#endif

#ifdef RLIMIT_OFILE
	doit(RLIMIT_OFILE);
#endif

#ifdef RLIMIR_NPROC
	doit(RLIMIR_NPROC);
#endif

#ifdef RLIMIT_RSS
	doit(RLIMIT_RSS);
#endif

#ifdef RLIMIT_STACK
	doit(RLIMIT_STACK);
#endif

#ifdef RLIMIT_VMEM
	doit(RLIMIT_VMEM)
#endif
		return 0;
}

static void pt_limits(char *name, int resource)
{

	struct rlimit limit;

	if (getrlimit(resource, &limit) < 0)
	{
		printf("getrlimit error for %s", name);
		return;
	}

	printf("%-15s ", name);

	if (limit.rlim_cur == RLIM_INFINITY)
		printf("(infinite) ");
	else
		printf("%10ld ", limit.rlim_cur);
	if (limit.rlim_max == RLIM_INFINITY)
		printf("(infinite) \n");
	else
		printf("%10ld\n", limit.rlim_max);
}
