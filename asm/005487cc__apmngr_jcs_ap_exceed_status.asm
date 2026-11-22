; func _apmngr_jcs_ap_exceed_status @ 0x005487cc size=0x3c
  5487cc:	27bdffe0 	addiu	sp,sp,-32
  5487d0:	afbf001c 	sw	ra,28(sp)
  5487d4:	afb00018 	sw	s0,24(sp)
  5487d8:	0c14ac57 	jal	0x52b15c
  5487dc:	00a08021 	move	s0,a1
  5487e0:	0c101d34 	jal	0x4074d0
  5487e4:	00402021 	move	a0,v0
  5487e8:	3c05006d 	lui	a1,0x6d
  5487ec:	02002021 	move	a0,s0
  5487f0:	8fbf001c 	lw	ra,28(sp)
  5487f4:	8fb00018 	lw	s0,24(sp)
  5487f8:	24a5eb84 	addiu	a1,a1,-5244
  5487fc:	27bd0020 	addiu	sp,sp,32
  548800:	08101d78 	j	0x4075e0
  548804:	00403021 	move	a2,v0
