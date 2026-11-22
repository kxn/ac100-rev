; func uac_id_fix @ 0x00519db8 size=0x90
  519db8:	10800021 	beqz	a0,0x519e40
  519dbc:	00000000 	nop
  519dc0:	8c820014 	lw	v0,20(a0)
  519dc4:	1040001e 	beqz	v0,0x519e40
  519dc8:	00001021 	move	v0,zero
  519dcc:	8c830010 	lw	v1,16(a0)
  519dd0:	2405ffff 	li	a1,-1
  519dd4:	2463ffff 	addiu	v1,v1,-1
  519dd8:	0043302a 	slt	a2,v0,v1
  519ddc:	50c00012 	beqzl	a2,0x519e28
  519de0:	8c820010 	lw	v0,16(a0)
  519de4:	8c870000 	lw	a3,0(a0)
  519de8:	00023080 	sll	a2,v0,0x2
  519dec:	00e64021 	addu	t0,a3,a2
  519df0:	8d080000 	lw	t0,0(t0)
  519df4:	5105fff8 	beql	t0,a1,0x519dd8
  519df8:	24420001 	addiu	v0,v0,1
  519dfc:	00034880 	sll	t1,v1,0x2
  519e00:	00e93821 	addu	a3,a3,t1
  519e04:	8ce90000 	lw	t1,0(a3)
  519e08:	51250003 	beql	t1,a1,0x519e18
  519e0c:	ace80000 	sw	t0,0(a3)
  519e10:	1000fff1 	b	0x519dd8
  519e14:	2463ffff 	addiu	v1,v1,-1
  519e18:	8c870000 	lw	a3,0(a0)
  519e1c:	00e63021 	addu	a2,a3,a2
  519e20:	1000ffed 	b	0x519dd8
  519e24:	acc50000 	sw	a1,0(a2)
  519e28:	8c830014 	lw	v1,20(a0)
  519e2c:	ac80000c 	sw	zero,12(a0)
  519e30:	004001f4 	teq	v0,zero,0x7
  519e34:	0062001a 	div	zero,v1,v0
  519e38:	00001010 	mfhi	v0
  519e3c:	ac820008 	sw	v0,8(a0)
  519e40:	03e00008 	jr	ra
  519e44:	00000000 	nop
