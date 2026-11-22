; func acpdt_destroy @ 0x00666344 size=0x3c
  666344:	27bdffe0 	addiu	sp,sp,-32
  666348:	afb00018 	sw	s0,24(sp)
  66634c:	3c10007d 	lui	s0,0x7d
  666350:	afbf001c 	sw	ra,28(sp)
  666354:	8e02c8a8 	lw	v0,-14168(s0)
  666358:	10400005 	beqz	v0,0x666370
  66635c:	00000000 	nop
  666360:	8fbf001c 	lw	ra,28(sp)
  666364:	8fb00018 	lw	s0,24(sp)
  666368:	03e00008 	jr	ra
  66636c:	27bd0020 	addiu	sp,sp,32
  666370:	0c101f7c 	jal	0x407df0
  666374:	00002021 	move	a0,zero
  666378:	081998d8 	j	0x666360
  66637c:	ae00c8a8 	sw	zero,-14168(s0)
