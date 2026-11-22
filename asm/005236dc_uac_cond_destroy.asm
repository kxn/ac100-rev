; func uac_cond_destroy @ 0x005236dc size=0x78
  5236dc:	3c1c0024 	lui	gp,0x24
  5236e0:	279cda24 	addiu	gp,gp,-9692
  5236e4:	0399e021 	addu	gp,gp,t9
  5236e8:	27bdffe0 	addiu	sp,sp,-32
  5236ec:	afbc0010 	sw	gp,16(sp)
  5236f0:	afb00018 	sw	s0,24(sp)
  5236f4:	00808021 	move	s0,a0
  5236f8:	10800012 	beqz	a0,0x523744
  5236fc:	afbf001c 	sw	ra,28(sp)
  523700:	8f99850c 	lw	t9,-31476(gp)
  523704:	0320f809 	jalr	t9
  523708:	00000000 	nop
  52370c:	8e040030 	lw	a0,48(s0)
  523710:	10800006 	beqz	a0,0x52372c
  523714:	8fbc0010 	lw	gp,16(sp)
  523718:	8f998054 	lw	t9,-32684(gp)
  52371c:	0411ea2d 	bal	0x51dfd4
  523720:	00000000 	nop
  523724:	8fbc0010 	lw	gp,16(sp)
  523728:	ae000030 	sw	zero,48(s0)
  52372c:	02002021 	move	a0,s0
  523730:	8fbf001c 	lw	ra,28(sp)
  523734:	8fb00018 	lw	s0,24(sp)
  523738:	8f998054 	lw	t9,-32684(gp)
  52373c:	1000ea25 	b	0x51dfd4
  523740:	27bd0020 	addiu	sp,sp,32
  523744:	8fbf001c 	lw	ra,28(sp)
  523748:	8fb00018 	lw	s0,24(sp)
  52374c:	03e00008 	jr	ra
  523750:	27bd0020 	addiu	sp,sp,32
