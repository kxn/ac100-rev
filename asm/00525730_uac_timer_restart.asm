; func uac_timer_restart @ 0x00525730 size=0x24
  525730:	3c1c0024 	lui	gp,0x24
  525734:	279cb9d0 	addiu	gp,gp,-17968
  525738:	0399e021 	addu	gp,gp,t9
  52573c:	8f9982f8 	lw	t9,-32008(gp)
  525740:	00002821 	move	a1,zero
  525744:	00003021 	move	a2,zero
  525748:	27394b9c 	addiu	t9,t9,19356
  52574c:	1000fd13 	b	0x524b9c
  525750:	24070001 	li	a3,1
