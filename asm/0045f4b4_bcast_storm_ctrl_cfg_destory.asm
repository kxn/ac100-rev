; func bcast_storm_ctrl_cfg_destory @ 0x0045f4b4 size=0x4c
  45f4b4:	27bdffe0 	addiu	sp,sp,-32
  45f4b8:	afb00018 	sw	s0,24(sp)
  45f4bc:	3c100076 	lui	s0,0x76
  45f4c0:	afbf001c 	sw	ra,28(sp)
  45f4c4:	0c117c90 	jal	0x45f240
  45f4c8:	8e04707c 	lw	a0,28796(s0)
  45f4cc:	ae00707c 	sw	zero,28796(s0)
  45f4d0:	3c100076 	lui	s0,0x76
  45f4d4:	8e047078 	lw	a0,28792(s0)
  45f4d8:	10800005 	beqz	a0,0x45f4f0
  45f4dc:	8fbf001c 	lw	ra,28(sp)
  45f4e0:	0c1020d8 	jal	0x408360
  45f4e4:	00000000 	nop
  45f4e8:	ae007078 	sw	zero,28792(s0)
  45f4ec:	8fbf001c 	lw	ra,28(sp)
  45f4f0:	00001021 	move	v0,zero
  45f4f4:	8fb00018 	lw	s0,24(sp)
  45f4f8:	03e00008 	jr	ra
  45f4fc:	27bd0020 	addiu	sp,sp,32
