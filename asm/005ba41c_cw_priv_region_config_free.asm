; func cw_priv_region_config_free @ 0x005ba41c size=0x3c
  5ba41c:	27bdffe0 	addiu	sp,sp,-32
  5ba420:	afb00018 	sw	s0,24(sp)
  5ba424:	00808021 	move	s0,a0
  5ba428:	afbf001c 	sw	ra,28(sp)
  5ba42c:	8c840010 	lw	a0,16(a0)
  5ba430:	10800005 	beqz	a0,0x5ba448
  5ba434:	8fbf001c 	lw	ra,28(sp)
  5ba438:	0c101f7c 	jal	0x407df0
  5ba43c:	00000000 	nop
  5ba440:	ae000010 	sw	zero,16(s0)
  5ba444:	8fbf001c 	lw	ra,28(sp)
  5ba448:	00001021 	move	v0,zero
  5ba44c:	8fb00018 	lw	s0,24(sp)
  5ba450:	03e00008 	jr	ra
  5ba454:	27bd0020 	addiu	sp,sp,32
