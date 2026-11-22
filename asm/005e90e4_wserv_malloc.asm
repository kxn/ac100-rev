; func wserv_malloc @ 0x005e90e4 size=0x3c
  5e90e4:	27bdffe0 	addiu	sp,sp,-32
  5e90e8:	24050101 	li	a1,257
  5e90ec:	afb00018 	sw	s0,24(sp)
  5e90f0:	afbf001c 	sw	ra,28(sp)
  5e90f4:	0c102114 	jal	0x408450
  5e90f8:	00808021 	move	s0,a0
  5e90fc:	10400004 	beqz	v0,0x5e9110
  5e9100:	3c03007d 	lui	v1,0x7d
  5e9104:	8c64bf70 	lw	a0,-16528(v1)
  5e9108:	02048021 	addu	s0,s0,a0
  5e910c:	ac70bf70 	sw	s0,-16528(v1)
  5e9110:	8fbf001c 	lw	ra,28(sp)
  5e9114:	8fb00018 	lw	s0,24(sp)
  5e9118:	03e00008 	jr	ra
  5e911c:	27bd0020 	addiu	sp,sp,32
