/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _FS_CEPH_CRYPTO_H
#define _FS_CEPH_CRYPTO_H

#include <linux/types.h>

/*
 * Header for the crypted file when truncating the size, this
 * will be sent to MDS, and MDS will do the encrypted last
 * block's update and size truncating.
 */
struct ceph_fscrypt_truncate_size_header {
       __u8  ver;
       __u8  compat;
       /* length of sizeof(assert_ver + file_offset + block_size + CEPH_FSCRYPT_BLOCK_SIZE) */
       __le32 data_len;

       __le64 assert_ver;
       __le64 file_offset;
       __le32 block_size;
} __packed;

#endif
