; func cw_priv_rrm_neighs_list_free @ 0x005be400 size=0x3c
  5be400:	27bdffe0 	addiu	sp,sp,-32
  5be404:	afb00018 	sw	s0,24(sp)
  5be408:	00808021 	move	s0,a0
  5be40c:	afbf001c 	sw	ra,28(sp)
  5be410:	8c840010 	lw	a0,16(a0)
  5be414:	10800005 	beqz	a0,0x5be42c
  5be418:	8fbf001c 	lw	ra,28(sp)
  5be41c:	0c16f8d3 	jal	0x5be34c
  5be420:	00000000 	nop
  5be424:	ae000010 	sw	zero,16(s0)
  5be428:	8fbf001c 	lw	ra,28(sp)
  5be42c:	00001021 	move	v0,zero
  5be430:	8fb00018 	lw	s0,24(sp)
  5be434:	03e00008 	jr	ra
  5be438:	27bd0020 	addiu	sp,sp,32
