; func uac_id_free @ 0x00519c9c size=0xa4
  519c9c:	10800026 	beqz	a0,0x519d38
  519ca0:	00000000 	nop
  519ca4:	04a00024 	bltz	a1,0x519d38
  519ca8:	00000000 	nop
  519cac:	8c820010 	lw	v0,16(a0)
  519cb0:	00a2102a 	slt	v0,a1,v0
  519cb4:	10400020 	beqz	v0,0x519d38
  519cb8:	00051143 	sra	v0,a1,0x5
  519cbc:	8c860004 	lw	a2,4(a0)
  519cc0:	30a3001f 	andi	v1,a1,0x1f
  519cc4:	00021080 	sll	v0,v0,0x2
  519cc8:	00c23021 	addu	a2,a2,v0
  519ccc:	8cc60000 	lw	a2,0(a2)
  519cd0:	00663007 	srav	a2,a2,v1
  519cd4:	30c60001 	andi	a2,a2,0x1
  519cd8:	10c00017 	beqz	a2,0x519d38
  519cdc:	00000000 	nop
  519ce0:	8c86000c 	lw	a2,12(a0)
  519ce4:	8c880000 	lw	t0,0(a0)
  519ce8:	00063880 	sll	a3,a2,0x2
  519cec:	01073821 	addu	a3,t0,a3
  519cf0:	ace50000 	sw	a1,0(a3)
  519cf4:	24c50001 	addiu	a1,a2,1
  519cf8:	8c860010 	lw	a2,16(a0)
  519cfc:	ac85000c 	sw	a1,12(a0)
  519d00:	00a6282a 	slt	a1,a1,a2
  519d04:	50a00001 	beqzl	a1,0x519d0c
  519d08:	ac80000c 	sw	zero,12(a0)
  519d0c:	8c850004 	lw	a1,4(a0)
  519d10:	00a21021 	addu	v0,a1,v0
  519d14:	24050001 	li	a1,1
  519d18:	00651804 	sllv	v1,a1,v1
  519d1c:	8c450000 	lw	a1,0(v0)
  519d20:	00031827 	nor	v1,zero,v1
  519d24:	00a31824 	and	v1,a1,v1
  519d28:	ac430000 	sw	v1,0(v0)
  519d2c:	8c820014 	lw	v0,20(a0)
  519d30:	2442ffff 	addiu	v0,v0,-1
  519d34:	ac820014 	sw	v0,20(a0)
  519d38:	03e00008 	jr	ra
  519d3c:	00000000 	nop
