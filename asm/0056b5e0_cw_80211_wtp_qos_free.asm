; func cw_80211_wtp_qos_free @ 0x0056b5e0 size=0x3c
  56b5e0:	27bdffe0 	addiu	sp,sp,-32
  56b5e4:	afb00018 	sw	s0,24(sp)
  56b5e8:	00808021 	move	s0,a0
  56b5ec:	afbf001c 	sw	ra,28(sp)
  56b5f0:	8c840010 	lw	a0,16(a0)
  56b5f4:	10800005 	beqz	a0,0x56b60c
  56b5f8:	8fbf001c 	lw	ra,28(sp)
  56b5fc:	0c101f7c 	jal	0x407df0
  56b600:	00000000 	nop
  56b604:	ae000010 	sw	zero,16(s0)
  56b608:	8fbf001c 	lw	ra,28(sp)
  56b60c:	00001021 	move	v0,zero
  56b610:	8fb00018 	lw	s0,24(sp)
  56b614:	03e00008 	jr	ra
  56b618:	27bd0020 	addiu	sp,sp,32
