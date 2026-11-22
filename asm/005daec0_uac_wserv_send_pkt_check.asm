; func uac_wserv_send_pkt_check @ 0x005daec0 size=0x8c
  5daec0:	27bdffd0 	addiu	sp,sp,-48
  5daec4:	2405ffff 	li	a1,-1
  5daec8:	afb00020 	sw	s0,32(sp)
  5daecc:	3c100076 	lui	s0,0x76
  5daed0:	afb10024 	sw	s1,36(sp)
  5daed4:	00008821 	move	s1,zero
  5daed8:	afb20028 	sw	s2,40(sp)
  5daedc:	02009021 	move	s2,s0
  5daee0:	afbf002c 	sw	ra,44(sp)
  5daee4:	a3a00018 	sb	zero,24(sp)
  5daee8:	0c1020b4 	jal	0x4082d0
  5daeec:	8e0498e4 	lw	a0,-26396(s0)
  5daef0:	0c1506a9 	jal	0x541aa4
  5daef4:	00000000 	nop
  5daef8:	0222102a 	slt	v0,s1,v0
  5daefc:	5040000a 	beqzl	v0,0x5daf28
  5daf00:	00008021 	move	s0,zero
  5daf04:	27a50018 	addiu	a1,sp,24
  5daf08:	0c175f70 	jal	0x5d7dc0
  5daf0c:	02202021 	move	a0,s1
  5daf10:	1440fff7 	bnez	v0,0x5daef0
  5daf14:	26310001 	addiu	s1,s1,1
  5daf18:	93a20018 	lbu	v0,24(sp)
  5daf1c:	1040fff4 	beqz	v0,0x5daef0
  5daf20:	00000000 	nop
  5daf24:	24100001 	li	s0,1
  5daf28:	0c101fcc 	jal	0x407f30
  5daf2c:	8e4498e4 	lw	a0,-26396(s2)
  5daf30:	02001021 	move	v0,s0
  5daf34:	8fbf002c 	lw	ra,44(sp)
  5daf38:	8fb20028 	lw	s2,40(sp)
  5daf3c:	8fb10024 	lw	s1,36(sp)
  5daf40:	8fb00020 	lw	s0,32(sp)
  5daf44:	03e00008 	jr	ra
  5daf48:	27bd0030 	addiu	sp,sp,48
