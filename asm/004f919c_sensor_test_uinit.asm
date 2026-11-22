; func sensor_test_uinit @ 0x004f919c size=0x20
  4f919c:	27bdffe0 	addiu	sp,sp,-32
  4f91a0:	afbf001c 	sw	ra,28(sp)
  4f91a4:	0c14067a 	jal	0x5019e8
  4f91a8:	00000000 	nop
  4f91ac:	00001021 	move	v0,zero
  4f91b0:	8fbf001c 	lw	ra,28(sp)
  4f91b4:	03e00008 	jr	ra
  4f91b8:	27bd0020 	addiu	sp,sp,32
