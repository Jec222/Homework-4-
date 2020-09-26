//#include "recursive.h"
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

      //return sum(list, size - 1, sum + array[size - 1]);

  /* 
  if (size == 0)  
        return sum; 
  
    // Function Call Observe sum+array[size-1] 
    // to maintain sum of elements 
    return arrSum(array, size - 1, sum + array[size - 1]); 
    // EFFECTS: returns the sum of each element in list

    //          zero if the list is empty.

    */
}

