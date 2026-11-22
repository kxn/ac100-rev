; func uac_list_insert_first @ 0x0051afb8 size=0x74
  51afb8:	3c1c0024 	lui	gp,0x24
  51afbc:	279c6148 	addiu	gp,gp,24904
  51afc0:	0399e021 	addu	gp,gp,t9
  51afc4:	1080000f 	beqz	a0,0x51b004
  51afc8:	8f828320 	lw	v0,-31968(gp)
  51afcc:	50a0000e 	beqzl	a1,0x51b008
  51afd0:	8c420000 	lw	v0,0(v0)
  51afd4:	8c820000 	lw	v0,0(a0)
  51afd8:	aca40004 	sw	a0,4(a1)
  51afdc:	aca20000 	sw	v0,0(a1)
  51afe0:	ac450004 	sw	a1,4(v0)
  51afe4:	8ca20004 	lw	v0,4(a1)
  51afe8:	ac450000 	sw	a1,0(v0)
  51afec:	aca40008 	sw	a0,8(a1)
  51aff0:	8c820008 	lw	v0,8(a0)
  51aff4:	24420001 	addiu	v0,v0,1
  51aff8:	ac820008 	sw	v0,8(a0)
  51affc:	03e00008 	jr	ra
  51b000:	00000000 	nop
  51b004:	8c420000 	lw	v0,0(v0)
  51b008:	1040fffc 	beqz	v0,0x51affc
  51b00c:	00000000 	nop
  51b010:	8f848028 	lw	a0,-32728(gp)
  51b014:	24060116 	li	a2,278
  51b018:	8f858028 	lw	a1,-32728(gp)
  51b01c:	8f9987d0 	lw	t9,-30768(gp)
  51b020:	2484250c 	addiu	a0,a0,9484
  51b024:	03200008 	jr	t9
  51b028:	24a52620 	addiu	a1,a1,9760
