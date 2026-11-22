; func uac_wservice_is_wserv_bind_to_rd @ 0x005dd09c size=0x30
  5dd09c:	27bdffe0 	addiu	sp,sp,-32
  5dd0a0:	30a500ff 	andi	a1,a1,0xff
  5dd0a4:	afb00018 	sw	s0,24(sp)
  5dd0a8:	afbf001c 	sw	ra,28(sp)
  5dd0ac:	0c186b96 	jal	0x61ae58
  5dd0b0:	00c08021 	move	s0,a2
  5dd0b4:	02002821 	move	a1,s0
  5dd0b8:	8fbf001c 	lw	ra,28(sp)
  5dd0bc:	00402021 	move	a0,v0
  5dd0c0:	8fb00018 	lw	s0,24(sp)
  5dd0c4:	0817ce7d 	j	0x5f39f4
  5dd0c8:	27bd0020 	addiu	sp,sp,32
