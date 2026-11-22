; func di_mem_stat_dump @ 0x004e1f1c size=0x2c
  4e1f1c:	27bdffe0 	addiu	sp,sp,-32
  4e1f20:	afbf001c 	sw	ra,28(sp)
  4e1f24:	0c101e38 	jal	0x4078e0
  4e1f28:	00002021 	move	a0,zero
  4e1f2c:	3c04006b 	lui	a0,0x6b
  4e1f30:	8fbf001c 	lw	ra,28(sp)
  4e1f34:	00003021 	move	a2,zero
  4e1f38:	2484f3c8 	addiu	a0,a0,-3128
  4e1f3c:	27bd0020 	addiu	sp,sp,32
  4e1f40:	08101b74 	j	0x406dd0
  4e1f44:	00402821 	move	a1,v0
