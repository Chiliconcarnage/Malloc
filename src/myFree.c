/*
** myFree.c for myFree in /home/gadrat_r/delivery/PSU/PSU_2016_malloc
**
** Made by Romain Gadrat
** Login   <gadrat_r@epitech.net>
**
** Started on  Thu Feb  9 15:16:47 2017 Romain Gadrat
** Last update Sat Feb 11 21:23:26 2017 Maxence Lauqué
*/

#include "myMalloc.h"

void		free_merge(t_chunk tmp)
{
  t_chunk left;

  if (tmp->next && (tmp->next->free == 0))
    {
      tmp->free_memory_page += tmp->next->free_memory_page;
      if (tmp->next->next)
	{
	  tmp->next->next->prev = tmp;
	  tmp->next = tmp->next->next;
	}
    }
  else if (tmp->prev && (tmp->prev->free == 0))
    {
      left = tmp->prev;
      left->free_memory_page += tmp->free_memory_page;
      left->next = tmp->next;
      if (tmp->next)
	tmp->next->prev = left;
    }
}

void		free(void *ptr)
{
  t_chunk	tmp;

  if (!ptr)
    return ;
  tmp = node;
  while (tmp != NULL && (tmp->ptr != ptr))
    {
      tmp = tmp->next;
    }
  if (tmp != NULL  && (tmp->ptr != ptr))
    {
      tmp->free = 0;
      tmp->free_memory_page += tmp->map_size;
      tmp->map_size = 0;
      tmp->size = 0;
      free_merge(tmp);
      if (tmp->next == NULL && tmp != node)
	{
	  if (tmp->prev != NULL)
	    tmp->prev->next = NULL;
	  brk(tmp);
	}
      return ;
    }
}
