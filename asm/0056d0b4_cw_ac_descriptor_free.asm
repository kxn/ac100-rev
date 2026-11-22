; func cw_ac_descriptor_free @ 0x0056d0b4 size=0x3c
  56d0b4:	27bdffe0 	addiu	sp,sp,-32
  56d0b8:	afb00018 	sw	s0,24(sp)
  56d0bc:	00808021 	move	s0,a0
  56d0c0:	afbf001c 	sw	ra,28(sp)
  56d0c4:	8c840010 	lw	a0,16(a0)
  56d0c8:	10800005 	beqz	a0,0x56d0e0
  56d0cc:	8fbf001c 	lw	ra,28(sp)
  56d0d0:	0c15b40d 	jal	0x56d034
  56d0d4:	00000000 	nop
  56d0d8:	ae000010 	sw	zero,16(s0)
  56d0dc:	8fbf001c 	lw	ra,28(sp)
  56d0e0:	00001021 	move	v0,zero
  56d0e4:	8fb00018 	lw	s0,24(sp)
  56d0e8:	03e00008 	jr	ra
  56d0ec:	27bd0020 	addiu	sp,sp,32
