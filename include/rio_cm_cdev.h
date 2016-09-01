/*
 * Copyright (c) 2015, Integrated Device Technology Inc.
 * Copyright (c) 2015, Prodrive Technologies
 * Copyright (c) 2015, RapidIO Trade Association
 * All rights reserved.
 *
 * This software is available to you under a choice of one of two licenses.
 * You may choose to be licensed under the terms of the GNU General Public
 * License(GPL) Version 2, or the BSD-3 Clause license below:
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors
 * may be used to endorse or promote products derived from this software without
 * specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _RIO_MPORT_H_
#define _RIO_MPORT_H_

#ifndef __user
#define __user
#endif

struct rio_cm_channel {
	uint16_t id;
	uint32_t remote_destid;
	uint32_t remote_mbox;
	uint16_t remote_channel;
	uint8_t mport_id;
};

struct rio_cm_msg {
	uint16_t ch_num;
	void __user *msg;
	uint16_t size;
	uint32_t rxto;	/* receive timeout in mSec. 0 = blocking */
};

struct rio_cm_accept {
	uint16_t ch_num;
	uint32_t wait_to;	/* accept timeout in mSec. 0 = blocking */
};

/* RapidIO Channel Manager driver IOCTLs */
#define RIO_CM_IOC_MAGIC	'c'

#define RIO_CM_EP_GET_LIST_SIZE	_IOWR(RIO_CM_IOC_MAGIC, 1, uint32_t)
#define RIO_CM_EP_GET_LIST	_IOWR(RIO_CM_IOC_MAGIC, 2, uint32_t)
#define RIO_CM_CHAN_CREATE	_IOWR(RIO_CM_IOC_MAGIC, 3, uint16_t)
#define RIO_CM_CHAN_CLOSE	_IOW(RIO_CM_IOC_MAGIC, 4, uint16_t)
#define RIO_CM_CHAN_BIND	_IOW(RIO_CM_IOC_MAGIC, 5, struct rio_cm_channel)
#define RIO_CM_CHAN_LISTEN	_IOW(RIO_CM_IOC_MAGIC, 6, uint16_t)
#define RIO_CM_CHAN_ACCEPT	_IOWR(RIO_CM_IOC_MAGIC, 7, struct rio_cm_accept)
#define RIO_CM_CHAN_CONNECT	_IOW(RIO_CM_IOC_MAGIC, 8, struct rio_cm_channel)
#define RIO_CM_CHAN_SEND	_IOW(RIO_CM_IOC_MAGIC, 9, struct rio_cm_msg)
#define RIO_CM_CHAN_RECEIVE	_IOWR(RIO_CM_IOC_MAGIC, 10, struct rio_cm_msg)
#define RIO_CM_MPORT_GET_LIST	_IOWR(RIO_CM_IOC_MAGIC, 11, uint32_t)

#endif /* _RIO_MPORT_H_ */