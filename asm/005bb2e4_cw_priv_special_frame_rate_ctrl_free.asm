; func cw_priv_special_frame_rate_ctrl_free @ 0x005bb2e4 size=0x4c
  5bb2e4:	27bdffe0 	addiu	sp,sp,-32
  5bb2e8:	afb00018 	sw	s0,24(sp)
  5bb2ec:	afbf001c 	sw	ra,28(sp)
  5bb2f0:	8c820010 	lw	v0,16(a0)
  5bb2f4:	10400009 	beqz	v0,0x5bb31c
  5bb2f8:	00808021 	move	s0,a0
  5bb2fc:	8c440004 	lw	a0,4(v0)
  5bb300:	10800003 	beqz	a0,0x5bb310
  5bb304:	00000000 	nop
  5bb308:	0c101f7c 	jal	0x407df0
  5bb30c:	00000000 	nop
  5bb310:	0c101f7c 	jal	0x407df0
  5bb314:	8e040010 	lw	a0,16(s0)
  5bb318:	ae000010 	sw	zero,16(s0)
  5bb31c:	8fbf001c 	lw	ra,28(sp)
  5bb320:	00001021 	move	v0,zero
  5bb324:	8fb00018 	lw	s0,24(sp)
  5bb328:	03e00008 	jr	ra
  5bb32c:	27bd0020 	addiu	sp,sp,32
