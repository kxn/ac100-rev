; func cw_session_id_generate @ 0x00580b68 size=0x6c
  580b68:	27bdffd0 	addiu	sp,sp,-48
  580b6c:	afb10020 	sw	s1,32(sp)
  580b70:	00808821 	move	s1,a0
  580b74:	afbf002c 	sw	ra,44(sp)
  580b78:	afb30028 	sw	s3,40(sp)
  580b7c:	afb20024 	sw	s2,36(sp)
  580b80:	1080000d 	beqz	a0,0x580bb8
  580b84:	afb0001c 	sw	s0,28(sp)
  580b88:	00008021 	move	s0,zero
  580b8c:	24120100 	li	s2,256
  580b90:	24130010 	li	s3,16
  580b94:	0c101cac 	jal	0x4072b0
  580b98:	00000000 	nop
  580b9c:	02301821 	addu	v1,s1,s0
  580ba0:	024001f4 	teq	s2,zero,0x7
  580ba4:	0052001a 	div	zero,v0,s2
  580ba8:	26100001 	addiu	s0,s0,1
  580bac:	00001010 	mfhi	v0
  580bb0:	1613fff8 	bne	s0,s3,0x580b94
  580bb4:	a0620000 	sb	v0,0(v1)
  580bb8:	8fbf002c 	lw	ra,44(sp)
  580bbc:	8fb30028 	lw	s3,40(sp)
  580bc0:	8fb20024 	lw	s2,36(sp)
  580bc4:	8fb10020 	lw	s1,32(sp)
  580bc8:	8fb0001c 	lw	s0,28(sp)
  580bcc:	03e00008 	jr	ra
  580bd0:	27bd0030 	addiu	sp,sp,48
	...
