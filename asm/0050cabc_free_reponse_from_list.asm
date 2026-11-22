; func free_reponse_from_list @ 0x0050cabc size=0x6c
  50cabc:	27bdffd8 	addiu	sp,sp,-40
  50cac0:	afb10020 	sw	s1,32(sp)
  50cac4:	24910004 	addiu	s1,a0,4
  50cac8:	afbf0024 	sw	ra,36(sp)
  50cacc:	10800011 	beqz	a0,0x50cb14
  50cad0:	afb0001c 	sw	s0,28(sp)
  50cad4:	0c10206c 	jal	0x4081b0
  50cad8:	02202021 	move	a0,s1
  50cadc:	1040000d 	beqz	v0,0x50cb14
  50cae0:	00408021 	move	s0,v0
  50cae4:	8e040018 	lw	a0,24(s0)
  50cae8:	10800004 	beqz	a0,0x50cafc
  50caec:	00000000 	nop
  50caf0:	0c101f7c 	jal	0x407df0
  50caf4:	00000000 	nop
  50caf8:	ae000018 	sw	zero,24(s0)
  50cafc:	0c102140 	jal	0x408500
  50cb00:	02002021 	move	a0,s0
  50cb04:	0c101f7c 	jal	0x407df0
  50cb08:	02002021 	move	a0,s0
  50cb0c:	081432b5 	j	0x50cad4
  50cb10:	00000000 	nop
  50cb14:	8fbf0024 	lw	ra,36(sp)
  50cb18:	8fb10020 	lw	s1,32(sp)
  50cb1c:	8fb0001c 	lw	s0,28(sp)
  50cb20:	03e00008 	jr	ra
  50cb24:	27bd0028 	addiu	sp,sp,40
