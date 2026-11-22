; func cw_image_information_free @ 0x00577414 size=0x3c
  577414:	27bdffe0 	addiu	sp,sp,-32
  577418:	afb00018 	sw	s0,24(sp)
  57741c:	00808021 	move	s0,a0
  577420:	afbf001c 	sw	ra,28(sp)
  577424:	8c840010 	lw	a0,16(a0)
  577428:	10800005 	beqz	a0,0x577440
  57742c:	8fbf001c 	lw	ra,28(sp)
  577430:	0c101f7c 	jal	0x407df0
  577434:	00000000 	nop
  577438:	ae000010 	sw	zero,16(s0)
  57743c:	8fbf001c 	lw	ra,28(sp)
  577440:	00001021 	move	v0,zero
  577444:	8fb00018 	lw	s0,24(sp)
  577448:	03e00008 	jr	ra
  57744c:	27bd0020 	addiu	sp,sp,32
