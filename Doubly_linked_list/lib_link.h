/*
 * Copyright 2018 zf-online <zf-online@qq.com>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 * AUTHOR: ZHANGFEIONLINE
 * 
*/

# ifndef __LIB_LINK
# define __LIB_LINK
# include <stdio.h>
# include <stdlib.h>

/*
 * This platform is linux ,the mutex is make pthread safe!
 */

#ifdef linux	
# include <pthread.h>
# define PTHREAD_PLATFORM_LOCK       pthread_mutex_t 
# define PTHREAD_SAFE_LOCK(LOCK)     pthread_mutex_lock(LOCK)
# define PTHREAD_SAFE_UNLOCK(LOCK)   pthread_mutex_unlock(LOCK)
#endif

#ifdef WINDOWSi

#endif
// 获得结构体(TYPE)的变量成员(MEMBER)在此结构体中的偏移量。
#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
// 根据"结构体(type)变量"中的"域成员变量(member)的指针(ptr)"来获取指向整个结构体变量的指针
#define container_of(ptr, type, member) ({          \
const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
 (type *)( (char *)__mptr - offsetof(type,member) );})

typedef struct _link_head
{
	struct _link_head * next,*prev;
}link_head,*link_head_p;


int link_init(link_head * list, PTHREAD_PLATFORM_LOCK * mutex_lock);

void link_add_first(link_head * new,link_head * head);

void link_add_tail(link_head* new,link_head *head);

void list_del(link_head * entry_own);

int list_is_empty(link_head * head);

#define list_for_each(pos,head)\
	for (pos = (head)->next; pos != (head); pos = pos->next)
#define list_entry(ptr, type, member) \
     container_of(ptr, type, member)
# endif 

