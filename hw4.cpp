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

      /* 
    // EFFECTS: returns the product of each element in list
    //          one if the list is empty.
    */
}


