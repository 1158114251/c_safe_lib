/*
 * test
*/
#include "lib_fifo.h"




int main(int argc, const char *argv[])
{


	struct _fifo *fifo=fifo_init(1024 , 0);
    char p;

    fifo_put(fifo,"a",1);
    fifo_put(fifo,"a",1);
    fifo_put(fifo,"a",1);
    fifo_put(fifo,"a",1);
    fifo_put(fifo,"a",1);

	fifo_get(fifo,&p,1);
    printf("%c\n",p);

	fifo_get(fifo,&p,1);
    printf("%c\n",p);
	fifo_get(fifo,&p,1);
    printf("%c\n",p);
	return 0;
}
