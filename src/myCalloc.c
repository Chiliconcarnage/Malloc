/*
** myCalloc.c for myCalloc in /home/gadrat_r/delivery/PSU/PSU_2016_malloc/src
**
** Made by Romain Gadrat
** Login   <gadrat_r@epitech.net>
**
** Started on  Tue Feb  7 09:48:04 2017 Romain Gadrat
** Last update Fri Feb 10 18:59:12 2017 Romain Gadrat
*/

#include "myMalloc.h"

void		*calloc(size_t nbMalloc, size_t size)
{
  void		*mem;
  size_t	tot;

  tot = nbMalloc * size;
  if (!tot)
    return (malloc(size));
  if (size && (tot / size != nbMalloc))
    return (NULL);
  if ((mem = malloc(tot)) == NULL)
    return (NULL);
  return (memset(mem, 0, tot));
}
