; func uac_wservice_is_wlanid_bind @ 0x005dd0fc size=0x30
  5dd0fc:	27bdffe0 	addiu	sp,sp,-32
  5dd100:	30a500ff 	andi	a1,a1,0xff
  5dd104:	afb00018 	sw	s0,24(sp)
  5dd108:	afbf001c 	sw	ra,28(sp)
  5dd10c:	0c186b96 	jal	0x61ae58
  5dd110:	30d000ff 	andi	s0,a2,0xff
  5dd114:	02002821 	move	a1,s0
  5dd118:	8fbf001c 	lw	ra,28(sp)
  5dd11c:	00402021 	move	a0,v0
  5dd120:	8fb00018 	lw	s0,24(sp)
  5dd124:	0817d137 	j	0x5f44dc
  5dd128:	27bd0020 	addiu	sp,sp,32
