; func balance_dis_sta_hash_obj @ 0x0045bdec size=0x6c
  45bdec:	27bdffe0 	addiu	sp,sp,-32
  45bdf0:	10800006 	beqz	a0,0x45be0c
  45bdf4:	afbf001c 	sw	ra,28(sp)
  45bdf8:	8fbf001c 	lw	ra,28(sp)
  45bdfc:	24050006 	li	a1,6
  45be00:	00003021 	move	a2,zero
  45be04:	081020f4 	j	0x4083d0
  45be08:	27bd0020 	addiu	sp,sp,32
  45be0c:	3c020073 	lui	v0,0x73
  45be10:	8c4213e0 	lw	v0,5088(v0)
  45be14:	14400004 	bnez	v0,0x45be28
  45be18:	8fbf001c 	lw	ra,28(sp)
  45be1c:	00001021 	move	v0,zero
  45be20:	03e00008 	jr	ra
  45be24:	27bd0020 	addiu	sp,sp,32
  45be28:	0c16276a 	jal	0x589da8
  45be2c:	00000000 	nop
  45be30:	5040fffa 	beqzl	v0,0x45be1c
  45be34:	8fbf001c 	lw	ra,28(sp)
  45be38:	3c040068 	lui	a0,0x68
  45be3c:	3c050069 	lui	a1,0x69
  45be40:	24847440 	addiu	a0,a0,29760
  45be44:	24a5a790 	addiu	a1,a1,-22640
  45be48:	0c101b74 	jal	0x406dd0
  45be4c:	240600b0 	li	a2,176
  45be50:	08116f87 	j	0x45be1c
  45be54:	8fbf001c 	lw	ra,28(sp)
