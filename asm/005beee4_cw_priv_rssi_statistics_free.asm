; func cw_priv_rssi_statistics_free @ 0x005beee4 size=0x54
  5beee4:	27bdffd8 	addiu	sp,sp,-40
  5beee8:	afb10020 	sw	s1,32(sp)
  5beeec:	afbf0024 	sw	ra,36(sp)
  5beef0:	afb0001c 	sw	s0,28(sp)
  5beef4:	8c900010 	lw	s0,16(a0)
  5beef8:	12000009 	beqz	s0,0x5bef20
  5beefc:	00808821 	move	s1,a0
  5bef00:	8e040014 	lw	a0,20(s0)
  5bef04:	10800003 	beqz	a0,0x5bef14
  5bef08:	00000000 	nop
  5bef0c:	0c101f7c 	jal	0x407df0
  5bef10:	00000000 	nop
  5bef14:	0c101f7c 	jal	0x407df0
  5bef18:	02002021 	move	a0,s0
  5bef1c:	ae200010 	sw	zero,16(s1)
  5bef20:	8fbf0024 	lw	ra,36(sp)
  5bef24:	00001021 	move	v0,zero
  5bef28:	8fb10020 	lw	s1,32(sp)
  5bef2c:	8fb0001c 	lw	s0,28(sp)
  5bef30:	03e00008 	jr	ra
  5bef34:	27bd0028 	addiu	sp,sp,40
