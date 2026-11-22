; func rbtree_get_first @ 0x0051fc98 size=0x68
  51fc98:	3c1c0024 	lui	gp,0x24
  51fc9c:	279c1468 	addiu	gp,gp,5224
  51fca0:	0399e021 	addu	gp,gp,t9
  51fca4:	27bdffe0 	addiu	sp,sp,-32
  51fca8:	afbc0010 	sw	gp,16(sp)
  51fcac:	afbf001c 	sw	ra,28(sp)
  51fcb0:	5080000b 	beqzl	a0,0x51fce0
  51fcb4:	8f848028 	lw	a0,-32728(gp)
  51fcb8:	8f998378 	lw	t9,-31880(gp)
  51fcbc:	0411feb8 	bal	0x51f7a0
  51fcc0:	00000000 	nop
  51fcc4:	00401821 	move	v1,v0
  51fcc8:	10600002 	beqz	v1,0x51fcd4
  51fccc:	00001021 	move	v0,zero
  51fcd0:	8c62000c 	lw	v0,12(v1)
  51fcd4:	8fbf001c 	lw	ra,28(sp)
  51fcd8:	03e00008 	jr	ra
  51fcdc:	27bd0020 	addiu	sp,sp,32
  51fce0:	240602c1 	li	a2,705
  51fce4:	8f858028 	lw	a1,-32728(gp)
  51fce8:	8f9987d0 	lw	t9,-30768(gp)
  51fcec:	24843480 	addiu	a0,a0,13440
  51fcf0:	0320f809 	jalr	t9
  51fcf4:	24a535ac 	addiu	a1,a1,13740
  51fcf8:	1000fff6 	b	0x51fcd4
  51fcfc:	00001021 	move	v0,zero
