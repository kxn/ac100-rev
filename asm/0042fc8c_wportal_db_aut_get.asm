; func wportal_db_aut_get @ 0x0042fc8c size=0x8c
  42fc8c:	27bdffd0 	addiu	sp,sp,-48
  42fc90:	2402ffff 	li	v0,-1
  42fc94:	afb20024 	sw	s2,36(sp)
  42fc98:	00a09021 	move	s2,a1
  42fc9c:	afb10020 	sw	s1,32(sp)
  42fca0:	00808821 	move	s1,a0
  42fca4:	afbf002c 	sw	ra,44(sp)
  42fca8:	afb30028 	sw	s3,40(sp)
  42fcac:	1080000f 	beqz	a0,0x42fcec
  42fcb0:	afb0001c 	sw	s0,28(sp)
  42fcb4:	10a0000d 	beqz	a1,0x42fcec
  42fcb8:	3c130076 	lui	s3,0x76
  42fcbc:	2405ffff 	li	a1,-1
  42fcc0:	0c1020b4 	jal	0x4082d0
  42fcc4:	8e64a150 	lw	a0,-24240(s3)
  42fcc8:	02202021 	move	a0,s1
  42fccc:	0c10ae30 	jal	0x42b8c0
  42fcd0:	02402821 	move	a1,s2
  42fcd4:	00408021 	move	s0,v0
  42fcd8:	1440000b 	bnez	v0,0x42fd08
  42fcdc:	8e64a150 	lw	a0,-24240(s3)
  42fce0:	0c101fcc 	jal	0x407f30
  42fce4:	00000000 	nop
  42fce8:	00001021 	move	v0,zero
  42fcec:	8fbf002c 	lw	ra,44(sp)
  42fcf0:	8fb30028 	lw	s3,40(sp)
  42fcf4:	8fb20024 	lw	s2,36(sp)
  42fcf8:	8fb10020 	lw	s1,32(sp)
  42fcfc:	8fb0001c 	lw	s0,28(sp)
  42fd00:	03e00008 	jr	ra
  42fd04:	27bd0030 	addiu	sp,sp,48
  42fd08:	0c101fcc 	jal	0x407f30
  42fd0c:	00000000 	nop
  42fd10:	0810bf3b 	j	0x42fcec
  42fd14:	02001021 	move	v0,s0
