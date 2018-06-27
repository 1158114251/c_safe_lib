#include "lib_link.h"
#include "lib_error.h"

static unsigned int kfifo_unused(struct __rfifo *fifo)
{
		return (fifo->mask + 1) - (fifo->in - fifo->out);
}
