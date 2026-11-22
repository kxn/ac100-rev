; func cw_priv_reset_mask_free @ 0x005baf50 size=0x3c
  5baf50:	27bdffe0 	addiu	sp,sp,-32
  5baf54:	afb00018 	sw	s0,24(sp)
  5baf58:	00808021 	move	s0,a0
  5baf5c:	afbf001c 	sw	ra,28(sp)
  5baf60:	8c840010 	lw	a0,16(a0)
  5baf64:	10800005 	beqz	a0,0x5baf7c
  5baf68:	8fbf001c 	lw	ra,28(sp)
  5baf6c:	0c101f7c 	jal	0x407df0
  5baf70:	00000000 	nop
  5baf74:	ae000010 	sw	zero,16(s0)
  5baf78:	8fbf001c 	lw	ra,28(sp)
  5baf7c:	00001021 	move	v0,zero
  5baf80:	8fb00018 	lw	s0,24(sp)
  5baf84:	03e00008 	jr	ra
  5baf88:	27bd0020 	addiu	sp,sp,32
