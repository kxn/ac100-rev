; func cw_session_id_free @ 0x00580918 size=0x3c
  580918:	27bdffe0 	addiu	sp,sp,-32
  58091c:	afb00018 	sw	s0,24(sp)
  580920:	00808021 	move	s0,a0
  580924:	afbf001c 	sw	ra,28(sp)
  580928:	8c840010 	lw	a0,16(a0)
  58092c:	10800005 	beqz	a0,0x580944
  580930:	8fbf001c 	lw	ra,28(sp)
  580934:	0c101f7c 	jal	0x407df0
  580938:	00000000 	nop
  58093c:	ae000010 	sw	zero,16(s0)
  580940:	8fbf001c 	lw	ra,28(sp)
  580944:	00001021 	move	v0,zero
  580948:	8fb00018 	lw	s0,24(sp)
  58094c:	03e00008 	jr	ra
  580950:	27bd0020 	addiu	sp,sp,32
