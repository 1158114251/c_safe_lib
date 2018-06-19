/*
 * test
 *
 */
#include "lib_error.h"
#include "lib_link.h"
#include <stdio.h>

struct _test
{
	int test_value;
	struct _link_head ll;
};

pthread_mutex_t  test_mutex;


int main(int argc, const char *argv[])
{

	size_t i =0;

	struct _test test, *new ,*con_test_p;
	struct _link_head *pos;

	pthread_mutex_init(&test_mutex, NULL);  

	if (link_init(&test.ll,&test_mutex)<0)

		exit(-1);

	for (i=0;i<20;i++)
	{
		new=(struct _test *)malloc(sizeof(struct _test));
		new->test_value=i;
		link_add_tail(&new->ll,&test.ll);
	}

	list_for_each(pos, &test.ll)
	{ 
		con_test_p = list_entry(pos, struct _test, ll); 
		printf("value:%d\n", con_test_p->test_value); 
	} 

	return 0;
}
