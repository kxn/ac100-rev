; func uac_id_is_allocated @ 0x00519ff0 size=0x44
  519ff0:	1080000e 	beqz	a0,0x51a02c
  519ff4:	00001021 	move	v0,zero
  519ff8:	04a0000c 	bltz	a1,0x51a02c
  519ffc:	00000000 	nop
  51a000:	8c830010 	lw	v1,16(a0)
  51a004:	00a3182a 	slt	v1,a1,v1
  51a008:	10600008 	beqz	v1,0x51a02c
  51a00c:	00051943 	sra	v1,a1,0x5
  51a010:	8c820004 	lw	v0,4(a0)
  51a014:	00031880 	sll	v1,v1,0x2
  51a018:	00431821 	addu	v1,v0,v1
  51a01c:	24020001 	li	v0,1
  51a020:	8c630000 	lw	v1,0(v1)
  51a024:	00a22804 	sllv	a1,v0,a1
  51a028:	00a31024 	and	v0,a1,v1
  51a02c:	03e00008 	jr	ra
  51a030:	00000000 	nop
