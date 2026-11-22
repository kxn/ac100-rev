; func cloud_mngt_sync_module_config_clear @ 0x0048ede4 size=0x38
  48ede4:	27bdffe0 	addiu	sp,sp,-32
  48ede8:	2405ffff 	li	a1,-1
  48edec:	afb00018 	sw	s0,24(sp)
  48edf0:	3c100076 	lui	s0,0x76
  48edf4:	afbf001c 	sw	ra,28(sp)
  48edf8:	0c1020b4 	jal	0x4082d0
  48edfc:	8e0478c8 	lw	a0,30920(s0)
  48ee00:	0c1231d3 	jal	0x48c74c
  48ee04:	00000000 	nop
  48ee08:	8e0478c8 	lw	a0,30920(s0)
  48ee0c:	8fbf001c 	lw	ra,28(sp)
  48ee10:	8fb00018 	lw	s0,24(sp)
  48ee14:	08101fcc 	j	0x407f30
  48ee18:	27bd0020 	addiu	sp,sp,32
