; func balance_dis_sta_hash_key @ 0x0045bd80 size=0x6c
  45bd80:	27bdffe0 	addiu	sp,sp,-32
  45bd84:	10800006 	beqz	a0,0x45bda0
  45bd88:	afbf001c 	sw	ra,28(sp)
  45bd8c:	8fbf001c 	lw	ra,28(sp)
  45bd90:	24050006 	li	a1,6
  45bd94:	00003021 	move	a2,zero
  45bd98:	081020f4 	j	0x4083d0
  45bd9c:	27bd0020 	addiu	sp,sp,32
  45bda0:	3c020073 	lui	v0,0x73
  45bda4:	8c4213e0 	lw	v0,5088(v0)
  45bda8:	14400004 	bnez	v0,0x45bdbc
  45bdac:	8fbf001c 	lw	ra,28(sp)
  45bdb0:	00001021 	move	v0,zero
  45bdb4:	03e00008 	jr	ra
  45bdb8:	27bd0020 	addiu	sp,sp,32
  45bdbc:	0c16276a 	jal	0x589da8
  45bdc0:	00000000 	nop
  45bdc4:	5040fffa 	beqzl	v0,0x45bdb0
  45bdc8:	8fbf001c 	lw	ra,28(sp)
  45bdcc:	3c040068 	lui	a0,0x68
  45bdd0:	3c050069 	lui	a1,0x69
  45bdd4:	24847440 	addiu	a0,a0,29760
  45bdd8:	24a5a774 	addiu	a1,a1,-22668
  45bddc:	0c101b74 	jal	0x406dd0
  45bde0:	240600c8 	li	a2,200
  45bde4:	08116f6c 	j	0x45bdb0
  45bde8:	8fbf001c 	lw	ra,28(sp)
