; func _apdb_ap_model_region_list_free @ 0x005ffa84 size=0x60
  5ffa84:	27bdffd8 	addiu	sp,sp,-40
  5ffa88:	afb1001c 	sw	s1,28(sp)
  5ffa8c:	00a08821 	move	s1,a1
  5ffa90:	afbf0024 	sw	ra,36(sp)
  5ffa94:	afb20020 	sw	s2,32(sp)
  5ffa98:	1080000c 	beqz	a0,0x5ffacc
  5ffa9c:	afb00018 	sw	s0,24(sp)
  5ffaa0:	18a0000a 	blez	a1,0x5ffacc
  5ffaa4:	00009021 	move	s2,zero
  5ffaa8:	00808021 	move	s0,a0
  5ffaac:	8e040030 	lw	a0,48(s0)
  5ffab0:	10800004 	beqz	a0,0x5ffac4
  5ffab4:	26520001 	addiu	s2,s2,1
  5ffab8:	0c101f7c 	jal	0x407df0
  5ffabc:	00000000 	nop
  5ffac0:	ae000030 	sw	zero,48(s0)
  5ffac4:	1651fff9 	bne	s2,s1,0x5ffaac
  5ffac8:	26100038 	addiu	s0,s0,56
  5ffacc:	8fbf0024 	lw	ra,36(sp)
  5ffad0:	8fb20020 	lw	s2,32(sp)
  5ffad4:	8fb1001c 	lw	s1,28(sp)
  5ffad8:	8fb00018 	lw	s0,24(sp)
  5ffadc:	03e00008 	jr	ra
  5ffae0:	27bd0028 	addiu	sp,sp,40
