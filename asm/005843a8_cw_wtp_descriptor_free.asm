; func cw_wtp_descriptor_free @ 0x005843a8 size=0x3c
  5843a8:	27bdffe0 	addiu	sp,sp,-32
  5843ac:	afb00018 	sw	s0,24(sp)
  5843b0:	00808021 	move	s0,a0
  5843b4:	afbf001c 	sw	ra,28(sp)
  5843b8:	8c840010 	lw	a0,16(a0)
  5843bc:	10800005 	beqz	a0,0x5843d4
  5843c0:	8fbf001c 	lw	ra,28(sp)
  5843c4:	0c1610c0 	jal	0x584300
  5843c8:	00000000 	nop
  5843cc:	ae000010 	sw	zero,16(s0)
  5843d0:	8fbf001c 	lw	ra,28(sp)
  5843d4:	00001021 	move	v0,zero
  5843d8:	8fb00018 	lw	s0,24(sp)
  5843dc:	03e00008 	jr	ra
  5843e0:	27bd0020 	addiu	sp,sp,32
