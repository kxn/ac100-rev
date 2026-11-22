; func wportal_db_aut_get_by_ip @ 0x0042fd18 size=0x8c
  42fd18:	27bdffd0 	addiu	sp,sp,-48
  42fd1c:	2402ffff 	li	v0,-1
  42fd20:	afb20024 	sw	s2,36(sp)
  42fd24:	00a09021 	move	s2,a1
  42fd28:	afb10020 	sw	s1,32(sp)
  42fd2c:	00808821 	move	s1,a0
  42fd30:	afbf002c 	sw	ra,44(sp)
  42fd34:	afb30028 	sw	s3,40(sp)
  42fd38:	1080000f 	beqz	a0,0x42fd78
  42fd3c:	afb0001c 	sw	s0,28(sp)
  42fd40:	10a0000d 	beqz	a1,0x42fd78
  42fd44:	3c130076 	lui	s3,0x76
  42fd48:	2405ffff 	li	a1,-1
  42fd4c:	0c1020b4 	jal	0x4082d0
  42fd50:	8e64a150 	lw	a0,-24240(s3)
  42fd54:	02202021 	move	a0,s1
  42fd58:	0c10ae4d 	jal	0x42b934
  42fd5c:	02402821 	move	a1,s2
  42fd60:	00408021 	move	s0,v0
  42fd64:	1440000b 	bnez	v0,0x42fd94
  42fd68:	8e64a150 	lw	a0,-24240(s3)
  42fd6c:	0c101fcc 	jal	0x407f30
  42fd70:	00000000 	nop
  42fd74:	00001021 	move	v0,zero
  42fd78:	8fbf002c 	lw	ra,44(sp)
  42fd7c:	8fb30028 	lw	s3,40(sp)
  42fd80:	8fb20024 	lw	s2,36(sp)
  42fd84:	8fb10020 	lw	s1,32(sp)
  42fd88:	8fb0001c 	lw	s0,28(sp)
  42fd8c:	03e00008 	jr	ra
  42fd90:	27bd0030 	addiu	sp,sp,48
  42fd94:	0c101fcc 	jal	0x407f30
  42fd98:	00000000 	nop
  42fd9c:	0810bf5e 	j	0x42fd78
  42fda0:	02001021 	move	v0,s0
