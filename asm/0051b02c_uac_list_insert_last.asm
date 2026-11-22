; func uac_list_insert_last @ 0x0051b02c size=0x74
  51b02c:	3c1c0024 	lui	gp,0x24
  51b030:	279c60d4 	addiu	gp,gp,24788
  51b034:	0399e021 	addu	gp,gp,t9
  51b038:	1080000f 	beqz	a0,0x51b078
  51b03c:	8f828320 	lw	v0,-31968(gp)
  51b040:	50a0000e 	beqzl	a1,0x51b07c
  51b044:	8c420000 	lw	v0,0(v0)
  51b048:	8c820004 	lw	v0,4(a0)
  51b04c:	aca40000 	sw	a0,0(a1)
  51b050:	aca20004 	sw	v0,4(a1)
  51b054:	ac850004 	sw	a1,4(a0)
  51b058:	8ca20004 	lw	v0,4(a1)
  51b05c:	ac450000 	sw	a1,0(v0)
  51b060:	aca40008 	sw	a0,8(a1)
  51b064:	8c820008 	lw	v0,8(a0)
  51b068:	24420001 	addiu	v0,v0,1
  51b06c:	ac820008 	sw	v0,8(a0)
  51b070:	03e00008 	jr	ra
  51b074:	00000000 	nop
  51b078:	8c420000 	lw	v0,0(v0)
  51b07c:	1040fffc 	beqz	v0,0x51b070
  51b080:	00000000 	nop
  51b084:	8f848028 	lw	a0,-32728(gp)
  51b088:	2406013a 	li	a2,314
  51b08c:	8f858028 	lw	a1,-32728(gp)
  51b090:	8f9987d0 	lw	t9,-30768(gp)
  51b094:	2484250c 	addiu	a0,a0,9484
  51b098:	03200008 	jr	t9
  51b09c:	24a52638 	addiu	a1,a1,9784
