; func wips_ap_multilink @ 0x004c69f0 size=0x34
  4c69f0:	27bdffe0 	addiu	sp,sp,-32
  4c69f4:	afb00018 	sw	s0,24(sp)
  4c69f8:	3090ffff 	andi	s0,a0,0xffff
  4c69fc:	afbf001c 	sw	ra,28(sp)
  4c6a00:	0c131958 	jal	0x4c6560
  4c6a04:	02002021 	move	a0,s0
  4c6a08:	0c131a3c 	jal	0x4c68f0
  4c6a0c:	02002021 	move	a0,s0
  4c6a10:	00001021 	move	v0,zero
  4c6a14:	8fbf001c 	lw	ra,28(sp)
  4c6a18:	8fb00018 	lw	s0,24(sp)
  4c6a1c:	03e00008 	jr	ra
  4c6a20:	27bd0020 	addiu	sp,sp,32
