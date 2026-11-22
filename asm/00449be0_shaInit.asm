; func shaInit @ 0x00449be0 size=0x68
  449be0:	3c026745 	lui	v0,0x6745
  449be4:	ac800154 	sw	zero,340(a0)
  449be8:	24030140 	li	v1,320
  449bec:	ac80015c 	sw	zero,348(a0)
  449bf0:	24422301 	addiu	v0,v0,8961
  449bf4:	ac800158 	sw	zero,344(a0)
  449bf8:	ac820000 	sw	v0,0(a0)
  449bfc:	3c02efcd 	lui	v0,0xefcd
  449c00:	3442ab89 	ori	v0,v0,0xab89
  449c04:	ac820004 	sw	v0,4(a0)
  449c08:	3c0298ba 	lui	v0,0x98ba
  449c0c:	3442dcfe 	ori	v0,v0,0xdcfe
  449c10:	ac820008 	sw	v0,8(a0)
  449c14:	3c021032 	lui	v0,0x1032
  449c18:	24425476 	addiu	v0,v0,21622
  449c1c:	ac82000c 	sw	v0,12(a0)
  449c20:	3c02c3d2 	lui	v0,0xc3d2
  449c24:	3442e1f0 	ori	v0,v0,0xe1f0
  449c28:	ac820010 	sw	v0,16(a0)
  449c2c:	00001021 	move	v0,zero
  449c30:	00822821 	addu	a1,a0,v0
  449c34:	24420004 	addiu	v0,v0,4
  449c38:	1443fffd 	bne	v0,v1,0x449c30
  449c3c:	aca00014 	sw	zero,20(a1)
  449c40:	03e00008 	jr	ra
  449c44:	00000000 	nop
