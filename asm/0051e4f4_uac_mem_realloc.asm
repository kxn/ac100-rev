; func uac_mem_realloc @ 0x0051e4f4 size=0x70
  51e4f4:	3c1c0024 	lui	gp,0x24
  51e4f8:	279c2c0c 	addiu	gp,gp,11276
  51e4fc:	0399e021 	addu	gp,gp,t9
  51e500:	27bdffe0 	addiu	sp,sp,-32
  51e504:	afbc0010 	sw	gp,16(sp)
  51e508:	afbf001c 	sw	ra,28(sp)
  51e50c:	10800007 	beqz	a0,0x51e52c
  51e510:	00000000 	nop
  51e514:	18a0000d 	blez	a1,0x51e54c
  51e518:	8f998054 	lw	t9,-32684(gp)
  51e51c:	8fbf001c 	lw	ra,28(sp)
  51e520:	8f9987c0 	lw	t9,-30784(gp)
  51e524:	03200008 	jr	t9
  51e528:	27bd0020 	addiu	sp,sp,32
  51e52c:	18a0000a 	blez	a1,0x51e558
  51e530:	8fbf001c 	lw	ra,28(sp)
  51e534:	8fbf001c 	lw	ra,28(sp)
  51e538:	00a02021 	move	a0,a1
  51e53c:	8f99804c 	lw	t9,-32692(gp)
  51e540:	24050193 	li	a1,403
  51e544:	1000fe59 	b	0x51deac
  51e548:	27bd0020 	addiu	sp,sp,32
  51e54c:	0411fea1 	bal	0x51dfd4
  51e550:	00000000 	nop
  51e554:	8fbf001c 	lw	ra,28(sp)
  51e558:	00001021 	move	v0,zero
  51e55c:	03e00008 	jr	ra
  51e560:	27bd0020 	addiu	sp,sp,32
	...
  51e578:	3c190052 	lui	t9,0x52
  51e57c:	2739e580 	addiu	t9,t9,-6784
