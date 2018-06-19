#include "lib_link.h"
#include "lib_error.h"


static PTHREAD_PLATFORM_LOCK * global_mutex_lock;

int link_init(link_head * list, PTHREAD_PLATFORM_LOCK * mutex_lock)
{
	list->next=list;
	list->prev=list;
	if(!global_mutex_lock)
	{
		show_info("lib error ,mutex_lock is NULL!\n");
		return -1;
	}
    global_mutex_lock=mutex_lock;

}


static void  __link_add(link_head * new,link_head * next,link_head * prev)
{
  
	/*This is the next node of the head node */
	next->prev=new;
    new->next=next;
	new->prev=prev;
    prev->next=new;
    
}



void link_add_first(link_head * new,link_head * head)
{

	PTHREAD_SAFE_LOCK(global_mutex_lock); 

    __link_add(new,head->next,head);

	PTHREAD_SAFE_UNLOCK(global_mutex_lock); 

}

void link_add_tail(link_head* new,link_head *head)
{

	PTHREAD_SAFE_LOCK(global_mutex_lock); 
 
	__link_add(new,head,head->prev);

	PTHREAD_SAFE_UNLOCK(global_mutex_lock); 

}




static void __list_del (link_head *prev,link_head*next)
{



}

void list_del()
{
 
	PTHREAD_SAFE_LOCK(global_mutex_lock); 

	void __list_del()

	PTHREAD_SAFE_UNLOCK(global_mutex_lock); 
}


