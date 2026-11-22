; func uac_nms_report_msg_handle @ 0x0049d620 size=0x50
  49d620:	27bdffe0 	addiu	sp,sp,-32
  49d624:	afbf001c 	sw	ra,28(sp)
  49d628:	1080000d 	beqz	a0,0x49d660
  49d62c:	afb00018 	sw	s0,24(sp)
  49d630:	0c101b84 	jal	0x406e10
  49d634:	00000000 	nop
  49d638:	10400009 	beqz	v0,0x49d660
  49d63c:	00408021 	move	s0,v0
  49d640:	00002821 	move	a1,zero
  49d644:	0c1438c1 	jal	0x50e304
  49d648:	00402021 	move	a0,v0
  49d64c:	02002021 	move	a0,s0
  49d650:	8fbf001c 	lw	ra,28(sp)
  49d654:	8fb00018 	lw	s0,24(sp)
  49d658:	08101f30 	j	0x407cc0
  49d65c:	27bd0020 	addiu	sp,sp,32
  49d660:	8fbf001c 	lw	ra,28(sp)
  49d664:	8fb00018 	lw	s0,24(sp)
  49d668:	03e00008 	jr	ra
  49d66c:	27bd0020 	addiu	sp,sp,32
