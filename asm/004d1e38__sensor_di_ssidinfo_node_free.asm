; func _sensor_di_ssidinfo_node_free @ 0x004d1e38 size=0x94
  4d1e38:	27bdffd8 	addiu	sp,sp,-40
  4d1e3c:	afb20020 	sw	s2,32(sp)
  4d1e40:	2492000c 	addiu	s2,a0,12
  4d1e44:	afb1001c 	sw	s1,28(sp)
  4d1e48:	00808821 	move	s1,a0
  4d1e4c:	afbf0024 	sw	ra,36(sp)
  4d1e50:	10800018 	beqz	a0,0x4d1eb4
  4d1e54:	afb00018 	sw	s0,24(sp)
  4d1e58:	0c10206c 	jal	0x4081b0
  4d1e5c:	02402021 	move	a0,s2
  4d1e60:	1040000d 	beqz	v0,0x4d1e98
  4d1e64:	00408021 	move	s0,v0
  4d1e68:	0c102140 	jal	0x408500
  4d1e6c:	02002021 	move	a0,s0
  4d1e70:	8e040024 	lw	a0,36(s0)
  4d1e74:	10800004 	beqz	a0,0x4d1e88
  4d1e78:	00000000 	nop
  4d1e7c:	0c101f7c 	jal	0x407df0
  4d1e80:	00000000 	nop
  4d1e84:	ae000024 	sw	zero,36(s0)
  4d1e88:	0c101f7c 	jal	0x407df0
  4d1e8c:	02002021 	move	a0,s0
  4d1e90:	08134796 	j	0x4d1e58
  4d1e94:	00000000 	nop
  4d1e98:	02202021 	move	a0,s1
  4d1e9c:	8fbf0024 	lw	ra,36(sp)
  4d1ea0:	8fb20020 	lw	s2,32(sp)
  4d1ea4:	8fb1001c 	lw	s1,28(sp)
  4d1ea8:	8fb00018 	lw	s0,24(sp)
  4d1eac:	08101f7c 	j	0x407df0
  4d1eb0:	27bd0028 	addiu	sp,sp,40
  4d1eb4:	8fbf0024 	lw	ra,36(sp)
  4d1eb8:	8fb20020 	lw	s2,32(sp)
  4d1ebc:	8fb1001c 	lw	s1,28(sp)
  4d1ec0:	8fb00018 	lw	s0,24(sp)
  4d1ec4:	03e00008 	jr	ra
  4d1ec8:	27bd0028 	addiu	sp,sp,40
