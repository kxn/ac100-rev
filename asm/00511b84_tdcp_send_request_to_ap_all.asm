; func tdcp_send_request_to_ap_all @ 0x00511b84 size=0x44
  511b84:	27bdffd0 	addiu	sp,sp,-48
  511b88:	00801821 	move	v1,a0
  511b8c:	24040001 	li	a0,1
  511b90:	00a01021 	move	v0,a1
  511b94:	afa60010 	sw	a2,16(sp)
  511b98:	afa4001c 	sw	a0,28(sp)
  511b9c:	24060001 	li	a2,1
  511ba0:	00002021 	move	a0,zero
  511ba4:	afa70014 	sw	a3,20(sp)
  511ba8:	00602821 	move	a1,v1
  511bac:	afbf002c 	sw	ra,44(sp)
  511bb0:	00403821 	move	a3,v0
  511bb4:	0c1442b3 	jal	0x510acc
  511bb8:	afa00018 	sw	zero,24(sp)
  511bbc:	8fbf002c 	lw	ra,44(sp)
  511bc0:	03e00008 	jr	ra
  511bc4:	27bd0030 	addiu	sp,sp,48
