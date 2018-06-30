#include "lib_fifo.h"


/*
   =out======used=======in=
   used = in  - out 
   unused= all - used
   */

unsigned int _min (unsigned int a,unsigned int b)
{
	return a < b ? a : b;

}
static int fifo_len(struct _fifo *fifo)
{
	return fifo->size - fifo->in + fifo->out;
}

struct _fifo * fifo_init(unsigned int size,unsigned int more_pth_flag)
{

	struct _fifo * fifo =NULL;

	if(fifo=(struct _fifo *)malloc(sizeof(struct _fifo)),!fifo)
		return NULL;

	if(fifo->buffer=(char *) malloc(size),!fifo->buffer)
	{
		free(fifo);
		return NULL;
	}

	/*Get actual memory when it is initialized, not when it is used.*/
	memset(fifo->buffer,0,size);

	if(more_pth_flag)
	{
		pthread_mutex_t put_lock,get_lock;
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


unsigned int _fifo_get(struct _fifo * fifo, char * buffer, unsigned int size)
{

	unsigned int len;

	assert(!fifo || !buffer);

	size= _min(size,fifo->in-fifo->out);

	len = _min(size, fifo->size - (fifo->out & (fifo->size - 1)));

	memcpy(buffer, fifo->buffer + (fifo->out & (fifo->size - 1)), len);

	memcpy(buffer + len, fifo->buffer, size - len);

	__sync_synchronize();

	fifo->out += size;

	return size;

}

unsigned int _fifo_put(struct _fifo *fifo, char *buffer, unsigned int size)
{
	unsigned int  len ;

	assert(!fifo || !buffer);

	size = _min(size, fifo->size - fifo->in + fifo->out);

	len = _min(size, fifo->size - (fifo->in & (fifo->size - 1)));

	memcpy(fifo->buffer + (fifo->in & (fifo->size - 1)), buffer, len);

	memcpy(fifo->buffer, buffer + len, size - len);

	__sync_synchronize();

	fifo->in += size;

	return size;
}

unsigned int fifo_get(struct _fifo * fifo,char * buffer,unsigned int size)
{

	unsigned int ret_value;

	if(fifo->pth_flag)
		PTHREAD_SAFE_LOCK(&fifo->get_lock);    

	ret_value= _fifo_get(fifo, buffer,size);

	if(fifo->pth_flag)
		PTHREAD_SAFE_UNLOCK(&fifo->get_lock);   

	return ret_value;

}






