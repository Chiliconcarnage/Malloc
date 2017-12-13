/*
** malloc.c for malloc  in /home/gadrat_r/delivery/PSU/PSU_2016_malloc/src
**
** Made by Romain Gadrat
** Login   <gadrat_r@epitech.net>
**
** Started on  Wed Jan 25 11:46:25 2017 Romain Gadrat
** Last update Sat Feb 11 21:20:28 2017 Maxence Lauqué
*/

#include "myMalloc.h"

t_chunk		node = NULL;

void		*init_first_memory_chunk(size_t size_struct_and_data)
{
  size_t	ret;

  ret = MAX_SIZE;
  while (ret < size_struct_and_data)
    ret += MAX_SIZE;
  if ((node = sbrk(ret)) == (void*)-1)
    return (NULL);
  node->ptr = (void*)((void*)node + SIZE_STRUCT);
  node->next = NULL;
  node->prev = NULL;
  node->size = size_struct_and_data - SIZE_STRUCT;
  node->map_size = size_struct_and_data;
  node->free_memory_page = ret - size_struct_and_data;
  node->free = 1;
  return ((void*)((void*)node + SIZE_STRUCT));
}

void		*finded(t_chunk tmp, size_t s)
{
  t_chunk	new;

  if (tmp->free == 1)
    {
      new = (t_chunk)((void*)tmp->ptr + tmp->size);
      new->ptr = (void*)((void*)new + SIZE_STRUCT);
      new->free = 1;
      new->size = s - SIZE_STRUCT;
      new->map_size = s;
      new->free_memory_page = (tmp->free_memory_page - s);
      tmp->free_memory_page = 0;
      if (tmp->next)
	tmp->next->prev = new;
      new->next = tmp->next;
      new->prev = tmp;
      tmp->next = new;
      return (new->ptr);
    }
  tmp->free = 1;
  tmp->size = s - SIZE_STRUCT;
  tmp->map_size = s;
  tmp->free_memory_page = tmp->free_memory_page - s;
  return (tmp->ptr);
}

void		*resize_mem(size_t s)
{
  t_chunk	tmp;
  size_t	ret;

  tmp = node;
  ret = MAX_SIZE;
  while (ret < s)
    ret += MAX_SIZE;
  if ((sbrk(ret)) == (void*)-1)
    return (NULL);
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->free_memory_page += ret;
  return (finded(tmp, s));
}

void		*malloc(size_t size)
{
  size_t	size_struct_and_data;
  t_chunk	tmp;
  void		*p;

  size_struct_and_data = align(SIZE_STRUCT + size);
  if (node == NULL)
    {
      p = init_first_memory_chunk(size_struct_and_data);
      return (p);
    }
  else
    {
      tmp = node;
      while (tmp != NULL && (tmp->free_memory_page < size_struct_and_data))
	tmp = tmp->next;
      if (tmp == NULL)
	return (resize_mem(size_struct_and_data));
      else
	return (finded(tmp, size_struct_and_data));
    }
  return (NULL);
}
