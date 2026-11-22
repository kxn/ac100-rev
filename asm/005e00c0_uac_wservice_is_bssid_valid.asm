; func uac_wservice_is_bssid_valid @ 0x005e00c0 size=0x30
  5e00c0:	27bdffe0 	addiu	sp,sp,-32
  5e00c4:	30a500ff 	andi	a1,a1,0xff
  5e00c8:	afb00018 	sw	s0,24(sp)
  5e00cc:	afbf001c 	sw	ra,28(sp)
  5e00d0:	0c186b96 	jal	0x61ae58
  5e00d4:	00c08021 	move	s0,a2
  5e00d8:	02002821 	move	a1,s0
  5e00dc:	8fbf001c 	lw	ra,28(sp)
  5e00e0:	00402021 	move	a0,v0
  5e00e4:	8fb00018 	lw	s0,24(sp)
  5e00e8:	0817d25a 	j	0x5f4968
  5e00ec:	27bd0020 	addiu	sp,sp,32
