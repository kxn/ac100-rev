; func wportal_db_nsa_get @ 0x00430b3c size=0x8c
  430b3c:	27bdffd0 	addiu	sp,sp,-48
  430b40:	2402ffff 	li	v0,-1
  430b44:	afb20024 	sw	s2,36(sp)
  430b48:	00a09021 	move	s2,a1
  430b4c:	afb10020 	sw	s1,32(sp)
  430b50:	00808821 	move	s1,a0
  430b54:	afbf002c 	sw	ra,44(sp)
  430b58:	afb30028 	sw	s3,40(sp)
  430b5c:	1080000f 	beqz	a0,0x430b9c
  430b60:	afb0001c 	sw	s0,28(sp)
  430b64:	10a0000d 	beqz	a1,0x430b9c
  430b68:	3c130076 	lui	s3,0x76
  430b6c:	2405ffff 	li	a1,-1
  430b70:	0c1020b4 	jal	0x4082d0
  430b74:	8e64a154 	lw	a0,-24236(s3)
  430b78:	02202021 	move	a0,s1
  430b7c:	0c10ae6a 	jal	0x42b9a8
  430b80:	02402821 	move	a1,s2
  430b84:	00408021 	move	s0,v0
  430b88:	1440000b 	bnez	v0,0x430bb8
  430b8c:	8e64a154 	lw	a0,-24236(s3)
  430b90:	0c101fcc 	jal	0x407f30
  430b94:	00000000 	nop
  430b98:	00001021 	move	v0,zero
  430b9c:	8fbf002c 	lw	ra,44(sp)
  430ba0:	8fb30028 	lw	s3,40(sp)
  430ba4:	8fb20024 	lw	s2,36(sp)
  430ba8:	8fb10020 	lw	s1,32(sp)
  430bac:	8fb0001c 	lw	s0,28(sp)
  430bb0:	03e00008 	jr	ra
  430bb4:	27bd0030 	addiu	sp,sp,48
  430bb8:	0c101fcc 	jal	0x407f30
  430bbc:	00000000 	nop
  430bc0:	0810c2e7 	j	0x430b9c
  430bc4:	02001021 	move	v0,s0
