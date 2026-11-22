; func uac_wservice_get_wserv_id @ 0x005dd06c size=0x30
  5dd06c:	27bdffe0 	addiu	sp,sp,-32
  5dd070:	30a500ff 	andi	a1,a1,0xff
  5dd074:	afb00018 	sw	s0,24(sp)
  5dd078:	afbf001c 	sw	ra,28(sp)
  5dd07c:	0c186b96 	jal	0x61ae58
  5dd080:	30d000ff 	andi	s0,a2,0xff
  5dd084:	02002821 	move	a1,s0
  5dd088:	8fbf001c 	lw	ra,28(sp)
  5dd08c:	00402021 	move	a0,v0
  5dd090:	8fb00018 	lw	s0,24(sp)
  5dd094:	0817b668 	j	0x5ed9a0
  5dd098:	27bd0020 	addiu	sp,sp,32
