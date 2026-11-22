; func cw_parsed_pkt_destroy @ 0x005888f4 size=0x40
  5888f4:	27bdffe0 	addiu	sp,sp,-32
  5888f8:	afb00018 	sw	s0,24(sp)
  5888fc:	00808021 	move	s0,a0
  588900:	10800008 	beqz	a0,0x588924
  588904:	afbf001c 	sw	ra,28(sp)
  588908:	0c161e1f 	jal	0x58787c
  58890c:	00000000 	nop
  588910:	02002021 	move	a0,s0
  588914:	8fbf001c 	lw	ra,28(sp)
  588918:	8fb00018 	lw	s0,24(sp)
  58891c:	08101f7c 	j	0x407df0
  588920:	27bd0020 	addiu	sp,sp,32
  588924:	8fbf001c 	lw	ra,28(sp)
  588928:	8fb00018 	lw	s0,24(sp)
  58892c:	03e00008 	jr	ra
  588930:	27bd0020 	addiu	sp,sp,32
