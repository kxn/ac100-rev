; func uac_wservice_wlanid_get_by_wservid @ 0x005dd0cc size=0x30
  5dd0cc:	27bdffe0 	addiu	sp,sp,-32
  5dd0d0:	30a500ff 	andi	a1,a1,0xff
  5dd0d4:	afb00018 	sw	s0,24(sp)
  5dd0d8:	afbf001c 	sw	ra,28(sp)
  5dd0dc:	0c186b96 	jal	0x61ae58
  5dd0e0:	00c08021 	move	s0,a2
  5dd0e4:	02002821 	move	a1,s0
  5dd0e8:	8fbf001c 	lw	ra,28(sp)
  5dd0ec:	00402021 	move	a0,v0
  5dd0f0:	8fb00018 	lw	s0,24(sp)
  5dd0f4:	0817cf18 	j	0x5f3c60
  5dd0f8:	27bd0020 	addiu	sp,sp,32
