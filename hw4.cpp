#include "recursive.h"
//#include "hw3.h"

int accumulate(list_t l, int (*fn)(int, int), int base)
{
  if (list_isEmpty(l)) {
    return base;
  } else {
    return accumulate(list_rest(l), fn, fn(base, list_first(l)));
  }
}
int sum(list_t list){
  
  if (list_isEmpty(list))
    return 0;

  return list_first(list) +sum(list_rest(list));
}
int product(list_t list){

  if (list_isEmpty(list))
    return 1;

  return list_first(list) * product(list_rest(list));
}
list_t reverse(list_t list){

  if(list_isEmpty(list))
    return list_make();

  return list_make( list_first(list), list_rest(list));

      /*
    // EFFECTS: returns the reverse of list
    //
    // For example: the reverse of ( 3 2 1 ) is ( 1 2 3 )
    */

}



