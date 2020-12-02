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
 list_t reverse_helper(list_t list,list_t l){

  if(!list_isEmpty(list)){
    l=list_make(list_first(list),l);
    return reverse_helper( list_rest(list),l);
  }
  return l;
 }
list_t reverse(list_t list){

  if (list_isEmpty(list))
    return list_make();

  return reverse_helper(list, list_make());
}

list_t append(list_t first, list_t second){

  if (list_isEmpty(first))
    return second;

  return append( list_make(list_first(first),list_make()), second);
}
static bool odd(int x){
   if(x&&1)
       return true;
   else
       return false;
}

list_t filter(list_t list, bool (*fn)(int)){

   list_t l=list_make();
   list_t f=list_make();

   int x;
   while(!list_isEmpty(list)){
      
       x = list_first(list);
       list = list_rest(list);
       if(fn(x))
           l=list_make(x,l);
   }

   while(!list_isEmpty(l)){
  
       x=list_first(l);
       f=list_make(x,f);
       l=list_rest(l);
   }
   return f;

    /*
    // EFFECTS: returns a list containing precisely the elements of list
    //          for which the predicate fn() evaluates to true, in the
    //          order in which  they appeared in list.
    */
}
static list_t FilterOddHelper(list_t list,list_t new_list) {
  if(list_isEmpty(list)) {
    return new_list;
  }
  if((list_first(list) % 2)) {
    new_list = list_make(list_first(list), new_list);
  }
  return FilterOddHelper(list_rest(list),new_list);
}

list_t filter_odd(list_t list){
  
  list_t new_list = list_make();
  return reverse(FilterOddHelper(list,new_list));
   return filter(list,odd);
 
}

