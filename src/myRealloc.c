/*
** realloc.c for realloc in /home/gadrat_r/delivery/PSU/PSU_2016_malloc/src
**
** Made by Romain Gadrat
** Login   <gadrat_r@epitech.net>
**
** Started on  Wed Jan 25 11:46:34 2017 Romain Gadrat
** Last update Fri Feb 10 19:04:45 2017 Romain Gadrat
*/

#include "myMalloc.h"

void		*realloc(void *ptr, size_t size)
{
  void          *new;
  t_chunk	tmp;

  if (!size || !(new = malloc(size)))
    {
      if (size)
	free(ptr);
      return (NULL);
    }
  if (!ptr)
    return (new);
  tmp = ((t_chunk)((void *)ptr - SIZE_STRUCT));
  if (size < tmp->size)
    new = memcpy(new, ptr, size);
  else
    new = memcpy(new, ptr, tmp->size);
  free(ptr);
  return (new);
}
