; func cw_priv_ap_offline_mngr_free @ 0x005a6aa8 size=0x3c
  5a6aa8:	27bdffe0 	addiu	sp,sp,-32
  5a6aac:	afb00018 	sw	s0,24(sp)
  5a6ab0:	00808021 	move	s0,a0
  5a6ab4:	afbf001c 	sw	ra,28(sp)
  5a6ab8:	8c840010 	lw	a0,16(a0)
  5a6abc:	10800005 	beqz	a0,0x5a6ad4
  5a6ac0:	8fbf001c 	lw	ra,28(sp)
  5a6ac4:	0c101f7c 	jal	0x407df0
  5a6ac8:	00000000 	nop
  5a6acc:	ae000010 	sw	zero,16(s0)
  5a6ad0:	8fbf001c 	lw	ra,28(sp)
  5a6ad4:	00001021 	move	v0,zero
  5a6ad8:	8fb00018 	lw	s0,24(sp)
  5a6adc:	03e00008 	jr	ra
  5a6ae0:	27bd0020 	addiu	sp,sp,32
