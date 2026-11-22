; func apdb_print_ap_cnt @ 0x0060b928 size=0x44
  60b928:	27bdffe0 	addiu	sp,sp,-32
  60b92c:	2405ffff 	li	a1,-1
  60b930:	afb00018 	sw	s0,24(sp)
  60b934:	3c10007d 	lui	s0,0x7d
  60b938:	afbf001c 	sw	ra,28(sp)
  60b93c:	0c1020b4 	jal	0x4082d0
  60b940:	8e04c288 	lw	a0,-15736(s0)
  60b944:	3c02007d 	lui	v0,0x7d
  60b948:	3c040070 	lui	a0,0x70
  60b94c:	8c45c28c 	lw	a1,-15732(v0)
  60b950:	0c101b74 	jal	0x406dd0
  60b954:	24840fdc 	addiu	a0,a0,4060
  60b958:	8e04c288 	lw	a0,-15736(s0)
  60b95c:	8fbf001c 	lw	ra,28(sp)
  60b960:	8fb00018 	lw	s0,24(sp)
  60b964:	08101fcc 	j	0x407f30
  60b968:	27bd0020 	addiu	sp,sp,32
