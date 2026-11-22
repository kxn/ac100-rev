; func uac_report_uninit @ 0x004b59b4 size=0x74
  4b59b4:	27bdffe0 	addiu	sp,sp,-32
  4b59b8:	afb00018 	sw	s0,24(sp)
  4b59bc:	3c100076 	lui	s0,0x76
  4b59c0:	afbf001c 	sw	ra,28(sp)
  4b59c4:	0c12cdd0 	jal	0x4b3740
  4b59c8:	26107c58 	addiu	s0,s0,31832
  4b59cc:	8e040100 	lw	a0,256(s0)
  4b59d0:	10800005 	beqz	a0,0x4b59e8
  4b59d4:	3c020076 	lui	v0,0x76
  4b59d8:	0c101f7c 	jal	0x407df0
  4b59dc:	00000000 	nop
  4b59e0:	ae000100 	sw	zero,256(s0)
  4b59e4:	3c020076 	lui	v0,0x76
  4b59e8:	8c447c48 	lw	a0,31816(v0)
  4b59ec:	10800004 	beqz	a0,0x4b5a00
  4b59f0:	3c020076 	lui	v0,0x76
  4b59f4:	0c1020d8 	jal	0x408360
  4b59f8:	00000000 	nop
  4b59fc:	3c020076 	lui	v0,0x76
  4b5a00:	8c447c4c 	lw	a0,31820(v0)
  4b5a04:	10800004 	beqz	a0,0x4b5a18
  4b5a08:	8fbf001c 	lw	ra,28(sp)
  4b5a0c:	0c102088 	jal	0x408220
  4b5a10:	00000000 	nop
  4b5a14:	8fbf001c 	lw	ra,28(sp)
  4b5a18:	00001021 	move	v0,zero
  4b5a1c:	8fb00018 	lw	s0,24(sp)
  4b5a20:	03e00008 	jr	ra
  4b5a24:	27bd0020 	addiu	sp,sp,32
