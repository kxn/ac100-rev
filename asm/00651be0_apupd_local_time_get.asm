; func apupd_local_time_get @ 0x00651be0 size=0x38
  651be0:	27bdffd8 	addiu	sp,sp,-40
  651be4:	afb00020 	sw	s0,32(sp)
  651be8:	00808021 	move	s0,a0
  651bec:	afbf0024 	sw	ra,36(sp)
  651bf0:	0c101e38 	jal	0x4078e0
  651bf4:	00002021 	move	a0,zero
  651bf8:	27a40018 	addiu	a0,sp,24
  651bfc:	02002821 	move	a1,s0
  651c00:	0c101f20 	jal	0x407c80
  651c04:	afa20018 	sw	v0,24(sp)
  651c08:	8fbf0024 	lw	ra,36(sp)
  651c0c:	8fb00020 	lw	s0,32(sp)
  651c10:	03e00008 	jr	ra
  651c14:	27bd0028 	addiu	sp,sp,40
