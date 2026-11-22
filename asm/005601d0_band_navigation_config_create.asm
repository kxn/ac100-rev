; func band_navigation_config_create @ 0x005601d0 size=0x44
  5601d0:	27bdffe0 	addiu	sp,sp,-32
  5601d4:	24040014 	li	a0,20
  5601d8:	afb00018 	sw	s0,24(sp)
  5601dc:	afbf001c 	sw	ra,28(sp)
  5601e0:	0c102114 	jal	0x408450
  5601e4:	2405003c 	li	a1,60
  5601e8:	10400005 	beqz	v0,0x560200
  5601ec:	00408021 	move	s0,v0
  5601f0:	00002821 	move	a1,zero
  5601f4:	24060014 	li	a2,20
  5601f8:	0c101cf0 	jal	0x4073c0
  5601fc:	00402021 	move	a0,v0
  560200:	8fbf001c 	lw	ra,28(sp)
  560204:	02001021 	move	v0,s0
  560208:	8fb00018 	lw	s0,24(sp)
  56020c:	03e00008 	jr	ra
  560210:	27bd0020 	addiu	sp,sp,32
