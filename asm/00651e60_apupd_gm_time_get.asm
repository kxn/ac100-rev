; func apupd_gm_time_get @ 0x00651e60 size=0x38
  651e60:	27bdffd8 	addiu	sp,sp,-40
  651e64:	afb00020 	sw	s0,32(sp)
  651e68:	00808021 	move	s0,a0
  651e6c:	afbf0024 	sw	ra,36(sp)
  651e70:	0c101e38 	jal	0x4078e0
  651e74:	00002021 	move	a0,zero
  651e78:	27a40018 	addiu	a0,sp,24
  651e7c:	02002821 	move	a1,s0
  651e80:	0c101f28 	jal	0x407ca0
  651e84:	afa20018 	sw	v0,24(sp)
  651e88:	8fbf0024 	lw	ra,36(sp)
  651e8c:	8fb00020 	lw	s0,32(sp)
  651e90:	03e00008 	jr	ra
  651e94:	27bd0028 	addiu	sp,sp,40
