; func cw_sta_rssi_free @ 0x00581504 size=0x4c
  581504:	27bdffe0 	addiu	sp,sp,-32
  581508:	afb00018 	sw	s0,24(sp)
  58150c:	afbf001c 	sw	ra,28(sp)
  581510:	8c820010 	lw	v0,16(a0)
  581514:	10400009 	beqz	v0,0x58153c
  581518:	00808021 	move	s0,a0
  58151c:	8c440008 	lw	a0,8(v0)
  581520:	10800003 	beqz	a0,0x581530
  581524:	00000000 	nop
  581528:	0c101f7c 	jal	0x407df0
  58152c:	00000000 	nop
  581530:	0c101f7c 	jal	0x407df0
  581534:	8e040010 	lw	a0,16(s0)
  581538:	ae000010 	sw	zero,16(s0)
  58153c:	8fbf001c 	lw	ra,28(sp)
  581540:	00001021 	move	v0,zero
  581544:	8fb00018 	lw	s0,24(sp)
  581548:	03e00008 	jr	ra
  58154c:	27bd0020 	addiu	sp,sp,32
