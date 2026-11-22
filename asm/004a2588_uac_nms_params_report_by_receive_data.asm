; func uac_nms_params_report_by_receive_data @ 0x004a2588 size=0x44
  4a2588:	27bdffe0 	addiu	sp,sp,-32
  4a258c:	2405ffff 	li	a1,-1
  4a2590:	afb00018 	sw	s0,24(sp)
  4a2594:	3c100076 	lui	s0,0x76
  4a2598:	afbf001c 	sw	ra,28(sp)
  4a259c:	0c1020b4 	jal	0x4082d0
  4a25a0:	8e047b1c 	lw	a0,31516(s0)
  4a25a4:	3c020076 	lui	v0,0x76
  4a25a8:	0c10212c 	jal	0x4084b0
  4a25ac:	8c447b20 	lw	a0,31520(v0)
  4a25b0:	0c101fcc 	jal	0x407f30
  4a25b4:	8e047b1c 	lw	a0,31516(s0)
  4a25b8:	00001021 	move	v0,zero
  4a25bc:	8fbf001c 	lw	ra,28(sp)
  4a25c0:	8fb00018 	lw	s0,24(sp)
  4a25c4:	03e00008 	jr	ra
  4a25c8:	27bd0020 	addiu	sp,sp,32
