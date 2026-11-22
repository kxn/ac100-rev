; func apmngr_hdap_get_direct @ 0x00548264 size=0x40
  548264:	27bdffe0 	addiu	sp,sp,-32
  548268:	00001021 	move	v0,zero
  54826c:	1080000a 	beqz	a0,0x548298
  548270:	afbf001c 	sw	ra,28(sp)
  548274:	10a00009 	beqz	a1,0x54829c
  548278:	8fbf001c 	lw	ra,28(sp)
  54827c:	0c101e4c 	jal	0x407930
  548280:	24060006 	li	a2,6
  548284:	00401821 	move	v1,v0
  548288:	04600003 	bltz	v1,0x548298
  54828c:	24020001 	li	v0,1
  548290:	24020002 	li	v0,2
  548294:	0003100a 	movz	v0,zero,v1
  548298:	8fbf001c 	lw	ra,28(sp)
  54829c:	03e00008 	jr	ra
  5482a0:	27bd0020 	addiu	sp,sp,32
