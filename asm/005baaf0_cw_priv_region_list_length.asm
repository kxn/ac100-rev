; func cw_priv_region_list_length @ 0x005baaf0 size=0xc4
  5baaf0:	27bdffd8 	addiu	sp,sp,-40
  5baaf4:	afb20020 	sw	s2,32(sp)
  5baaf8:	3c12007c 	lui	s2,0x7c
  5baafc:	afb00018 	sw	s0,24(sp)
  5bab00:	afbf0024 	sw	ra,36(sp)
  5bab04:	afb1001c 	sw	s1,28(sp)
  5bab08:	8e425988 	lw	v0,22920(s2)
  5bab0c:	1440001e 	bnez	v0,0x5bab88
  5bab10:	00808021 	move	s0,a0
  5bab14:	12000008 	beqz	s0,0x5bab38
  5bab18:	00008821 	move	s1,zero
  5bab1c:	0c16ea8e 	jal	0x5baa38
  5bab20:	02002021 	move	a0,s0
  5bab24:	24420001 	addiu	v0,v0,1
  5bab28:	3051ffff 	andi	s1,v0,0xffff
  5bab2c:	8e425988 	lw	v0,22920(s2)
  5bab30:	14400008 	bnez	v0,0x5bab54
  5bab34:	00000000 	nop
  5bab38:	8fbf0024 	lw	ra,36(sp)
  5bab3c:	02201021 	move	v0,s1
  5bab40:	8fb20020 	lw	s2,32(sp)
  5bab44:	8fb1001c 	lw	s1,28(sp)
  5bab48:	8fb00018 	lw	s0,24(sp)
  5bab4c:	03e00008 	jr	ra
  5bab50:	27bd0028 	addiu	sp,sp,40
  5bab54:	0c16276a 	jal	0x589da8
  5bab58:	00000000 	nop
  5bab5c:	5040fff7 	beqzl	v0,0x5bab3c
  5bab60:	8fbf0024 	lw	ra,36(sp)
  5bab64:	3c04006f 	lui	a0,0x6f
  5bab68:	3c05006f 	lui	a1,0x6f
  5bab6c:	2484d31c 	addiu	a0,a0,-11492
  5bab70:	24a5d840 	addiu	a1,a1,-10176
  5bab74:	2406009c 	li	a2,156
  5bab78:	0c101b74 	jal	0x406dd0
  5bab7c:	02203821 	move	a3,s1
  5bab80:	0816eacf 	j	0x5bab3c
  5bab84:	8fbf0024 	lw	ra,36(sp)
  5bab88:	0c16276a 	jal	0x589da8
  5bab8c:	00000000 	nop
  5bab90:	1040ffe0 	beqz	v0,0x5bab14
  5bab94:	3c05006f 	lui	a1,0x6f
  5bab98:	3c04006f 	lui	a0,0x6f
  5bab9c:	2484d7ac 	addiu	a0,a0,-10324
  5baba0:	24a5d840 	addiu	a1,a1,-10176
  5baba4:	0c101b74 	jal	0x406dd0
  5baba8:	24060093 	li	a2,147
  5babac:	0816eac5 	j	0x5bab14
  5babb0:	00000000 	nop
