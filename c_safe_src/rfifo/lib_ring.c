#include "lib_link.h"
#include "lib_error.h"


static PTHREAD_PLATFORM_LOCK * global_mutex_lock;

int link_init(link_head * list, PTHREAD_PLATFORM_LOCK * mutex_lock)
{
	list->next=list;
	list->prev=list;
	if(!mutex_lock)
	{
		show_info("lib error ,mutex_lock is NULL!\n");
		return -1;
	}
	global_mutex_lock=mutex_lock;
	return 0;

}


static void  __link_add(link_head * new,link_head * next,link_head * prev)
{

	/*This is the next node of the head node */
	PTHREAD_SAFE_LOCK(global_mutex_lock); 
	next->prev=new;
	new->next=next;
	new->prev=prev;
	prev->next=new;
	PTHREAD_SAFE_UNLOCK(global_mutex_lock); 

}



void link_add_first(link_head * new,link_head * head)
{

	__link_add(new,head->next,head);


}

void link_add_tail(link_head* new,link_head *head)
{

	__link_add(new,head,head->prev);


}




static void __list_del (link_head*next,link_head*prev)
{

	PTHREAD_SAFE_LOCK(global_mutex_lock); 
	next->prev=prev;
	prev->next=next;
	PTHREAD_SAFE_UNLOCK(global_mutex_lock); 

}

/*
 * This delete is delete self
 */

void list_del(link_head * entry_own)
{


	__list_del(entry_own->next,entry_own->prev);

}


int list_is_empty(link_head * head)
{

	return head->next==head;

}

