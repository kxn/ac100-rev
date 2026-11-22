; func cw_priv_wlan_rssi_orient_free @ 0x005cbcb0 size=0x3c
  5cbcb0:	27bdffe0 	addiu	sp,sp,-32
  5cbcb4:	afb00018 	sw	s0,24(sp)
  5cbcb8:	00808021 	move	s0,a0
  5cbcbc:	afbf001c 	sw	ra,28(sp)
  5cbcc0:	8c840010 	lw	a0,16(a0)
  5cbcc4:	10800005 	beqz	a0,0x5cbcdc
  5cbcc8:	8fbf001c 	lw	ra,28(sp)
  5cbccc:	0c101f7c 	jal	0x407df0
  5cbcd0:	00000000 	nop
  5cbcd4:	ae000010 	sw	zero,16(s0)
  5cbcd8:	8fbf001c 	lw	ra,28(sp)
  5cbcdc:	00001021 	move	v0,zero
  5cbce0:	8fb00018 	lw	s0,24(sp)
  5cbce4:	03e00008 	jr	ra
  5cbce8:	27bd0020 	addiu	sp,sp,32
