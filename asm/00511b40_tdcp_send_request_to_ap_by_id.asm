; func tdcp_send_request_to_ap_by_id @ 0x00511b40 size=0x44
  511b40:	27bdffd0 	addiu	sp,sp,-48
  511b44:	00801821 	move	v1,a0
  511b48:	00a01021 	move	v0,a1
  511b4c:	97a40042 	lhu	a0,66(sp)
  511b50:	00602821 	move	a1,v1
  511b54:	afa60010 	sw	a2,16(sp)
  511b58:	24060001 	li	a2,1
  511b5c:	afa70014 	sw	a3,20(sp)
  511b60:	00403821 	move	a3,v0
  511b64:	afa40018 	sw	a0,24(sp)
  511b68:	00002021 	move	a0,zero
  511b6c:	afbf002c 	sw	ra,44(sp)
  511b70:	0c1442b3 	jal	0x510acc
  511b74:	afa0001c 	sw	zero,28(sp)
  511b78:	8fbf002c 	lw	ra,44(sp)
  511b7c:	03e00008 	jr	ra
  511b80:	27bd0030 	addiu	sp,sp,48
