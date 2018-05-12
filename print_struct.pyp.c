#include "print_struct.h"
#include <stdio.h>

%{
#run pymacro showable(
    struct memes{
      int x;
      int  y;
      char *n;
      struct asdf {
        int a;
      } a;
    }
)
}%

int main(){
  struct memes m;
  m.x = 1;
  m.y = 2;
  m.n = "New meme!";
  printmemes(&m);
}
