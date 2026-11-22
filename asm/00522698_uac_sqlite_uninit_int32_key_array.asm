; func uac_sqlite_uninit_int32_key_array @ 0x00522698 size=0x54
  522698:	3c1c0024 	lui	gp,0x24
  52269c:	279cea68 	addiu	gp,gp,-5528
  5226a0:	0399e021 	addu	gp,gp,t9
  5226a4:	27bdffe0 	addiu	sp,sp,-32
  5226a8:	afbc0010 	sw	gp,16(sp)
  5226ac:	afb00018 	sw	s0,24(sp)
  5226b0:	00808021 	move	s0,a0
  5226b4:	10a00002 	beqz	a1,0x5226c0
  5226b8:	afbf001c 	sw	ra,28(sp)
  5226bc:	aca00000 	sw	zero,0(a1)
  5226c0:	8e040000 	lw	a0,0(s0)
  5226c4:	10800004 	beqz	a0,0x5226d8
  5226c8:	8f998054 	lw	t9,-32684(gp)
  5226cc:	0411ee41 	bal	0x51dfd4
  5226d0:	00000000 	nop
  5226d4:	ae000000 	sw	zero,0(s0)
  5226d8:	8fbf001c 	lw	ra,28(sp)
  5226dc:	00001021 	move	v0,zero
  5226e0:	8fb00018 	lw	s0,24(sp)
  5226e4:	03e00008 	jr	ra
  5226e8:	27bd0020 	addiu	sp,sp,32
