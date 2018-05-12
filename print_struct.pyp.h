#include <stdio.h>
#include "algebraic-c/macro_iter.h"

%{
#define pymacro showable(struct x):
  %{x.source}%;
  _derive_print(%{x.name}%, %{to_arg_list(x.vals)}%);   
#enddef
}%

#define _generic_print(owner, X) _Generic((owner->X), \
  int: printf("%d", owner->X), \
  char: printf("%c", owner->X), \
  char*: printf("\"%s\"", owner->X), \
  void*: printf("v: %p", owner->X), \
  default: printf("%s", #X)\
  )

//#define _generic_print(x)                                                      \
//  _Generic((x),                                                                \
//  int: "%d",                                                                   \
//  char: "%c",                                                                  \
//  char*: "%s",                                                                 \
//  double: "%f",                                                                \
//  float: "%f",                                                                 \
//  void*: "%p",                                                                 \
//  default: "%d"                                                                \
//  );

#define __print__helper(owner, x)                                              \
  printf(" ");                                                                 \
  _generic_print(owner, x);

#define _derive_print(x, ...)                                                  \
  void print##x(struct x *val){                                                \
    printf("%s", #x);                                                          \
    P1_APPLY_ALL(__print__helper, val, __VA_ARGS__);                           \
    puts("");                                                                  \
  }
