; func uac_md5_timer_restart @ 0x0051d1a4 size=0x24
  51d1a4:	3c1c0024 	lui	gp,0x24
  51d1a8:	279c3f5c 	addiu	gp,gp,16220
  51d1ac:	0399e021 	addu	gp,gp,t9
  51d1b0:	8f9982f8 	lw	t9,-32008(gp)
  51d1b4:	00002821 	move	a1,zero
  51d1b8:	00003021 	move	a2,zero
  51d1bc:	2739c87c 	addiu	t9,t9,-14212
  51d1c0:	1000fdae 	b	0x51c87c
  51d1c4:	24070001 	li	a3,1
