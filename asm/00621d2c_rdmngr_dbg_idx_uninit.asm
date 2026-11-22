; func rdmngr_dbg_idx_uninit @ 0x00621d2c size=0x38
  621d2c:	27bdffe0 	addiu	sp,sp,-32
  621d30:	afb00018 	sw	s0,24(sp)
  621d34:	3c10007d 	lui	s0,0x7d
  621d38:	afbf001c 	sw	ra,28(sp)
  621d3c:	8e04c630 	lw	a0,-14800(s0)
  621d40:	10800005 	beqz	a0,0x621d58
  621d44:	8fbf001c 	lw	ra,28(sp)
  621d48:	0c101f7c 	jal	0x407df0
  621d4c:	00000000 	nop
  621d50:	ae00c630 	sw	zero,-14800(s0)
  621d54:	8fbf001c 	lw	ra,28(sp)
  621d58:	8fb00018 	lw	s0,24(sp)
  621d5c:	03e00008 	jr	ra
  621d60:	27bd0020 	addiu	sp,sp,32
