/*
** myShowAllocMem.c for show_alloc_mem in /home/gadrat_r/test2/PSU_2016_malloc/src
**
** Made by Romain Gadrat
** Login   <gadrat_r@epitech.net>
**
** Started on  Sat Feb 11 14:59:00 2017 Romain Gadrat
** Last update Sat Feb 11 21:22:46 2017 Maxence Lauqué
*/

#include "myMalloc.h"


void	show_alloc_mem()
{
  t_chunk	tmp;

  tmp = node;

  printf("break : %p\n", sbrk(0));
  while (tmp)
    {
      if (tmp->free == 1)
	printf("%p - %p : %d bytes\n", tmp,				\
	       (void*)((void*)tmp->ptr + tmp->size), (int)tmp->map_size);
      tmp = tmp->next;
    }
}
