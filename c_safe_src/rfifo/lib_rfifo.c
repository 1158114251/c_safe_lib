#include "lib_link.h"
#include "lib_error.h"

/*
     =out======used=======in=
     used = in  - out 
     unused= all - used
*/


static unsigned int rfifo_unused(struct __rfifo *fifo)
{
	__sync_synchronize();
	return (fifo->mask + 1) - (fifo->in - fifo->out);
}





