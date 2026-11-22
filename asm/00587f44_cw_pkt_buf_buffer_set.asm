; func cw_pkt_buf_buffer_set @ 0x00587f44 size=0x54
  587f44:	27bdffe0 	addiu	sp,sp,-32
  587f48:	00801821 	move	v1,a0
  587f4c:	30c6ffff 	andi	a2,a2,0xffff
  587f50:	afbf001c 	sw	ra,28(sp)
  587f54:	1080000d 	beqz	a0,0x587f8c
  587f58:	2402ffff 	li	v0,-1
  587f5c:	8c840000 	lw	a0,0(a0)
  587f60:	1080000b 	beqz	a0,0x587f90
  587f64:	8fbf001c 	lw	ra,28(sp)
  587f68:	10c00009 	beqz	a2,0x587f90
  587f6c:	00000000 	nop
  587f70:	8c670008 	lw	a3,8(v1)
  587f74:	00e6382a 	slt	a3,a3,a2
  587f78:	14e00005 	bnez	a3,0x587f90
  587f7c:	00000000 	nop
  587f80:	0c101c8c 	jal	0x407230
  587f84:	a4660004 	sh	a2,4(v1)
  587f88:	00001021 	move	v0,zero
  587f8c:	8fbf001c 	lw	ra,28(sp)
  587f90:	03e00008 	jr	ra
  587f94:	27bd0020 	addiu	sp,sp,32
