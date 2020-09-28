/*
 * Copyright (c) 2019 TAOS Data, Inc. <jhtao@taosdata.com>
 *
 * This program is free software: you can use, redistribute, and/or modify
 * it under the terms of the GNU Affero General Public License, version 3
 * or later ("AGPL"), as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TDENGINE_OS_ARM32_H
#define TDENGINE_OS_ARM32_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <argp.h>
#include <arpa/inet.h>
#include <assert.h>
#include <ctype.h>
#include <dirent.h>
#include <endian.h>
#include <errno.h>
#include <float.h>
#include <ifaddrs.h>
#include <libgen.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <pthread.h>
#include <pwd.h>
#include <regex.h>
#include <semaphore.h>
#include <signal.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <strings.h>
#include <sys/epoll.h>
#include <sys/eventfd.h>
#include <sys/file.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/sendfile.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <sys/statvfs.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/un.h>
#include <syslog.h>
#include <termios.h>
#include <unistd.h>
#include <wchar.h>
#include <wordexp.h>
#include <wctype.h>
#include <inttypes.h>
#include <fcntl.h>
#include <sys/utsname.h>
#include <sys/resource.h>
#include <error.h>

#define TAOS_OS_FUNC_LZ4
  #define BUILDIN_CLZL(val) __builtin_clzll(val)
  #define BUILDIN_CTZL(val) __builtin_ctzll(val)
  #define BUILDIN_CLZ(val) __builtin_clz(val)
  #define BUILDIN_CTZ(val) __builtin_ctz(val)

#define TAOS_OS_FUNC_ATOMIC
  #define atomic_load_8(ptr) __atomic_load_n((ptr), __ATOMIC_SEQ_CST)
  #define atomic_load_16(ptr) __atomic_load_n((ptr), __ATOMIC_SEQ_CST)
  #define atomic_load_32(ptr) __atomic_load_n((ptr), __ATOMIC_SEQ_CST)
  #define atomic_load_64(ptr) __atomic_load_n((ptr), __ATOMIC_SEQ_CST)
  #define atomic_load_ptr(ptr) __atomic_load_n((ptr), __ATOMIC_SEQ_CST)

  //specify for arm32
  #define atomic_store_8(ptr, val)   (*(ptr)=(val))

  #define atomic_store_16(ptr, val) __atomic_store_n((ptr), (val), __ATOMIC_SEQ_CST)
  #define atomic_store_32(ptr, val) __atomic_store_n((ptr), (val), __ATOMIC_SEQ_CST)
  #define atomic_store_64(ptr, val) __atomic_store_n((ptr), (val), __ATOMIC_SEQ_CST)
  #define atomic_store_ptr(ptr, val) __atomic_store_n((ptr), (val), __ATOMIC_SEQ_CST)

  #define atomic_exchange_8(ptr, val) __atomic_exchange_n((ptr), (val), __ATOMIC_SEQ_CST)
  #define atomic_exchange_16(ptr, val) __atomic_exchange_n((ptr), (val), __ATOMIC_SEQ_CST)
  #define atomic_exchange_32(ptr, val) __atomic_exchange_n((ptr), (val), __ATOMIC_SEQ_CST)
  #define atomic_exchange_64(ptr, val) __atomic_exchange_n((ptr), (val), __ATOMIC_SEQ_CST)
  #define atomic_exchange_ptr(ptr, val) __atomic_exchange_n((ptr), (val), __ATOMIC_SEQ_CST)

  #define atomic_val_compare_exchange_8 __sync_val_compare_and_swap
  #define atomic_val_compare_exchange_16 __sync_val_compare_and_swap
  #define atomic_val_compare_exchange_32 __sync_val_compare_and_swap
  #define atomic_val_compare_exchange_64 __sync_val_compare_and_swap
  #define atomic_val_compare_exchange_ptr __sync_val_compare_and_swap

  #define atomic_add_fetch_8(ptr, val) __atomic_add_fetch((ptr), (val), __ATOMIC_SEQ_CST)
  #define atomic_add_fetch_16(ptr, val) __atomic_add_fetch((ptr), (val), __ATOMIC_SEQ_CST)
  #define atomic_add_fetch_32(ptr, val) __atomic_add_fetch((ptr), (val), __ATOMIC_SEQ_CST)
  #define atomic_add_fetch_64(ptr, val) __atomic_add_fetch((ptr), (val), __ATOMIC_SEQ_CST)
  #define atomic_add_fetch_ptr(ptr, val) __atomic_add_fetch((ptr), (val), __ATOMIC_SEQ_CST)

  // specify for arm32
  #define atomic_fetch_add_8(ptr, val) __sync_fetch_and_add((ptr), (val))
  
  #define atomic_fetch_add_16(ptr, val) __atomic_fetch_add((ptr), (val), __ATOMIC_SEQ_CST)
  #define atomic_fetch_add_32(ptr, val) __atomic_fetch_add((ptr), (val), __ATOMIC_SEQ_CST)
  #define atomic_fetch_add_64(ptr, val) __atomic_fetch_add((ptr), (val), __ATOMIC_SEQ_CST)
  #define atomic_fetch_add_ptr(ptr, val) __atomic_fetch_add((ptr), (val), __ATOMIC_SEQ_CST)

  #define atomic_sub_fetch_8(ptr, val) __atomic_sub_fetch((ptr), (val), __ATOMIC_SEQ_CST)
  #define atomic_sub_fetch_16(ptr, val) __atomic_sub_fetch((ptr), (val), __ATOMIC_SEQ_CST)
  #define atomic_sub_fetch_32(ptr, val) __atomic_sub_fetch((ptr), (val), __ATOMIC_SEQ_CST)
  #define atomic_sub_fetch_64(ptr, val) __atomic_sub_fetch((ptr), (val), __ATOMIC_SEQ_CST)
  #define atomic_sub_fetch_ptr(ptr, val) __atomic_sub_fetch((ptr), (val), __ATOMIC_SEQ_CST)

  // specify for arm32
  #define atomic_fetch_sub_8(ptr, val) __sync_fetch_and_sub((ptr), (val))

  #define atomic_fetch_sub_16(ptr, val) __atomic_fetch_sub((ptr), (val), __ATOMIC_SEQ_CST)
  #define atomic_fetch_sub_32(ptr, val) __atomic_fetch_sub((ptr), (val), __ATOMIC_SEQ_CST)
  #define atomic_fetch_sub_64(ptr, val) __atomic_fetch_sub((ptr), (val), __ATOMIC_SEQ_CST)
  #define atomic_fetch_sub_ptr(ptr, val) __atomic_fetch_sub((ptr), (val), __ATOMIC_SEQ_CST)

  #define atomic_and_fetch_8(ptr, val) __atomic_and_fetch((ptr), (val), __ATOMIC_SEQ_CST)
  #define atomic_and_fetch_16(ptr, val) __atomic_and_fetch((ptr), (val), __ATOMIC_SEQ_CST)
  #define atomic_and_fetch_32(ptr, val) __atomic_and_fetch((ptr), (val), __ATOMIC_SEQ_CST)
  #define atomic_and_fetch_64(ptr, val) __atomic_and_fetch((ptr), (val), __ATOMIC_SEQ_CST)
  #define atomic_and_fetch_ptr(ptr, val) __atomic_and_fetch((ptr), (val), __ATOMIC_SEQ_CST)

  #define atomic_fetch_and_8(ptr, val) __atomic_fetch_and((ptr), (val), __ATOMIC_SEQ_CST)
  #define atomic_fetch_and_16(ptr, val) __atomic_fetch_and((ptr), (val), __ATOMIC_SEQ_CST)
  #define atomic_fetch_and_32(ptr, val) __atomic_fetch_and((ptr), (val), __ATOMIC_SEQ_CST)
  #define atomic_fetch_and_64(ptr, val) __atomic_fetch_and((ptr), (val), __ATOMIC_SEQ_CST)
  #define atomic_fetch_and_ptr(ptr, val) __atomic_fetch_and((ptr), (val), __ATOMIC_SEQ_CST)

  #define atomic_or_fetch_8(ptr, val) __atomic_or_fetch((ptr), (val), __ATOMIC_SEQ_CST)
  #define atomic_or_fetch_16(ptr, val) __atomic_or_fetch((ptr), (val), __ATOMIC_SEQ_CST)
  #define atomic_or_fetch_32(ptr, val) __atomic_or_fetch((ptr), (val), __ATOMIC_SEQ_CST)
  #define atomic_or_fetch_64(ptr, val) __atomic_or_fetch((ptr), (val), __ATOMIC_SEQ_CST)
  #define atomic_or_fetch_ptr(ptr, val) __atomic_or_fetch((ptr), (val), __ATOMIC_SEQ_CST)

  #define atomic_fetch_or_8(ptr, val) __atomic_fetch_or((ptr), (val), __ATOMIC_SEQ_CST)
  #define atomic_fetch_or_16(ptr, val) __atomic_fetch_or((ptr), (val), __ATOMIC_SEQ_CST)
  #define atomic_fetch_or_32(ptr, val) __atomic_fetch_or((ptr), (val), __ATOMIC_SEQ_CST)
  #define atomic_fetch_or_64(ptr, val) __atomic_fetch_or((ptr), (val), __ATOMIC_SEQ_CST)
  #define atomic_fetch_or_ptr(ptr, val) __atomic_fetch_or((ptr), (val), __ATOMIC_SEQ_CST)

  #define atomic_xor_fetch_8(ptr, val) __atomic_xor_fetch((ptr), (val), __ATOMIC_SEQ_CST)
  #define atomic_xor_fetch_16(ptr, val) __atomic_xor_fetch((ptr), (val), __ATOMIC_SEQ_CST)
  #define atomic_xor_fetch_32(ptr, val) __atomic_xor_fetch((ptr), (val), __ATOMIC_SEQ_CST)
  #define atomic_xor_fetch_64(ptr, val) __atomic_xor_fetch((ptr), (val), __ATOMIC_SEQ_CST)
  #define atomic_xor_fetch_ptr(ptr, val) __atomic_xor_fetch((ptr), (val), __ATOMIC_SEQ_CST)

  #define atomic_fetch_xor_8(ptr, val) __atomic_fetch_xor((ptr), (val), __ATOMIC_SEQ_CST)
  #define atomic_fetch_xor_16(ptr, val) __atomic_fetch_xor((ptr), (val), __ATOMIC_SEQ_CST)
  #define atomic_fetch_xor_32(ptr, val) __atomic_fetch_xor((ptr), (val), __ATOMIC_SEQ_CST)
  #define atomic_fetch_xor_64(ptr, val) __atomic_fetch_xor((ptr), (val), __ATOMIC_SEQ_CST)
  #define atomic_fetch_xor_ptr(ptr, val) __atomic_fetch_xor((ptr), (val), __ATOMIC_SEQ_CST)

#ifdef __cplusplus
}
#endif

#endif
