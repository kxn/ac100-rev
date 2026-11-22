; func balance_wtp_hash_key @ 0x0045be58 size=0x6c
  45be58:	27bdffe0 	addiu	sp,sp,-32
  45be5c:	10800006 	beqz	a0,0x45be78
  45be60:	afbf001c 	sw	ra,28(sp)
  45be64:	8fbf001c 	lw	ra,28(sp)
  45be68:	24050006 	li	a1,6
  45be6c:	00003021 	move	a2,zero
  45be70:	081020f4 	j	0x4083d0
  45be74:	27bd0020 	addiu	sp,sp,32
  45be78:	3c020073 	lui	v0,0x73
  45be7c:	8c4213e0 	lw	v0,5088(v0)
  45be80:	14400004 	bnez	v0,0x45be94
  45be84:	8fbf001c 	lw	ra,28(sp)
  45be88:	00001021 	move	v0,zero
  45be8c:	03e00008 	jr	ra
  45be90:	27bd0020 	addiu	sp,sp,32
  45be94:	0c16276a 	jal	0x589da8
  45be98:	00000000 	nop
  45be9c:	5040fffa 	beqzl	v0,0x45be88
  45bea0:	8fbf001c 	lw	ra,28(sp)
  45bea4:	3c040068 	lui	a0,0x68
  45bea8:	3c050069 	lui	a1,0x69
  45beac:	24847440 	addiu	a0,a0,29760
  45beb0:	24a5a7c4 	addiu	a1,a1,-22588
  45beb4:	0c101b74 	jal	0x406dd0
  45beb8:	2406007b 	li	a2,123
  45bebc:	08116fa2 	j	0x45be88
  45bec0:	8fbf001c 	lw	ra,28(sp)
