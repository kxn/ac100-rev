; func cw_priv_ap_spectral_free @ 0x005a7258 size=0x3c
  5a7258:	27bdffe0 	addiu	sp,sp,-32
  5a725c:	afb00018 	sw	s0,24(sp)
  5a7260:	00808021 	move	s0,a0
  5a7264:	afbf001c 	sw	ra,28(sp)
  5a7268:	8c840010 	lw	a0,16(a0)
  5a726c:	10800005 	beqz	a0,0x5a7284
  5a7270:	8fbf001c 	lw	ra,28(sp)
  5a7274:	0c101f7c 	jal	0x407df0
  5a7278:	00000000 	nop
  5a727c:	ae000010 	sw	zero,16(s0)
  5a7280:	8fbf001c 	lw	ra,28(sp)
  5a7284:	00001021 	move	v0,zero
  5a7288:	8fb00018 	lw	s0,24(sp)
  5a728c:	03e00008 	jr	ra
  5a7290:	27bd0020 	addiu	sp,sp,32
