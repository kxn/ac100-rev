; func cw_wtp_capability_flag_free @ 0x00583d04 size=0x3c
  583d04:	27bdffe0 	addiu	sp,sp,-32
  583d08:	afb00018 	sw	s0,24(sp)
  583d0c:	00808021 	move	s0,a0
  583d10:	afbf001c 	sw	ra,28(sp)
  583d14:	8c840010 	lw	a0,16(a0)
  583d18:	10800005 	beqz	a0,0x583d30
  583d1c:	8fbf001c 	lw	ra,28(sp)
  583d20:	0c101f7c 	jal	0x407df0
  583d24:	00000000 	nop
  583d28:	ae000010 	sw	zero,16(s0)
  583d2c:	8fbf001c 	lw	ra,28(sp)
  583d30:	00001021 	move	v0,zero
  583d34:	8fb00018 	lw	s0,24(sp)
  583d38:	03e00008 	jr	ra
  583d3c:	27bd0020 	addiu	sp,sp,32
