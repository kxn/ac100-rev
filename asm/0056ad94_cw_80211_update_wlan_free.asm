; func cw_80211_update_wlan_free @ 0x0056ad94 size=0x54
  56ad94:	27bdffd8 	addiu	sp,sp,-40
  56ad98:	afb10020 	sw	s1,32(sp)
  56ad9c:	afbf0024 	sw	ra,36(sp)
  56ada0:	afb0001c 	sw	s0,28(sp)
  56ada4:	8c900010 	lw	s0,16(a0)
  56ada8:	12000009 	beqz	s0,0x56add0
  56adac:	00808821 	move	s1,a0
  56adb0:	8e040008 	lw	a0,8(s0)
  56adb4:	10800003 	beqz	a0,0x56adc4
  56adb8:	00000000 	nop
  56adbc:	0c101f7c 	jal	0x407df0
  56adc0:	00000000 	nop
  56adc4:	0c101f7c 	jal	0x407df0
  56adc8:	02002021 	move	a0,s0
  56adcc:	ae200010 	sw	zero,16(s1)
  56add0:	8fbf0024 	lw	ra,36(sp)
  56add4:	00001021 	move	v0,zero
  56add8:	8fb10020 	lw	s1,32(sp)
  56addc:	8fb0001c 	lw	s0,28(sp)
  56ade0:	03e00008 	jr	ra
  56ade4:	27bd0028 	addiu	sp,sp,40
