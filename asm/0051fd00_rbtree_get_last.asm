; func rbtree_get_last @ 0x0051fd00 size=0x68
  51fd00:	3c1c0024 	lui	gp,0x24
  51fd04:	279c1400 	addiu	gp,gp,5120
  51fd08:	0399e021 	addu	gp,gp,t9
  51fd0c:	27bdffe0 	addiu	sp,sp,-32
  51fd10:	afbc0010 	sw	gp,16(sp)
  51fd14:	afbf001c 	sw	ra,28(sp)
  51fd18:	5080000b 	beqzl	a0,0x51fd48
  51fd1c:	8f848028 	lw	a0,-32728(gp)
  51fd20:	8f99837c 	lw	t9,-31876(gp)
  51fd24:	0411fea8 	bal	0x51f7c8
  51fd28:	00000000 	nop
  51fd2c:	00401821 	move	v1,v0
  51fd30:	10600002 	beqz	v1,0x51fd3c
  51fd34:	00001021 	move	v0,zero
  51fd38:	8c62000c 	lw	v0,12(v1)
  51fd3c:	8fbf001c 	lw	ra,28(sp)
  51fd40:	03e00008 	jr	ra
  51fd44:	27bd0020 	addiu	sp,sp,32
  51fd48:	240602df 	li	a2,735
  51fd4c:	8f858028 	lw	a1,-32728(gp)
  51fd50:	8f9987d0 	lw	t9,-30768(gp)
  51fd54:	24843480 	addiu	a0,a0,13440
  51fd58:	0320f809 	jalr	t9
  51fd5c:	24a535c0 	addiu	a1,a1,13760
  51fd60:	1000fff6 	b	0x51fd3c
  51fd64:	00001021 	move	v0,zero
