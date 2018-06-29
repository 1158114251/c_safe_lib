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

# ifndef __LIB_SHARE
# define __LIB_SHARE
# include <stdio.h>
# include <stdlib.h>

/*
 * This library supports linux and windows, but windows does not have time to test. Currently, it is mainly linux. 
 * Some mutexes are used in the library. This may affect efficiency, but for the sake of thread safety, 
 *  the granularity of the lock has been reduced as much as possible.
 */

#ifdef __linux	
# include <pthread.h>
# define PTHREAD_PLATFORM_LOCK       pthread_mutex_t 
# define PTHREAD_SAFE_LOCK(LOCK)     pthread_mutex_lock(LOCK)
# define PTHREAD_SAFE_UNLOCK(LOCK)   pthread_mutex_unlock(LOCK)

#else



#endif
#endif



