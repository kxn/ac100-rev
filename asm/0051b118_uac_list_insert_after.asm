; func uac_list_insert_after @ 0x0051b118 size=0x78
  51b118:	3c1c0024 	lui	gp,0x24
  51b11c:	279c5fe8 	addiu	gp,gp,24552
  51b120:	0399e021 	addu	gp,gp,t9
  51b124:	10800010 	beqz	a0,0x51b168
  51b128:	8f828320 	lw	v0,-31968(gp)
  51b12c:	50a0000f 	beqzl	a1,0x51b16c
  51b130:	8c420000 	lw	v0,0(v0)
  51b134:	aca40004 	sw	a0,4(a1)
  51b138:	8c820000 	lw	v0,0(a0)
  51b13c:	aca20000 	sw	v0,0(a1)
  51b140:	ac450004 	sw	a1,4(v0)
  51b144:	8ca20004 	lw	v0,4(a1)
  51b148:	ac450000 	sw	a1,0(v0)
  51b14c:	8c820008 	lw	v0,8(a0)
  51b150:	aca20008 	sw	v0,8(a1)
  51b154:	8c430008 	lw	v1,8(v0)
  51b158:	24630001 	addiu	v1,v1,1
  51b15c:	ac430008 	sw	v1,8(v0)
  51b160:	03e00008 	jr	ra
  51b164:	00000000 	nop
  51b168:	8c420000 	lw	v0,0(v0)
  51b16c:	1040fffc 	beqz	v0,0x51b160
  51b170:	00000000 	nop
  51b174:	8f848028 	lw	a0,-32728(gp)
  51b178:	24060188 	li	a2,392
  51b17c:	8f858028 	lw	a1,-32728(gp)
  51b180:	8f9987d0 	lw	t9,-30768(gp)
  51b184:	2484254c 	addiu	a0,a0,9548
  51b188:	03200008 	jr	t9
  51b18c:	24a52668 	addiu	a1,a1,9832
