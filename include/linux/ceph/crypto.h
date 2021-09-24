/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _FS_CEPH_CRYPTO_H
#define _FS_CEPH_CRYPTO_H

#include <linux/types.h>

/*
 * Header for the crypted file when truncating the size, this
 * will be sent to MDS, and the MDS will update the encrypted
 * last block and then truncate the size.
 */
struct ceph_fscrypt_truncate_size_header {
       __u8  ver;
       __u8  compat;

       /*
	* It will be sizeof(assert_ver + file_offset + block_size)
	* if the last block is empty when it's located in a file
	* hole. Or the data_len will plus CEPH_FSCRYPT_BLOCK_SIZE.
	*/
       __le32 data_len;

       __le64 assert_ver;
       __le64 file_offset;
       __le32 block_size;
} __packed;

#endif
