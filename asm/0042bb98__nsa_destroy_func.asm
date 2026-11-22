; func _nsa_destroy_func @ 0x0042bb98 size=0x38
  42bb98:	27bdffe0 	addiu	sp,sp,-32
  42bb9c:	afb00018 	sw	s0,24(sp)
  42bba0:	afbf001c 	sw	ra,28(sp)
  42bba4:	0c102140 	jal	0x408500
  42bba8:	00808021 	move	s0,a0
  42bbac:	0c102140 	jal	0x408500
  42bbb0:	26040110 	addiu	a0,s0,272
  42bbb4:	0c102140 	jal	0x408500
  42bbb8:	2604011c 	addiu	a0,s0,284
  42bbbc:	02002021 	move	a0,s0
  42bbc0:	8fbf001c 	lw	ra,28(sp)
  42bbc4:	8fb00018 	lw	s0,24(sp)
  42bbc8:	08101f7c 	j	0x407df0
  42bbcc:	27bd0020 	addiu	sp,sp,32
