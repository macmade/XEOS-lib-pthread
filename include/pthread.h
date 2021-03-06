/*******************************************************************************
 * XEOS - X86 Experimental Operating System
 * 
 * Copyright (c) 2010-2013, Jean-David Gadina - www.xs-labs.com
 * All rights reserved.
 * 
 * XEOS Software License - Version 1.0 - December 21, 2012
 * 
 * Permission is hereby granted, free of charge, to any person or organisation
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to deal in the Software, with or without
 * modification, without restriction, including without limitation the rights
 * to use, execute, display, copy, reproduce, transmit, publish, distribute,
 * modify, merge, prepare derivative works of the Software, and to permit
 * third-parties to whom the Software is furnished to do so, all subject to the
 * following conditions:
 * 
 *      1.  Redistributions of source code, in whole or in part, must retain the
 *          above copyright notice and this entire statement, including the
 *          above license grant, this restriction and the following disclaimer.
 * 
 *      2.  Redistributions in binary form must reproduce the above copyright
 *          notice and this entire statement, including the above license grant,
 *          this restriction and the following disclaimer in the documentation
 *          and/or other materials provided with the distribution, unless the
 *          Software is distributed by the copyright owner as a library.
 *          A "library" means a collection of software functions and/or data
 *          prepared so as to be conveniently linked with application programs
 *          (which use some of those functions and data) to form executables.
 * 
 *      3.  The Software, or any substancial portion of the Software shall not
 *          be combined, included, derived, or linked (statically or
 *          dynamically) with software or libraries licensed under the terms
 *          of any GNU software license, including, but not limited to, the GNU
 *          General Public License (GNU/GPL) or the GNU Lesser General Public
 *          License (GNU/LGPL).
 * 
 *      4.  All advertising materials mentioning features or use of this
 *          software must display an acknowledgement stating that the product
 *          includes software developed by the copyright owner.
 * 
 *      5.  Neither the name of the copyright owner nor the names of its
 *          contributors may be used to endorse or promote products derived from
 *          this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT OWNER AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE, TITLE AND NON-INFRINGEMENT ARE DISCLAIMED.
 * 
 * IN NO EVENT SHALL THE COPYRIGHT OWNER, CONTRIBUTORS OR ANYONE DISTRIBUTING
 * THE SOFTWARE BE LIABLE FOR ANY CLAIM, DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN ACTION OF CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF OR IN CONNECTION WITH
 * THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 ******************************************************************************/

/*!
 * @author          Jean-David Gadina
 * @copyright       (c) 2010-2015, Jean-David Gadina - www.xs-labs.com
 */

#ifndef XEOS_LIB_PTHREAD_PTHREAD_H
#define XEOS_LIB_PTHREAD_PTHREAD_H

