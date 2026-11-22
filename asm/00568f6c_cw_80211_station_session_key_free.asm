; func cw_80211_station_session_key_free @ 0x00568f6c size=0x54
  568f6c:	27bdffd8 	addiu	sp,sp,-40
  568f70:	afb10020 	sw	s1,32(sp)
  568f74:	afbf0024 	sw	ra,36(sp)
  568f78:	afb0001c 	sw	s0,28(sp)
  568f7c:	8c900010 	lw	s0,16(a0)
  568f80:	12000009 	beqz	s0,0x568fa8
  568f84:	00808821 	move	s1,a0
  568f88:	8e040018 	lw	a0,24(s0)
  568f8c:	10800003 	beqz	a0,0x568f9c
  568f90:	00000000 	nop
  568f94:	0c101f7c 	jal	0x407df0
  568f98:	00000000 	nop
  568f9c:	0c101f7c 	jal	0x407df0
  568fa0:	02002021 	move	a0,s0
  568fa4:	ae200010 	sw	zero,16(s1)
  568fa8:	8fbf0024 	lw	ra,36(sp)
  568fac:	00001021 	move	v0,zero
  568fb0:	8fb10020 	lw	s1,32(sp)
  568fb4:	8fb0001c 	lw	s0,28(sp)
  568fb8:	03e00008 	jr	ra
  568fbc:	27bd0028 	addiu	sp,sp,40
