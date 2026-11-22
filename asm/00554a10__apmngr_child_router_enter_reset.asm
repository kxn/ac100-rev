; func _apmngr_child_router_enter_reset @ 0x00554a10 size=0x38
  554a10:	27bdffe0 	addiu	sp,sp,-32
  554a14:	94a30000 	lhu	v1,0(a1)
  554a18:	afbf001c 	sw	ra,28(sp)
  554a1c:	84820018 	lh	v0,24(a0)
  554a20:	10430005 	beq	v0,v1,0x554a38
  554a24:	00000000 	nop
  554a28:	8fbf001c 	lw	ra,28(sp)
  554a2c:	00001021 	move	v0,zero
  554a30:	03e00008 	jr	ra
  554a34:	27bd0020 	addiu	sp,sp,32
  554a38:	0c14be62 	jal	0x52f988
  554a3c:	94840010 	lhu	a0,16(a0)
  554a40:	0815528b 	j	0x554a2c
  554a44:	8fbf001c 	lw	ra,28(sp)