#ifdef __cplusplus
extern "C" {
#endif

#include <system/types/pthread_attr_t.h>
#include <system/types/pthread_barrier_t.h>
#include <system/types/pthread_barrierattr_t.h>
#include <system/types/pthread_cond_t.h>
#include <system/types/pthread_condattr_t.h>
#include <system/types/pthread_key_t.h>
#include <system/types/pthread_mutex_t.h>
#include <system/types/pthread_mutexattr_t.h>
#include <system/types/pthread_once_t.h>
#include <system/types/pthread_rwlock_t.h>
#include <system/types/pthread_rwlockattr_t.h>
#include <system/types/pthread_spinlock_t.h>
#include <system/types/pthread_t.h>

#include <sched.h>
#include <time.h>

#define PTHREAD_CANCELED                ( ( void * )1 )

#define PTHREAD_CANCEL_DISABLE          0x00
#define PTHREAD_CANCEL_ENABLE           0x01
#define PTHREAD_CANCEL_DEFERRED         0x02
#define PTHREAD_CANCEL_ASYNCHRONOUS     0x03

#define PTHREAD_CREATE_JOINABLE         0x01
#define PTHREAD_CREATE_DETACHED         0x02

#define PTHREAD_MUTEX_NORMAL            0x00
#define PTHREAD_MUTEX_DEFAULT           0x00
#define PTHREAD_MUTEX_ERRORCHECK        0x01
#define PTHREAD_MUTEX_RECURSIVE         0x02
#define PTHREAD_MUTEX_ROBUST            0x03
#define PTHREAD_MUTEX_STALLED           0x04

#define PTHREAD_PRIO_NONE               0x00
#define PTHREAD_PRIO_INHERIT            0x01
#define PTHREAD_PRIO_PROTECT            0x02

#define PTHREAD_PROCESS_SHARED          0x01
#define PTHREAD_PROCESS_PRIVATE         0x02

#define PTHREAD_INHERIT_SCHED           0x01
#define PTHREAD_EXPLICIT_SCHED          0x02

#define PTHREAD_SCOPE_SYSTEM            0x01
#define PTHREAD_SCOPE_PROCESS           0x02

#define PTHREAD_BARRIER_SERIAL_THREAD   0x00

int         pthread_create( pthread_t * restrict thread, const pthread_attr_t * restrict attr, void * ( * start_routine )( void * ), void * restrict arg );
int         pthread_once( pthread_once_t * once_control, void ( * init_routine )( void ) );
int         pthread_cancel( pthread_t thread );
void        pthread_exit( void * value_ptr );
int         pthread_detach( pthread_t thread );
int         pthread_join( pthread_t thread, void ** value_ptr );
int         pthread_equal( pthread_t t1, pthread_t t2 );
void        pthread_testcancel( void );
pthread_t   pthread_self( void );
int         pthread_atfork( void ( * prepare )( void ), void ( * parent )( void ), void ( * child )( void ) );

int         pthread_getconcurrency( void );
int         pthread_setconcurrency( int new_level );
int         pthread_getschedparam( pthread_t thread, int * restrict policy, struct sched_param * restrict param );
int         pthread_setschedparam( pthread_t thread, int policy, const struct sched_param * param );
void *      pthread_getspecific( pthread_key_t key );
int         pthread_setspecific( pthread_key_t key, const void * value );
int         pthread_setcancelstate( int state, int * oldstate );
int         pthread_setcanceltype( int type, int * oldtype );
int         pthread_getcpuclockid( pthread_t thread_id, clockid_t * clock_id );

int         pthread_attr_init( pthread_attr_t * attr );
int         pthread_attr_destroy( pthread_attr_t * attr );
int         pthread_attr_getdetachstate( const pthread_attr_t * attr, int * detachstate );
int         pthread_attr_setdetachstate( pthread_attr_t * attr, int detachstate );
int         pthread_attr_getguardsize( const pthread_attr_t * restrict attr, size_t * restrict guardsize );
int         pthread_attr_setguardsize( pthread_attr_t * attr, size_t guardsize );
int         pthread_attr_getinheritsched( const pthread_attr_t * restrict attr, int * restrict inheritsched );
int         pthread_attr_setinheritsched( pthread_attr_t * attr, int inheritsched );
int         pthread_attr_getschedparam( const pthread_attr_t * restrict attr, struct sched_param * restrict param );
int         pthread_attr_setschedparam( pthread_attr_t * restrict attr, const struct sched_param * restrict param );
int         pthread_attr_getschedpolicy( const pthread_attr_t * restrict attr, int * restrict policy );
int         pthread_attr_setschedpolicy( pthread_attr_t * attr, int policy );
int         pthread_attr_getscope( const pthread_attr_t * restrict attr, int * restrict contentionscope );
int         pthread_attr_setscope( pthread_attr_t * attr, int contentionscope );
int         pthread_attr_getstack( const pthread_attr_t * restrict attr, void ** restrict stackaddr, size_t * restrict stacksize );
int         pthread_attr_setstack( pthread_attr_t * attr, void * stackaddr, size_t stacksize );
int         pthread_attr_getstacksize( const pthread_attr_t * restrict attr, size_t * restrict stacksize );
int         pthread_attr_setstacksize( pthread_attr_t * attr, size_t stacksize );

int         pthread_barrier_init( pthread_barrier_t * restrict barrier, const pthread_barrierattr_t * restrict attr, unsigned count );
int         pthread_barrier_destroy( pthread_barrier_t * barrier );
int         pthread_barrier_wait( pthread_barrier_t * barrier );

int         pthread_barrierattr_init( pthread_barrierattr_t * attr );
int         pthread_barrierattr_destroy( pthread_barrierattr_t * attr );
int         pthread_barrierattr_getpshared( const pthread_barrierattr_t * restrict attr, int * restrict pshared );
int         pthread_barrierattr_setpshared( pthread_barrierattr_t * attr, int pshared );

void        pthread_cleanup_push( void ( * routine )( void * ), void * arg );
void        pthread_cleanup_pop( int execute );

int         pthread_cond_init( pthread_cond_t * restrict cond, const pthread_condattr_t * restrict attr );
int         pthread_cond_destroy( pthread_cond_t * cond );
int         pthread_cond_broadcast( pthread_cond_t * cond );
int         pthread_cond_signal( pthread_cond_t * cond );
int         pthread_cond_wait( pthread_cond_t * restrict cond, pthread_mutex_t * restrict mutex );
int         pthread_cond_timedwait( pthread_cond_t * restrict cond,  pthread_mutex_t * restrict mutex, const struct timespec * restrict abstime );

int         pthread_condattr_init( pthread_condattr_t * attr );
int         pthread_condattr_destroy( pthread_condattr_t * attr );
int         pthread_condattr_getpshared( const pthread_condattr_t * restrict attr, int * restrict pshared );
int         pthread_condattr_setpshared( pthread_condattr_t * attr, int pshared );
int         pthread_condattr_getclock( const pthread_condattr_t * restrict attr, clockid_t * restrict clock_id );
int         pthread_condattr_setclock( pthread_condattr_t * attr, clockid_t clock_id );

int         pthread_key_create( pthread_key_t * key, void ( * destructor )( void * ) );
int         pthread_key_delete( pthread_key_t key );

int         pthread_mutex_init( pthread_mutex_t * restrict mutex, const pthread_mutexattr_t * restrict attr );
int         pthread_mutex_destroy( pthread_mutex_t * mutex );
int         pthread_mutex_lock( pthread_mutex_t * mutex );
int         pthread_mutex_trylock( pthread_mutex_t * mutex );
int         pthread_mutex_unlock( pthread_mutex_t * mutex );
int         pthread_mutex_getprioceiling( const pthread_mutex_t * restrict mutex, int * restrict prioceiling );
int         pthread_mutex_setprioceiling( pthread_mutex_t * restrict mutex, int prioceiling, int * restrict old_ceiling );
int         pthread_mutex_timedlock( pthread_mutex_t * restrict mutex, const struct timespec * restrict abs_timeout );
int         pthread_mutex_consistent( pthread_mutex_t * mutex );

int         pthread_mutexattr_init( pthread_mutexattr_t * attr );
int         pthread_mutexattr_destroy( pthread_mutexattr_t * attr );
int         pthread_mutexattr_getprioceiling( const pthread_mutexattr_t * restrict attr, int * restrict prioceiling );
int         pthread_mutexattr_setprioceiling( pthread_mutexattr_t * attr, int prioceiling );
int         pthread_mutexattr_getprotocol( const pthread_mutexattr_t * restrict attr, int * restrict protocol );
int         pthread_mutexattr_setprotocol( pthread_mutexattr_t * attr, int protocol );
int         pthread_mutexattr_getpshared( const pthread_mutexattr_t * restrict attr, int * restrict pshared );
int         pthread_mutexattr_setpshared( pthread_mutexattr_t * attr, int pshared );
int         pthread_mutexattr_gettype( const pthread_mutexattr_t * restrict attr, int * restrict type );
int         pthread_mutexattr_settype( pthread_mutexattr_t * attr, int type );
int         pthread_mutexattr_getrobust( const pthread_mutexattr_t * restrict attr, int * restrict robust );
int         pthread_mutexattr_setrobust( pthread_mutexattr_t * attr, int robust );

int         pthread_rwlock_init( pthread_rwlock_t * restrict rwlock, const pthread_rwlockattr_t * restrict attr );
int         pthread_rwlock_destroy( pthread_rwlock_t * rwlock );
int         pthread_rwlock_rdlock( pthread_rwlock_t * rwlock );
int         pthread_rwlock_wrlock( pthread_rwlock_t * rwlock );
int         pthread_rwlock_tryrdlock( pthread_rwlock_t * rwlock );
int         pthread_rwlock_trywrlock( pthread_rwlock_t * rwlock );
int         pthread_rwlock_unlock( pthread_rwlock_t * rwlock );
int         pthread_rwlock_timedrdlock( pthread_rwlock_t * restrict rwlock, const struct timespec * restrict abs_timeout );
int         pthread_rwlock_timedwrlock( pthread_rwlock_t * restrict rwlock, const struct timespec * restrict abs_timeout );

int         pthread_rwlockattr_init( pthread_rwlockattr_t * attr );
int         pthread_rwlockattr_destroy( pthread_rwlockattr_t * attr );
int         pthread_rwlockattr_getpshared( const pthread_rwlockattr_t * restrict attr, int * restrict pshared );
int         pthread_rwlockattr_setpshared( pthread_rwlockattr_t * attr, int pshared );

int         pthread_spin_init( pthread_spinlock_t * lock, int pshared );
int         pthread_spin_destroy( pthread_spinlock_t * lock );
int         pthread_spin_lock( pthread_spinlock_t * lock );
int         pthread_spin_trylock( pthread_spinlock_t * lock );
int         pthread_spin_unlock( pthread_spinlock_t * lock );

#ifdef __cplusplus
}
#endif

#endif /* XEOS_LIB_PTHREAD_PTHREAD_H */
