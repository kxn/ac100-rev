; func sensor_mngt_uninit @ 0x004e9d30 size=0x38
  4e9d30:	27bdffe0 	addiu	sp,sp,-32
  4e9d34:	afb00018 	sw	s0,24(sp)
  4e9d38:	3c100077 	lui	s0,0x77
  4e9d3c:	afbf001c 	sw	ra,28(sp)
  4e9d40:	8e04862c 	lw	a0,-31188(s0)
  4e9d44:	10800005 	beqz	a0,0x4e9d5c
  4e9d48:	8fbf001c 	lw	ra,28(sp)
  4e9d4c:	0c1020d8 	jal	0x408360
  4e9d50:	00000000 	nop
  4e9d54:	ae00862c 	sw	zero,-31188(s0)
  4e9d58:	8fbf001c 	lw	ra,28(sp)
  4e9d5c:	8fb00018 	lw	s0,24(sp)
  4e9d60:	0813460b 	j	0x4d182c
  4e9d64:	27bd0020 	addiu	sp,sp,32
