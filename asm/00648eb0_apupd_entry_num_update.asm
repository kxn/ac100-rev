; func apupd_entry_num_update @ 0x00648eb0 size=0x5c
  648eb0:	24020002 	li	v0,2
  648eb4:	1082000b 	beq	a0,v0,0x648ee4
  648eb8:	3c02007d 	lui	v0,0x7d
  648ebc:	3c02007d 	lui	v0,0x7d
  648ec0:	14a00005 	bnez	a1,0x648ed8
  648ec4:	8c43c760 	lw	v1,-14496(v0)
  648ec8:	1060000b 	beqz	v1,0x648ef8
  648ecc:	2463ffff 	addiu	v1,v1,-1
  648ed0:	03e00008 	jr	ra
  648ed4:	ac43c760 	sw	v1,-14496(v0)
  648ed8:	24630001 	addiu	v1,v1,1
  648edc:	03e00008 	jr	ra
  648ee0:	ac43c760 	sw	v1,-14496(v0)
  648ee4:	14a00006 	bnez	a1,0x648f00
  648ee8:	8c43c75c 	lw	v1,-14500(v0)
  648eec:	10600002 	beqz	v1,0x648ef8
  648ef0:	2463ffff 	addiu	v1,v1,-1
  648ef4:	ac43c75c 	sw	v1,-14500(v0)
  648ef8:	03e00008 	jr	ra
  648efc:	00000000 	nop
  648f00:	24630001 	addiu	v1,v1,1
  648f04:	03e00008 	jr	ra
  648f08:	ac43c75c 	sw	v1,-14500(v0)
