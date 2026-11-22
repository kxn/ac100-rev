; func cw_delete_mac_acl_entry_free @ 0x005740e0 size=0x54
  5740e0:	27bdffd8 	addiu	sp,sp,-40
  5740e4:	afb10020 	sw	s1,32(sp)
  5740e8:	afbf0024 	sw	ra,36(sp)
  5740ec:	afb0001c 	sw	s0,28(sp)
  5740f0:	8c900010 	lw	s0,16(a0)
  5740f4:	12000009 	beqz	s0,0x57411c
  5740f8:	00808821 	move	s1,a0
  5740fc:	8e040004 	lw	a0,4(s0)
  574100:	10800003 	beqz	a0,0x574110
  574104:	00000000 	nop
  574108:	0c101f7c 	jal	0x407df0
  57410c:	00000000 	nop
  574110:	0c101f7c 	jal	0x407df0
  574114:	02002021 	move	a0,s0
  574118:	ae200010 	sw	zero,16(s1)
  57411c:	8fbf0024 	lw	ra,36(sp)
  574120:	00001021 	move	v0,zero
  574124:	8fb10020 	lw	s1,32(sp)
  574128:	8fb0001c 	lw	s0,28(sp)
  57412c:	03e00008 	jr	ra
  574130:	27bd0028 	addiu	sp,sp,40
