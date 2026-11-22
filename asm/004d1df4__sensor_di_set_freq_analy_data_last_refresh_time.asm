; func _sensor_di_set_freq_analy_data_last_refresh_time @ 0x004d1df4 size=0x44
  4d1df4:	27bdffd8 	addiu	sp,sp,-40
  4d1df8:	2405ffff 	li	a1,-1
  4d1dfc:	afb0001c 	sw	s0,28(sp)
  4d1e00:	3c100077 	lui	s0,0x77
  4d1e04:	afb10020 	sw	s1,32(sp)
  4d1e08:	00808821 	move	s1,a0
  4d1e0c:	afbf0024 	sw	ra,36(sp)
  4d1e10:	0c1020b4 	jal	0x4082d0
  4d1e14:	8e0485e4 	lw	a0,-31260(s0)
  4d1e18:	3c020077 	lui	v0,0x77
  4d1e1c:	8e0485e4 	lw	a0,-31260(s0)
  4d1e20:	8fbf0024 	lw	ra,36(sp)
  4d1e24:	8fb0001c 	lw	s0,28(sp)
  4d1e28:	a45185ea 	sh	s1,-31254(v0)
  4d1e2c:	8fb10020 	lw	s1,32(sp)
  4d1e30:	08101fcc 	j	0x407f30
  4d1e34:	27bd0028 	addiu	sp,sp,40
