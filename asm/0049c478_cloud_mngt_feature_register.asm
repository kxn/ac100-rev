; func cloud_mngt_feature_register @ 0x0049c478 size=0x34
  49c478:	3c020073 	lui	v0,0x73
  49c47c:	27bdffe0 	addiu	sp,sp,-32
  49c480:	80421824 	lb	v0,6180(v0)
  49c484:	10400004 	beqz	v0,0x49c498
  49c488:	afbf001c 	sw	ra,28(sp)
  49c48c:	3c04006a 	lui	a0,0x6a
  49c490:	0c101d74 	jal	0x4075d0
  49c494:	2484a420 	addiu	a0,a0,-23520
  49c498:	3c04006a 	lui	a0,0x6a
  49c49c:	8fbf001c 	lw	ra,28(sp)
  49c4a0:	27bd0020 	addiu	sp,sp,32
  49c4a4:	08101d74 	j	0x4075d0
  49c4a8:	2484a4ac 	addiu	a0,a0,-23380
