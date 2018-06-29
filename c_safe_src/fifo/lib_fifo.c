#include "lib_fifo.h"

/*
     =out======used=======in=
     used = in  - out 
     unused= all - used
*/


static unsigned int fifo_unused(struct __rfifo *fifo)
{
	__sync_synchronize();
	return (fifo->mask + 1) - (fifo->in - fifo->out);
}

struct _fifo * fifo_init(unsigned int size,unsigned int more_pth_flag)
{

	struct _fifo * fifo =NULL;
    if(fifo=(struct _fifo *)malloc(sizeof(struct _fifo)),!fifo)
		return fifo;
	if(fifo->buffer=(char *) malloc(size),!fifo->buffer)
	{
		free(fifo);
		return fifo->buffer;
	}

	/*Get actual memory when it is initialized, not when it is used.*/
	memset(fifo->buffer,0,size);

	if(more_pth_flag)
	{
		pthread_mutex_init(&put_lock,NULL);
		pthread_mutex_init(&get_lock,NULL);
	}
	fifo->size = size;
	fifo->in = 0;
	fifo->out = 0;
	fifo->pth_flag=more_pth_flag;
    
   return fifo;

}

void fifo_free(struct _fifo * fifo)
{
   if(fifo)
   {
	   if(fifo->buffer)
		   free(fifo->buffer);
	   free(fifo);
	   fifo=NULL;
	   fifo->buffer=NULL;
   }

}
