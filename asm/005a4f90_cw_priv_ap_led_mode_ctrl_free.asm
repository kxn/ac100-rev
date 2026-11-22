; func cw_priv_ap_led_mode_ctrl_free @ 0x005a4f90 size=0x3c
  5a4f90:	27bdffe0 	addiu	sp,sp,-32
  5a4f94:	afb00018 	sw	s0,24(sp)
  5a4f98:	00808021 	move	s0,a0
  5a4f9c:	afbf001c 	sw	ra,28(sp)
  5a4fa0:	8c840010 	lw	a0,16(a0)
  5a4fa4:	10800005 	beqz	a0,0x5a4fbc
  5a4fa8:	8fbf001c 	lw	ra,28(sp)
  5a4fac:	0c101f7c 	jal	0x407df0
  5a4fb0:	00000000 	nop
  5a4fb4:	ae000010 	sw	zero,16(s0)
  5a4fb8:	8fbf001c 	lw	ra,28(sp)
  5a4fbc:	00001021 	move	v0,zero
  5a4fc0:	8fb00018 	lw	s0,24(sp)
  5a4fc4:	03e00008 	jr	ra
  5a4fc8:	27bd0020 	addiu	sp,sp,32
