; func _apdb_ap_model_rrst_free @ 0x005ffae4 size=0x60
  5ffae4:	27bdffd8 	addiu	sp,sp,-40
  5ffae8:	afb1001c 	sw	s1,28(sp)
  5ffaec:	00a08821 	move	s1,a1
  5ffaf0:	afbf0024 	sw	ra,36(sp)
  5ffaf4:	afb20020 	sw	s2,32(sp)
  5ffaf8:	1080000c 	beqz	a0,0x5ffb2c
  5ffafc:	afb00018 	sw	s0,24(sp)
  5ffb00:	18a0000a 	blez	a1,0x5ffb2c
  5ffb04:	00009021 	move	s2,zero
  5ffb08:	00808021 	move	s0,a0
  5ffb0c:	8e040034 	lw	a0,52(s0)
  5ffb10:	10800004 	beqz	a0,0x5ffb24
  5ffb14:	26520001 	addiu	s2,s2,1
  5ffb18:	0c101f7c 	jal	0x407df0
  5ffb1c:	00000000 	nop
  5ffb20:	ae000034 	sw	zero,52(s0)
  5ffb24:	1651fff9 	bne	s2,s1,0x5ffb0c
  5ffb28:	26100038 	addiu	s0,s0,56
  5ffb2c:	8fbf0024 	lw	ra,36(sp)
  5ffb30:	8fb20020 	lw	s2,32(sp)
  5ffb34:	8fb1001c 	lw	s1,28(sp)
  5ffb38:	8fb00018 	lw	s0,24(sp)
  5ffb3c:	03e00008 	jr	ra
  5ffb40:	27bd0028 	addiu	sp,sp,40
