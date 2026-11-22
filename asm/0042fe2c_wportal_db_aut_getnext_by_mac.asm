; func wportal_db_aut_getnext_by_mac @ 0x0042fe2c size=0x8c
  42fe2c:	27bdffd0 	addiu	sp,sp,-48
  42fe30:	2402ffff 	li	v0,-1
  42fe34:	afb20024 	sw	s2,36(sp)
  42fe38:	00a09021 	move	s2,a1
  42fe3c:	afb10020 	sw	s1,32(sp)
  42fe40:	00808821 	move	s1,a0
  42fe44:	afbf002c 	sw	ra,44(sp)
  42fe48:	afb30028 	sw	s3,40(sp)
  42fe4c:	1080000f 	beqz	a0,0x42fe8c
  42fe50:	afb0001c 	sw	s0,28(sp)
  42fe54:	10a0000d 	beqz	a1,0x42fe8c
  42fe58:	3c130076 	lui	s3,0x76
  42fe5c:	2405ffff 	li	a1,-1
  42fe60:	0c1020b4 	jal	0x4082d0
  42fe64:	8e64a150 	lw	a0,-24240(s3)
  42fe68:	02202021 	move	a0,s1
  42fe6c:	0c10aeaa 	jal	0x42baa8
  42fe70:	02402821 	move	a1,s2
  42fe74:	00408021 	move	s0,v0
  42fe78:	1440000b 	bnez	v0,0x42fea8
  42fe7c:	8e64a150 	lw	a0,-24240(s3)
  42fe80:	0c101fcc 	jal	0x407f30
  42fe84:	00000000 	nop
  42fe88:	00001021 	move	v0,zero
  42fe8c:	8fbf002c 	lw	ra,44(sp)
  42fe90:	8fb30028 	lw	s3,40(sp)
  42fe94:	8fb20024 	lw	s2,36(sp)
  42fe98:	8fb10020 	lw	s1,32(sp)
  42fe9c:	8fb0001c 	lw	s0,28(sp)
  42fea0:	03e00008 	jr	ra
  42fea4:	27bd0030 	addiu	sp,sp,48
  42fea8:	0c101fcc 	jal	0x407f30
  42feac:	00000000 	nop
  42feb0:	0810bfa3 	j	0x42fe8c
  42feb4:	02001021 	move	v0,s0
