; func cw_fsm_stat_dec @ 0x0059cd98 size=0x70
  59cd98:	50800014 	beqzl	a0,0x59cdec
  59cd9c:	3c040069 	lui	a0,0x69
  59cda0:	8c8200b4 	lw	v0,180(a0)
  59cda4:	2442fff9 	addiu	v0,v0,-7
  59cda8:	2c420007 	sltiu	v0,v0,7
  59cdac:	10400009 	beqz	v0,0x59cdd4
  59cdb0:	00000000 	nop
  59cdb4:	8c82000c 	lw	v0,12(a0)
  59cdb8:	8c43005c 	lw	v1,92(v0)
  59cdbc:	2463ffff 	addiu	v1,v1,-1
  59cdc0:	ac43005c 	sw	v1,92(v0)
  59cdc4:	2402000d 	li	v0,13
  59cdc8:	8c8300b4 	lw	v1,180(a0)
  59cdcc:	50620003 	beql	v1,v0,0x59cddc
  59cdd0:	8c82000c 	lw	v0,12(a0)
  59cdd4:	03e00008 	jr	ra
  59cdd8:	00000000 	nop
  59cddc:	8c430060 	lw	v1,96(v0)
  59cde0:	2463ffff 	addiu	v1,v1,-1
  59cde4:	03e00008 	jr	ra
  59cde8:	ac430060 	sw	v1,96(v0)
  59cdec:	3c05006e 	lui	a1,0x6e
  59cdf0:	3c07006e 	lui	a3,0x6e
  59cdf4:	2484d3ac 	addiu	a0,a0,-11348
  59cdf8:	24a54b70 	addiu	a1,a1,19312
  59cdfc:	24060107 	li	a2,263
  59ce00:	08101b74 	j	0x406dd0
  59ce04:	24e718e4 	addiu	a3,a3,6372
