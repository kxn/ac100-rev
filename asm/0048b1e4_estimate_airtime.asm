; func estimate_airtime @ 0x0048b1e4 size=0x54
  48b1e4:	30e700ff 	andi	a3,a3,0xff
  48b1e8:	30c6ffff 	andi	a2,a2,0xffff
  48b1ec:	70c73002 	mul	a2,a2,a3
  48b1f0:	24030064 	li	v1,100
  48b1f4:	006001f4 	teq	v1,zero,0x7
  48b1f8:	00c3001a 	div	zero,a2,v1
  48b1fc:	00003012 	mflo	a2
  48b200:	30c7ffff 	andi	a3,a2,0xffff
  48b204:	14e00003 	bnez	a3,0x48b214
  48b208:	240200ff 	li	v0,255
  48b20c:	03e00008 	jr	ra
  48b210:	00000000 	nop
  48b214:	00a43021 	addu	a2,a1,a0
  48b218:	70c33002 	mul	a2,a2,v1
  48b21c:	00e001f4 	teq	a3,zero,0x7
  48b220:	00c7001b 	divu	zero,a2,a3
  48b224:	00003812 	mflo	a3
  48b228:	2ce20065 	sltiu	v0,a3,101
  48b22c:	0062380a 	movz	a3,v1,v0
  48b230:	03e00008 	jr	ra
  48b234:	30e200ff 	andi	v0,a3,0xff
