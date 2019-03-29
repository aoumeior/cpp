
#include <iostream>
#include <memory>
#include <malloc.h>

#define local_type __attribute__((cleanup(my_free)))

int *m;

static void my_free(void *pmem)
{
  void **ppmem = (void **)pmem;
  free(*ppmem);
  *ppmem = NULL;
  m = (int *)ppmem;
  std::cout << __FUNCTION__ << std::endl;
}

int main(void)
{

  {
    local_type int *p = (int *)malloc(sizeof(int));

  } // action scope - call my_free

  std::cout << (int)*m << std::endl;
  return 0;
}