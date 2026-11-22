; func uac_list_insert_before @ 0x0051b0a0 size=0x78
  51b0a0:	3c1c0024 	lui	gp,0x24
  51b0a4:	279c6060 	addiu	gp,gp,24672
  51b0a8:	0399e021 	addu	gp,gp,t9
  51b0ac:	10800010 	beqz	a0,0x51b0f0
  51b0b0:	8f828320 	lw	v0,-31968(gp)
  51b0b4:	50a0000f 	beqzl	a1,0x51b0f4
  51b0b8:	8c420000 	lw	v0,0(v0)
  51b0bc:	aca40000 	sw	a0,0(a1)
  51b0c0:	8c820004 	lw	v0,4(a0)
  51b0c4:	aca20004 	sw	v0,4(a1)
  51b0c8:	ac850004 	sw	a1,4(a0)
  51b0cc:	8ca20004 	lw	v0,4(a1)
  51b0d0:	ac450000 	sw	a1,0(v0)
  51b0d4:	8c820008 	lw	v0,8(a0)
  51b0d8:	aca20008 	sw	v0,8(a1)
  51b0dc:	8c430008 	lw	v1,8(v0)
  51b0e0:	24630001 	addiu	v1,v1,1
  51b0e4:	ac430008 	sw	v1,8(v0)
  51b0e8:	03e00008 	jr	ra
  51b0ec:	00000000 	nop
  51b0f0:	8c420000 	lw	v0,0(v0)
  51b0f4:	1040fffc 	beqz	v0,0x51b0e8
  51b0f8:	00000000 	nop
  51b0fc:	8f848028 	lw	a0,-32728(gp)
  51b100:	24060160 	li	a2,352
  51b104:	8f858028 	lw	a1,-32728(gp)
  51b108:	8f9987d0 	lw	t9,-30768(gp)
  51b10c:	2484254c 	addiu	a0,a0,9548
  51b110:	03200008 	jr	t9
  51b114:	24a52650 	addiu	a1,a1,9808
