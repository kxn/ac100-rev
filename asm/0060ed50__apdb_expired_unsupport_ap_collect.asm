; func _apdb_expired_unsupport_ap_collect @ 0x0060ed50 size=0x6c
  60ed50:	10800018 	beqz	a0,0x60edb4
  60ed54:	00000000 	nop
  60ed58:	10a00016 	beqz	a1,0x60edb4
  60ed5c:	00000000 	nop
  60ed60:	8ca2000c 	lw	v0,12(a1)
  60ed64:	10400013 	beqz	v0,0x60edb4
  60ed68:	00000000 	nop
  60ed6c:	8ca30000 	lw	v1,0(a1)
  60ed70:	8ca60004 	lw	a2,4(a1)
  60ed74:	0066302a 	slt	a2,v1,a2
  60ed78:	10c0000e 	beqz	a2,0x60edb4
  60ed7c:	00000000 	nop
  60ed80:	8ca70008 	lw	a3,8(a1)
  60ed84:	8c860048 	lw	a2,72(a0)
  60ed88:	00c7402a 	slt	t0,a2,a3
  60ed8c:	11000009 	beqz	t0,0x60edb4
  60ed90:	00e63023 	subu	a2,a3,a2
  60ed94:	28c6012c 	slti	a2,a2,300
  60ed98:	14c00006 	bnez	a2,0x60edb4
  60ed9c:	00031880 	sll	v1,v1,0x2
  60eda0:	00431021 	addu	v0,v0,v1
  60eda4:	ac440000 	sw	a0,0(v0)
  60eda8:	8ca20000 	lw	v0,0(a1)
  60edac:	24420001 	addiu	v0,v0,1
  60edb0:	aca20000 	sw	v0,0(a1)
  60edb4:	03e00008 	jr	ra
  60edb8:	00000000 	nop
