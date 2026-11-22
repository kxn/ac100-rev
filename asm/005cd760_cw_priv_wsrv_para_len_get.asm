; func cw_priv_wsrv_para_len_get @ 0x005cd760 size=0xa8
  5cd760:	10800005 	beqz	a0,0x5cd778
  5cd764:	00001021 	move	v0,zero
  5cd768:	90830008 	lbu	v1,8(a0)
  5cd76c:	2c650005 	sltiu	a1,v1,5
  5cd770:	54a00003 	bnezl	a1,0x5cd780
  5cd774:	3c02006f 	lui	v0,0x6f
  5cd778:	03e00008 	jr	ra
  5cd77c:	00000000 	nop
  5cd780:	00031880 	sll	v1,v1,0x2
  5cd784:	24421d50 	addiu	v0,v0,7504
  5cd788:	00431821 	addu	v1,v0,v1
  5cd78c:	8c620000 	lw	v0,0(v1)
  5cd790:	00400008 	jr	v0
  5cd794:	00000000 	nop
  5cd798:	88830009 	lwl	v1,9(a0)
  5cd79c:	9883000c 	lwr	v1,12(a0)
  5cd7a0:	90620019 	lbu	v0,25(v1)
  5cd7a4:	9064001a 	lbu	a0,26(v1)
  5cd7a8:	90630006 	lbu	v1,6(v1)
  5cd7ac:	00021200 	sll	v0,v0,0x8
  5cd7b0:	14600012 	bnez	v1,0x5cd7fc
  5cd7b4:	00821025 	or	v0,a0,v0
  5cd7b8:	24420017 	addiu	v0,v0,23
  5cd7bc:	3042ffff 	andi	v0,v0,0xffff
  5cd7c0:	03e00008 	jr	ra
  5cd7c4:	00000000 	nop
  5cd7c8:	88830009 	lwl	v1,9(a0)
  5cd7cc:	9883000c 	lwr	v1,12(a0)
  5cd7d0:	90620006 	lbu	v0,6(v1)
  5cd7d4:	90630007 	lbu	v1,7(v1)
  5cd7d8:	00021200 	sll	v0,v0,0x8
  5cd7dc:	00621025 	or	v0,v1,v0
  5cd7e0:	24420011 	addiu	v0,v0,17
  5cd7e4:	03e00008 	jr	ra
  5cd7e8:	3042ffff 	andi	v0,v0,0xffff
  5cd7ec:	03e00008 	jr	ra
  5cd7f0:	24020009 	li	v0,9
  5cd7f4:	03e00008 	jr	ra
  5cd7f8:	2402008f 	li	v0,143
  5cd7fc:	24420023 	addiu	v0,v0,35
  5cd800:	03e00008 	jr	ra
  5cd804:	3042ffff 	andi	v0,v0,0xffff
