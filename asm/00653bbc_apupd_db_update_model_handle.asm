; func apupd_db_update_model_handle @ 0x00653bbc size=0x12c
  653bbc:	27bdffd0 	addiu	sp,sp,-48
  653bc0:	afb00018 	sw	s0,24(sp)
  653bc4:	3c10007d 	lui	s0,0x7d
  653bc8:	afb40028 	sw	s4,40(sp)
  653bcc:	00a0a021 	move	s4,a1
  653bd0:	afb20020 	sw	s2,32(sp)
  653bd4:	afbf002c 	sw	ra,44(sp)
  653bd8:	afb30024 	sw	s3,36(sp)
  653bdc:	afb1001c 	sw	s1,28(sp)
  653be0:	8e02c7ac 	lw	v0,-14420(s0)
  653be4:	1040002f 	beqz	v0,0x653ca4
  653be8:	00809021 	move	s2,a0
  653bec:	10800020 	beqz	a0,0x653c70
  653bf0:	3c02007d 	lui	v0,0x7d
  653bf4:	3c11007d 	lui	s1,0x7d
  653bf8:	2405ffff 	li	a1,-1
  653bfc:	02209821 	move	s3,s1
  653c00:	0c1020b4 	jal	0x4082d0
  653c04:	8e24c778 	lw	a0,-14472(s1)
  653c08:	0c10206c 	jal	0x4081b0
  653c0c:	8e04c7ac 	lw	a0,-14420(s0)
  653c10:	00408021 	move	s0,v0
  653c14:	1200000b 	beqz	s0,0x653c44
  653c18:	00000000 	nop
  653c1c:	0c1021a0 	jal	0x408680
  653c20:	02002021 	move	a0,s0
  653c24:	02002021 	move	a0,s0
  653c28:	00408821 	move	s1,v0
  653c2c:	02802821 	move	a1,s4
  653c30:	0240c821 	move	t9,s2
  653c34:	0320f809 	jalr	t9
  653c38:	02208021 	move	s0,s1
  653c3c:	1600fff7 	bnez	s0,0x653c1c
  653c40:	00000000 	nop
  653c44:	0c101fcc 	jal	0x407f30
  653c48:	8e64c778 	lw	a0,-14472(s3)
  653c4c:	8fbf002c 	lw	ra,44(sp)
  653c50:	02001021 	move	v0,s0
  653c54:	8fb40028 	lw	s4,40(sp)
  653c58:	8fb30024 	lw	s3,36(sp)
  653c5c:	8fb20020 	lw	s2,32(sp)
  653c60:	8fb1001c 	lw	s1,28(sp)
  653c64:	8fb00018 	lw	s0,24(sp)
  653c68:	03e00008 	jr	ra
  653c6c:	27bd0030 	addiu	sp,sp,48
  653c70:	8c42c758 	lw	v0,-14504(v0)
  653c74:	1040fff5 	beqz	v0,0x653c4c
  653c78:	00008021 	move	s0,zero
  653c7c:	0c16276a 	jal	0x589da8
  653c80:	00000000 	nop
  653c84:	1040fff2 	beqz	v0,0x653c50
  653c88:	8fbf002c 	lw	ra,44(sp)
  653c8c:	3c040071 	lui	a0,0x71
  653c90:	3c050072 	lui	a1,0x72
  653c94:	24846d00 	addiu	a0,a0,27904
  653c98:	24a5a41c 	addiu	a1,a1,-23524
  653c9c:	08194f36 	j	0x653cd8
  653ca0:	24061e0c 	li	a2,7692
  653ca4:	3c020076 	lui	v0,0x76
  653ca8:	8c428c08 	lw	v0,-29688(v0)
  653cac:	1040ffe7 	beqz	v0,0x653c4c
  653cb0:	2410ffff 	li	s0,-1
  653cb4:	0c16276a 	jal	0x589da8
  653cb8:	00000000 	nop
  653cbc:	1040ffe4 	beqz	v0,0x653c50
  653cc0:	8fbf002c 	lw	ra,44(sp)
  653cc4:	3c040071 	lui	a0,0x71
  653cc8:	3c050072 	lui	a1,0x72
  653ccc:	24840720 	addiu	a0,a0,1824
  653cd0:	24a5a41c 	addiu	a1,a1,-23524
  653cd4:	24061e05 	li	a2,7685
  653cd8:	0c101b74 	jal	0x406dd0
  653cdc:	00000000 	nop
  653ce0:	08194f13 	j	0x653c4c
  653ce4:	00000000 	nop
