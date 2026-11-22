; func uac_nms_params_report_fini @ 0x004a3070 size=0x74
  4a3070:	27bdffe0 	addiu	sp,sp,-32
  4a3074:	afb00018 	sw	s0,24(sp)
  4a3078:	afbf001c 	sw	ra,28(sp)
  4a307c:	0c128c01 	jal	0x4a3004
  4a3080:	3c100076 	lui	s0,0x76
  4a3084:	8e047b08 	lw	a0,31496(s0)
  4a3088:	50800005 	beqzl	a0,0x4a30a0
  4a308c:	3c100076 	lui	s0,0x76
  4a3090:	0c1020d8 	jal	0x408360
  4a3094:	00000000 	nop
  4a3098:	ae007b08 	sw	zero,31496(s0)
  4a309c:	3c100076 	lui	s0,0x76
  4a30a0:	8e047b1c 	lw	a0,31516(s0)
  4a30a4:	50800005 	beqzl	a0,0x4a30bc
  4a30a8:	3c100076 	lui	s0,0x76
  4a30ac:	0c1020d8 	jal	0x408360
  4a30b0:	00000000 	nop
  4a30b4:	ae007b1c 	sw	zero,31516(s0)
  4a30b8:	3c100076 	lui	s0,0x76
  4a30bc:	8e047b20 	lw	a0,31520(s0)
  4a30c0:	10800005 	beqz	a0,0x4a30d8
  4a30c4:	8fbf001c 	lw	ra,28(sp)
  4a30c8:	0c102088 	jal	0x408220
  4a30cc:	00000000 	nop
  4a30d0:	ae007b20 	sw	zero,31520(s0)
  4a30d4:	8fbf001c 	lw	ra,28(sp)
  4a30d8:	8fb00018 	lw	s0,24(sp)
  4a30dc:	03e00008 	jr	ra
  4a30e0:	27bd0020 	addiu	sp,sp,32
