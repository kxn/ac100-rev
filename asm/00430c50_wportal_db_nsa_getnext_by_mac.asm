; func wportal_db_nsa_getnext_by_mac @ 0x00430c50 size=0x8c
  430c50:	27bdffd0 	addiu	sp,sp,-48
  430c54:	2402ffff 	li	v0,-1
  430c58:	afb20024 	sw	s2,36(sp)
  430c5c:	00a09021 	move	s2,a1
  430c60:	afb10020 	sw	s1,32(sp)
  430c64:	00808821 	move	s1,a0
  430c68:	afbf002c 	sw	ra,44(sp)
  430c6c:	afb30028 	sw	s3,40(sp)
  430c70:	1080000f 	beqz	a0,0x430cb0
  430c74:	afb0001c 	sw	s0,28(sp)
  430c78:	10a0000d 	beqz	a1,0x430cb0
  430c7c:	3c130076 	lui	s3,0x76
  430c80:	2405ffff 	li	a1,-1
  430c84:	0c1020b4 	jal	0x4082d0
  430c88:	8e64a154 	lw	a0,-24236(s3)
  430c8c:	02202021 	move	a0,s1
  430c90:	0c10ae88 	jal	0x42ba20
  430c94:	02402821 	move	a1,s2
  430c98:	00408021 	move	s0,v0
  430c9c:	1440000b 	bnez	v0,0x430ccc
  430ca0:	8e64a154 	lw	a0,-24236(s3)
  430ca4:	0c101fcc 	jal	0x407f30
  430ca8:	00000000 	nop
  430cac:	00001021 	move	v0,zero
  430cb0:	8fbf002c 	lw	ra,44(sp)
  430cb4:	8fb30028 	lw	s3,40(sp)
  430cb8:	8fb20024 	lw	s2,36(sp)
  430cbc:	8fb10020 	lw	s1,32(sp)
  430cc0:	8fb0001c 	lw	s0,28(sp)
  430cc4:	03e00008 	jr	ra
  430cc8:	27bd0030 	addiu	sp,sp,48
  430ccc:	0c101fcc 	jal	0x407f30
  430cd0:	00000000 	nop
  430cd4:	0810c32c 	j	0x430cb0
  430cd8:	02001021 	move	v0,s0
