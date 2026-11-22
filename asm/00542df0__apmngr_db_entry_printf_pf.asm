; func _apmngr_db_entry_printf_pf @ 0x00542df0 size=0x3c
  542df0:	27bdffe0 	addiu	sp,sp,-32
  542df4:	afbf001c 	sw	ra,28(sp)
  542df8:	8c82000c 	lw	v0,12(a0)
  542dfc:	10400007 	beqz	v0,0x542e1c
  542e00:	00000000 	nop
  542e04:	0c1508ee 	jal	0x5423b8
  542e08:	00002821 	move	a1,zero
  542e0c:	8fbf001c 	lw	ra,28(sp)
  542e10:	00001021 	move	v0,zero
  542e14:	03e00008 	jr	ra
  542e18:	27bd0020 	addiu	sp,sp,32
  542e1c:	0c150ad2 	jal	0x542b48
  542e20:	00000000 	nop
  542e24:	08150b84 	j	0x542e10
  542e28:	8fbf001c 	lw	ra,28(sp)
