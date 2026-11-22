; func uac_sqlite_delete_int32_key_in_db @ 0x005226ec size=0x44
  5226ec:	3c1c0024 	lui	gp,0x24
  5226f0:	279cea14 	addiu	gp,gp,-5612
  5226f4:	0399e021 	addu	gp,gp,t9
  5226f8:	27bdffd8 	addiu	sp,sp,-40
  5226fc:	8f9982f8 	lw	t9,-32008(gp)
  522700:	afbc0018 	sw	gp,24(sp)
  522704:	afbf0024 	sw	ra,36(sp)
  522708:	27392058 	addiu	t9,t9,8280
  52270c:	8fa20038 	lw	v0,56(sp)
  522710:	0411fe51 	bal	0x522058
  522714:	afa20010 	sw	v0,16(sp)
  522718:	2403ffff 	li	v1,-1
  52271c:	8fbf0024 	lw	ra,36(sp)
  522720:	27bd0028 	addiu	sp,sp,40
  522724:	0002180a 	movz	v1,zero,v0
  522728:	03e00008 	jr	ra
  52272c:	00601021 	move	v0,v1
