; func cw_priv_ap_working_channel_list_free @ 0x005aac24 size=0x3c
  5aac24:	27bdffe0 	addiu	sp,sp,-32
  5aac28:	afb00018 	sw	s0,24(sp)
  5aac2c:	00808021 	move	s0,a0
  5aac30:	afbf001c 	sw	ra,28(sp)
  5aac34:	8c840010 	lw	a0,16(a0)
  5aac38:	10800005 	beqz	a0,0x5aac50
  5aac3c:	8fbf001c 	lw	ra,28(sp)
  5aac40:	0c101f7c 	jal	0x407df0
  5aac44:	00000000 	nop
  5aac48:	ae000010 	sw	zero,16(s0)
  5aac4c:	8fbf001c 	lw	ra,28(sp)
  5aac50:	00001021 	move	v0,zero
  5aac54:	8fb00018 	lw	s0,24(sp)
  5aac58:	03e00008 	jr	ra
  5aac5c:	27bd0020 	addiu	sp,sp,32
