/*
** myMalloc.h for myMalloc in /home/gadrat_r/delivery/PSU/PSU_2016_malloc/include
**
** Made by Romain Gadrat
** Login   <gadrat_r@epitech.net>
**
** Started on  Wed Jan 25 11:52:51 2017 Romain Gadrat
** Last update Sun Feb 12 19:25:11 2017 Romain Gadrat
*/

#ifndef MYMALLOC_H_
# define MYMALLOC_H_

# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>

typedef struct	s_chunk *t_chunk;
struct	s_chunk
{
  size_t		map_size;
  size_t		free_memory_page;
  size_t		size;
  int			free;
  t_chunk		next;
  t_chunk		prev;
  void			*ptr;
};

extern t_chunk		node;
#ifndef __X86_64__
# define POINT_ALIGN (16)
# else
# define POINT_ALIGN (8)
#endif

# define SIZE_STRUCT (sizeof(struct s_chunk))
# define align(x) ((((x - 1) / 4) * 4) + 4)
# define MAX_SIZE align((POINT_ALIGN * 10 * sysconf(_SC_PAGESIZE)))

void		free(void *ptr);
void		free_merge(t_chunk tmp);
t_chunk		*init_new_memory_chunk(size_t size);
t_chunk		*add_new_memory_chunk(size_t size, int check);
void		*malloc(size_t size);
void		*realloc(void *ptr, size_t size);
bool		chunk_is_free(size_t size);
void		show_alloc_mem();

#endif /* !MYMALLOC_H_ */
