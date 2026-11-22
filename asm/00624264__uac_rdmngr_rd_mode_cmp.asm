; func _uac_rdmngr_rd_mode_cmp @ 0x00624264 size=0x48
  624264:	27bdffe0 	addiu	sp,sp,-32
  624268:	24020001 	li	v0,1
  62426c:	afb00018 	sw	s0,24(sp)
  624270:	00808021 	move	s0,a0
  624274:	afbf001c 	sw	ra,28(sp)
  624278:	12000008 	beqz	s0,0x62429c
  62427c:	00a02021 	move	a0,a1
  624280:	10a00007 	beqz	a1,0x6242a0
  624284:	8fbf001c 	lw	ra,28(sp)
  624288:	0c101db4 	jal	0x4076d0
  62428c:	00000000 	nop
  624290:	82030009 	lb	v1,9(s0)
  624294:	00431026 	xor	v0,v0,v1
  624298:	0002102b 	sltu	v0,zero,v0
  62429c:	8fbf001c 	lw	ra,28(sp)
  6242a0:	8fb00018 	lw	s0,24(sp)
  6242a4:	03e00008 	jr	ra
  6242a8:	27bd0020 	addiu	sp,sp,32
