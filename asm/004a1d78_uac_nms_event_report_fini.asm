; func uac_nms_event_report_fini @ 0x004a1d78 size=0x74
  4a1d78:	27bdffe0 	addiu	sp,sp,-32
  4a1d7c:	afb00018 	sw	s0,24(sp)
  4a1d80:	afbf001c 	sw	ra,28(sp)
  4a1d84:	0c128743 	jal	0x4a1d0c
  4a1d88:	3c100076 	lui	s0,0x76
  4a1d8c:	8e047ab8 	lw	a0,31416(s0)
  4a1d90:	50800005 	beqzl	a0,0x4a1da8
  4a1d94:	3c100076 	lui	s0,0x76
  4a1d98:	0c1020d8 	jal	0x408360
  4a1d9c:	00000000 	nop
  4a1da0:	ae007ab8 	sw	zero,31416(s0)
  4a1da4:	3c100076 	lui	s0,0x76
  4a1da8:	8e047ad0 	lw	a0,31440(s0)
  4a1dac:	50800005 	beqzl	a0,0x4a1dc4
  4a1db0:	3c100076 	lui	s0,0x76
  4a1db4:	0c1020d8 	jal	0x408360
  4a1db8:	00000000 	nop
  4a1dbc:	ae007ad0 	sw	zero,31440(s0)
  4a1dc0:	3c100076 	lui	s0,0x76
  4a1dc4:	8e047ad4 	lw	a0,31444(s0)
  4a1dc8:	10800005 	beqz	a0,0x4a1de0
  4a1dcc:	8fbf001c 	lw	ra,28(sp)
  4a1dd0:	0c102088 	jal	0x408220
  4a1dd4:	00000000 	nop
  4a1dd8:	ae007ad4 	sw	zero,31444(s0)
  4a1ddc:	8fbf001c 	lw	ra,28(sp)
  4a1de0:	8fb00018 	lw	s0,24(sp)
  4a1de4:	03e00008 	jr	ra
  4a1de8:	27bd0020 	addiu	sp,sp,32
