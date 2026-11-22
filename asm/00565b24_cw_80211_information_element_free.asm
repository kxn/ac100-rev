; func cw_80211_information_element_free @ 0x00565b24 size=0x54
  565b24:	27bdffd8 	addiu	sp,sp,-40
  565b28:	afb10020 	sw	s1,32(sp)
  565b2c:	afbf0024 	sw	ra,36(sp)
  565b30:	afb0001c 	sw	s0,28(sp)
  565b34:	8c900010 	lw	s0,16(a0)
  565b38:	12000009 	beqz	s0,0x565b60
  565b3c:	00808821 	move	s1,a0
  565b40:	8e040008 	lw	a0,8(s0)
  565b44:	10800003 	beqz	a0,0x565b54
  565b48:	00000000 	nop
  565b4c:	0c101f7c 	jal	0x407df0
  565b50:	00000000 	nop
  565b54:	0c101f7c 	jal	0x407df0
  565b58:	02002021 	move	a0,s0
  565b5c:	ae200010 	sw	zero,16(s1)
  565b60:	8fbf0024 	lw	ra,36(sp)
  565b64:	00001021 	move	v0,zero
  565b68:	8fb10020 	lw	s1,32(sp)
  565b6c:	8fb0001c 	lw	s0,28(sp)
  565b70:	03e00008 	jr	ra
  565b74:	27bd0028 	addiu	sp,sp,40
