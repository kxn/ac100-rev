; func mesh_db_discover_list_delete_by_capid @ 0x004b9d54 size=0x124
  4b9d54:	27bdffc8 	addiu	sp,sp,-56
  4b9d58:	2405ffff 	li	a1,-1
  4b9d5c:	afb0001c 	sw	s0,28(sp)
  4b9d60:	3c100076 	lui	s0,0x76
  4b9d64:	afbf0034 	sw	ra,52(sp)
  4b9d68:	26027eb0 	addiu	v0,s0,32432
  4b9d6c:	afb50030 	sw	s5,48(sp)
  4b9d70:	afb30028 	sw	s3,40(sp)
  4b9d74:	3095ffff 	andi	s5,a0,0xffff
  4b9d78:	afb10020 	sw	s1,32(sp)
  4b9d7c:	02009821 	move	s3,s0
  4b9d80:	afb4002c 	sw	s4,44(sp)
  4b9d84:	afb20024 	sw	s2,36(sp)
  4b9d88:	0c1020b4 	jal	0x4082d0
  4b9d8c:	8c440004 	lw	a0,4(v0)
  4b9d90:	3c040076 	lui	a0,0x76
  4b9d94:	0c10206c 	jal	0x4081b0
  4b9d98:	24847f5c 	addiu	a0,a0,32604
  4b9d9c:	00408821 	move	s1,v0
  4b9da0:	52200018 	beqzl	s1,0x4b9e04
  4b9da4:	26737eb0 	addiu	s3,s3,32432
  4b9da8:	26320058 	addiu	s2,s1,88
  4b9dac:	0c1021a0 	jal	0x408680
  4b9db0:	02202021 	move	a0,s1
  4b9db4:	02402021 	move	a0,s2
  4b9db8:	0c10206c 	jal	0x4081b0
  4b9dbc:	0040a021 	move	s4,v0
  4b9dc0:	0812e777 	j	0x4b9ddc
  4b9dc4:	00000000 	nop
  4b9dc8:	9602000c 	lhu	v0,12(s0)
  4b9dcc:	10550024 	beq	v0,s5,0x4b9e60
  4b9dd0:	02002021 	move	a0,s0
  4b9dd4:	0c1021a0 	jal	0x408680
  4b9dd8:	00000000 	nop
  4b9ddc:	1440fffa 	bnez	v0,0x4b9dc8
  4b9de0:	00408021 	move	s0,v0
  4b9de4:	0c101ff8 	jal	0x407fe0
  4b9de8:	02402021 	move	a0,s2
  4b9dec:	10400011 	beqz	v0,0x4b9e34
  4b9df0:	00000000 	nop
  4b9df4:	02808821 	move	s1,s4
  4b9df8:	1620ffec 	bnez	s1,0x4b9dac
  4b9dfc:	26320058 	addiu	s2,s1,88
  4b9e00:	26737eb0 	addiu	s3,s3,32432
  4b9e04:	0c101fcc 	jal	0x407f30
  4b9e08:	8e640004 	lw	a0,4(s3)
  4b9e0c:	00001021 	move	v0,zero
  4b9e10:	8fbf0034 	lw	ra,52(sp)
  4b9e14:	8fb50030 	lw	s5,48(sp)
  4b9e18:	8fb4002c 	lw	s4,44(sp)
  4b9e1c:	8fb30028 	lw	s3,40(sp)
  4b9e20:	8fb20024 	lw	s2,36(sp)
  4b9e24:	8fb10020 	lw	s1,32(sp)
  4b9e28:	8fb0001c 	lw	s0,28(sp)
  4b9e2c:	03e00008 	jr	ra
  4b9e30:	27bd0038 	addiu	sp,sp,56
  4b9e34:	0c102140 	jal	0x408500
  4b9e38:	02202021 	move	a0,s1
  4b9e3c:	26627eb0 	addiu	v0,s3,32432
  4b9e40:	02202821 	move	a1,s1
  4b9e44:	0c101fd0 	jal	0x407f40
  4b9e48:	8c4400b8 	lw	a0,184(v0)
  4b9e4c:	02202021 	move	a0,s1
  4b9e50:	0c101f7c 	jal	0x407df0
  4b9e54:	02808821 	move	s1,s4
  4b9e58:	0812e77e 	j	0x4b9df8
  4b9e5c:	00000000 	nop
  4b9e60:	0c102140 	jal	0x408500
  4b9e64:	00000000 	nop
  4b9e68:	0c101f7c 	jal	0x407df0
  4b9e6c:	02002021 	move	a0,s0
  4b9e70:	0812e779 	j	0x4b9de4
  4b9e74:	00000000 	nop
