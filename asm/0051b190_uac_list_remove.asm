; func uac_list_remove @ 0x0051b190 size=0x78
  51b190:	3c1c0024 	lui	gp,0x24
  51b194:	279c5f70 	addiu	gp,gp,24432
  51b198:	0399e021 	addu	gp,gp,t9
  51b19c:	50800010 	beqzl	a0,0x51b1e0
  51b1a0:	8f828320 	lw	v0,-31968(gp)
  51b1a4:	8c820000 	lw	v0,0(a0)
  51b1a8:	8c830004 	lw	v1,4(a0)
  51b1ac:	ac430004 	sw	v1,4(v0)
  51b1b0:	8c820004 	lw	v0,4(a0)
  51b1b4:	8c830000 	lw	v1,0(a0)
  51b1b8:	ac430000 	sw	v1,0(v0)
  51b1bc:	8c820008 	lw	v0,8(a0)
  51b1c0:	8c430008 	lw	v1,8(v0)
  51b1c4:	2463ffff 	addiu	v1,v1,-1
  51b1c8:	ac430008 	sw	v1,8(v0)
  51b1cc:	ac800008 	sw	zero,8(a0)
  51b1d0:	ac800000 	sw	zero,0(a0)
  51b1d4:	ac800004 	sw	zero,4(a0)
  51b1d8:	03e00008 	jr	ra
  51b1dc:	00000000 	nop
  51b1e0:	8c420000 	lw	v0,0(v0)
  51b1e4:	1040fffc 	beqz	v0,0x51b1d8
  51b1e8:	00000000 	nop
  51b1ec:	8f848028 	lw	a0,-32728(gp)
  51b1f0:	240601ad 	li	a2,429
  51b1f4:	8f858028 	lw	a1,-32728(gp)
  51b1f8:	8f9987d0 	lw	t9,-30768(gp)
  51b1fc:	248424d4 	addiu	a0,a0,9428
  51b200:	03200008 	jr	t9
  51b204:	24a52680 	addiu	a1,a1,9856
