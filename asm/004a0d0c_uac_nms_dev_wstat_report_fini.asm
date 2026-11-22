; func uac_nms_dev_wstat_report_fini @ 0x004a0d0c size=0x74
  4a0d0c:	27bdffe0 	addiu	sp,sp,-32
  4a0d10:	afb00018 	sw	s0,24(sp)
  4a0d14:	afbf001c 	sw	ra,28(sp)
  4a0d18:	0c128328 	jal	0x4a0ca0
  4a0d1c:	3c100076 	lui	s0,0x76
  4a0d20:	8e047a7c 	lw	a0,31356(s0)
  4a0d24:	50800005 	beqzl	a0,0x4a0d3c
  4a0d28:	3c100076 	lui	s0,0x76
  4a0d2c:	0c1020d8 	jal	0x408360
  4a0d30:	00000000 	nop
  4a0d34:	ae007a7c 	sw	zero,31356(s0)
  4a0d38:	3c100076 	lui	s0,0x76
  4a0d3c:	8e047a90 	lw	a0,31376(s0)
  4a0d40:	50800005 	beqzl	a0,0x4a0d58
  4a0d44:	3c100076 	lui	s0,0x76
  4a0d48:	0c1020d8 	jal	0x408360
  4a0d4c:	00000000 	nop
  4a0d50:	ae007a90 	sw	zero,31376(s0)
  4a0d54:	3c100076 	lui	s0,0x76
  4a0d58:	8e047a94 	lw	a0,31380(s0)
  4a0d5c:	10800005 	beqz	a0,0x4a0d74
  4a0d60:	8fbf001c 	lw	ra,28(sp)
  4a0d64:	0c102088 	jal	0x408220
  4a0d68:	00000000 	nop
  4a0d6c:	ae007a94 	sw	zero,31380(s0)
  4a0d70:	8fbf001c 	lw	ra,28(sp)
  4a0d74:	8fb00018 	lw	s0,24(sp)
  4a0d78:	03e00008 	jr	ra
  4a0d7c:	27bd0020 	addiu	sp,sp,32
