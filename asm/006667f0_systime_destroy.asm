; func systime_destroy @ 0x006667f0 size=0x38
  6667f0:	27bdffe0 	addiu	sp,sp,-32
  6667f4:	afb00018 	sw	s0,24(sp)
  6667f8:	3c10007d 	lui	s0,0x7d
  6667fc:	afbf001c 	sw	ra,28(sp)
  666800:	8e04c8b0 	lw	a0,-14160(s0)
  666804:	10800005 	beqz	a0,0x66681c
  666808:	8fbf001c 	lw	ra,28(sp)
  66680c:	0c101f7c 	jal	0x407df0
  666810:	00000000 	nop
  666814:	ae00c8b0 	sw	zero,-14160(s0)
  666818:	8fbf001c 	lw	ra,28(sp)
  66681c:	8fb00018 	lw	s0,24(sp)
  666820:	03e00008 	jr	ra
  666824:	27bd0020 	addiu	sp,sp,32
	...
