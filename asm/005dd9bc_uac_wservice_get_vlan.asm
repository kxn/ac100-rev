; func uac_wservice_get_vlan @ 0x005dd9bc size=0x40
  5dd9bc:	27bdffd8 	addiu	sp,sp,-40
  5dd9c0:	30a500ff 	andi	a1,a1,0xff
  5dd9c4:	afb10020 	sw	s1,32(sp)
  5dd9c8:	00e08821 	move	s1,a3
  5dd9cc:	afb0001c 	sw	s0,28(sp)
  5dd9d0:	afbf0024 	sw	ra,36(sp)
  5dd9d4:	0c186b96 	jal	0x61ae58
  5dd9d8:	30d000ff 	andi	s0,a2,0xff
  5dd9dc:	02002821 	move	a1,s0
  5dd9e0:	02203021 	move	a2,s1
  5dd9e4:	8fbf0024 	lw	ra,36(sp)
  5dd9e8:	8fb10020 	lw	s1,32(sp)
  5dd9ec:	00402021 	move	a0,v0
  5dd9f0:	8fb0001c 	lw	s0,28(sp)
  5dd9f4:	0817c861 	j	0x5f2184
  5dd9f8:	27bd0028 	addiu	sp,sp,40
