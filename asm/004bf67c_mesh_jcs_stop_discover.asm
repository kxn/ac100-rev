; func mesh_jcs_stop_discover @ 0x004bf67c size=0x44
  4bf67c:	27bdffe0 	addiu	sp,sp,-32
  4bf680:	afbf001c 	sw	ra,28(sp)
  4bf684:	afb00018 	sw	s0,24(sp)
  4bf688:	0c12fd80 	jal	0x4bf600
  4bf68c:	00a08021 	move	s0,a1
  4bf690:	0c12fd16 	jal	0x4bf458
  4bf694:	00000000 	nop
  4bf698:	0c101d34 	jal	0x4074d0
  4bf69c:	00402021 	move	a0,v0
  4bf6a0:	3c050067 	lui	a1,0x67
  4bf6a4:	02002021 	move	a0,s0
  4bf6a8:	8fbf001c 	lw	ra,28(sp)
  4bf6ac:	8fb00018 	lw	s0,24(sp)
  4bf6b0:	24a56a24 	addiu	a1,a1,27172
  4bf6b4:	27bd0020 	addiu	sp,sp,32
  4bf6b8:	08101d78 	j	0x4075e0
  4bf6bc:	00403021 	move	a2,v0
