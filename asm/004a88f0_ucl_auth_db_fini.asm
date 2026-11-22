; func ucl_auth_db_fini @ 0x004a88f0 size=0x6c
  4a88f0:	3c1c002c 	lui	gp,0x2c
  4a88f4:	279c8810 	addiu	gp,gp,-30704
  4a88f8:	0399e021 	addu	gp,gp,t9
  4a88fc:	27bdffe0 	addiu	sp,sp,-32
  4a8900:	afbc0010 	sw	gp,16(sp)
  4a8904:	afb00018 	sw	s0,24(sp)
  4a8908:	afbf001c 	sw	ra,28(sp)
  4a890c:	8f908290 	lw	s0,-32112(gp)
  4a8910:	8e040000 	lw	a0,0(s0)
  4a8914:	10800005 	beqz	a0,0x4a892c
  4a8918:	8f9982a0 	lw	t9,-32096(gp)
  4a891c:	0320f809 	jalr	t9
  4a8920:	00000000 	nop
  4a8924:	8fbc0010 	lw	gp,16(sp)
  4a8928:	ae000000 	sw	zero,0(s0)
  4a892c:	8f908294 	lw	s0,-32108(gp)
  4a8930:	8e040000 	lw	a0,0(s0)
  4a8934:	10800004 	beqz	a0,0x4a8948
  4a8938:	8f9982a0 	lw	t9,-32096(gp)
  4a893c:	0320f809 	jalr	t9
  4a8940:	00000000 	nop
  4a8944:	ae000000 	sw	zero,0(s0)
  4a8948:	8fbf001c 	lw	ra,28(sp)
  4a894c:	00001021 	move	v0,zero
  4a8950:	8fb00018 	lw	s0,24(sp)
  4a8954:	03e00008 	jr	ra
  4a8958:	27bd0020 	addiu	sp,sp,32
  4a895c:	00000000 	nop
